#ifndef KEYBOARD_H
#define KEYBOARD_H

////////////////////////////////////////////////////////////////////////
// Keyboard02.c
// Mochilote - www.cpcmania.com
////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enumeration to identify each physical key
typedef enum _eKey
{
  Key_CursorUp = 0,
  Key_CursorRight,
  Key_CursorDown,
  Key_F9,
  Key_F6,
  Key_F3,
  Key_Enter,
  Key_FDot,
  Key_CursorLeft, //8
  Key_Copy,
  Key_F7,
  Key_F8,
  Key_F5,
  Key_F1,
  Key_F2,
  Key_F0,
  Key_Clr, //16
  Key_BraceOpen,
  Key_Return,
  Key_BraceClose,
  Key_F4,
  Key_Shift,
  Key_BackSlash,
  Key_Control,
  Key_Caret, //24
  Key_Hyphen,
  Key_At,
  Key_P,
  Key_SemiColon,
  Key_Colon,
  Key_Slash,
  Key_Dot,
  Key_0, //32
  Key_9,
  Key_O,
  Key_I,
  Key_L,
  Key_K,
  Key_M,
  Key_Comma,
  Key_8, //40
  Key_7,
  Key_U,
  Key_Y,
  Key_H,
  Key_J,
  Key_N,
  Key_Space,
  Key_6_Joy2Up, //48
  Key_5_Joy2Down,
  Key_R_Joy2Left,
  Key_T_Joy2Right,
  Key_G_Joy2Fire,
  Key_F,
  Key_B,
  Key_V,
  Key_4, //56
  Key_3,
  Key_E,
  Key_W,
  Key_S,
  Key_D,
  Key_C,
  Key_X,
  Key_1, //64
  Key_2,
  Key_Esc,
  Key_Q,
  Key_Tab,
  Key_A,
  Key_CapsLock,
  Key_Z,
  Key_Joy1Up, //72
  Key_Joy1Down,
  Key_Joy1Left,
  Key_Joy1Right,
  Key_Joy1Fire1,
  Key_Joy1Fire2,
  Key_Joy1Fire3,
  Key_Del,
  Key_Max //80
}_ekey;

//Array to associate each physical key to an ASCII character
const unsigned char aKeyAscii[Key_Max] =
{ 
  0xF0, 0xF3, 0xF1, 0x80, 0x80, 0x80, 0x80, 0x80,
  0xF2, 0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x10, 0x5B, 0x0D, 0x5D, 0x80, 0x80, 0x5C, 0x80,
  0x5E, 0x2D, 0x40, 0x70, 0x3B, 0x3A, 0x2F, 0x2E,
  0x30, 0x39, 0x6F, 0x69, 0x6C, 0x6B, 0x6D, 0x2C,
  0x38, 0x37, 0x75, 0x79, 0x68, 0x6A, 0x6E, 0x20,
  0x36, 0x35, 0x72, 0x74, 0x67, 0x66, 0x62, 0x76,
  0x34, 0x33, 0x65, 0x77, 0x73, 0x64, 0x63, 0x78,
  0x31, 0x32, 0x80, 0x71, 0x09, 0x61, 0x80, 0x7A,
  0x0B, 0x0A, 0x08, 0x09, 0x58, 0x5A, 0x80, 0x7F
};

#define KEYBOARD_HW_LINES 10

//Array to handle the 80 physical keys bit state
unsigned char aKeyboard[KEYBOARD_HW_LINES];


