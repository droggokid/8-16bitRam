#include "register.hpp"

Register::Register(ClkSignal& clock) : clock(clock), dataCells{DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock), DataCell(clock)}
{
}

Register::~Register() {}

DataCell& Register::getDataCell(int index) 
{
    return dataCells[index];
}