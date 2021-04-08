#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#elif __linux
#include <AL/al.h>
#include <AL/alc.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "music.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>


ALCdevice  * openal_output_device;
ALCcontext * openal_output_context;

ALuint internal_buffer;
ALuint streaming_source[1];

int al_check_error(const char * given_label)
{
    ALenum al_error;
    al_error = alGetError();

    if(AL_NO_ERROR != al_error)
    {
        printf("ERROR - %s  (%s)\n", alGetString(al_error), given_label);
        return al_error;
    }
    return 0;
}

void MM_init_al()
{
    const char * defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    openal_output_device  = alcOpenDevice(defname);
    openal_output_context = alcCreateContext(openal_output_device, NULL);
    alcMakeContextCurrent(openal_output_context);

    // setup buffer and source
    alGenBuffers(1, & internal_buffer);
    al_check_error("failed call to alGenBuffers");
}

void MM_exit_al()
{
    ALenum errorCode = 0;

    // Stop the sources
    alSourceStopv(1, & streaming_source[0]);        //      streaming_source
    int ii;
    for (ii = 0; ii < 1; ++ii)
    {
        alSourcei(streaming_source[ii], AL_BUFFER, 0);
    }

    // Clean-up
    alDeleteSources(1, &streaming_source[0]);
    alDeleteBuffers(16, &streaming_source[0]);
    errorCode = alGetError();
    alcMakeContextCurrent(NULL);
    errorCode = alGetError();
    alcDestroyContext(openal_output_context);
    alcCloseDevice(openal_output_device);
}

// Por alguna razon a mayor rate mas rapido se reproduce, pero el rate determina el pitch
void play(unsigned rate, int ms)
{
  MM_init_al();
  float freq = rate;
  float incr_freq = 0.1f;

  size_t buf_size = ms*200*(rate/10000 +1);

  // allocate PCM audio buffer
  short * samples = malloc(sizeof(short) * buf_size);

  int i=0;
  for(; i<buf_size; ++i)
  {
      samples[i] = 10000+i*500;
  }

  /* upload buffer to OpenAL */
  alBufferData( internal_buffer, AL_FORMAT_MONO16, samples, buf_size, rate);
  al_check_error("populating alBufferData");

  free(samples);
  alGenSources(1, & streaming_source[0]);
  alSourcei(streaming_source[0], AL_BUFFER, internal_buffer);
  alSourcePlay(streaming_source[0]);

  // ---------------------

  ALenum current_playing_state;
  alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
  al_check_error("alGetSourcei AL_SOURCE_STATE");

  while (AL_PLAYING == current_playing_state)
  {
      alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
      al_check_error("alGetSourcei AL_SOURCE_STATE");
  }

  /* Dealloc OpenAL */
  MM_exit_al();
}

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

