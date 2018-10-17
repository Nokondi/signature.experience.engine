#include "SoundDevice.h"
//#include "AssetLibrary.h"
//#include "ResourceManager.h"

SoundDevice::~SoundDevice()
{
	Shutdown();
}
//**************************************
//set's up initial setting for sound device
bool SoundDevice::initialize(ResourceManager* devices)
//**************************************
{
	this->devices= devices;
	//allows for OGG support
	{
		auto flags = MIX_INIT_OGG;
		auto initted = Mix_Init(flags);

		if (initted && flags != flags)
		{
			printf("Mix_Init: Failed to init required ogg and mod support!\n");
			printf("Mix_Init: %s\n", Mix_getError());
			return false;
		}
	}

	//Load the Mixer subsystem
	if(Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 4096 ) <0)
	{
		printf( "SDL Mixer could not initialize! SDL_Error: %s\n", Mix_getError() );
		return false;
	}

	//Allocate sufficient channels
    Mix_AllocateChannels(100);
	return true;
}

//**************************************
//plays a sound for a number of loops, must be in the sound library.
bool SoundDevice::PlaySound(std::string sound, int numLoops)
//**************************************
{
	int channelID = -1; //Select first available channel
	PlaySound(sound, numLoops, channelID);
	return true;
}
//**************************************
//same as above, but here we can specify a channel to play the sound on.
bool SoundDevice::PlaySound(std::string sound, int numLoops, int channel)
//**************************************
{
		Mix_PlayChannel(channel, devices->getAssetLibrary() ->getSoundEffect(sound), numLoops);
		return true;
}
//**************************************
//set's the background music to play.
void SoundDevice::setBackground(std::string background)
//**************************************
{
	if(Mix_PlayMusic(devices->getAssetLibrary()-> getMusic(background), -1) == -1)
	{printf("Mix_PlayMusic: %s\n", Mix_getError());}
}
void SoundDevice::Shutdown()
{
	
}