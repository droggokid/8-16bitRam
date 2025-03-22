#include <iostream>
#include "clk_signal.hpp"
#include "data_cell.hpp"
#include "register.hpp"

int main() {
    ClkSignal clock;
    Register registerA(clock);
    while(1)
    {
        for(int i = 0; i < 8; i++)
        {
            bool value = registerA.getRegister(i).getClk();
            std::cout << value << std::endl;
        }
    }
    return 0;
}