#include <stdlib.h>
#include "tictactoe_leds.h"

int main()
{
    uint8_t iX, iY;

    srand(get_seed());

    init_ports();

    set_on_led();
    while(1)
    {


        set_xy_red_led(0,0);
        _delay_ms(250);
        set_xy_red_led(2,0);
        _delay_ms(250);
        set_xy_red_led(1,1);
        _delay_ms(250);
        set_xy_red_led(0,2);
        _delay_ms(250);
        set_xy_red_led(0,0);
        _delay_ms(250);
    }
}
