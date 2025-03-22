#include "data_cell.hpp"

DataCell::DataCell() 
    : input_1(0), input_2(0), output(0), clk(0)
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

void DataCell::setClk(unsigned int val) {
    clk = val;
}

unsigned int DataCell::getClk() const {
    return clk;
}