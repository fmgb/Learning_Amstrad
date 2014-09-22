
#include <stdio.h>
#include <stdlib.h>

void main() {
	unsigned char *pScreen = (unsigned char *) 0xC000;
	unsigned int nByte = 0;

	//SCR_SET_MODE 0
	__asm
		ld a, #0
		call #0xBC0E
	__endasm;
	
	for(nByte=0; nByte < 0x3FFF; nByte++) {
		pScreen[nByte] = (unsigned char) (rand() % 256);
		
		//KM_WAIT_CHAR
		__asm
			call #0xBB06
	    __endasm;
	}
}
