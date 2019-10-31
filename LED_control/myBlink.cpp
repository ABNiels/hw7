
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unistd.h>
#include"derek_LED.h"
using namespace std;

int main(int argc, char* argv[]){
   if(argc>3){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   char *ptr;
   long int blinks = strtol(argv[2], &ptr, 10);
   LED led(0);
   if(cmd=="on")led.turnOn();
   else if(cmd=="off")led.turnOff();
   else if(cmd=="flash")led.flash("100"); //default is "50"
   else if(cmd=="blink" && !(*ptr))led.blink((int)blinks);
   else if(cmd=="status")led.outputState();
   else{ cout << "Invalid command!" << endl; }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
