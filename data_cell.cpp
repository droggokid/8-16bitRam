#include "data_cell.hpp"

DataCell::DataCell(ClkSignal& clk) 
    : input_1(0), input_2(0), output(0), clock(clk)
{
}

DataCell::~DataCell() {}

void DataCell::setInput1(unsigned int val) {
    input_1 = val;
}

unsigned int DataCell::getInput1() const {
    return input_1;
}

void DataCell::setInput2(unsigned int val) {
    input_2 = val;
}

unsigned int DataCell::getInput2() const {
    return input_2;
}

void DataCell::setOutput(unsigned int val) {
    output = val;
}

unsigned int DataCell::getOutput() const {
    return output;
}

bool DataCell::getClk() const {
    return clock.getValue();
}