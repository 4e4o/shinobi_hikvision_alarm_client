#include "ServerConfigEx.hpp"
#include "ChannelConfigEx.hpp"

ServerConfigEx::ServerConfigEx(const boost::json::object &o)
    : ServerConfig(o) {
    registerType<ConfigItem, ChannelConfigEx, const boost::json::object&>();
}
