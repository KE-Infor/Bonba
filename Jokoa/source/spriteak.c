/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia
#include "spriteak.h"
#include "definizioak.h"

u16* gfx_sprite_gorria;
u16* gfx_sprite_berdea;
u16* gfx_sprite_urdina;
u16* gfx_sprite_morea;
u16* gfx_sprite_horia;


/* Pantailan erakutsi nahi den sprite bakoitzeko memoria erreserbatu.*/
void memoriaErreserbatu()
{
	gfx_sprite_gorria=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_sprite_berdea=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_sprite_urdina=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_sprite_morea=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx_sprite_horia=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}

void PaletaNagusiaEzarri() {
	SPRITE_PALETTE[1] = RGB15(0, 0, 0);
	SPRITE_PALETTE[2] = RGB15(1, 1, 0);
	SPRITE_PALETTE[3] = RGB15(1, 1, 8);
	SPRITE_PALETTE[4] = RGB15(1, 2, 13);
	SPRITE_PALETTE[5] = RGB15(1, 8, 1);
	SPRITE_PALETTE[6] = RGB15(1, 12, 2);
	SPRITE_PALETTE[7] = RGB15(2, 1, 0);
	SPRITE_PALETTE[8] = RGB15(2, 3, 18);
	SPRITE_PALETTE[9] = RGB15(3, 2, 0);
	SPRITE_PALETTE[10] = RGB15(3, 19, 5);
	SPRITE_PALETTE[11] = RGB15(4, 2, 0);
	SPRITE_PALETTE[12] = RGB15(4, 3, 0);
	SPRITE_PALETTE[13] = RGB15(4, 3, 1);
	SPRITE_PALETTE[14] = RGB15(5, 2, 0);
	SPRITE_PALETTE[15] = RGB15(5, 3, 0);
	SPRITE_PALETTE[16] = RGB15(5, 4, 2);
	SPRITE_PALETTE[17] = RGB15(6, 0, 9);
	SPRITE_PALETTE[18] = RGB15(6, 3, 0);
	SPRITE_PALETTE[19] = RGB15(6, 4, 0);
	SPRITE_PALETTE[20] = RGB15(6, 4, 1);
	SPRITE_PALETTE[21] = RGB15(6, 4, 2);
	SPRITE_PALETTE[22] = RGB15(6, 5, 3);
	SPRITE_PALETTE[23] = RGB15(7, 1, 0);
	SPRITE_PALETTE[24] = RGB15(7, 4, 0);
	SPRITE_PALETTE[25] = RGB15(7, 4, 1);
	SPRITE_PALETTE[26] = RGB15(7, 4, 2);
	SPRITE_PALETTE[27] = RGB15(7, 5, 1);
	SPRITE_PALETTE[28] = RGB15(7, 6, 4);
	SPRITE_PALETTE[29] = RGB15(8, 2, 0);
	SPRITE_PALETTE[30] = RGB15(8, 5, 1);
	SPRITE_PALETTE[31] = RGB15(8, 5, 2);
	SPRITE_PALETTE[32] = RGB15(9, 4, 1);
	SPRITE_PALETTE[33] = RGB15(9, 5, 1);
	SPRITE_PALETTE[34] = RGB15(9, 7, 4);
	SPRITE_PALETTE[35] = RGB15(10, 1, 0);
	SPRITE_PALETTE[36] = RGB15(10, 6, 1);
	SPRITE_PALETTE[37] = RGB15(10, 6, 2);
	SPRITE_PALETTE[38] = RGB15(10, 8, 5);
	SPRITE_PALETTE[39] = RGB15(11, 0, 17);
	SPRITE_PALETTE[40] = RGB15(11, 4, 1);
	SPRITE_PALETTE[41] = RGB15(11, 7, 1);
	SPRITE_PALETTE[42] = RGB15(12, 9, 5);
	SPRITE_PALETTE[43] = RGB15(13, 5, 1);
	SPRITE_PALETTE[44] = RGB15(13, 12, 2);
	SPRITE_PALETTE[45] = RGB15(14, 1, 0);
	SPRITE_PALETTE[46] = RGB15(14, 9, 1);
	SPRITE_PALETTE[47] = RGB15(15, 5, 1);
	SPRITE_PALETTE[48] = RGB15(15, 7, 23);
	SPRITE_PALETTE[49] = RGB15(15, 12, 11);
	SPRITE_PALETTE[50] = RGB15(17, 1, 0);
	SPRITE_PALETTE[51] = RGB15(17, 12, 3);
	SPRITE_PALETTE[52] = RGB15(19, 18, 17);
	SPRITE_PALETTE[53] = RGB15(21, 1, 0);
	SPRITE_PALETTE[54] = RGB15(24, 23, 6);
}