////////////////////////////////////////////////////////////////////////
//ReadKeyboard()
//Copied and adapted from the function shown in CPCWiki:
//http://www.cpcwiki.eu/index.php/Programming:Keyboard_scanning
////////////////////////////////////////////////////////////////////////
void ReadKeyboard()
{
  __asm
    di
    ld hl, #_aKeyboard
    ld bc,#0xf782
    out (c),c
    ld bc,#0xf40e
    ld e,b
    out (c),c
    ld bc,#0xf6c0
    ld d,b
    out (c),c
    ld c,#0x00
    out (c),c
    ld bc,#0xf792
    out (c),c
    ld a,#0x40
    ld c,#0x4a
    _loop:
    ld b,d
    out (c),a
    ld b,e
    ini
    inc a
    cp c
    jr c,_loop
    ld bc,#0xf782
    out (c),c
    ei
  __endasm;
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//GetFirstKeyPressed
////////////////////////////////////////////////////////////////////////
enum _eKey GetFirstKeyPressed()
{
  unsigned char nKeyLine = 0;
  unsigned char nBit = 0;
  
  for(nKeyLine = 0; nKeyLine < KEYBOARD_HW_LINES; nKeyLine++)
  {
    for(nBit = 0; nBit < 8; nBit++)
    {
      if(((unsigned char)1 << nBit & aKeyboard[nKeyLine]) == 0)
        return (enum _eKey)(nKeyLine * 8 + nBit);
    }
  }
  
  return Key_Max;
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//IsKeyPressed
////////////////////////////////////////////////////////////////////////
unsigned char IsKeyPressed(enum _eKey eKey)
{
  unsigned char nKeyLine = eKey / 8;
  unsigned char nBit = eKey % 8;
  
  if(((unsigned char)1 << nBit & aKeyboard[nKeyLine]) == 0)
    return 1;
  
  return 0;
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//SetMode
////////////////////////////////////////////////////////////////////////
void SetMode(unsigned char nMode)
{
  __asm
    ld a, 4 (ix)
    call #0xBC0E ;SCR_SET_MODE
  __endasm;
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//SetCursor
////////////////////////////////////////////////////////////////////////
void SetCursor(unsigned char nColum, unsigned char nLine)
{
  __asm
    ld h, 4 (ix)
    ld l, 5 (ix)
    call #0xBB75 ;TXT SET CURSOR
  __endasm;
}
////////////////////////////////////////////////////////////////////////

enum _eKey aPlayerKeys[6] = { Key_CursorUp, Key_CursorDown, Key_CursorLeft, Key_CursorRight, Key_Z, Key_X};
const char aPlayerKeyText[6][6] = { "Up   ", "Down ", "Left ", "Right", "Fire1", "Fire2"};

////////////////////////////////////////////////////////////////////////
//Redefine
////////////////////////////////////////////////////////////////////////
void Redefine()
{
  unsigned char nKey = 0;
  enum _eKey eKey = Key_Max;
    
  SetMode(1);
  
  for(nKey = 0; nKey < 6; nKey++)
  {
    SetCursor(1, 3 + nKey);
    printf("Press a key for %s", aPlayerKeyText[nKey]);
    
    do
    {
      ReadKeyboard();
      eKey = GetFirstKeyPressed();
	  printf("Entro");
    }
    while(eKey == Key_Max);
    
    aPlayerKeys[nKey] = eKey;

    do
    {
      ReadKeyboard();
      eKey = GetFirstKeyPressed();
    }
    while(eKey != Key_Max);
  }
}
////////////////////////////////////////////////////////////////////////

void wait(void){
        __asm

        _kkk:
        ld b,#100
        llll:
        halt
        djnz llll
        __endasm;
}


void tecladoEjemplo() {
	cpc_PrintStr("Press a Key to redefine as #1");
	cpc_RedefineKey(0);             //redefine key. There are 12 available keys (0..1)
	cpc_PrintStr("Done!");
	
	
	cpc_PrintStr("Press any key");
	while(!(cpc_AnyKeyPressed())){}
	
	cpc_PrintStr("fine! try again");
	
	cpc_PrintStr("Press any key to continue");
	while(!(cpc_AnyKeyPressed())){}
	
	
	cpc_PrintStr("Press a Key to redefine as #2");
	cpc_RedefineKey(3);             //redefine key. There are 12 available keys (0..1)
	cpc_PrintStr("Done!");
	
	
    wait();
	
	cpc_SetBorder(3);
	
	
	cpc_PrintStr("Press a Key to test it..");
       while (1) {
                if (cpc_TestKey(0)) {   //test if the key has been pressed.
                        cpc_PrintStr("OK Key #1");
                        }
                if (cpc_TestKey(3)) {   //test if the key has been pressed.
                        cpc_PrintStr("OK Key #2");
                        }
                        //else cpc_PrintStr(no);
        }

	
}
#endif
