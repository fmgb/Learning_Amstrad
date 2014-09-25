#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../cpcrslib_br2014/include/cpcrslib.h"
#include "datos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"


void asignarTeclas() {
	cpc_AssignKey(0,  (int)0x4001); //Cursor hacia derecha.
	cpc_AssignKey(1,  (int)0x4000); //Cursor hacia arriba.
	cpc_AssignKey(2,  (int)0x4100); //Cursor izquierda.
	cpc_AssignKey(3,  (int)0x4002); //Cursor abajo.
	cpc_AssignKey(4,  (int)0x4507); //Espacio (Fire1)
	cpc_AssignKey(11, (int)0x4801); //Tecla numerica 1
	cpc_AssignKey(12, (int)0x4802); //Tecla numerica 2
	cpc_AssignKey(13, (int)0x4702); //Tecla numerica 3
	cpc_AssignKey(14, (int)0x4701); //Tecla numerica 4
	cpc_AssignKey(15, (int)0x4602); //Tecla numerica 5
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
///////////////////////////////////////////////////////////
unsigned char char1,char2,char3,char4;

unsigned int GetTime()
{
    unsigned int nTime = 0;

    __asm
        CALL #0xBD0D ;KL TIME PLEASE
        PUSH HL
        POP DE
        LD HL, #_char3
        LD (HL), D
        LD HL, #_char4
        LD (HL), E
    __endasm;

    nTime = (char3 << 8) + char4;

    return nTime;
}
////////////////////////////////////////////////////////////////////

void JugarArcade() {
//	unsigned char buffer[16*3];
	cpc_ClrScr();
	Dibujar();
/*	cpc_PrintGphStrXYM1("1;PUTS,A;SPRITE;IN;THE;SCREEN",0,8*23);
	cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*24);
	while (!cpc_AnyKeyPressed()){}
	cpc_PutSp(sprite,16,3,0xc19b);
	// Captura de la pantalla el area indicada y la guarda en memoria.
    cpc_PrintGphStrXYM1("2;CAPTURES;A;SCREEN;AREA;;;;;",0,8*23);
    cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*24);
    while (!cpc_AnyKeyPressed()){}
	cpc_GetSp(buffer,16,3,0xc19c);
    cpc_PrintGphStrXYM1("3;PRINTS;CAPTURED;AREA",0,8*23);
    cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*24);
    while (!cpc_AnyKeyPressed()){}
	// En este ejemplo, imprime en &c19f el area capturada .
	cpc_PutSp(buffer,16,3,0xc19f);
	// Imprime el Sprite en modo XOR en la coordenada (x,y)=(100,50)
    cpc_PrintGphStrXYM1("4;PUTS;A SPRITE;IN;XOR;MODE",0,8*23);
    cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*24);
    while (!cpc_AnyKeyPressed()){}
    cpc_PutSpXOR(sprite,16,3,cpc_GetScrAddress(100,50));
    cpc_PrintGphStrXYM1("5;SPRITE;PRINTED;AGAIN;IN;XOR;MODE",0,8*23);
    cpc_PrintGphStrXYM1("PRESS;ANY;KEY",0,8*24);
    while (!cpc_AnyKeyPressed()){}
    cpc_PutSpXOR(sprite,16,3,cpc_GetScrAddress(100,50));

    cpc_PrintGphStrXYM1(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;",0,8*23);
    cpc_PrintGphStrXYM1("THE;END;;;;;;",0,8*24);
   while(!cpc_AnyKeyPressed());
	while(!cpc_AnyKeyPressed());
	pause();*/
}

void JugarSupervivencia() {
	
}

void JugarMultijugador() {
	
}
#endif