note shiftNote2(note real, int offset)
{
  if(real.frequency == REST)
    return real;
  note n = real;
  while(offset > 0)
  {
      if(n.frequency == B5)
      {
        printf("ERROR: Can't exceed available octaves!\n");
        exit(1);
      }
      if(n.frequency == C3)
      {
        n.frequency = C3_sharp;
        n.desc[2] = 'C';
        n.desc[3] = '#';
      }
      else if(n.frequency == C3_sharp)
      {
        n.frequency = D3;
        n.desc[2] = 'D';
        n.desc[3] = 0;
      }
      else if(n.frequency == D3)
      {
        n.frequency = D3_sharp;
        n.desc[2] = 'D';
        n.desc[3] = '#';
      }
      else if(n.frequency == D3_sharp)
      {
        n.frequency = E3;
        n.desc[2] = 'E';
        n.desc[3] = 0;
      }
      else if(n.frequency == E3)
      {
        n.frequency = F3;
        n.desc[2] = 'F';
        n.desc[3] = 0;
      }
      else if(n.frequency == F3)
      {
        n.frequency = F3_sharp;
        n.desc[2] = 'F';
        n.desc[3] = '#';
      }
      else if(n.frequency == F3_sharp)
      {
        n.frequency = G3;
        n.desc[2] = 'G';
        n.desc[3] = 0;
      }
      else if(n.frequency == G3)
      {
        n.frequency = G3_sharp;
        n.desc[2] = 'G';
        n.desc[3] = '#';
      }
      else if(n.frequency == G3_sharp)
      {
        n.frequency = A3;
        n.desc[2] = 'G';
        n.desc[3] = 0;
      }
      else if(n.frequency == A3)
      {
        n.frequency = A3_sharp;
        n.desc[2] = 'A';
        n.desc[3] = '#';
      }
      else if(n.frequency == A3_sharp)
      {
        n.frequency = B3;
        n.desc[2] = 'B';
        n.desc[3] = 0;
      }
      else if(n.frequency == B3)
      {
        n.frequency = C4;
        n.desc[1] = '1';
        n.desc[2] = 'C';
        n.desc[3] = 0;
      }

      else if(n.frequency == C4)
      {
        n.frequency = C4_sharp;
        n.desc[2] = 'C';
        n.desc[3] = '#';
      }
      else if(n.frequency == C4_sharp)
      {
        n.frequency = D4;
        n.desc[2] = 'D';
        n.desc[3] = 0;
      }
      else if(n.frequency == D4)
      {
        n.frequency = D4_sharp;
        n.desc[2] = 'D';
        n.desc[3] = '#';
      }
      else if(n.frequency == D4_sharp)
      {
        n.frequency = E4;
        n.desc[2] = 'E';
        n.desc[3] = 0;
      }
      else if(n.frequency == E4)
      {
        n.frequency = F4;
        n.desc[2] = 'F';
        n.desc[3] = 0;
      }
      else if(n.frequency == F4)
      {
        n.frequency = F4_sharp;
        n.desc[2] = 'F';
        n.desc[3] = '#';
      }
      else if(n.frequency == F4_sharp)
      {
        n.frequency = G4;
        n.desc[2] = 'G';
        n.desc[3] = 0;
      }
      else if(n.frequency == G4)
      {
        n.frequency = G4_sharp;
        n.desc[2] = 'G';
        n.desc[3] = '#';
      }
      else if(n.frequency == G4_sharp)
      {
        n.frequency = A4;
        n.desc[2] = 'A';
        n.desc[3] = 0;
      }
      else if(n.frequency == A4)
      {
        n.frequency = A4_sharp;
        n.desc[2] = 'A';
        n.desc[3] = '#';
      }
      else if(n.frequency == A4_sharp)
      {
        n.frequency = B4;
        n.desc[2] = 'B';
        n.desc[3] = 0;
      }
      else if(n.frequency == B4)
      {
        n.frequency = C5;
        n.desc[1] = '2';
        n.desc[2] = 'C';
        n.desc[3] = 0;
      }

      else if(n.frequency == C5)
      {
        n.frequency = C5_sharp;
        n.desc[2] = 'G';
        n.desc[3] = '#';
      }
      else if(n.frequency == C5_sharp)
      {
        n.frequency = D5;
        n.desc[2] = 'D';
        n.desc[3] = 0;
      }
      else if(n.frequency == D5)
      {
        n.frequency = D5_sharp;
        n.desc[2] = 'D';
        n.desc[3] = '#';
      }
      else if(n.frequency == D5_sharp)
      {
        n.frequency = E5;
        n.desc[2] = 'E';
        n.desc[3] = 0;
      }
      else if(n.frequency == E5)
      {
        n.frequency = F5;
        n.desc[2] = 'F';
        n.desc[3] = 0;
      }
      else if(n.frequency == F5)
      {
        n.frequency = F5_sharp;
        n.desc[2] = 'G';
        n.desc[3] = '#';
      }
      else if(n.frequency == F5_sharp)
      {
        n.frequency = G5;
        n.desc[2] = 'G';
        n.desc[3] = 0;
      }
      else if(n.frequency == G5)
      {
        n.frequency = G5_sharp;
        n.desc[2] = 'G';
        n.desc[3] = '#';
      }
      else if(n.frequency == G5_sharp)
      {
        n.frequency = A5;
        n.desc[2] = 'A';
        n.desc[3] = 0;
      }
      else if(n.frequency == A5)
      {
        n.frequency = A5_sharp;
        n.desc[2] = 'A';
        n.desc[3] = '#';
      }
      else if(n.frequency == A5_sharp)
      {
        n.frequency = B5;
        n.desc[2] = 'B';
        n.desc[3] = 0;
      }
      offset--;
  }
  while(offset < 0)
  {
    if(n.frequency == C3)
    {
      printf("ERROR: Can't exceed available octaves!\n");
      exit(1);
    }
    else if(n.frequency == C3_sharp)
    {
      n.frequency = C3;
      n.desc[2] = 'C';
      n.desc[3] = 0;
    }
    else if(n.frequency == D3)
    {
      n.frequency = C3_sharp;
      n.desc[2] = 'C';
      n.desc[3] = '#';
    }
    else if(n.frequency == D3_sharp)
    {
      n.frequency = D3;
      n.desc[2] = 'D';
      n.desc[3] = 0;
    }
    else if(n.frequency == E3)
    {
      n.frequency = D3_sharp;
      n.desc[2] = 'D';
      n.desc[3] = '#';
    }
    else if(n.frequency == F3)
    {
      n.frequency = E3;
      n.desc[2] = 'E';
      n.desc[3] = 0;
    }
    else if(n.frequency == F3_sharp)
    {
      n.frequency = F3;
      n.desc[2] = 'F';
      n.desc[3] = 0;
    }
    else if(n.frequency == G3)
    {
      n.frequency = F3_sharp;
      n.desc[2] = 'F';
      n.desc[3] = '#';
    }
    else if(n.frequency == G3_sharp)
    {
      n.frequency = G3;
      n.desc[2] = 'G';
      n.desc[3] = 0;
    }
    else if(n.frequency == A3)
    {
      n.frequency = G3_sharp;
      n.desc[2] = 'G';
      n.desc[3] = '#';
    }
    else if(n.frequency == A3_sharp)
    {
      n.frequency = A3;
      n.desc[2] = 'A';
      n.desc[3] = 0;
    }
    else if(n.frequency == B3)
    {
      n.frequency = A3_sharp;
      n.desc[2] = 'A';
      n.desc[3] = '#';
    }

    else if(n.frequency == C4)
    {
      n.frequency = B3;
      n.desc[1] = '0';
      n.desc[2] = 'B';
      n.desc[3] = 0;
    }
    else if(n.frequency == C4_sharp)
    {
      n.frequency = C4;
      n.desc[2] = 'C';
      n.desc[3] = 0;
    }
    else if(n.frequency == D4)
    {
      n.frequency = C4_sharp;
      n.desc[2] = 'C';
      n.desc[3] = '#';
    }
    else if(n.frequency == D4_sharp)
    {
      n.frequency = D4;
      n.desc[2] = 'D';
      n.desc[3] = 0;
    }
    else if(n.frequency == E4)
    {
      n.frequency = D4_sharp;
      n.desc[2] = 'D';
      n.desc[3] = '#';
    }
    else if(n.frequency == F4)
    {
      n.frequency = E4;
      n.desc[2] = 'E';
      n.desc[3] = 0;
    }
    else if(n.frequency == F4_sharp)
    {
      n.frequency = F4;
      n.desc[2] = 'F';
      n.desc[3] = 0;
    }
    else if(n.frequency == G4)
    {
      n.frequency = F4_sharp;
      n.desc[2] = 'F';
      n.desc[3] = '#';
    }
    else if(n.frequency == G4_sharp)
    {
      n.frequency = G4;
      n.desc[2] = 'G';
      n.desc[3] = 0;
    }
    else if(n.frequency == A4)
    {
      n.frequency = G4_sharp;
      n.desc[2] = 'G';
      n.desc[3] = '#';
    }
    else if(n.frequency == A4_sharp)
    {
      n.frequency = A4;
      n.desc[2] = 'A';
      n.desc[3] = 0;
    }
    else if(n.frequency == B4)
    {
      n.frequency = A4_sharp;
      n.desc[2] = 'A';
      n.desc[3] = '#';
    }

    else if(n.frequency == C5)
    {
      n.frequency = B4;
      n.desc[1] = '1';
      n.desc[2] = 'B';
      n.desc[3] = 0;
    }
    else if(n.frequency == C5_sharp)
    {
      n.frequency = C5;
      n.desc[2] = 'C';
      n.desc[3] = 0;
    }
    else if(n.frequency == D5)
    {
      n.frequency = C5_sharp;
      n.desc[2] = 'C';
      n.desc[3] = '#';
    }
    else if(n.frequency == D5_sharp)
    {
      n.frequency = D5;
      n.desc[2] = 'D';
      n.desc[3] = 0;
    }
    else if(n.frequency == E5)
    {
      n.frequency = D5_sharp;
      n.desc[2] = 'D';
      n.desc[3] = '#';
    }
    else if(n.frequency == F5)
    {
      n.frequency = E5;
      n.desc[2] = 'E';
      n.desc[3] = 0;
    }
    else if(n.frequency == F5_sharp)
    {
      n.frequency = F5;
      n.desc[2] = 'F';
      n.desc[3] = 0;
    }
    else if(n.frequency == G5)
    {
      n.frequency = F5_sharp;
      n.desc[2] = 'F';
      n.desc[3] = '#';
    }
    else if(n.frequency == G5_sharp)
    {
      n.frequency = G5;
      n.desc[2] = 'G';
      n.desc[3] = 0;
    }
    else if(n.frequency == A5)
    {
      n.frequency = G5_sharp;
      n.desc[2] = 'G';
      n.desc[3] = '#';
    }
    else if(n.frequency == A5_sharp)
    {
      n.frequency = A5;
      n.desc[2] = 'A';
      n.desc[3] = 0;
    }
    else if(n.frequency == B5)
    {
      n.frequency = A5_sharp;
      n.desc[2] = 'A';
      n.desc[3] = '#';
    }
    offset++;
  }
  return n;
}

void playNote(note n)
{
  if(n.frequency == REST)
    usleep(n.length * 10000);
  else
    play(n.frequency, n.length);
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
  return 1;
}
