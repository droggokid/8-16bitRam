#ifndef DATA_CELL_HPP
#define DATA_CELL_HPP

#include "clk_signal.hpp"

class DataCell {
public:
    DataCell(ClkSignal& clk);
    ~DataCell();

    void setInput1(unsigned int val);
    unsigned int getInput1() const;

    void setInput2(unsigned int val);

    unsigned int getInput2() const;

    void setOutput(unsigned int val);
    unsigned int getOutput() const;

    bool getClk() const;

private:
    unsigned int input_1;
    unsigned int input_2;
    unsigned int output;
    ClkSignal& clock; 
};

#endif