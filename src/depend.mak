main.o: main.c z80.h cpc.h gfx.h gui.h memmenu.h config.h exit.h util.h \
 audio.h
cpc.o: cpc.c cpc.h z80.h
config.o: config.c config.h util.h exit.h
gfx.o: gfx.c gfx.h exit.h config.h util.h font.h
gui.o: gui.c gui.h gfx.h exit.h symtochar.h util.h
util.o: util.c util.h exit.h
exit.o: exit.c exit.h
symtochar.o: symtochar.c symtochar.h
font.o: font.c font.h
expr.o: expr.c
audio.o: audio.c audio.h util.h
memmenu.o: memmenu.c memmenu.h z80.h cpc.h gfx.h gui.h util.h expr.h
z80.o: z80.c z80.h z80_private.h
z80_decode.o: z80_decode.c z80.h z80_private.h
z80_dis.o: z80_dis.c
