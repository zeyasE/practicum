#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

int main()
{
    uint16_t light;
    init_peri();
    while(1)
    {
        light = read_adc(PC4);
        for(int i = 0;i < 8;i++)
        {
            int result = 100;
            if(light < result + i*100){
               set_led_value(i);
                break;
            }
        }
        /*
        if(light < 500)
           set_led_value(0b001);
        else if(light < 700)
           set_led_value(0b010);
        else
           set_led_value(0b100);
        */
    }
}