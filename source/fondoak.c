/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fondoak.h"
#include "grafikoak.h"
#include "fondoa.h"
static const int DMA_CHANNEL = 3;


void erakutsiFondoa() {
	dmaCopyHalfWords(DMA_CHANNEL, fondoaBitmap, (uint16 *)BG_BMP_RAM(0), fondoaBitmapLen);
}
