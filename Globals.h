// Copyright (c) 2012- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <utility>

#include "ppsspp_config.h"

#include "Common/Log.h"
#include "Common/CommonTypes.h"

#define IS_LITTLE_ENDIAN (*(const u16 *)"\0\xff" >= 0x100)
#define IS_BIG_ENDIAN (*(const u16 *)"\0\xff" < 0x100)

static inline u8 clamp_u8(int i) {
#if PPSSPP_ARCH(ARM)
	asm("usat %0, #8, %1" : "=r"(i) : "r"(i));
#else
	if (i > 255)
		return 255;
	if (i < 0)
		return 0;
#endif
	return i;
}

static inline s16 clamp_s16(int i) {
#if PPSSPP_ARCH(ARM)
	asm("ssat %0, #16, %1" : "=r"(i) : "r"(i));
#else
	if (i > 32767)
		return 32767;
	if (i < -32768)
		return -32768;
#endif
	return i;
}

#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(t) \
 private: \
 t(const t &other);  \
 void operator =(const t &other);
#endif
