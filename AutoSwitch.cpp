#include <iostream>
#include <string.h>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <thread>
#include <chrono>
using namespace std;

const char *Outlet_5_On = "python3 ~/send.py -p 188 -t 1 95491";
const char *Outlet_5_Off = "python3 ~/send.py -p 188 -t 1 95500";
const char *Outlet_4_On = "python3 ~/send.py -p 188 -t 1 89347";
const char *Outlet_4_Off = "python3 ~/send.py -p 188 -t 1 89356";
const char *Outlet_3_On = "python3 ~/send.py -p 188 -t 1 87811";
const char *Outlet_3_Off = "python3 ~/send.py -p 188 -t 1 87820";
const char *Outlet_2_On = "python3 ~/send.py -p 188 -t 1 87491";
const char *Outlet_2_Off = "python3 ~/send.py -p 188 -t 1 87500";
const char *Outlet_1_On = "python3 ~/send.py -p 188 -t 1 87347";
const char *Outlet_1_Off = "python3 ~/send.py -p 188 -t 1 87356";

void MSU_Lamp(int tme){
    if((tme >=8) and (tme < 12)){
        system(Outlet_5_On);
    }else{
        system(Outlet_5_Off);
    }
}

void Christmas_Lights(int tme, string day){
    if((day == "Fri") or (day == "Tue") or (day == "Thu")){
	if((tme >= 8) and (tme < 10)){	
	    system(Outlet_4_On);
	}else{
	    system(Outlet_4_Off);
	}
    }else if((day == "Mon") or (day == "Wed")){
	if((tme >= 7) and (tme < 8)){
	    system(Outlet_4_On);
	}else{
	    system(Outlet_4_Off);
	}
    }else{
	if((tme >= 9) and (tme < 11)){
	    system(Outlet_4_On);
	}else{
	    system(Outlet_4_Off);
	}
    }
}	

// You can implement more functions for different outlets here

int main(){
    string hour_s;
    string day_s;
    int hour;
    while(1){
        time_t timer = time(0);
        char *tme = ctime(&timer);
        hour_s.assign(tme + 11, tme + 13);
	day_s.assign(tme, tme + 3);
        hour = stoi(hour_s);
        MSU_Lamp(hour);
	Christmas_Lights(hour, day_s);
        sleep(60);
    }
    return 0;
}
