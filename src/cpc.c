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

#include "cpc.h"

/* ---------------------------------------- EXPORTED FUNCTIONS
*/
void CPCInit(Z80 *z80)
{
}

void CPCKeyEvent(SDL_Event *e)
{
}

Z80Byte CPCPeek(Z80 *z80, Z80Word addr)
{
    return 0;
}

void CPCPoke(Z80 *z80, Z80Word addr, Z80Byte val)
{
}

Z80Byte CPCReadPort(Z80 *z80, Z80Word port)
{
    return 0;
}

void CPCWritePort(Z80 *z80, Z80Word port, Z80Byte val)
{
}

const Z80Label *CPCGetLabel(void)
{
    return NULL;
}

const char *CPCInfo(Z80 *z80)
{
    return "";
}

void CPCEnableScreen(int enable)
{
}

void CPCShowScreen(void)
{
}

void CPCReset(Z80 *z80)
{
}

int CPCAudioFrequency(void)
{
    return 44100;
}
