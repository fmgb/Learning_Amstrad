#ifndef SONIDO_H
#define SONIDO_H
#include <stdio.h>


//TONOS
// LA 284
// DO 478
// RE 426
// MI = 379
// FA = 358
// SI = 253
// SOL = 319
//Firmware requires it in the central 32K of RAM (0x4000 to 0xC000), move it as you need...
#define SOUND_BUFF 0x4FF6 //9 bytes
#define ENT_BUFF 0x4FE6 //16 bytes
#define ENV_BUFF 0x4FD6 //16 bytes

////////////////////////////////////////////////////////////////////////
//sound
////////////////////////////////////////////////////////////////////////
unsigned char bQueue = 0;

unsigned char
sound(unsigned char nChannelStatus, 
	  int nTonePeriod, 
	  int nDuration,
	  unsigned char nVolume, 
	  char nVolumeEnvelope, 
	  char nToneEnvelope,
	  unsigned char nNoisePeriod)
{
  //This function uses 9 bytes of memory for sound buffer. Firmware requires it in the central 32K of RAM (0x4000 to 0xC000)
  /*
    The bytes required to define the sound are as follows
    byte 0 - channel status byte
    byte 1 - volume envelope to use
    byte 2 - tone envelope to use
    bytes 3&4 - tone period
    byte 5 - noise period
    byte 6 - start volume
    bytes 7&8 - duration of the sound, or envelope repeat count 
  */
  
  __asm
    LD HL, #SOUND_BUFF

    LD A, 4 (IX) ;nChannelStatus
    LD (HL), A
    INC HL

    LD A, 10 (IX) ;nVolumeEnvelope
    LD (HL), A
    INC HL

    LD A, 11 (IX) ;nToneEnvelope
    LD (HL), A
    INC HL

    LD A, 5 (IX) ;nTonePeriod
    LD (HL), A
    INC HL
    LD A, 6 (IX) ;nTonePeriod
    LD (HL), A
    INC HL

    LD A, 12 (IX) ;nNoisePeriod
    LD (HL), A
    INC HL

    LD A, 9 (IX) ;nVolume
    LD (HL), A
    INC HL

    LD A, 7 (IX) ;nDuration
    LD (HL), A
    INC HL
    LD A, 8 (IX) ;nDuration
    LD (HL), A
    INC HL

    LD HL, #SOUND_BUFF
    CALL #0xBCAA ;SOUND QUEUE
  
    LD HL, #_bQueue
    LD (HL), #0
    JP NC, _EndSound
    LD (HL), #1
    _EndSound:
  __endasm;
  
  return bQueue;
}

////////////////////////////////////////////////////////////////////////
//ent
////////////////////////////////////////////////////////////////////////
void ent(unsigned char nEnvelopeNumber, unsigned char nNumberOfSteps, char nTonePeriodOfStep, unsigned char nTimePerStep)
{
  //This function uses 16 bytes of memory for ent buffer. Firmware requires it in the central 32K of RAM (0x4000 to 0xC000)
  
  __asm
    LD HL, #ENT_BUFF

    LD A, #0x1
    LD (HL), A
    INC HL

    LD A, 5 (IX) ;nNumberOfSteps
    LD (HL), A
    INC HL

    LD A, 6 (IX) ;nTonePeriodOfStep
    LD (HL), A
    INC HL

    LD A, 7 (IX) ;nTimePerStep
    LD (HL), A
    INC HL

    LD A, 4 (IX) ;nEnvelopeNumber
    LD HL, #ENT_BUFF
    CALL #0xBCBF ;SOUND TONE ENVELOPE
  __endasm;
}
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//env
////////////////////////////////////////////////////////////////////////
void env(unsigned char nEnvelopeNumber, unsigned char nNumberOfSteps, char nSizeOfStep, unsigned char nTimePerStep)
{
  //This function uses 16 bytes of memory for env buffer. Firmware requires it in the central 32K of RAM (0x4000 to 0xC000)
  
  __asm
    LD HL, #ENV_BUFF

    LD A, #0x1
    LD (HL), A
    INC HL

    LD A, 5 (IX) ;nNumberOfSteps
    LD (HL), A
    INC HL

    LD A, 6 (IX) ;nSizeOfStep
    LD (HL), A
    INC HL

    LD A, 7 (IX) ;nTimePerStep
    LD (HL), A
    INC HL

    LD A, 4 (IX) ;nEnvelopeNumber
    LD HL, #ENV_BUFF
    CALL #0xBCBC ;SOUND AMPL ENVELOPE
  __endasm;
}
////////////////////////////////////////////////////////////////////////
#endif
