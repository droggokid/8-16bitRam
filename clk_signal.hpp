#ifndef CLK_SIGNAL_HPP
#define CLK_SIGNAL_HPP

#include <thread>
#include <atomic>

class ClkSignal {
public:
    ClkSignal();
    ~ClkSignal();

private:
    void run();

    unsigned int value;
    std::atomic<bool> running; 
    std::thread clock_thread;
};

#endif