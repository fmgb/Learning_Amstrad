#include <string.h>

main()
{
	unsigned char nColor = 0;

	//Set mode 0
	__asm
		ld a, #0
		call #0xBC0E
	__endasm;

	for(nColor = 0; nColor<255;nColor++) 
	{
		memset(0xC000,nColor, 0x3FFF);
	}
	//wait char
	__asm
		call #0xBB06
	__endasm;
}
