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
#include <stdlib.h>

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