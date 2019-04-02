#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

#include "qamg8833.h"

using namespace std;

int main()
{
   int fd, result;

    // 0x69 - is a AMG8833 number. 
    // looks like can be 0x68 for original adaruit sensor
    // can be checked with `gpio i2cdetect` command
   fd = wiringPiI2CSetup(0x69);

   cout << "Init result: "<< fd << endl;

   for(int i = 0; i < 0x0000000f; i++)
   {

      result = wiringPiI2CWriteReg8(fd, 0x40, (i & 0xf) );

      if(result == -1)
      {
         cout << "Error.  Errno is: " << errno << endl;
      }
   }
}

