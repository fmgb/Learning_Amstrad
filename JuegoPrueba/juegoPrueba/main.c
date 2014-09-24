#include <stdio.h>
#include "./include/includes.h"
#include "./include/menu.h"
#include "./include/modelo.h"

void pause(void){
	__asm
	ld b,#10
	kolo:
		halt
	djnz kolo

	__endasm;
}

void asignarTeclas() {
	cpc_SetMode(1);
	cpc_DisableFirmware();
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

void main() {
	unsigned int option = 0;
	asignarTeclas();
	MenuPrincipal();

	while(!option) {
		option = elegirOpcion();
		if(option == 1) {
			menuJugar();
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
