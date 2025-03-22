#ifndef DATA_CELL_HPP
#define DATA_CELL_HPP

#include "clk_signal.hpp"

class DataCell {
public:
    DataCell(ClkSignal& clk);
    ~DataCell();

    void setInput(bool val);
    bool getInput() const;

    void setOutput(bool val);
    bool getOutput() const;

    bool getClk() const;
    
    void update();

private:
    bool input;
    bool output;
    ClkSignal& clock;
    bool prev_clk;
};

#endif