u8 sprite_gorria[1024] = 
{
	14,19,32,40,43,15,12,29,  14,19,32,40,32,11,14,23,  14,25,32,43,18, 9,29,23,  14,23,29,40,11,11,23,35,  15,15,32,35, 9,15,29,35,  15,23,32,25,12,29,35,35,  15,29,35,19,12,23,35,45,  15,29,40,15,12,29,35,45,
	23,35,35,45,45,35,29, 1,  35,35,45,45,29,15,12, 1,  35,45,45,29,14,18,14, 1,  35,45,45,14,15,47, 1,51,  45,50,35,14,40,47, 1,50,  45,50,11,15,47,14, 1,52,  50,50,12,19,23, 7,52,54,  50,45,12, 9, 1,54,54,51,
	51,45,23, 1,53,50,53,50,  50,35, 1, 2,50,53,53,53,  50,23, 1,15,15,50,53,53,  45,23, 1,40,15,32,53,53,  23, 1,14,47,24,18,50,53,  51, 2,43,47,32,15,45,50,  51, 1,11,43,32,15,32,50,  43,41, 1, 1,11,11,29,45,
	50,29,11,29,43,40,43,43,  50,50, 9,14,43,43,45,32,  53,53,29,12,35,47,47,18,  53,53,45,11,29,47,47,14,  53,53,53, 9,18,47,45,12,  53,53,53,12,11,47,40,15,  53,53,53,32,19,47,32,15,  50,53,53,45,15,47,25,15,
	23,29,35,12,12,23,35,45,  14,29,40, 9,15,35,35,50,  23,29,40,12,15,23,45,45,  18,29,40, 9,14,35,45,50,  29,29,40,11,14,35,35,50,  15,35,35, 9,14,35,45,50,  15,29,40, 9,14,35,45,50,  23,32,35,11,14,35,45,50,
	50,45, 2, 1,54,47, 2,47,  50,45, 1,51,51, 1, 1,51,  53,35, 2,51, 1, 1,51,51,  23, 1, 1,46, 1, 1,41,40,   1,51,51,32, 1, 1,24, 1,   1,46, 1, 1,14,11, 1, 9,  23, 1, 7,32,43,40,33,30,  53,45,15,40,43,40,32,30,
	33,25,41,51, 1, 2,14,45,  36, 1, 1,41,46, 1, 2,35,  36, 1,11, 1,32,33, 1,35,  24,15, 1,14, 1,30, 1, 9,   1,15, 1,14, 1,30,18, 1,   1,15,19, 1, 1,19, 1, 9,   9, 1, 1,14,14, 1, 2,35,  30,33,40,43,47,15,15,35,
	50,53,53,45,15,43,15,15,  45,53,53,45,11,40,11,14,  45,50,53,45,11,35,11,15,  45,50,53,45,15,43,15,19,  45,50,53,45,15,43,15,19,  45,50,53,45,15,43,14,18,  45,50,53,45,14,43,14,18,  45,50,53,45,15,43,14,18,
	15,29,43, 9,11,35,45,50,  15,29,35,15,12,35,45,50,  23,29,40,15,11,29,45,50,  15,29,40,29,14,29,45,50,  14,29,40,29,12,29,45,50,  14,29,32,40,14,15,35,50,  14,15,32,43,15,15,35,45,  14,15,29,40,19,15,29,45,
	53,45,15,32,43,43,36,30,  53,50,12,32,43,43,40,33,  53,50,15,25,47,43,40,40,  53,53,15,15,47,47,43,40,  53,53,32,15,40,47,47,43,  53,53,50,15,25,47,47,47,  53,23, 1, 1, 2,32,47,47,  50, 1,54,51, 1, 2,15,15,
	30,32,40,43,43,15,15,35,  33,36,40,43,43,15,15,35,  11, 1,14,47,40,12,29,35,   1,54, 1,15,25,11,29, 9,   1,51,51, 1,15,14, 9, 1,   1,46,32, 1,15,15, 1,54,  29, 1,30, 1, 7,29, 1,51,  15, 1,46,46, 1, 9, 1,46,
	35,50,53,45,15,43,15,15,  45,50,53,35,15,47,15,15,  45,50,53,19,15,47,19,15,   1,23,50,15,15,53,32,15,  51, 1,50,15,25,47,40,15,  47, 1,45,12,40,47,47,12,   1,23,18,15,47,47,47,15,   1,45,19,30,47,47,47,30,
	14,15,29,40,40,15,15,45,  14,14,19,32,43,19,15,29,  11,14,19,32,40,40,15,12,  11,14,18,30,40,40,40,15,  11,11,15,30,30,40,40,40,  11, 9,15,25,30,32,40,40,   9, 9,15,25,30,30,30,40,  11, 9,15,25,30,30,30,30,
	50, 1,46,47,46, 1, 1, 1,  50,23, 1, 1,25,46,51,54,  35,50,53,23, 1, 1, 1,43,  15,29,50,53,53,53,23, 1,  15,15,15,35,50,53,53,53,  43,19,15,12,12,12,14, 9,  40,40,40,32,19,12,12,12,  30,40,40,43,40,43,43,43,
	 2, 2, 1,51, 1, 1,54,47,   1, 1, 1,54,54, 1,51, 1,  51,51,54,54,51,46,43,30,   1, 2,43,45,32,19, 1,19,  53, 2, 1,15,15, 1, 1, 1,  12, 1,52,50,23, 1,32,40,   2, 1,51,45,23, 1,40,40,   1,49,50,23, 1,11,32,40,
	 1,25,19,43,46,47,46,43,  11,18,30,47,43,46,47,47,   1, 1, 1,11,40,32,36,43,  30,36,36, 1,32,32,32,40,   1, 1, 1,11,36,36,33,32,  40,41,37,36,36,36,36,36,  37,40,37,36,36,36,36,36,  36,37,36,33,30,30,33,36
};

