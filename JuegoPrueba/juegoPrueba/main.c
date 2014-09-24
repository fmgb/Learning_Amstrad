#include <stdio.h>
#include "./include/includes.h"
#include "./include/menu.h"
#include "./include/modelo.h"

void asignarTeclas() {
	cpc_SetMode(1);
	cpc_DisableFirmware();

	cpc_AssignKey(11, (int)0x4801); //Tecla numerica 1
	cpc_AssignKey(12, (int)0x4802);  //Tecla numerica 2
	cpc_AssignKey(13, (int)0x4702);  //Tecla numerica 3
	cpc_AssignKey(14, (int)0x4701);  //Tecla numerica 4
	cpc_AssignKey(15, (int)0x4602); //Tecla numerica 5
}

void main() {
	unsigned int option = 0;
	asignarTeclas();
	mostrarMenu();

	while(!option) {
		option = elegirOpcion();
		if(option == 1) {
			Jugar();
		}
		else if(option == 2) {
			printf("Entro en configurar");
			Configurar();
		}
		else if(option == 3) {
			SobreMi();
		}
		else if(option == 4) {
			Puntuaciones();
		}
		else if(option == 5) {
			//sale del bucle.
		}
		else {
			option = 0;
		}
	}
	
	printf("Termino");
}
