//lab3Clock.h
// ENSF 614 FALL 2023 LAB 3 - EXERCISE C
#ifndef LAB3CLOCK_H
#define LAB3CLOCK_H

class Clock{
private:
    int hour;
    int minute;
    int second;

    // Private Helper functions
    int hms_to_sec(int h, int m, int s);
    void sec_to_hms(int seconds);

public:
    // Constructor
    Clock();
    Clock(int s);
    Clock(int h, int m, int s);
    
    // Member Functions
    
    // Setter Funcs
    void set_time(int h, int m, int s);
    void set_hour(int h);
    void set_minute(int m);
    void set_second(int s);

    // Getter Funcs
    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    // Additonal Funcs
    void increment();
    void decrement();
    void add_seconds(int seconds);
    
    // Display
    //void displayTime();

};


#endif

