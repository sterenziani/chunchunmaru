#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

note createNote(unsigned rate, int ms)
{
  note n;
  n.frequency = rate;
  n.length = ms;
  switch(ms)
  {
    case CORCHEA: n.desc[0] = '1';
                  break;
    case NEGRA: n.desc[0] = '2';
                  break;
    case BLANCA: n.desc[0] = '3';
                  break;
    case REDONDA: n.desc[0] = '4';
                  break;
  }
  if(rate == REST)
  {
    n.desc[1] = '?';
    n.desc[2] = 'R';
    n.desc[3] = 0;
    return n;
  }
  if(rate >= C3 && rate <= B3)
    n.desc[1] = '0';
  else if(rate >= C4 && rate <= B4)
    n.desc[1] = '1';
  else if(rate >= C5 && rate <= B5)
    n.desc[1] = '2';
  else
    n.desc[1] = '?';

  if(rate == C3 || rate == C4 || rate == C5 || rate == C3_sharp || rate == C4_sharp || rate == C5_sharp)
    n.desc[2] = 'C';
  else if(rate == D3 || rate == D4 || rate == D5 || rate == D3_sharp || rate == D4_sharp || rate == D5_sharp)
    n.desc[2] = 'D';
  else if(rate == E3 || rate == E4 || rate == E5)
    n.desc[2] = 'E';
  else if(rate == F3 || rate == F4 || rate == F5 || rate == F3_sharp || rate == F4_sharp || rate == F5_sharp)
    n.desc[2] = 'F';
  else if(rate == G3 || rate == G4 || rate == G5 || rate == G3_sharp || rate == G4_sharp || rate == G5_sharp)
    n.desc[2] = 'G';
  else if(rate == A3 || rate == A4 || rate == A5 || rate == A3_sharp || rate == A4_sharp || rate == A5_sharp)
    n.desc[2] = 'A';
  else if(rate == B3 || rate == B4 || rate == B5)
    n.desc[2] = 'B';

  if(rate == C3_sharp || rate == C4_sharp || rate == C5_sharp)
    n.desc[3] = '#';
  else if(rate == D3_sharp || rate == D4_sharp || rate == D5_sharp)
    n.desc[3] = '#';
  else if(rate == F3_sharp || rate == F4_sharp || rate == F5_sharp)
    n.desc[3] = '#';
  else if(rate == G3_sharp || rate == G4_sharp || rate == G5_sharp)
    n.desc[3] = '#';
  else if(rate == A3_sharp || rate == A4_sharp || rate == A5_sharp)
    n.desc[3] = '#';
  else
    n.desc[3] = 0;
  n.desc[4] = 0;
  return n;
}

void shiftNote(char* n, int offset, char* ret)
{
  char octave = n[1]+3-'0';
  char key = n[2];
  char sharp = (n[3] == '#')?1:0;
  if(key == 'R')
    ret[0] = 0;

  while(offset > 0)
  {
      if(key == 'B' && octave == 5)
      {
        ret[0] = 0;
        return;
      }

      if((key == 'C' || key == 'D' || key == 'F' || key == 'G' || key == 'A') && !sharp)
      {
        sharp = 1;
      }
      else if(key == 'E')
      {
        key = 'F';
      }
      else if(key == 'B')
      {
        octave++;
        key = 'C';
      }
      else if(key == 'C' && sharp)
      {
        key = 'D';
        sharp = 0;
      }
      else if(key == 'D' && sharp)
      {
        key = 'E';
        sharp = 0;
      }
      else if(key == 'F' && sharp)
      {
        key = 'G';
        sharp = 0;
      }
      else if(key == 'G' && sharp)
      {
        key = 'A';
        sharp = 0;
      }
      else if(key == 'A' && sharp)
      {
        key = 'B';
        sharp = 0;
      }
      offset--;
  }
  while(offset < 0)
  {
    if(key == 'C' && octave == 3)
    {
      ret[0] = 0;
      return;
    }
    if(key == 'C' && !sharp)
    {
      key = 'B';
      octave--;
    }
    else if(key == 'D' && !sharp)
    {
      key = 'C';
      sharp = 1;
    }
    else if(key == 'E')
    {
      key = 'D';
      sharp = 1;
    }
    else if(key == 'F' && !sharp)
    {
      key = 'E';
    }
    else if(key == 'G' && !sharp)
    {
      key = 'F';
      sharp = 1;
    }
    else if(key == 'A' && !sharp)
    {
      key = 'G';
      sharp = 1;
    }
    else if(key == 'B')
    {
      key = 'A';
      sharp = 1;
    }
    else if((key == 'C' || key == 'D' || key == 'F' || key == 'G' || key == 'A') && sharp)
    {
      sharp = 0;
    }
    offset++;
  }
  ret[0] = n[0];
  ret[1] = octave-3+'0';
  ret[2] = key;
  ret[3] = '#';
  ret[4] = 0;
  if(!sharp)
    ret[3] = 0;
}

void playNote(note n)
{
  printf("Please get OpenAL!\n");
}

int noteCmp(note n1, note n2)
{
  int resp = n1.frequency - n2.frequency;
  if(resp == 0)
    return n1.length - n2.length;
  return resp;
}

int isThereMusic()
{
  return 0;
}
