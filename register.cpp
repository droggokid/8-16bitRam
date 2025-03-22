#include "register.hpp"

Register::Register(ClkSignal& clock) : clock(clock), value(0), dataCells{DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock)}
{
}

Register::~Register() {}

unsigned char Register::getValue() 
{
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        if (getDataCell(i).getOutput()) {
            result |= (1 << i);
        }
    }
    return result;
}

DataCell& Register::getDataCell(int index) 
{
    return dataCells[index];
}