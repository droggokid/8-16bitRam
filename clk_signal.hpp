#ifndef CLK_SIGNAL_HPP
#define CLK_SIGNAL_HPP

#include <thread>
#include <atomic>

class ClkSignal {
public:
    ClkSignal();
    ~ClkSignal();

    bool getValue();

private:
    void run();

    bool value;
    std::atomic<bool> running; 
    std::thread clock_thread;
};

#endif