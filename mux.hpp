#ifndef MUX_HPP
#define MUX_HPP

class Mux {
public:
    Mux();
    ~Mux();

    void setInput0(unsigned char value);
    void setInput1(unsigned char value);

    void setSelect(bool sel);

    unsigned char getOutput() const;

private:
    unsigned char input0;
    unsigned char input1;
    bool select;
};

#endif 