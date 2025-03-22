#include "data_cell.hpp"

DataCell::DataCell(ClkSignal& clk) 
    : input(0), output(0), clock(clk), prev_clk(clock.getValue())
{
}

DataCell::~DataCell() {}

void DataCell::setInput(bool val) 
{
    input = val;
}

bool DataCell::getInput() const 
{
    return input;
}


void DataCell::setOutput(bool val) 
{
    output = val;
}

bool DataCell::getOutput() const 
{
    return output;
}

bool DataCell::getClk() const 
{
    return clock.getValue();
}

void DataCell::update() {
    bool curr_clk = getClk();
    if (!prev_clk && curr_clk) {
        output = input;
    }
    prev_clk = curr_clk;
}