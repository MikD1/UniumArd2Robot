#include <SPI.h>
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"

#include "RadioSimple.h"

Radio::Radio(char* name, int channel, int dataSize)
{
    int payload = dataSize;
    if (payload < 1 || payload > 256)
    {
        payload = 256;
    }

    _data = new byte[payload];

    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((uint8_t*)name);
    Mirf.payload = sizeof(byte) * payload;
    Mirf.channel = channel;
    Mirf.config();
}

Radio::~Radio()
{
    delete[] _data;
}

void Radio::sendData(char* target, byte* data)
{
    send(target, data);
}

void Radio::sendValue(char* target, byte value)
{
    byte data[] = { value };
    send(target, data);
}

bool Radio::available()
{
    return Mirf.dataReady();
}

byte* Radio::receiveData()
{
    Mirf.getData(_data);
    return _data;
}

byte Radio::receiveValue()
{
    Mirf.getData(_data);
    return _data[0];
}

void Radio::send(char* target, byte* data)
{
    Mirf.setTADDR((uint8_t*)target);
    Mirf.send(data);
    while (Mirf.isSending())
    {
    }
}
