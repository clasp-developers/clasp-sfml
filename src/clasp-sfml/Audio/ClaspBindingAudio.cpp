#include <SFML/Audio/Listener.hpp>
#include <clasp-sfml/Audio/Music.hpp>
#include <clasp-sfml/Audio/Sound.hpp>
#include <clasp-sfml/Audio/SoundBuffer.hpp>
#include <clasp-sfml/Audio/SoundBufferRecorder.hpp>
#include <clasp-sfml/Audio/SoundRecorder.hpp>
#include <clasp-sfml/Audio/SoundSource.hpp>
#include <clasp-sfml/Audio/SoundStream.hpp>
#include <SFML/System/InputStream.hpp>
#include <clasp-sfml/translators.hpp>

#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

#include <cstdlib>

#define EXPORT __attribute__((visibility("default")))


extern "C"
{
EXPORT
void CLASP_MAIN()
{
    using namespace clbind;
    package("SF")
	[
	 //registerListener(),
	 registerSoundBuffer(),
	 registerSoundRecorder(),
	 registerSoundSource(),
	 registerSoundStream(),
	 registerMusic(),
	 registerSound(),
	 registerSoundBufferRecorder()
	];
    }
}
