/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "spriteak.h"

#define OFFSET_Y 80
#define OFFSET_X_GORRIA 65
#define OFFSET_X_BERDEA 88
#define OFFSET_X_URDINA 107
#define OFFSET_X_MOREA 128
#define OFFSET_X_HORIA 159

#define X_MIN 71
#define GORRIA_MAX 92
#define BERDEA_MAX 109
#define URDINA_MAX 133
#define MOREA_MAX 163
#define HORIA_MAX 187

#define Y_MIN 49
#define Y_MAX 143

int get_kable(int px, int py);
char* kable_izena(int kablea);
void reset();

int offseta[10] =
{
	OFFSET_X_GORRIA,
	OFFSET_X_BERDEA,
	OFFSET_X_URDINA,
	OFFSET_X_MOREA,
	OFFSET_X_HORIA,
};

void jokoa01()
{
	IME = 1;
	konfiguratuTeklatua(0x00004001);
	konfiguratuTenporizadorea(39322,0x00000042);
	TekEtenBaimendu();
	DenbEtenBaimendu();
	etenZerbErrutEzarri();

	srand(time(NULL));

	erakutsiFondoa();

	int kable_ona = rand() % 5; // 0-4 tarteko zenbaki bat
	iprintf("\x1b[5;2HKable ona: %s", kable_izena(kable_ona));
	while(1)
	{
		touchRead(&PANT_DAT);
		int px = PANT_DAT.px;
		int py = PANT_DAT.py;
		int kablea = get_kable(px, py);
		if(kablea != -1)
		{
			iprintf("\x1b[7;2HKlikatutako kablea: %s      ", kable_izena(kablea));
			
			ErakutsiSpritea(kablea, offseta[kablea], OFFSET_Y);
		}
		else
		{
			iprintf("\x1b[7;2H                                ");
		}
	}
}

void reset()
{
	int i;
	for(i = 0; i<5; i++) EzabatuSpritea(i, offseta[i], OFFSET_Y);
}

int get_kable(int px, int py)
{
	if(py < Y_MAX && py > Y_MIN)
	{
		if(px > X_MIN && px < HORIA_MAX)
		{
			if(px < GORRIA_MAX) return GORRIA;
			else if(px < BERDEA_MAX) return BERDEA;
			else if(px < URDINA_MAX) return URDINA;
			else if(px < MOREA_MAX) return MOREA;
			else if(px < HORIA_MAX) return HORIA;
		}
	}
	return -1;
}

char* kable_izena(int kablea)
{
	if(kablea == GORRIA) return "GORRIA";
	else if(kablea == BERDEA) return "BERDEA";
	else if(kablea == URDINA) return "URDINA";
	else if(kablea == MOREA) return "MOREA";
	else if(kablea == HORIA) return "HORIA";
	else return "ERROREA!";
}
