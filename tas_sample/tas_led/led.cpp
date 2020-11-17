#define JC_TEST 1


#if !JC_TEST
#include <wiringPi.h>
#endif 

#include <stdio.h>
#include <string.h>

#define VCC_PIN 0
#define GREEN_PIN 1
#define BLUE_PIN 2

int turn_on_green(){
	printf("%s\n", "Green Light ON!");
#if !JC_TEST
	digitalWrite(VCC_PIN, HIGH); 
	digitalWrite(GREEN_PIN, LOW);
#endif
	return 0;
}

int turn_off_green(){
	printf("%s\n", "Green Light OFF!");
#if !JC_TEST
	digitalWrite(VCC_PIN, HIGH); 
	digitalWrite(GREEN_PIN, HIGH);
#endif 
	
	return 0;
}

int turn_on_blue(){
	printf("%s\n", "Blue Light ON!");
#if !JC_TEST
	digitalWrite(VCC_PIN, HIGH); 
	digitalWrite(BLUE_PIN, LOW);
#endif 
	
	return 0;
}

int turn_off_blue(){
	printf("%s\n", "Blue Light OFF!");
#if !JC_TEST
	digitalWrite(VCC_PIN, HIGH); 
	digitalWrite(BLUE_PIN, HIGH);
#endif 
	
	return 0;
}

int init(){
	printf("%s\n", "Init Light!");
#if !JC_TEST
	digitalWrite(VCC_PIN, HIGH); 
	digitalWrite(GREEN_PIN, HIGH);
	digitalWrite(BLUE_PIN, HIGH);
#endif 
}

int main (int argc,char *argv[])
{
	int i;
    for (i=0; i < argc; i++)
        printf("Argument %d is %s\n", i, argv[i]);
	
#if !JC_TEST
	wiringPiSetup() ;
	pinMode(VCC_PIN, OUTPUT) ;
	pinMode(GREEN_PIN, OUTPUT) ;
	pinMode(BLUE_PIN, OUTPUT) ;
#endif 

	if(argc == 2){
		char* comm = argv[1];
		
		if(strcmp(comm, "1") == 0){
			turn_on_green();
		} else if(strcmp(comm, "2") == 0){
			turn_off_green();
		} else if(strcmp(comm, "3") == 0){
			turn_on_blue();
		} else if(strcmp(comm, "4") == 0){
			turn_off_blue();
		}else if(strcmp(comm, "0") == 0){
			init();
		}
	}

	return 0 ;
}