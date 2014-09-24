#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../cpcrslib_br2014/include/cpcrslib.h"

extern const char sprite[], buffer[];
void data(void) {
	__asm
		_sprite:
		.db #0x00,#0x60,#0x00
		.db #0x00,#0xF0,#0x00
		.db #0x10,#0xD0,#0xC0
		.db #0x10,#0xF0,#0xE0
		.db #0x10,#0xF0,#0xE0
		.db #0x22,#0xE4,#0xC0
		.db #0x33,#0x66,#0x00
		.db #0x33,#0x77,#0x00
		.db #0x33,#0x77,#0x00
		.db #0x33,#0xCC,#0x00
		.db #0x11,#0xEE,#0x00
		.db #0x00,#0xFF,#0x00
		.db #0x1F,#0x33,#0x00
		.db #0x0D,#0x03,#0x0E
		.db #0x0E,#0x0B,#0x0D
		.db #0x05,#0x09,#0x0A

		_buffer:
		.db #0,#0,#0,#0,#0,#0,#0,#0
		.db #0,#0,#0,#0,#0,#0,#0,#0
		.db #0,#0,#0,#0,#0,#0,#0,#0
		.db #0,#0,#0,#0,#0,#0,#0,#0
		.db #0,#0,#0,#0,#0,#0,#0,#0
		.db #0,#0,#0,#0,#0,#0,#0,#0
		__endasm;
}

unsigned int
elegirOpcion() {
	while(1) {
		if(cpc_TestKey(11)) {
			printf("Pulsado 1");
			return 1;
		}
		else if(cpc_TestKey(12)) {
			printf("Pulsado 2");
			return 2;
		}
		else if(cpc_TestKey(13)) {
			printf("Pulsado 3");
			return 3;
		}
		else if(cpc_TestKey(14)) {
			printf("Puchfuyfylsado 4");
			return 4;
		}else if(cpc_TestKey(15)) {
			return 5;
		}
	}
}

void JugarArcade() {
	unsigned char buffer[16*3];
	cpc_PrintGphStrXYM1("1;PUTS,A;SPRITE;IN;THE;SCREEN",0,8*23);
	cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*23);
	while(!cpc_AnyKeyPressed()) {}
	cpc_PutSp(sprite, 16,3,0xc19f);
}

void JugarSupervivencia() {
	
}

void JugarMultijugador() {
	
}
#endif
