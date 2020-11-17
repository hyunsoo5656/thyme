#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdio.h>
 
#include <wiringPi.h>
#include <wiringSerial.h>
 
using namespace std;
 
int main()
{
    int fd;
    uint8_t pms[32];
    uint16_t pm1, pm25, pm10, checkcode = 0;
    if ((fd = serialOpen("/dev/ttyUSB0",9600)) < 0)
    {
        return 1;
    }
 
    while(1)
    {
        for(int i = 0 ; i < 32; i++)
        {
            pms[i] = serialGetchar(fd);
            if(i<30)
                checkcode += pms[i];
        }
        cout << endl;
        if ((pms[0] == 0x42) && (pms[1] == 0x4d))
        {
            uint16_t tmp = (pms[30] << 8) + pms[31];
            if(checkcode == tmp);
 
            pm1 = (pms[10] << 8) + pms[11];
            pm25 = (pms[12] << 8) + pms[13];
            pm10 = (pms[14] << 8) + pms[15];
 
            printf("%d, %d, %d", pm1,  pm25 ,pm10);
            break;
        }
        checkcode = 0;
        delay(1000);
    }
}
