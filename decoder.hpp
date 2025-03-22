#ifndef DECODER_HPP
#define DECODER_HPP

class Decoder
{
    public:
        Decoder();
        ~Decoder();

        // Update the outputs for a 1-to-2 decoder.
        // 'registerAddress' is the select (0 or 1) and 'write' is the global write enable.
        // 'output0' will be active when registerAddress is false; 'output1' when true.
        void update(bool registerAddress, bool write, bool &output0, bool &output1);

    private:
        // You can store additional state if needed.
};

#endif