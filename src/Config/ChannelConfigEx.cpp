#include "ChannelConfigEx.hpp"

ChannelConfigEx::ChannelConfigEx(const boost::json::object &o)
    : ChannelConfig(o),
      m_mappedId(get<std::int64_t>(o, "mapped_id")) {
}

int ChannelConfigEx::mappedId() const {
    return m_mappedId;
}
