#include <iostream>
#include "clk_signal.hpp"

int main() {
    ClkSignal clock;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}