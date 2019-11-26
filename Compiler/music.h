#ifndef MUSIC_H
#define MUSIC_H

#include <stdlib.h>
#include <stdio.h>

#define LOG_FILE	"sound.log"

#define CORCHEA		20
#define NEGRA		  40
#define BLANCA		80
#define REDONDA		160

#define REST    0
#define C2			6541
#define C2_sharp	6930
#define D2			7342
#define D2_sharp	7778
#define E2			8241
#define F2			8731
#define F2_sharp	9250
#define G2			9800
#define G2_sharp	10383
#define A2			11000
#define A2_sharp	11654
#define B2			12347

#define C3			13081
#define C3_sharp	13859
#define D3			14683
#define D3_sharp	15556
#define E3			16481
#define F3			18500
#define F3_sharp	18500
#define G3			19600
#define G3_sharp	20765
#define A3			22000
#define A3_sharp	23308
#define B3			24694

#define C4			26163
#define C4_sharp	27718
#define D4			29366
#define D4_sharp	31113
#define E4			32963
#define F4			34923
#define F4_sharp	36999
#define G4			39200
#define G4_sharp	41530
#define A4			44000
#define A4_sharp	46616
#define B4			49388

#define C5			52325
#define C5_sharp	55437
#define D5			58733
#define D5_sharp	62225
#define E5			65925
#define F5			69846
#define F5_sharp	73999
#define G5			78399
#define G5_sharp	83061
#define A5			88000
#define A5_sharp	93233
#define B5			98777

#define C6			104650
#define C6_sharp	110873
#define D6			117466
#define D6_sharp	124451
#define E6			131851
#define F6			139691
#define F6_sharp	147998
#define G6			156798
#define G6_sharp	166122
#define A6			176000
#define A6_sharp	186466
#define B6			197553

typedef struct note {
   unsigned	frequency;
   int		  length;
   char     desc[5];
} note;

void shiftNote(char* n, int offset, char* ret);
note createNote(unsigned rate, int ms);
void playNote(note n);
int noteCmp(note n1, note n2);

#endif
