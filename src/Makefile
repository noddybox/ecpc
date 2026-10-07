# ecpc - Amstrad CPC emulator
# 
# Copyright (C) 2026  Ian Cowburn <deathstation9000@gmail.com>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
# 
# -------------------------------------------------------------------------
# 


# This CFLAGS assumes that gcc is being used.
# Simply comment out if not, and replace as needed.
# Other CFLAGS lines *are* required.
#
CFLAGS	=	-g -O2

TARGET	=	ecpc

SOURCE	=	main.c		\
		cpc.c		\
		config.c	\
		gfx.c		\
		gui.c		\
		util.c		\
		exit.c		\
		symtochar.c	\
		font.c	        \
		expr.c		\
		audio.c		\
		memmenu.c	\
		z80.c		\
		z80_decode.c	\
		z80_dis.c

OBJECTS	=	$(SOURCE:.c=.o)

CFLAGS +=	`sdl2-config --cflags` -Igfx-bitmap -DENABLE_DISASSEM

LIBS	=	`sdl2-config --libs`

$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

depend.mak: $(SOURCE)
	$(CC) -MM $(SOURCE) > depend.mak || true

clean:
	rm -f $(TARGET) $(TARGET).exe $(OBJECTS) core

include depend.mak
