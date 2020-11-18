#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>

#define		PCF     120
#define		DOpin	0
#define		Buzz	1


int main()
{
	int analogVal;
	int tmp, status, count;
	
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}
	// Setup pcf8591 on base pin 120, and address 0x48
	pcf8591Setup(PCF, 0x48);

	pinMode (DOpin,	INPUT);
	pinMode (Buzz,	OUTPUT);
	digitalWrite(Buzz, HIGH);

	status = 0;
	count = 0;
	 // loop forever
	
		analogVal = analogRead(PCF + 0);
		printf("%d\n", analogVal);
		break;
		tmp = digitalRead(DOpin);

		if (tmp != status)
		{
			Print(tmp);
			status = tmp;
		}
		
		if (status == 0)
		{
			count ++;
			if (count % 2 == 0)
				{digitalWrite(Buzz, HIGH);}
			else
				{digitalWrite(Buzz, LOW);}
		}
		else
		{
			count = 0;
			digitalWrite(Buzz, HIGH);
		}
		delay (200);
	
	return 0;
}
