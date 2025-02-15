#ifndef _SERIAL_H
#define _SERIAL_H

#include <string>

class SerialPort
{
public:
    SerialPort();
    ~SerialPort();

    bool open(const char* portname, int baudrate = 115200, char parity = 0, char databit = 8, char stopbit = 1, char synchronizeflag = 1);
    bool close();
    int send(std::string dat);
    std::string receive();

private:
#ifdef WIN32
    int pHandle[16];
    char synchronizeflag;
#else
    int fd = 0;
#endif

#ifdef UNIT_TEST
friend class Test_SerialPort;
#endif
};

#endif
