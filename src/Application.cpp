#include "Application.h"
#include "Config/ServerConfigEx.hpp"
#include "Config/ChannelConfigEx.hpp"

#include <AlarmClient.hpp>
#include <Config/Config.hpp>
#include <IPC/IntQueue.h>

#define IPC_QUEUE_NAME  "shinobi_alarm_queue"

Application::Application(int argc, char* argv[])
    : HikAlarmApplication(argc, argv) {
    config()->registerType<ConfigItem, ServerConfigEx, const boost::json::object&>();
}

Application::~Application() {
}

bool Application::start(TConfigItems& c) {
    m_queue.reset(new IPCIntQueue(IPC_QUEUE_NAME));
    m_strand.reset(new StrandHolder(io()));
    return HikAlarmApplication::start(c);
}

void Application::onNewClient(AlarmClient* client) {
    using TMD = AlarmClient::TMotion;

    client->onMotion.connect([this, client](const TMD& md, const size_t& size) {
        const std::string server = client->config()->getComment().empty() ?
                    client->config()->getIp() : client->config()->getComment();
        for (size_t i = 0 ; i < size ; i++) {
            ChannelConfigEx* c = static_cast<ChannelConfigEx*>(md[i]);

            if (c->mappedId() < 0)
                continue;

            m_strand->post([this, c] {
                m_queue->send(c->mappedId());
            });
        }
    });
}
