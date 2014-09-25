#ifndef VIEW_H
#define VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

#define MAX_X 79
#define MAX_Y 199

void SetColor(unsigned char nColorIndex, unsigned char nPaletteIndex)
{
  __asm
    ld a, 4 (ix)
    ld b, 5 (ix)
    ld c, b
    call #0xBC32 ;SCR SET INK
    __endasm;
}

void SetPalette(const unsigned char *pPalette)
{
  unsigned char nColor = 0;

  for(nColor = 0; nColor < NUM_COLORS; nColor++)
    SetColor(nColor, pPalette[nColor]);
}

void PutSpriteMode0(unsigned char *pSprite, unsigned char nX, unsigned char nY, unsigned char nWidth, unsigned char nHeight)
{
    unsigned char nYPos = 0;
    unsigned char *pAddress = 0;
    
    for(nYPos = 0; nYPos < nHeight; nYPos++)
    {
        pAddress = (unsigned char *)(0xC000 + ((nY / 8u) * 80u) + ((nY % 8u) * 2048u) + nX);

        memcpy(pAddress, pSprite, nWidth);
        pSprite += nWidth;
        nY++;
    }
}

void Dibujar() {

    unsigned int nFPS = 0;
    unsigned int nTimeLast = 0;
    
    int nX = 40;
    int nY = 100;
    char nXDir = 1;
    char nYDir = 2;
    
    //SCR_SET_MODE 0
    __asm
        ld a, #0
        call #0xBC0E
    __endasm;

    //SCR SET BORDER 0
  __asm
    ld b, #0 ;black
    ld c, b
    call #0xBC38
  __endasm;
asignarTeclas();
    SetPalette(NickPalette);

    nTimeLast = GetTime();

while(1) {

if(cpc_TestKey(1) == 1){
//printf("ENTRO");
	nX += nXDir;
}
/*if(cpc_TestKey(1) == 1) 
	nY+= nYDir;
if(cpc_TestKey(2) == 1)
	nX-= nXDir;
if(cpc_TestKey(3) == 1)
nY-=nYDir;*/
if(nX <= 0)
{
nX = 0;
nXDir = 1;
        }

        if(nY <= 0)
        {
            nY = 0;
            nYDir = 2;
        }
        
        if(nX >= (MAX_X - NICK_ANCHO))
        {
            nX = MAX_X - NICK_ANCHO;
            nXDir = -1;
        }

        if(nY >= (MAX_Y - NICK_ALTO))
        {
            nY = MAX_Y - NICK_ALTO;
            nYDir = -2;
        }

        //paint
        PutSpriteMode0(sp_Nick, nX, nY, NICK_ANCHO, NICK_ALTO);
        
        
        nFPS++;
if(GetTime() - nTimeLast >= 300)
        {
            //TXT SET CURSOR 0,0
            __asm
                ld h, #1
                ld l, #1
                call #0xBB75
            __endasm;

            printf("%u  ", nFPS);

            nTimeLast = GetTime();
            nFPS = 0;
}
}
}

#endif
