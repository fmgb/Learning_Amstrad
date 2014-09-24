#ifndef __MENU_H__
#define __MENU_H__
#include "includes.h"
#include "../cpcrslib_br2014/include/cpcrslib.h"
void mostrarMenu() {
	cpc_ClrScr();
	printf("\n\nTITULO DEL JUEGO:\n\n");
	printf("1. Jugar");
	printf("2. Configurar");
	printf("3. About me");
	printf("4. Puntuaciones");
}

void pintarMenu();

unsigned int
elegirOpcion() {
//	cpc_ScanKeyboard();
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
		printf("Pulsado 4");
		return 4;
	}else if(cpc_TestKey(15)) {
		return 5;
	}
		return 0;
}

#endif
