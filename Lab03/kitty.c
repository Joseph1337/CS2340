#include "kitty.h"
#include "myLib.h"

KITTY kitties[KITTYCOUNT];
int bitmap1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                         
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 1, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 5, 5, 5, 5, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 5, 5, 5, 5, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 4, 5, 5, 4, 4, 4, 4, 1, 0, 0,
                0, 5, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 5, 0,                         
                0, 0, 5, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 5, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0,                        
                0, 5, 0, 1, 4, 2, 4, 2, 2, 4, 2, 4, 1, 0, 5, 0,                        
                0, 0, 0, 0, 1, 4, 2, 4, 4, 2, 4, 1, 0, 0, 0, 0,                                               
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

int bitmap2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                         
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 1, 5, 4, 4, 1, 1, 1, 1, 4, 4, 5, 1, 0, 0,                        
                0, 0, 1, 5, 5, 4, 4, 4, 4, 4, 4, 5, 5, 1, 0, 0,                        
                0, 0, 1, 5, 5, 5, 4, 4, 4, 4, 5, 5, 5, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 0,
                0, 5, 1, 4, 3, 3, 4, 4, 4, 4, 3, 3, 4, 1, 5, 0,                         
                0, 0, 5, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 5, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 5, 4, 4, 4, 2, 4, 4, 2, 4, 4, 4, 5, 0, 0,                        
                0, 5, 0, 1, 4, 4, 4, 2, 2, 4, 4, 4, 1, 0, 5, 0,                        
                0, 0, 0, 0, 1, 4, 2, 4, 4, 2, 4, 1, 0, 0, 0, 0,                                               
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

int bitmap3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                         
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 1, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 5, 4, 4, 5, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 5, 4, 4, 5, 4, 4, 4, 1, 0, 0,                       
                0, 0, 1, 4, 4, 4, 5, 4, 4, 5, 4, 4, 4, 1, 0, 0,
                0, 5, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 5, 0,                         
                0, 0, 5, 4, 3, 3, 4, 4, 4, 4, 3, 3, 4, 5, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0,                        
                0, 5, 0, 1, 4, 4, 2, 2, 2, 2, 4, 4, 1, 0, 5, 0,                        
                0, 0, 0, 0, 1, 4, 4, 2, 2, 4, 4, 1, 0, 0, 0, 0,                                               
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

int bitmap4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                         
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 1, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 0,                       
                0, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 0,
                0, 5, 1, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 1, 5, 0,                         
                0, 0, 5, 4, 3, 2, 4, 4, 4, 4, 2, 3, 4, 5, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0,                        
                0, 5, 0, 1, 4, 4, 2, 4, 4, 2, 4, 4, 1, 0, 5, 0,                        
                0, 0, 0, 0, 1, 4, 4, 2, 2, 4, 4, 1, 0, 0, 0, 0,                                               
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

int bitmap5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                         
                0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 1, 4, 1, 0, 0, 0,                        
                0, 0, 1, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 1, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 1, 4, 5, 4, 4, 4, 4, 4, 4, 5, 4, 1, 0, 0,                       
                0, 0, 1, 4, 4, 5, 4, 4, 4, 4, 5, 4, 4, 1, 0, 0,
                0, 5, 1, 4, 3, 3, 5, 4, 4, 5, 3, 3, 4, 1, 5, 0,                         
                0, 0, 5, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 5, 0, 0,                        
                0, 0, 1, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 1, 0, 0,                        
                0, 0, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0,                        
                0, 5, 0, 1, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 5, 0,                        
                0, 0, 0, 0, 1, 4, 4, 2, 2, 4, 4, 1, 0, 0, 0, 0,                                               
                0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

// TODO 1.0: initialize kittyBitmaps so that it contains bitmap1 through bitmap5 defined above
int kittyBitmaps[] = {bitmap1, bitmap2, bitmap3, bitmap4, bitmap5};

void initializeKitties() {
    for (int i = 0; i < KITTYCOUNT; i++) {
        kitties[i].bitmap = kittyBitmaps[i];
        kitties[i].furColor = COLOR(((i + 6) * 4) % 31, ((i + 11) * 11) % 31, ((i + 2) * 2) % 31);

    }
}

void drawKitty(KITTY* kitty_ptr, int index) {
    int row = SCREENHEIGHT / 2 - 16;
    int col = 20 + (index * 45);
    for (int i = 0; i < KITTYLEN; i++) {
        for (int j = 0; j < KITTYLEN; j++) {
            // retrieve the value of the kittyBitmap at a given location
            int value = kitty_ptr->bitmap[OFFSET(i, j, KITTYLEN)];
            switch (value) {
                case(1):
                    setPixel(col + i, row + j, WHITE);
                    break;
                case(2):
                    setPixel(col + i, row + j, DARKGREY);
                    break;
                case(3):
                    setPixel(col + i, row + j, GREY);
                    break;
                case(4):
                    setPixel(col + i, row + j, kitties[index].furColor);
                    break;
                case(5):
                    setPixel(col + i, row + j, LIGHTGREY);
                    break;
                // TODO 2.0: complete the switch statement; refer to the lab PDF for case by case instructions
                default:
                    break;
            }
        }
    }

}