u8 sprite_berdea[1024] = 
{
	50,50,29,11,29,43,40,43,  53,50,50, 9,14,43,43,45,  53,53,53,29,12,35,47,47,  53,53,53,45,11,29,47,47,  53,53,53,53, 9,18,47,45,  50,53,53,53,12,11,47,40,  50,53,53,53,32,19,47,32,  45,50,53,53,45,15,47,25,
	43,15, 9, 1, 6, 6, 5, 1,  32,11,14, 9, 1, 6, 5, 5,  19, 9,23,23, 1, 6, 5, 5,  14,11,23,35,14, 1,10, 5,  12,15,23,35, 1,10,10, 6,  15,29,35,14, 1, 2,52,51,  15,29,35, 1, 7,52,54,51,  15,35, 9, 1,54,54,51,43,
	23,35,29,15,15,15,45,50,   1,18,15,15,15,15,15,15,   1,24,47,47,47,47,40,15,   1,45,47,47,47,47,47,29,   1,47,43,35,40,40,45,47,   2,43,43,43,40,43,43,47,   1,15,37,36,36,40,43,43,  41, 1, 1, 9,30,32,40,43,
	53,50,53,50,50,29,15,25,  50,53,53,53,53,45,15,19,  15,50,53,53,53,53,32,15,  11,29,53,53,53,53,45, 9,  14,11,50,53,53,53,53, 9,  29,11,35,53,53,53,53,11,  32,11,29,50,53,53,53,29,  40,11,29,45,50,53,53,45,
	45,50,53,53,45,15,43,15,  35,45,53,53,45,11,40,11,  35,45,50,53,45,11,35,11,  35,45,50,53,45,15,43, 7,  35,45,50,53,45,15,43, 1,  35,45,50,53,45,15,43, 1,  35,45,50,53,45,14,43, 2,  35,35,50,53,45,15,43,14,
	15, 9, 1,54,47, 2,47,33,  14, 1,51,51, 1, 1,51,36,  15, 2,51, 1, 1,51,51,36,   1, 1,46, 1, 1,41,40,24,  51,51,32, 1, 1,24, 1, 1,  46, 1, 1,23,23, 1, 2, 1,   1,14,45,50,53,45,15,11,  18,45,45,50,53,45,15,32,
	25,46,51, 1, 9,33,40,43,   1, 1,41,46, 1, 9,40,43,   1,11, 1,32,33, 1,32,43,  15, 1, 9, 1,30, 1,11,40,  15, 1, 9, 1,30,18, 1,43,  15,19, 1, 1,19, 1,11,43,   1, 1, 9, 9, 1, 9,40,43,  43,40,32,30,30,33,40,40,
	43,11,15,45,50,53,53,45,  47, 9,11,35,45,53,53,45,  43,12,11,35,45,50,53,45,  47,15,15,35,45,50,53,45,  43,15,15,35,45,50,53,50,  47,15,15,35,45,50,53,45,  43,12, 9,35,45,50,53,45,  47,15,12,35,35,50,53,45,
	35,45,50,53,45,15,43,15,  35,45,50,53,35,15,47,15,  35,45,50,53,19,15,47,19,  35,45,50,50,15,15,53,32,  35,45,50,50,15,25,47,40,  35,50,50,45,15,40,47,47,  45,23, 1, 1, 2,47,47,47,  45, 1,54,51, 1,19,47,47,
	15,45,45,50,53,45,15,32,  15,45,45,50,53,50,15,32,   2, 1,23,50,53,50,15,25,   1,54, 1,23,53,53,15, 7,   1,51,51, 1,53,53, 9, 1,   1,46,32, 1,53,53, 1,54,   7, 1,30, 1,23,53, 1,51,  30, 1,46,46, 1,23, 1,46,
	43,43,36,33,33,32,40,43,  43,43,40,32,33,36,40,43,  47,43,40,40,40,40,43,43,   1,15,43,40,40,43,43,47,  51, 2,47,43,43,43,47,47,  47, 1,47,47,47,47,47,29,   1, 9,47,47,47,43,29,15,   1,15,12,15,15,14,12,12,
	43,12,15,35,45,50,53,45,  43,14,15,35,45,50,53,35,  40,12,23,35,45,50,53,18,  19,11,29,35,45,50,50,11,  14,12,23,35,45,50,50,11,  12,15,35,35,50,50,45, 9,  15,23,35,45,50,50,15,11,  29,29,35,45,50,45,11,15,
	50, 1,46,46,46, 1, 1, 1,  50, 9, 1, 1,25,46,51,54,  40,19,19,14, 1, 1, 1,43,  15,15,40,40,40,32, 9, 1,  18,40,40,40,37,36,36,36,  40,43,41,37,36,36,36,36,  40,37,36,37,36,36,36,36,  40,37,36,36,33,30,30,33,
	15, 7, 1,51, 2, 1,54,47,   1, 1, 1,54,54, 1,51, 1,  51,51,54,54,51,46,46,33,   1, 2,43,45,32,19, 1,19,  32, 1, 1,15,15, 1, 1, 1,  36, 1,10, 6, 5, 1,15,15,  36, 1,10, 6, 1,14,43,32,  36, 1,10,10, 6, 1,11,43,
	 1,35,15,12,12,12,29,23,  23,50,50,45,35,35,23,35,   1, 1, 1,23,45,45,35,45,  30,36,36, 1,50,45,50,45,   1, 1, 1,23,53,50,50,45,  15,12,12,12,11,15,20,15,  19,15,12,12,15,15,24,32,  43,43,43,43,47,47,43,43,
	29,35,45,45,50,25,11,32,  35,45,45,50,32,15,15,40,  45,45,50,40,15,19,40,32,  50,45,29,15,18,43,32,32,  32,11,15,24,43,43,32,29,  15,15,32,43,43,36,25,25,  32,40,40,43,41,40,25,24,  32,32,40,40,36,33,19,19
};

