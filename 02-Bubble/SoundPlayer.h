#pragma once

#include <irrKlang.h>
#include <string>
using namespace std;
using namespace irrklang;

class SoundPlayer
{

public:

	static SoundPlayer& instance()
	{
		static SoundPlayer SP;

		return SP;
	}
	
	void init();
	void play2DSong(char* path, bool loop);

private:

	ISoundEngine* soundEngine;
};

