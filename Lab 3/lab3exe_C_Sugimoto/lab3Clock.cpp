#include "lab3Clock.h"
#include <iostream>
using namespace std;

    Clock::Clock():hour(0), minute(0), second(0){

    }
    
    Clock::Clock(int s){
        if(59 < s || s < 0){
            second = 0;
            minute = 0;
            hour = 0;
        }
        else{
            sec_to_hms(s);
        }

    }

    Clock::Clock(int h, int m, int s){
        set_time(h,m,s);
    }
    
    void Clock::set_time(int h, int m, int s){
        if(59 < s || s < 0 || 59 < m || m < 0 || 23 < h || h <0){
            second = 0;
            minute = 0;
            hour = 0;
        }

        else{
            second = s;
            minute = m;
            hour = h;
        }
        
    }
    

    void Clock::set_second(int s){
        if(59 >= s && s > -1){
            second = s;
        }
    }

    void Clock::set_minute(int m){
        if(59 >= m && m > -1){
            minute = m;
        }
    }

    void Clock::set_hour(int h){
        if (23 >= h && h > -1){
            hour = h;
        }

    }
    
    int Clock::get_second() const{
        return second;
    }

    int Clock::get_minute() const{
        return minute;
    }

    int Clock::get_hour() const{
        return hour;
    }

    // Additonal Funcs
    void Clock::decrement(){
        second--;
        if(second < 0){
            second = 59;
            minute--;
        }
        if(minute < 0){
            minute = 59;
            hour--;
        }
        if(hour < 0){
            hour = 23;
        }

    }

    void Clock::increment(){
        second++;
        if(second > 59){
            second = 0;
            minute++;
        }
        if(minute > 59){
            minute= 0;
            hour++;
        }
        if(hour > 23){
            hour = 0;
        }
    }
    
    void Clock::add_seconds(int seconds){
        second += (seconds % 60);
        if(second > 59){
            second = 0;
            minute++;
        }
        minute += (seconds % 3600 / 60);
        if(minute > 59){
            minute = 0;
            hour++;
        }
         hour += (seconds / 3600);
        if(hour > 23){
            hour %= 24;
        }
        }
    
    int Clock::hms_to_sec(int h, int m, int s){
        int seconds;
        seconds = (h*3600) + (m*60) + s;

        return seconds;
    }
    void Clock::sec_to_hms(int seconds){
        hour = seconds / 3600;
        if (hour > 23){
            hour %= 24;
        }
        seconds %= 3600;
        minute = seconds / 60;
        second = seconds % 3600;
    }
        