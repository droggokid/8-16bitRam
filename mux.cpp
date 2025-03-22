#include "mux.hpp"

Mux::Mux() : input0(0), input1(0), select(false) {}

Mux::~Mux() {}

void Mux::setInput0(unsigned char value) {
    input0 = value;
}

void Mux::setInput1(unsigned char value) {
    input1 = value;
}

void Mux::setSelect(bool sel) {
    select = sel;
}

unsigned char Mux::getOutput() const {
    return select ? input1 : input0;
}