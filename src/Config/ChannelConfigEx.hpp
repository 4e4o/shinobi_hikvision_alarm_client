#ifndef CHANNEL_CONFIG_EX_HPP
#define CHANNEL_CONFIG_EX_HPP

#include <Config/ChannelConfig.hpp>

class ChannelConfigEx : public ChannelConfig {
public:
    ChannelConfigEx(const boost::json::object&);

    int mappedId() const;

private:
    const int m_mappedId;
};

#endif /* CHANNEL_CONFIG_EX_HPP */