u8 sprite_urdina[1024] = 
{
	15,15,15,45,50,53,50,53,  15,15,15,15,15,50,53,53,  47,47,47,40,15,15,50,53,  47,47,47,47,29,11,29,53,  40,35,43,45,47,14,11,50,  43,40,40,43,47,29,11,35,  36,36,40,43,43,32,11,29,  30,32,33,40,43,40,11,29,
	50,50,29,15,25, 1, 8, 3,  53,53,45,15,19, 1, 8, 4,  53,53,53,32,15, 1, 8, 4,  53,53,53,45, 9, 1, 4, 3,  53,53,53,53, 9, 7, 1, 3,  53,53,53,53,11, 7, 1,54,  50,53,53,53, 9, 2,52,54,  45,50,53,35, 1,54,54,51,
	 1,30,30,25,25,25,25,25,   1, 9,30,32,32,32,30,25,   3, 1,33,32,32,32,32,32,   3, 1,32,15,11,11,11,15,   3, 1,12,11,12,11,11,11,  51, 2,12,29,23,23,23,15,  51, 1, 7,23,23,35,35,35,  43,41, 1, 1, 9,35,35,35,
	25,25,25,40,43,43,19, 9,  25,32,25,40,43,40,15,15,  32,32,32,40,43,24,15,29,  32,40,40,40,43,15,15,29,  12,40,40,45,32,15,18,23,  11,15,43,43,29,11,29,35,  11,12,45,47,29, 9,23,35,  14,11,43,47,15, 9,23,35,
	30,30,32,40,43,43,11,15,  30,30,33,40,43,47, 9,11,  30,30,33,32,43,43,12,11,  30,30,30,40,40,47,15,15,  30,30,33,40,43,43,15,15,  30,30,33,36,43,47,15,15,  30,30,33,40,43,43,12,14,  33,30,33,40,40,47,15,14,
	45,50,23, 1,54,47, 2,47,  35,50, 1,51,51, 1, 1,51,  35,45, 2,51, 1, 1,51,51,   9, 1, 1,46, 1, 1,41,40,   1,51,51,32, 1, 1,24, 1,   1,46, 1, 1,23, 2, 1,14,   9, 1,23,53,45,12,32,43,  35,45,50,53,45,12,32,43,
	32,25,41,51, 1,23,45,50,  36, 1, 1,41,46, 1,23,50,  36, 1, 2, 1,32,30, 1,35,  24,15, 1, 2, 1,30, 1, 2,   1,15, 1, 7, 1,30,18, 1,   1,15,19, 1, 1,19, 1,11,  14, 1, 1, 9, 9, 1, 9,32,  40,32,30,30,32,30,30,30,
	14,15,47,47,14,11,23,35,  14,12,47,47,14,15,35,35,  14,15,47,43,12,14,35,45,  12,43,47,43,14,15,35,35,  40,43,43,43,14,15,35,45,  40,43,43,43,11,14,35,45,  32,40,43,43,14,14,35,45,  32,40,43,40,11,14,35,45,
	33,33,32,40,43,43,12,15,  32,33,36,40,43,43,14,15,  40,40,40,43,43,40,12,23,  40,40,43,43,47,19,11,29,  43,43,43,47,47,14,12,23,  47,47,47,47,29,12,15,35,  47,47,43,29,15,15,23, 9,  15,15,14,12,12,29,35, 1,
	35,35,50,53,45,12,32,43,  35,45,50,53,35,11,40,43,  35,45,50,53,18,11,14, 1,  35,45,50,50,11,15, 1,54,  35,45,50,50,11,19, 1,51,  35,50,50,45,11,32, 1,46,   1, 1,23,15, 9,43,14, 1,  54,51, 1, 2,15,43,40, 1,
	40,32,30,30,30,30,30,30,  40,30,30,30,30,27,30,30,   9,32,30,30,30,30,30,25,   1, 9,30,32,32, 9, 1, 9,  51, 1,32,32, 9, 1,51, 2,  32, 1,32,14, 1,54,47, 1,  30, 1, 2, 9, 1,51, 1, 2,  46,46, 1, 7, 1,46, 1,15,
	30,32,40,43,11,11,35,45,  32,32,40,43,14,11,35,45,  30,40,40,43,15,11,23,45,  32,32,40,43,29, 9,29,45,  32,40,40,43,29,11,23,35,  32,40,40,43,40, 9,15,45,  11,40,40,43,43,14,11,35,   9,14,43,35,43,29,12,29,
	12,12,12,29,23,29,35, 1,  45,35,35,23,35,35,45,14,  45,45,45,35,45,45,45,50,  50,50,45,50,45,50,45,29,  53,53,50,50,45,32,11,15,  12, 9,15,20,15,15,15,32,  12,15,18,24,32,32,40,40,  43,47,47,43,43,32,32,40,
	47,46,46, 1, 1, 1,14,14,   1, 1,30,46,51,54, 1, 1,  40, 7, 1, 1, 1,43,51,51,  15,18,43,32, 9, 1, 1, 1,  24,43,43,32,29,30, 9, 1,  43,43,36,25,25,30,30, 9,  43,41,40,25,24,25,30, 1,  40,36,33,19,19,25,25, 1,
	 1,51, 1, 1,54,47, 1,35,   1,54,54, 1,51, 2, 9,35,  54,54,51,46,41,32, 1, 1,  43,45,32,29, 1,24,30,36,   1,15,15, 1, 9, 1, 1, 1,   1, 8, 4, 1, 9, 9, 9, 9,  48, 8, 3, 1, 9, 9, 9,14,   8, 4, 3, 1,32,32,32,32,
	11,11,40,43,40,40, 9,15,  14, 9,40,40,40,43,19,15,   1, 2,32,40,40,40,43,18,  36, 1,40,32,32,40,43,43,   1, 7,32,32,36,40,41,43,  11,32,32,30,36,36,40,40,  25,32,30,30,36,36,36,33,  32,25,25,30,33,36,33,30
};
u8 sprite_morea[1024] = 
{
	25,25,25,25,25,25,40,43,  32,32,25,25,32,25,40,43,  32,32,32,32,32,32,40,43,  11,11,15,32,40,40,40,43,  11,12,11,12,40,40,45,32,  23,23,15,11,15,43,43,29,  35,35,35,11,12,45,47,29,  35,35,35,14,11,43,47,15,
	43,19, 9,14,23,35,35,45,  40,15,15,23,35,35,45,45,  24,15,29,23,35,45,45,29,  15,15,23,35,35,45,45, 9,  15,18,29,35,45,50,35, 2,  11,29,35,35,45,50,11, 1,   9,23,35,45,50,50, 7, 7,   9,23,35,45,50,14, 1,54,
	 1,39,17, 1, 9, 9,35,50,   1,39,17, 1, 9,11,11, 9,   1,39,17, 1,47,43,32, 9,   1,39,17, 1,47,47,47,32,   1,39,17, 1,43,43,47,47,   1,52,51, 2,40,43,47,47,  52,54,51, 1,11,41,43,47,  54,51,43,41, 1, 1,14,43,
	50,53,50,50,50,29,15,32,  50,53,53,53,53,45,15,18,   9,50,53,53,53,53,32,15,   9,35,53,53,53,53,45, 9,  18, 9,50,53,53,53,53, 9,  32, 9,35,50,53,53,53,15,  40, 9,35,50,53,53,53,32,  32, 9,29,45,50,53,53,45,
	45,45,50,15,12,47,47,14,  45,50,50,11,14,47,47,14,  45,50,35,14,18,47,43,12,  14,14,12,15,43,47,43,14,  12,12,15,40,43,43,43,14,  40,40,40,40,43,43,43,11,  33,33,32,32,40,43,43,14,  30,30,33,32,40,43,40,11,
	11,23,35,45,23, 1,54,47,  15,35,35,45, 1,51,51, 1,  14,35,45,50, 2,51, 1, 1,  15,35, 9, 1, 1,46, 1, 1,  14,35, 1,51,51,32, 1, 1,  15,35, 1,46, 1, 1, 2,11,  14,35,23, 1,23,45,11,32,  14,35,45,50,53,45,11,32,
	 2,47,36,25,46,51, 1,14,   1,51,40, 1, 1,41,46, 1,  51,51,36, 1, 9, 1,32,30,  41,40,24,15, 1, 9, 1,30,  24, 1, 1,15, 1, 9, 1,30,   1,11, 1,15,19, 1, 1,19,  43,40, 9, 1, 1, 9, 9, 1,  43,32,32,30,25,30,40,40,
	40,11,15,45,50,53,53,45,  23,12,12,35,45,53,53,45,   1,15,15,35,45,50,53,45,   1, 2,12,35,45,50,53,45,  18, 1,11,35,45,50,53,45,   1, 2,11,35,45,50,53,45,  14,11,11,23,45,50,53,45,  43,11,11,35,45,50,53,45,
	30,30,30,32,32,40,43,11,  30,30,30,30,32,40,43,14,  30,30,25,32,40,40,43,15,  32,30,32,32,32,40,43,29,  32,32,32,32,40,40,43,29,  11,11,15,32,40,40,43,40,   9, 9, 9,14,32,14, 1, 1,  23,23,15, 9,15, 1,54,51,
	11,35,45,50,53,45,11,29,  11,35,45,50,53,45,14,29,  11,23,45,50,23, 1, 2,18,  11,23,45,50, 1,54, 1, 2,   9,29,35,50, 1,51,51, 1,  11,14,45,45, 1,51,32, 1,   2,11,35,50,23, 1,30, 1,   1, 2,23,45,50, 1,46,46,
	43,40,32,30,30,32,32,43,  43,40,32,30,30,32,40,43,  47,43,40,32,32,32,40,45,  47,43,40, 9, 1,11,43,47,  35,47,14, 1,51, 1,47,45,  19,47, 1,54,47, 1,47,29,   2,29, 1,51, 1,14,29, 9,   1, 7, 1,46, 1, 9, 9, 9,
	43,14,14,35,35,50,53,45,  40,11,14,35,45,50,53,35,  32,11,23,23,45,50,53,15,  19,11,23,35,45,50,50, 9,  14,11,23,35,45,50,50,11,  11,15,35,35,50,50,35,11,  11,23,35,35,50,50,15, 9,  23,23,35,45,50,45,11,18,
	35,35,35,11,11, 1,47,46,  35,35,35,14, 9,11, 1, 1,  45,50,45,14,11,32,40,14,  45,50,50,11,11,40,40,32,  45,50,35, 9,15,32,32,36,   9, 9, 9,11,32,32,30,36,   9, 9,14,29,32,30,30,36,  32,32,32,32,30,25,30,33,
	46, 1, 1, 1,23,23, 1,51,  30,46,51,54, 1, 1, 1,54,   1, 1, 1,43,51,51,54,54,  40,43,14, 1, 1, 2,43,45,  40,41,43,40,14, 2, 1,15,  36,40,40,40,40,15, 1,39,  36,36,36,29,32,40, 1,39,  33,33,25,25,32,36, 1,39,
	 1, 1,54,46, 1,15,29,23,  54, 1,51, 2, 9,35,29,35,  51,46,43,32, 1, 1, 1, 9,  32,24, 1,24,30,36,36, 1,  15, 1, 1, 1, 1, 1, 1,14,  17, 1, 2,12,12, 9, 9, 9,  17, 1,12,12,12,12,15,29,  17, 1,43,43,43,43,43,40,
	23,35,45,45,50,14, 9,35,  35,35,45,50,23,11,15,43,  45,45,50,35,11,14,40,40,  50,45,23, 9,11,32,32,32,  29, 9, 9,15,40,32,32,32,   9,14,29,40,32,32,29,25,  32,40,40,32,32,25,25,25,  40,40,32,32,25,25,25,25
};

