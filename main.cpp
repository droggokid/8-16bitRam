#include <iostream>
#include "clk_signal.hpp"
#include "data_cell.hpp"
#include "register.hpp"
#include "decoder.hpp"
#include "data_bus.hpp"

int main() {
    ClkSignal clock;
    Decoder decoder;
    DataBus dataBus;

    Register registerA(clock);
    Register registerB(clock);
    
    std::cout << "Enter register select (0 for Register A, 1 for Register B): ";
    int selectInput;
    std::cin >> selectInput;
    bool registerSelect = (selectInput != 0);
    
    std::cout << "Enter global write enable (0 for disable, 1 for enable): ";
    int writeInput;
    std::cin >> writeInput;
    bool globalWrite = (writeInput != 0);
    
    bool writeEnableA = false;
    bool writeEnableB = false;
    
    decoder.update(registerSelect, globalWrite, writeEnableA, writeEnableB);
    
    std::cout << "Write enable for Register A: " << writeEnableA << std::endl;
    std::cout << "Write enable for Register B: " << writeEnableB << std::endl;
    
    std::cout << "Enter data value for the bus (0-255): ";
    unsigned int busData;
    std::cin >> busData;
    dataBus.setValue(static_cast<unsigned char>(busData)); 
    
    if (writeEnableA) {
        for (int i = 0; i < 8; i++) {
            bool bitVal = dataBus.getBit(i);
            registerA.getDataCell(i).setInput(bitVal);
        }
    }
    if (writeEnableB) {
        for (int i = 0; i < 8; i++) {
            bool bitVal = dataBus.getBit(i);
            registerB.getDataCell(i).setInput(bitVal);
        }
    }
    
    while (true) {
        for (int i = 0; i < 8; i++) {
            registerA.getDataCell(i).update();
            registerB.getDataCell(i).update();
        }
    }
    
    return 0;
}