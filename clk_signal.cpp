#include "clk_signal.hpp"
#include <iostream>
#include <chrono>

ClkSignal::ClkSignal() : running(true), clock_thread(&ClkSignal::run, this) {}

ClkSignal::~ClkSignal() {
    running = false;
    if (clock_thread.joinable()) {
        clock_thread.join();
    }
}

void ClkSignal::run() {
    while (running) {
        std::cout << "Clock Tick" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}