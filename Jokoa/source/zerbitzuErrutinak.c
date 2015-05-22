/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "egoera.h"
#include "lagungarriak.h"

int EGOERA;

void tekEten()
{
	int tek = SakatutakoTekla();
	if (tek == A)
	{
		if(EGOERA == EGOERA_HASIERA)
		{
			ezabatu_pantaila();
			EGOERA = EGOERA_JOLASTEN;
			ErlojuaMartxanJarri();
		}
		else if (EGOERA == EGOERA_GALDUTA || EGOERA_IRABAZITA)
		{
			ezabatu_pantaila();
			EGOERA = EGOERA_RESET_BERDIN;
		}
	}
	else if (tek == B)
	{
		if(EGOERA == EGOERA_GALDUTA || EGOERA == EGOERA_IRABAZITA)
		{
			ezabatu_pantaila();
			EGOERA = EGOERA_RESET_BERRI;
		}
	}
}

void tenpEten()
{
	static int tik = 0;
	static int seg = 0;

	if (EGOERA == EGOERA_JOLASTEN)
	{
		tik++;
		if(tik == 5)
		{
			tik = 0;
			seg++;
		}

		if (seg==10)
		{
			tik = 0;
			seg = 0;
			ezabatu_pantaila();
			EGOERA = EGOERA_GALDUTA;
			return;
		}
		ezabatu_pantaila_ezik(13);
		iprintf("\x1b[13;5HDenbora = %02d.%02d   ", 9-seg, (4-tik)*20);
	}
	else
	{
		tik = 0;
		seg = 0;
	}
}

void etenZerbErrutEzarri()
{
	irqSet(IRQ_KEYS, tekEten);
	irqSet(IRQ_TIMER0, tenpEten);
}

