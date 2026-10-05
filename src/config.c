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

    Config routines

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "config.h"

/* ---------------------------------------- PRIVATE FUNCTIONS
*/
static void Parse(FILE *fp)
{
    char buff[1024];
    char *section = NULL;

    while(fgets(buff, sizeof buff, fp))
    {
    	size_t l;

	l = strlen(buff);

	if (buff[l-1] == '\n')
	{
	    buff[--l] = 0;
	}

	if (l > 0 && buff[0] != '#')
	{
	    if (buff[0] == '[')
	    {
	    	if (buff[len - 1] != 
	    }
	    else if (section)
	    {
		char *t1=NULL;
		char *t2=NULL;

		t1=strtok(buff,"\t ");
		t2=strtok(NULL,"\t ");

		if (t2)
		{
		    int f;

		    for(f=0;config[f].name;f++)
		    {
			if (strcmp(config[f].name,t1)==0)
			{
			    if (config[f].is_int)
			    {
				int *i;

				i=config[f].var;
				*i=atoi(t2);
			    }
			    else
			    {
				char *p;

				p=config[f].var;
				strcpy(p,t2);
			    }
			}
		    }
		}
		else
		{
		    fprintf(stderr,"Ignored bad config: %s %s\n",t1,t2 ? t2:"");
		}
	    }
	    else
	    {
		fprintf(stderr,"Ignored config without section: %s\n",buff);
	    }
	}
    }
}


/* ---------------------------------------- EXPORTED ROUTINES
*/
void CONFIGRead(void)
{
    FILE *fp;
    char path[FILENAME_MAX]={0};

    if (getenv("HOME"))
    {
    	strcpy(path, getenv("HOME"));
    }

    strcat(path, "/.ecpcrc");

    if ((fp = fopen(path, "r")))
    {
    	Parse(fp);
	fclose(fp);
    }
}

const char *CONFIGValue(const char *section, const char *name)
{
}


long CONFIGValueInt(const char *section, const char *name, long default_value)
{
    const char *value = CONFIGValue(section, name);

    if (!value)
    {
    	return default_value;
    }

    return strtol(value, 0, NULL);
}
