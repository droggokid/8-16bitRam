#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "data_cell.hpp"
#include <array>

class Register
{
    public:
        Register(ClkSignal& clock);
        ~Register();

        DataCell& getRegister(int index);

    private:
        ClkSignal& clock;
        std::array<DataCell, 8> dataCells;
};

#endif