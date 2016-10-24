//
//Funktionen zur Steuerung der TicTacToe-Platine
//
//Datum: 11.09.2010
//
//Autor: Hohmann
//

#ifndef TTT
#define TTT
#include <avr\io.h>
#include <avr\iom644.h>
#include <util\delay.h>

// Initialisierung der globalen Variablen
void init_ports();

//setzen der grünen Status-LED zur Anzeige, dass der Spieler mit den grünen LEDs am Zug ist
void set_status_green_led();

//zurücksetzen der grünen Status-LED zur Anzeige,
//dass der Spieler mit den grünen LEDs nicht mehr am Zug
void reset_status_green_led();

//setzen der roten Status-LED zur Anzeige,
//dass der Spieler mit den roten LEDs am Zug ist
void set_status_red_led();

//zurücksetzen der roten Status-LED zur Anzeige,
// dass der Spieler mit den roten LEDs nicht mehr am Zug ist
void reset_status_red_led();

//setzen der Anzeige, dass das Spiel läuft
void set_on_led();

//zurücksetzen der Anzeige, dass das Spiel läuft
void reset_on_led();

//x,y-Position der gedrückten Tasten ermitteln
void get_button(uint8_t *x, uint8_t *y);

//setzen der roten LED an Position x,y im Spielfeld
void set_xy_red_led(uint8_t x,uint8_t y);

//rote LED an Position x,y zurücksetzen
void reset_xy_red_led(uint8_t x,uint8_t y);

//setzen der grünen LED an Position x,y im Spielfeld
void set_xy_green_led(uint8_t x,uint8_t y);

//grüne LED an Position x,y zurücksetzen
void reset_xy_green_led(uint8_t x,uint8_t y);

/*
Startwert (seed) besorgen
Am einfachsten geht dies, indem man eine Variable in die Section .noinit
lokatiert und den Wert liest:

unsigned long seed __attribute__ ((section (".noinit")));


Etwas bessere Resultate erhält man, wenn man den ganzen Inhalt des nicht
verwendeten SRAMs zur Bildung der seed heranzieht.
Das Symbol __heap_start wird übrigens im standard Linker-Script
definiert, RAMEND ist ein Makro aus avr/ioxxxx.h:
Das Beispiel interpretiert den SRAM-Inhalt als unsigned short Werte und
berechnet die seed, indem die einzelnen Werte mit exor "überlagert"
werden.

*/
unsigned short get_seed();

//
//interne Funktionen:
//gedrückte Taste ermitteln
uint8_t buttons_released();
uint8_t button();
#endif //TTT
