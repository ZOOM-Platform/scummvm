/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//Mix_HookMusicFinished

#include "ultima/nuvie/core/nuvie_defs.h"
#include "ultima/nuvie/sound/adplug/emu_opl.h"
#include "ultima/nuvie/sound/adplug/u6m.h"
#include "ultima/nuvie/sound/song_adplug.h"
#include "ultima/nuvie/sound/sound_manager.h"
#include "ultima/nuvie/nuvie.h"

namespace Ultima {
namespace Nuvie {

SongAdPlug::SongAdPlug(Audio::Mixer *m, CEmuopl *o) {
	mixer = m;
	opl = o;
	samples_left = 0;
	stream = NULL;
}

SongAdPlug::~SongAdPlug() {
}

bool SongAdPlug::Init(const char *filename, const char *fileId, uint16 song_num) {
	if (filename == NULL)
		return false;

	m_Filename = filename; // SB-X

	stream = new U6AdPlugDecoderStream(opl, string(filename), song_num);

	return true;
}

bool SongAdPlug::Play(bool looping) {
	// Just in case song is already playing, stop it
	Stop();

	// Tell the mixer to play the stream
	if (stream) {
		byte volume = g_engine->getSoundManager()->get_music_volume();
		mixer->playStream(Audio::Mixer::kPlainSoundType, &handle, stream, -1, volume, 0, DisposeAfterUse::NO);
	}
	return true;
}

bool SongAdPlug::Stop() {
	mixer->stopHandle(handle);
	stream->rewind();
	return true;
}

bool SongAdPlug::SetVolume(uint8 volume) {
	mixer->setChannelVolume(handle, volume);
	return true;
}

} // End of namespace Nuvie
} // End of namespace Ultima
