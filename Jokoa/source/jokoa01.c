/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "egoera.h"
#include "lagungarriak.h"

#define OFFSET_Y		80
#define OFFSET_X_GORRIA	65
#define OFFSET_X_BERDEA	88
#define OFFSET_X_URDINA	107
#define OFFSET_X_MOREA	128
#define OFFSET_X_HORIA	159

#define X_MIN			71
#define GORRIA_MAX		92
#define BERDEA_MAX		109
#define URDINA_MAX		133
#define MOREA_MAX		163
#define HORIA_MAX		187

#define Y_MIN			49
#define Y_MAX			143

int get_kable(int px, int py);
char* kable_izena(int kablea);
void reset();
void erakutsi_spritea(int kable);
void init();

int offseta[5] =
{
	OFFSET_X_GORRIA,
	OFFSET_X_BERDEA,
	OFFSET_X_URDINA,
	OFFSET_X_MOREA,
	OFFSET_X_HORIA,
};

int piztuta[5] = {0, 0, 0, 0, 0};

void jokoa01()
{
	init();

	srand(time(NULL));

	erakutsiFondoa();

	int kable_ona = rand() % 5; // 0-4 tarteko zenbaki bat
	while (1)
	{
		if(EGOERA == EGOERA_HASIERA)
		{
			iprintf("\x1b[5;2HA tekla sakatu jokoa hasteko     ");

			iprintf("\x1b[8;2HJokoa hasten denean, 10      ");
			iprintf("\x1b[9;2Hsegundu edukiko dituzu bonba    ");
			iprintf("\x1b[10;2Hdesaktibatzeko kable egokia    ");
			iprintf("\x1b[11;2Hmoztuz. Zorte on!     ");
		}
		else if (EGOERA == EGOERA_JOLASTEN)
		{
			touchRead(&PANT_DAT);
			int px = PANT_DAT.px;
			int py = PANT_DAT.py;
			int kablea = get_kable(px, py);
			if (kablea != -1)
			{
				erakutsi_spritea(kablea);
				if(kablea == kable_ona) EGOERA = EGOERA_IRABAZITA;
				else EGOERA = EGOERA_GALDUTA;
			}
		}
		else if (EGOERA == EGOERA_GALDUTA)
		{
			iprintf("\x1b[5;0H     BOOOOOOMMMMM!!!       ");

			iprintf("\x1b[8;0H     Bonba lehertu egin da!");

			iprintf("\x1b[10;0H   Sakatu A kable berdinerako");
			iprintf("\x1b[11;0H  Sakatu B kable berri baterako");
		}
		else if (EGOERA == EGOERA_IRABAZITA)
		{
			iprintf("\x1b[5;0H           ZORIONAK!!!          ");

			iprintf("\x1b[8;0H     Bonba desaktibatu duzu!");

			iprintf("\x1b[10;0H   Sakatu A kable berdinerako");
			iprintf("\x1b[11;0H  Sakatu B kable berri baterako");

			ezabatu_lerroa(13);
		}
		else if (EGOERA == EGOERA_RESET_BERDIN)
		{
			reset();
		}
		else if (EGOERA == EGOERA_RESET_BERRI)
		{
			kable_ona = rand() % 5;
			reset();
		}
	}
}

void init()
{
	IME = 1;
	konfiguratuTeklatua(0x00004003);
	konfiguratuTenporizadorea(39322, 0x00000042);
	TekEtenBaimendu();
	DenbEtenBaimendu();
	etenZerbErrutEzarri();
}

void erakutsi_spritea(int kablea)
{
	ErakutsiSpritea(kablea, offseta[kablea], OFFSET_Y);
	piztuta[kablea] = 1;
}

void reset()
{
	ezabatu_pantaila();
	int i;
	for (i = 0; i < 5; i++)
	{
		EzabatuSpritea(i, offseta[i], OFFSET_Y);
		piztuta[i] = 0;
	}
	EGOERA = EGOERA_HASIERA;
}

int get_kable(int px, int py)
{
	if (py < Y_MAX && py > Y_MIN)
	{
		if (px > X_MIN && px < HORIA_MAX)
		{
			if (px < GORRIA_MAX)		return GORRIA;
			else if (px < BERDEA_MAX)	return BERDEA;
			else if (px < URDINA_MAX)	return URDINA;
			else if (px < MOREA_MAX)	return MOREA;
			else if (px < HORIA_MAX)	return HORIA;
		}
	}
	return -1;
}

char* kable_izena(int kablea)
{
	if (kablea == GORRIA)		return "GORRIA";
	else if (kablea == BERDEA)	return "BERDEA";
	else if (kablea == URDINA)	return "URDINA";
	else if (kablea == MOREA)	return "MOREA";
	else if (kablea == HORIA)	return "HORIA";
	else						return "ERROREA!";
}
