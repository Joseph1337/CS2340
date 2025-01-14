# 1 "kitty.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "kitty.c"
# 1 "kitty.h" 1




typedef struct {
 int* bitmap;
 unsigned short furColor;
} KITTY;

extern KITTY kitties[5];
extern int kittyBitmaps[5];


void initializeKitties();
void drawKitty(KITTY* kitty_ptr, int index);
# 2 "kitty.c" 2
# 1 "myLib.h" 1




typedef unsigned short u16;
# 25 "myLib.h"
extern volatile unsigned short *videoBuffer;
# 42 "myLib.h"
void setPixel(int col, int row, unsigned short color);
void drawRect(int col, int row, int width, int height, unsigned short color);
void fillScreen(unsigned short color);


void waitForVBlank();
# 67 "myLib.h"
extern unsigned short oldButtons;
extern unsigned short buttons;
# 77 "myLib.h"
int collision(int colA, int rowA, int widthA, int heightA, int colB, int rowB, int widthB, int heightB);
# 3 "kitty.c" 2

KITTY kitties[5];
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


int kittyBitmaps[] = {bitmap1, bitmap2, bitmap3, bitmap4, bitmap5};

void initializeKitties() {
    for (int i = 0; i < 5; i++) {
        kitties[i].bitmap = kittyBitmaps[i];
        kitties[i].furColor = ((((i + 6) * 4) % 31) | (((i + 11) * 11) % 31)<<5 | (((i + 2) * 2) % 31)<<10);

    }
}

void drawKitty(KITTY* kitty_ptr, int index) {
    int row = 160 / 2 - 16;
    int col = 20 + (index * 45);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {

            int value = kitty_ptr->bitmap[((j)*(16)+(i))];
            switch (value) {
                case(1):
                    setPixel(col + i, row + j, ((31) | (31)<<5 | (31)<<10));
                    break;
                case(2):
                    setPixel(col + i, row + j, ((5) | (5)<<5 | (5)<<10));
                    break;
                case(3):
                    setPixel(col + i, row + j, ((15) | (15)<<5 | (15)<<10));
                    break;
                case(4):
                    setPixel(col + i, row + j, kitties[index].furColor);
                    break;
                case(5):
                    setPixel(col + i, row + j, ((25) | (25)<<5 | (25)<<10));
                    break;

                default:
                    break;
            }
        }
    }

}
