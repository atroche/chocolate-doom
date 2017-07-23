//
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
//
// Main dehacked code
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "doomtype.h"
#include "i_system.h"
#include "d_iwad.h"
#include "m_argv.h"
#include "w_wad.h"

#include "deh_defs.h"
#include "deh_io.h"

extern char *deh_signatures[];

// If true, we can parse [STRINGS] sections in BEX format.

boolean deh_allow_extended_strings = false;

// If true, we can do long string replacements.

boolean deh_allow_long_strings = false;

// If true, we can do cheat replacements longer than the originals.

boolean deh_allow_long_cheats = false;

// If false, dehacked cheat replacements are ignored.

boolean deh_apply_cheats = true;

