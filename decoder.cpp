#include "decoder.hpp"

Decoder::Decoder()
{
}

Decoder::~Decoder()
{
}

void Decoder::update(bool registerAddress, bool write, bool &output0, bool &output1)
{
    if (!write) {
        output0 = false;
        output1 = false;
    } else {
        output0 = (!registerAddress);
        output1 = registerAddress;
    }
}