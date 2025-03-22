#include "data_bus.hpp"

DataBus::DataBus() : bus(0) {}

DataBus::~DataBus() {}

void DataBus::setValue(unsigned char value) {
    bus = std::bitset<8>(value);
}

unsigned char DataBus::getValue() const {
    return static_cast<unsigned char>(bus.to_ulong());
}

void DataBus::setBit(int pos, bool value) {
    if (pos >= 0 && pos < 8) {
        bus.set(pos, value);
    }
}

bool DataBus::getBit(int pos) const {
    return (pos >= 0 && pos < 8) ? bus.test(pos) : false;
}

std::bitset<8> DataBus::getBits() const {
    return bus;
}