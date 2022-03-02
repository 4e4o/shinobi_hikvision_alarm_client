#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <HikAlarmApplication.h>

class IPCIntQueue;
class StrandHolder;

class Application : public HikAlarmApplication {
public:
    Application(int argc, char* argv[]);
    ~Application();

protected:
    void onNewClient(AlarmClient*) override final;

private:
    bool start(TConfigItems&) override;

    std::unique_ptr<IPCIntQueue> m_queue;
    std::unique_ptr<StrandHolder> m_strand;
};

#endif /* APPLICATION_HPP */
