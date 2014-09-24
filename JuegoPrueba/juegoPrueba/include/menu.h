#ifndef __MENU_H__
#define __MENU_H__
#include "includes.h"
#include "sonido.h"
#include "controlador.h"
#include "../cpcrslib_br2014/include/cpcrslib.h"
void mostrarMenu() 
{
	cpc_ClrScr();
	sound('1',478,200,'15',0,0,0);
	printf("\n\nTITULO DEL JUEGO:\n\n");
	printf("1. Jugar");
	printf("2. Configurar");
	printf("3. About me");
	printf("4. Puntuaciones");
}

void pintarMenu();

void menuJugar() {
	printf("1. Modo Arcade");
	printf("2. Modo Supervivencia");
	printf("3. Modo Multijugador");
	printf("4. Volver");
}

void ConfigurarSonido() {
	
}

void menuConfigurar() {
	printf("1. Sonido");
	printf("2. Teclado");
	printf("3. Volver");
}

void RedefinicionTeclas() {
	cpc_ClrScr();
	printf("Define la tecla >"); //Tecla hacia la derecha 0
	cpc_RedefineKey(0);
	cpc_ClrScr();
	printf("Define la tecla <"); //Tecla hacia la izquierda 1
	cpc_RedefineKey(1);
	cpc_ClrScr();
	printf("Define la tecla ^"); //Tecla hacia arriba 2
	cpc_RedefineKey(2);
	cpc_ClrScr();
	printf("Define la tecla v"); //Tecla hacia abajo 3
	cpc_RedefineKey(3);
	cpc_ClrScr();
	printf("Define la tecla Fire");
	cpc_RedefineKey(4);
	cpc_ClrScr();
	//COMPROBAR SI HA CAMBIADO LAS TECLAS
	while(1) {
		printf("\n");
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
		else if(cpc_TestKey(4)) {
			printf("Has pulsado la tecla Fire");
		}
		else if(cpc_TestKey(11)) { //Tecla 1 para salir.
			break;
		}
	}
}

void configurarTeclado() {
	RedefinicionTeclas();
	Configurar();
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
		else if(option == 3) {
			MenuPrincipal();
		}
		else {
			option = 0;
		}
	}
}
#endif
