//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	Simple basic typedefs, isolated here to make it easier
//	 separating modules.
//    


#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#include <strings.h>

//
// The packed attribute forces structures to be packed into the minimum 
// space necessary.  If this is not done, the compiler may align structure
// fields differently to optimize memory access, inflating the overall
// structure size.  It is important to use the packed attribute on certain
// structures where alignment is important, particularly data read/written
// to disk.
//

#define PACKEDATTR __attribute__((packed))

#define PACKED_STRUCT(...) struct __VA_ARGS__ PACKEDATTR

#include <inttypes.h>

#include <stdbool.h>

typedef uint8_t byte;
typedef uint8_t pixel_t;
typedef int16_t dpixel_t;

#include <limits.h>

#define DIR_SEPARATOR '/'
#define DIR_SEPARATOR_S "/"
#define PATH_SEPARATOR ':'

#define arrlen(array) (sizeof(array) / sizeof(*array))

#endif