u8 sprite_horia[1024] = 
{
	32,47,47,47,24,15,29,29,  18,47,47,43,15,15,29,35,  15,47,47,25,15,29,35,35,   9,32,50,11,11,23,35,35,   9,14,47,11,14,23,35,45,  15,12,40,14,29,35,35,45,  32,12,32,12,35,35,45,50,  45,14,18,12,35,35,45,50,
	35,35,45,45,45, 9, 1, 1,  35,45,45,32,15, 1,54,54,  45,45,32,15,25, 2,54,51,  45,45,15,15,14, 2,54,44,  50,40,15,35, 1,54,54,44,  50,15,15,14, 1,52,54, 1,  50,15, 9, 7,52,54,51, 1,  45, 7, 1,54,54,51,43,40,
	54,54,44, 1, 1,23,50,50,  54,44, 1,23,53,53,53,50,  31, 1, 2,11,50,53,53,53,   1,18,32,12,35,53,53,53,   1,47,47,15,12,50,53,53,   1,43,47,29,12,35,50,53,   2,43,43,40,11,35,50,53,   1, 1,14,40,11,29,45,50,
	29, 9,19,43,40,36,36,25,  50, 9,14,43,43,40,36,30,  53,29,11,32,43,43,36,33,  53,45,11,29,43,40,36,36,  53,53, 9,14,43,43,36,36,  53,53,12,11,40,40,40,36,  53,53,29,11,35,40,32,36,  53,53,45,14,32,40,32,25,
	45,12,15,11,35,45,45,50,  45,12,11,15,45,45,50,50,  45,11,11,15,45,45,50,53,  45,12,11,23,45,45,23, 1,  45,15,11,18,45,50, 1,51,  45,12,11,29,45,50, 1,46,  45,11,11,23,45,50,23, 1,  45,11,11,15,50,50,50,53,
	23, 1,54,47, 2,47,32,27,   1,51,51, 1, 1,51,36, 1,   2,51, 1, 1,51,51,36, 1,   1,46, 1, 1,41,40,24,15,  51,32, 1, 1,24, 1, 1,15,   1, 1,14,14, 1, 9, 1,15,  14,14,32,43,40,32, 9, 1,  45,14,32,43,40,33,30,30,
	46,51, 1,14,14,15,45,50,   1,41,46, 1, 2,12,35,45,   9, 1,32,33, 1,14,35,45,   1,11, 1,30, 1, 2,35,45,   1,11, 1,30,18, 1,35,45,  19, 1, 1,19, 1, 2,35,45,   1,11,14, 1, 2,12,35,45,  33,40,43,47,12,11,35,35,
	53,53,45,12,32,40,32,29,  53,53,45,12,32,43,32,30,  50,53,45,12,29,43,40,30,  50,53,45,11,32,43,40,30,  50,53,45,15,32,40,32,30,  50,53,45,11,29,43,32,32,  50,53,45,12,32,43,40,30,  50,53,45,15,29,40,32,30,
	45,11,11,11,45,50,50,53,  35,11,14,11,45,50,50,53,  15,11,18,11,45,50,50,53,  11,15,29,11,35,50,50,53,  11,29,35,11,35,45,50,53,   9,40,47, 9,23,45,50,53,  11,45,47,11, 2, 1, 1,23,  15,47,47,29, 1,54,51, 1,
	45,12,32,43,40,32,30,30,  50,11,29,43,43,36,32,30,  50,12,29,14, 1,11,40,36,  53,11,12, 1,54, 1,11,40,  53,29,11, 1,51,51, 1,43,  53,50, 9, 1,46,32, 1,47,  53,53,29, 2, 1,30, 1,23,  35,53,50,14, 1,46,46, 1,
	33,40,43,43,15,15,35,45,  32,40,43,43,15,15,35,45,  40,43,43,40,12,23,35,45,  43,43,15, 1, 2,29,35,45,  43,14, 1,51, 2,23,35,45,  47, 1,54,47, 1,35,35,50,  43, 1,51, 1, 7,35,45,50,   2, 1,46, 1,23,35,45,50,
	50,53,45,12,32,43,32,32,  50,53,35,12,40,40,40,30,  50,53,19,11,43,40,32,30,  50,50,11,15,43,40,32,30,  50,50,15,19,43,40,32,30,  50,45,12,32,40,32,30,25,  50,18,11,43,40,32,30,30,  45,15,18,43,40,32,30,30,
	40,45,43,40, 1,46,47,46,  40,40,40,43, 7, 1, 1,25,  40,40,40,40,43,15, 7, 1,  32,32,32,40,43,43,12,14,  32,25,30,36,40,43,32,15,  25,25,33,36,36,40,32,40,  25,30,33,36,33,25,29,40,  25,33,33,33,25,19,25,32,
	 1, 1, 1,23,14, 1,51, 2,  46,51,54, 1, 1, 1,54,54,   1, 1,43,51,51,54,54,51,  29,23, 1, 1, 2,43,45,32,  15,15,35,45, 7, 1,15,15,  25,15,15, 9, 1,54,54,44,  43,43,40, 2, 2,54,51, 1,  40,40,43, 1,54,54,44, 1,
	 1,54,47, 1,35,45,45,50,   1,51, 1, 9,45,45,50,29,  46,46,32, 1, 1, 1, 9,15,  19, 1,19,30,36,36, 1,15,   1,23, 1, 1, 1, 1, 7,40,   1,12,15,15,18,32,43,40,   2,15,25,40,43,40,40,40,  43,43,43,40,40,40,36,30,
	18,15,40,40,32,33,30,26,  15,19,40,40,33,30,30,36,  15,43,40,33,30,30,36,36,  40,40,32,30,30,36,36,36,  40,32,33,33,33,36,36,33,  40,32,30,30,36,36,36,36,  33,30,30,30,36,36,36,30,  30,30,27,33,36,36,33,27
};




