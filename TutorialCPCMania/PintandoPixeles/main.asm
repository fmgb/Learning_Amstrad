;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.0 #8981 (May 19 2014) (Linux)
; This file was generated Fri Sep 19 11:39:46 2014
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _rand
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;main.c:5: void main() {
;	---------------------------------
; Function main
; ---------------------------------
_main_start::
_main:
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;main.c:13: __endasm;
	ld a, #0
	call #0xBC0E
;main.c:15: for(nByte=0; nByte < 0x3FFF; nByte++) {
	ld	de,#0x0000
00102$:
;main.c:16: pScreen[nByte] = (unsigned char) (rand() % 256);
	ld	hl,#0xC000
	add	hl,de
	ex	(sp), hl
	push	de
	call	_rand
	ld	bc,#0x0100
	push	bc
	push	hl
	call	__modsint_rrx_s
	pop	af
	pop	af
	pop	de
	ld	a,l
	pop	hl
	push	hl
	ld	(hl),a
;main.c:21: __endasm;
	call #0xBB06
;main.c:15: for(nByte=0; nByte < 0x3FFF; nByte++) {
	inc	de
	ld	a,e
	sub	a, #0xFF
	ld	a,d
	sbc	a, #0x3F
	jr	C,00102$
	ld	sp, ix
	pop	ix
	ret
_main_end::
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
