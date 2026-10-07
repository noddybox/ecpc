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
#include "util.h"
#include "exit.h"

typedef struct
{
    const char	*section;
    const char	*item;
    const char	*value;
} ConfigItem;

static size_t num_config = 0;
static ConfigItem *config = NULL;

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
	    	if (buff[l - 1] != ']')
		{
		    Exit("Bad section header: %s\n",buff);
		}

		buff[--l] = 0;
		section = StrCopy(buff);
	    }
	    else if (section)
	    {
		char *t1=NULL;
		char *t2=NULL;

		t1=strtok(buff,"\t ");
		t2=strtok(NULL,"\t ");

		if (t2)
		{
		    config = Realloc(config, (sizeof *config) * ++num_config);
		    config[num_config - 1].section = section;
		    config[num_config - 1].item = StrCopy(t1);
		    config[num_config - 1].value = StrCopy(t2);
		}
		else
		{
		    Exit("Bad config: %s %s\n",t1,t2 ? t2:"");
		}
	    }
	    else
	    {
		Exit("Config without section: %s\n",buff);
	    }
	}
    }
}


/* ---------------------------------------- EXPORTED ROUTINES
*/
void ConfigRead(void)
{
    FILE *fp;
    char path[FILENAME_MAX]={0};

    if (getenv("HOME"))
    {
    	strcpy(path, getenv("HOME"));
    }

    strcat(path, "/.ecpc");

    if ((fp = fopen(path, "r")))
    {
    	Parse(fp);
	fclose(fp);
    }
}

const char *ConfigValue(const char *section, const char *name)
{
    size_t f;

    for(f = 0; f < num_config; f++)
    {
    	if (Equal(config[f].section, section) && Equal(config[f].item, name))
	{
	    return config[f].value;
	}
    }

    return NULL;
}


long ConfigValueInt(const char *section, const char *name, long default_value)
{
    const char *value = ConfigValue(section, name);

    if (!value)
    {
    	return default_value;
    }

    return strtol(value, NULL, 0);
}


int ConfigValueBool(const char *section, const char *name, int default_flag)
{
    const char *value = ConfigValue(section, name);

    if (!value)
    {
    	return default_flag;
    }

    return Equal(value, "1") || Equal(value, "true") ||
	   Equal(value, "on") || Equal(value, "yes");
}
