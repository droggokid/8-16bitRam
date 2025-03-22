#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "data_cell.hpp"
#include <array>

class Register
{
    public:
        Register(ClkSignal& clock);
        ~Register();

        unsigned char getValue();

        DataCell& getDataCell(int index);
        
    private:
        ClkSignal& clock;
        unsigned char value;
        std::array<DataCell, 8> dataCells;
};

#endif