/*
 * Copyright (C) 2006-2016 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_OGG_DECODER_H
#define SOLARUS_OGG_DECODER_H

#include "solarus/Common.h"
#include "solarus/lowlevel/Sound.h"
#include <string>

namespace Solarus {

/**
 * \brief Encapsulates the Ogg Vorbis music decoding.
 */
class OggDecoder {

  public:

    OggDecoder();
    ~OggDecoder();

    bool load(const std::string& ogg_data, bool loop);
    void unload();
    void decode(ALuint destination_buffer, ALsizei nb_samples);

  private:

    OggVorbis_File ogg_file;           /**< The file used by the vorbisfile lib. */
    Sound::SoundFromMemory ogg_mem;    /**< The encoded music loaded in memory,
                                        * passed to the vorbisfile lib as user data. */

};

}

#endif
