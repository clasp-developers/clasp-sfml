#include <SFML/Audio/Listener.hpp>
#include <CLASP-SFML/Audio/Music.hpp>
#include <CLASP-SFML/Audio/Sound.hpp>
#include <CLASP-SFML/Audio/SoundBuffer.hpp>
#include <CLASP-SFML/Audio/SoundBufferRecorder.hpp>
#include <CLASP-SFML/Audio/SoundRecorder.hpp>
#include <CLASP-SFML/Audio/SoundSource.hpp>
#include <CLASP-SFML/Audio/SoundStream.hpp>
#include <SFML/System/InputStream.hpp>
#include <CLASP-SFML/translators.hpp>

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
