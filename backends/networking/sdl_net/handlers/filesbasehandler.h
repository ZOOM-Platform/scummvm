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

#ifndef BACKENDS_NETWORKING_SDL_NET_FILESBASEHANDLER_H
#define BACKENDS_NETWORKING_SDL_NET_FILESBASEHANDLER_H

#include "backends/networking/sdl_net/handlers/basehandler.h"

namespace Networking {

class FilesBaseHandler: public BaseHandler {
protected:
	Common::String parentPath(const Common::String &path);

	/**
	* Transforms virtual <path> into actual file system path.
	*
	* Fills prefixes with actual file system prefix ("to remove")
	* and virtual path prefix ("to add").
	*
	* Returns true on success.
	*/
	bool transformPath(Common::String &path, Common::String &prefixToRemove, Common::String &prefixToAdd, bool isDirectory = true);
public:
	FilesBaseHandler();
	~FilesBaseHandler() override;
};

} // End of namespace Networking

#endif
