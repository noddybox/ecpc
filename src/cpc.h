/*

    ecpc - Amstrad CPC emulator

    Copyright (C) 2026  Ian Cowburn <deathstation9000@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    -------------------------------------------------------------------------

    Provides the emulation for the CPC
*/

#ifndef ECPC_CPC_H
#define ECPC_CPC_H

#include <SDL.h>
#include "z80.h"

/* Initialise the CPC
*/
void		CPCInit(Z80 *z80);

/* Handle keypresses
*/
void		CPCKeyEvent(SDL_Event *e);

/* Interfaces for the Z80
*/
Z80Byte		CPCPeek(Z80 *z80, Z80Word addr);
void		CPCPoke(Z80 *z80, Z80Word addr, Z80Byte val);

#define CPCDisPeek CPCPeek

Z80Byte		CPCReadPort(Z80 *z80, Z80Word port);
void		CPCWritePort(Z80 *z80, Z80Word port, Z80Byte val);

const Z80Label	*CPCGetLabel(void);

/* Interfaces for memory menu
*/
const char	*CPCInfo(Z80 *z80);
void		CPCEnableScreen(int enable);
void		CPCShowScreen(void);

/* Called when the machine is reset
*/
void		CPCReset(Z80 *z80);

/* Return the audio frequency wanted by the Spectrum
*/
int		CPCAudioFrequency(void);

#endif
