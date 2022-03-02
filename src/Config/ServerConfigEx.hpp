#ifndef SERVER_CONFIG_EX_HPP
#define SERVER_CONFIG_EX_HPP

#include <Config/ServerConfig.hpp>

class ServerConfigEx : public ServerConfig {
public:
    ServerConfigEx(const boost::json::object&);
};

#endif /* SERVER_CONFIG_EX_HPP */