/* Irudikatutako Spriteak memorian kargatzen ditu. SPRITE bat baino gehiago erakusteko
for bana egin behar da.*/

void SpriteakMemorianGorde(){ 
	
int i;
	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfx_sprite_gorria[i] = sprite_gorria[i*2] | (sprite_gorria[(i*2)+1]<<8);
	}

	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfx_sprite_berdea[i] = sprite_berdea[i*2] | (sprite_berdea[(i*2)+1]<<8);
	}

	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfx_sprite_urdina[i] = sprite_urdina[i*2] | (sprite_urdina[(i*2)+1]<<8);
	}

	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfx_sprite_morea[i] = sprite_morea[i*2] | (sprite_morea[(i*2)+1]<<8);
	}

	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfx_sprite_horia[i] = sprite_horia[i*2] | (sprite_horia[(i*2)+1]<<8);
	}
}

void ErakutsiSpritea(int indizea, int x, int y)
{
	u16* sprite;
	if(indizea == GORRIA) sprite = gfx_sprite_gorria;
	else if(indizea == BERDEA) sprite = gfx_sprite_berdea;
	else if(indizea == URDINA) sprite = gfx_sprite_urdina;
	else if(indizea == MOREA) sprite = gfx_sprite_morea;
	else if(indizea == HORIA) sprite = gfx_sprite_horia;
	else return;

	oamSet(&oamMain, indizea, x, y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, sprite, -1, false, false, false, false, false);
	oamUpdate(&oamMain);  
}

void EzabatuSpritea(int indizea, int x, int y)
{
	u16* sprite;
	if(indizea == GORRIA) sprite = gfx_sprite_gorria;
	else if(indizea == BERDEA) sprite = gfx_sprite_berdea;
	else if(indizea == URDINA) sprite = gfx_sprite_urdina;
	else if(indizea == MOREA) sprite = gfx_sprite_morea;
	else if(indizea == HORIA) sprite = gfx_sprite_horia;
	else return;

	oamSet(&oamMain, indizea, x, y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, sprite, -1, false, true, false, false, false); 
	oamUpdate(&oamMain); 
}