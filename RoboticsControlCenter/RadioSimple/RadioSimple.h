#ifndef RadioSimple_h
#define RadioSimple_h

#include <Arduino.h>

/*
 * Pins:
 * MISO -> 12
 * MOSI -> 11
 * SCK  -> 13
 * CE   -> 8
 * CSN  -> 7
*/

class Radio
{
public:
    // name:     5 characters
    // channel:  1 - 125
    // dataSize: 1 - 256 
    Radio(char* name, int channel, int dataSize = 1);
    ~Radio();

    void sendData(char* target, byte* data);
    void sendValue(char* target, byte value);
    bool available();
    byte* receiveData();
    byte receiveValue();

private:
    void send(char* target, byte* data);

private:
    byte* _data;
};

#endif // RadioSimple_h
