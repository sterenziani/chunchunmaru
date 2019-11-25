// LIBRERÍAS!!!
// sudo apt-get install libopenal-dev

// PARA COMPILAR!!!
// gcc -o sound sound.c -lopenal -lm

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#elif __linux
#include "openal-soft/include/AL/al.h"
#include "openal-soft/include/AL/alc.h"
#endif

#define LOG_FILE	"sound.log"

#define CORCHEA		10
#define NEGRA		20
#define BLANCA		40
#define REDONDA		80

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
   int		length;
} note;

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

  printf("\nPlaying %f\n", freq);
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

note create_note(unsigned rate, int ms)
{
  note n;
  n.frequency = rate;
  n.length = ms;
  return n;
}

void play_note(note n)
{
  play(n.frequency, n.length);
}

int main()
{
    close(STDERR_FILENO);
    int log = open(LOG_FILE, O_CREAT | O_RDWR | O_APPEND);
    play(F4, NEGRA);
    play(A4, NEGRA);
    play(B4, BLANCA);
    play(F4, NEGRA);
    play(A4, NEGRA);
    play(B4, BLANCA);

    play(F4, NEGRA);
    play(A4, NEGRA);
    play(B4, NEGRA);
    play(E5, NEGRA);
    play(D5, BLANCA);

    play(B4, NEGRA);
    play(C5, NEGRA);
    play(B4, NEGRA);
    play(G4, NEGRA);
    play(E4, REDONDA);

    play(D4, NEGRA);
    play(E4, NEGRA);
    play(G4, NEGRA);
    play(E4, REDONDA);

    sleep(1);

    play(E4, BLANCA);
    play(A3, NEGRA);
    play(C4, NEGRA);
    play(D4, NEGRA);
    play(E4, CORCHEA);
    play(D4, CORCHEA);
    play(C4, NEGRA);
    play(B3, NEGRA);
    play(A3, BLANCA);
    play(A3, NEGRA);
    play(C4, NEGRA);
    play(E4, BLANCA);
    play(D4, NEGRA);
    play(C4, NEGRA);
    play(B3, BLANCA);
    play(B3, NEGRA);
    play(C4, NEGRA);
    play(D4, BLANCA);
    play(E4, BLANCA);
    play(C4, BLANCA);
    play(A3, BLANCA);
    play(A3, REDONDA);
}
