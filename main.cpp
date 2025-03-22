#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <sstream>
#include "clk_signal.hpp"
#include "data_cell.hpp"
#include "register.hpp"
#include "decoder.hpp"
#include "data_bus.hpp"
#include "mux.hpp"

std::mutex ioMutex;

// Shared control variables (all thread-safe)
std::atomic<bool> registerSelect(false);
std::atomic<unsigned int> busData(0);
std::atomic<bool> writeRequested(false);
std::atomic<bool> printRequested(false);
std::atomic<bool> exitFlag(false);

void simulationLoop() {
    // Instantiate hardware components
    ClkSignal clock;
    Decoder decoder;
    DataBus dataBus;
    Register registerA(clock);
    Register registerB(clock);
    Mux mux;
    
    while (!exitFlag.load()) {
        bool writeEnableA = false, writeEnableB = false;
        // Use the writeRequested flag in the decoder update to decide which register gets written.
        decoder.update(registerSelect.load(), writeRequested.load(), writeEnableA, writeEnableB);
        
        // Update the common data bus with the current bus data.
        dataBus.setValue(static_cast<unsigned char>(busData.load()));
        
        // If a write is requested, update the selected register's data cells.
        if (writeRequested.load()) {
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
            // Simulate a clock edge: update all data cells.
            for (int i = 0; i < 8; i++) {
                registerA.getDataCell(i).update();
                registerB.getDataCell(i).update();
            }
            // Reset the write request flag.
            writeRequested.store(false);
        }
        
        // Set up the multiplexer for reading.
        unsigned char valueA = registerA.getValue();
        unsigned char valueB = registerB.getValue();
        mux.setInput0(valueA);
        mux.setInput1(valueB);
        mux.setSelect(registerSelect.load());
        
        // If user requested a print, display the mux output.
        if (printRequested.load()) {
            unsigned char muxOutput = mux.getOutput();
            {
                std::lock_guard<std::mutex> lock(ioMutex);
                std::cout << "Mux output: " << static_cast<int>(muxOutput) << std::endl;
            }
            printRequested.store(false);
        }
        
        // Delay for simulation pacing.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void inputLoop() {
    std::string line;
    while (!exitFlag.load()) {
        {
            std::lock_guard<std::mutex> lock(ioMutex);
            std::cout << "\nEnter command (set, write, print, quit): " << std::flush;
        }
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        
        if (cmd == "set") {
            std::string var;
            iss >> var;
            if (var == "regselect") {
                int val;
                iss >> val;
                registerSelect.store(val != 0);
                {
                    std::lock_guard<std::mutex> lock(ioMutex);
                    std::cout << "Register select set to " << (val != 0 ? "Register B" : "Register A") << std::endl;
                }
            }
            else if (var == "bus") {
                int val;
                iss >> val;
                if(val >= 0 && val < 256) {
                    busData.store(val);
                    {
                        std::lock_guard<std::mutex> lock(ioMutex);
                        std::cout << "Bus data set to " << val << std::endl;
                    }
                } else {
                    std::lock_guard<std::mutex> lock(ioMutex);
                    std::cout << "Invalid bus value. Enter a value between 0 and 255." << std::endl;
                }
            }
            else {
                std::lock_guard<std::mutex> lock(ioMutex);
                std::cout << "Unknown variable." << std::endl;
            }
        }
        else if (cmd == "write") {
            writeRequested.store(true);
            {
                std::lock_guard<std::mutex> lock(ioMutex);
                std::cout << "Write operation triggered." << std::endl;
            }
        }
        else if (cmd == "print") {
            printRequested.store(true);
        }
        else if (cmd == "quit") {
            exitFlag.store(true);
        }
        else {
            std::lock_guard<std::mutex> lock(ioMutex);
            std::cout << "Unknown command." << std::endl;
        }
    }
}

int main() {
    // Start the simulation and input threads.
    std::thread simThread(simulationLoop);
    std::thread inpThread(inputLoop);
    
    // Wait for threads to finish.
    if (inpThread.joinable()) {
        inpThread.join();
    }
    if (simThread.joinable()) {
        simThread.join();
    }
    
    return 0;
}
