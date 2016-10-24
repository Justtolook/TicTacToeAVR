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

//setzen der gr�nen Status-LED zur Anzeige, dass der Spieler mit den gr�nen LEDs am Zug ist
void set_status_green_led();

//zur�cksetzen der gr�nen Status-LED zur Anzeige,
//dass der Spieler mit den gr�nen LEDs nicht mehr am Zug
void reset_status_green_led();

//setzen der roten Status-LED zur Anzeige,
//dass der Spieler mit den roten LEDs am Zug ist
void set_status_red_led();

//zur�cksetzen der roten Status-LED zur Anzeige,
// dass der Spieler mit den roten LEDs nicht mehr am Zug ist
void reset_status_red_led();

//setzen der Anzeige, dass das Spiel l�uft
void set_on_led();

//zur�cksetzen der Anzeige, dass das Spiel l�uft
void reset_on_led();

//x,y-Position der gedr�ckten Tasten ermitteln
void get_button(uint8_t *x, uint8_t *y);

//setzen der roten LED an Position x,y im Spielfeld
void set_xy_red_led(uint8_t x,uint8_t y);

//rote LED an Position x,y zur�cksetzen
void reset_xy_red_led(uint8_t x,uint8_t y);

//setzen der gr�nen LED an Position x,y im Spielfeld
void set_xy_green_led(uint8_t x,uint8_t y);

//gr�ne LED an Position x,y zur�cksetzen
void reset_xy_green_led(uint8_t x,uint8_t y);

/*
Startwert (seed) besorgen
Am einfachsten geht dies, indem man eine Variable in die Section .noinit
lokatiert und den Wert liest:

unsigned long seed __attribute__ ((section (".noinit")));


Etwas bessere Resultate erh�lt man, wenn man den ganzen Inhalt des nicht
verwendeten SRAMs zur Bildung der seed heranzieht.
Das Symbol __heap_start wird �brigens im standard Linker-Script
definiert, RAMEND ist ein Makro aus avr/ioxxxx.h:
Das Beispiel interpretiert den SRAM-Inhalt als unsigned short Werte und
berechnet die seed, indem die einzelnen Werte mit exor "�berlagert"
werden.

*/
unsigned short get_seed();

//
//interne Funktionen:
//gedr�ckte Taste ermitteln
uint8_t buttons_released();
uint8_t button();
#endif //TTT
