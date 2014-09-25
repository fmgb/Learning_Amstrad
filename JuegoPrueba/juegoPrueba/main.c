#include <stdio.h>
#include "./include/includes.h"
#include "./include/menu.h"
#include "./include/modelo.h"
#include "./include/view.h"
void pause1(void){
	__asm
	ld b,#10
	kolo:
		halt
	djnz kolo

	__endasm;
}

void main() {
	cpc_SetMode(1);
	cpc_DisableFirmware();
//	SetBorder(1);
	SetColor(0,0);
//	SetColor(1,26);
	asignarTeclas();
	MenuPrincipal();

}
