#ifndef DATA_BUS_HPP
#define DATA_BUS_HPP

#include <bitset>

class DataBus
{
    public:
        DataBus();
        ~DataBus();

        void setValue(unsigned char value);
        unsigned char getValue() const;

        void setBit(int pos, bool value);
        bool getBit(int pos) const;

        std::bitset<8> getBits() const;

    private:
        std::bitset<8> bus;
};

#endif