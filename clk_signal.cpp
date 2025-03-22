#include "clk_signal.hpp"
#include <iostream>
#include <chrono>

ClkSignal::ClkSignal() : running(true), clock_thread(&ClkSignal::run, this) 
{
    value = false;
}

ClkSignal::~ClkSignal() {
    running = false;
    if (clock_thread.joinable()) {
        clock_thread.join();
    }
}



bool ClkSignal::getValue()
{
    return value;
}

void ClkSignal::run() {
    while (running) {
        value = !value;
        std::cout << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}