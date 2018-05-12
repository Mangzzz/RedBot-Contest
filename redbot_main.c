/*
 * Redbot_1.1.c
 *
 * Created: 2018-05-10 12:26:38
 * Author : Team Lauda
 */ 

#define  F_CPU 16000000

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "redbot.h"



struct sensor_data_ground track;
struct sensor_data_distance object;
/*
ISR(TIMER0_COMPA_vect){
	
}

ISR(TIMER0_COMPB_vect){
	
}

ISR(TIMER0_OVF_vect){
	
}
*/
int main(void){
	initialization();
    while (1){
		;
    }
	
	return 0;
}

void initialization(){
		TCCR0A |= (1 << COM0A0) | (1 << COM0A1) | (1 << COM0B0) |(1<<COM0B1) | (1 << WGM00)  | (1 << WGM00);
		TCCR0B |= (1 << CS00); //No prescaling
		OCR1A = 0xF0;
		OCR1B = 0xD0;

		sei();
}

void race(){
	read_track();
	read_object();
	set_speed();
}

int read_track(){
	//read track sensor values
	track.left_left;
	track.mid_left;
	track.mid_mid;
	track.mid_rigth;
	track.rigth_rigth
}

int read_object(){
	//read dist sensor values
	object.left;
	object.rigth;
	object.side;
}

void set_speed(){
	OCR1A = 0xE0;
	OCR1B = 0xE0;
	
	//if track is moving, turn to find optimal placement
	//if object is found, turn to avoid
}

void turn_left(char obj_dist){
	OCR1A = 0xE0;
	OCR1B = 0xD0;
}

void turn_rigth(char obj_dist){
	OCR1A = 0xE0;
	OCR1B = 0xD0;	
}

void park_car(){
	//Turn left until passed sideline (keep driving after sensors reading line to get whole care over the line)
	OCR1A = 0xE0;
	OCR1B = 0xD0;	
}






