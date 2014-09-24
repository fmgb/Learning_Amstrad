#ifndef MODELO_H
#define MODELO_H

#include "../cpcrslib_br2014/include/cpcrslib.h"
#include "menu.h"

void Jugar() {
	
}

void ConfigurarSonido() {
	
}

void menuConfigurar() {
	printf("1. Sonido");
	printf("2. Teclado");
}

void ConfigurarTeclado() {
	printf("Define la tecla >"); //Tecla hacia la derecha 0
	cpc_RedefineKey(0);
	printf("Define la tecla <"); //Tecla hacia la izquierda 1
	cpc_RedefineKey(1);
	printf("Define la tecla ^"); //Tecla hacia arriba 2
	cpc_RedefineKey(2);
	printf("Define la tecla v"); //Tecla hacia abajo 3
	cpc_RedefineKey(3);
	
	//COMPROBAR SI HA CAMBIADO LAS TECLAS
	while(1) {
		if(cpc_TestKey(0)) {
			printf("Has pulsado la tecla >");
		}
		else if(cpc_TestKey(1)) {
			printf("Has pulsado la tecla <");
		}
		else if(cpc_TestKey(2)) {
			printf("Has pulsado la tecla ^");
		}
		else if(cpc_TestKey(3)) {
			printf("Has pulsado la tecla v");
		}
		
	}
}

void Configurar() {
	unsigned int option = 0;
	cpc_ClrScr();
	menuConfigurar();
	while(!option) {
		option = elegirOpcion();
		if(option == 1) {
			ConfigurarSonido();
		}
		else if(option == 2) {
			ConfigurarTeclado();
		}
		else {
			option = 0;
		}
	}
}

void RedefinicionTeclas() {
	
}

void SobreMi() {
	
}

void Puntuaciones() {
	
}

#endif
