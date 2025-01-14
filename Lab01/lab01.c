// GBA Video Registers and Flags
#define REG_DISPCTL (*(volatile unsigned short *)0x4000000)
#define MODE3 3
#define BG2_ENABLE (1<<10)

// Create a color with the specified RGB values
#define COLOR(r, g, b) ((r) | (g)<<5 | (b)<<10)

// Calculate the position of a pixel based on its row and column
#define OFFSET(col, row, rowlen) ((row)*(rowlen)+(col))

// Predefined colors
#define RED COLOR(31, 0, 0)
#define GREEN COLOR(0, 31, 0)
#define BLUE COLOR(0, 0, 31)
#define MAGENTA COLOR(31, 0, 31)
#define CYAN COLOR(0, 31, 31)
#define YELLOW COLOR(31, 31, 0)
#define BLACK 0
#define WHITE COLOR(31, 31, 31)

// Function Prototypes
void setPixel(int, int, unsigned short);
void drawLetter(int, int);
void drawRect(int, int);

// Global Variables
volatile unsigned short *videoBuffer = (unsigned short *)0x6000000;

int main() {

    REG_DISPCTL = MODE3 | BG2_ENABLE;

    //TODO 1.1: Test your setPixel function
    //setPixel(0,0,YELLOW);
    
    //TODO 2.1: Call your drawRect function once
    drawRect(30, 15);

    //TODO 3.1: Call your drawLetter function twice
    drawLetter(60, 40);
    drawLetter(80, 60);
    while(1);
}


void setPixel(int col, int row, unsigned short color) {

    // TODO 1: Complete this function
    videoBuffer[OFFSET(col, row, 240)] = color;
}

void drawRect(int col, int row) {

    // TODO 2: Complete this function
    
    for(int i=0; i<25; i++) {
        setPixel(col + i, row, RED);
        setPixel(col + i, row + 16, RED);
    }
    for(int i=0; i<17; i++) {
        setPixel(col, row + i, RED);
        setPixel(col + 25, row + i, RED);
    }

}

void drawLetter(int col, int row) {

    // TODO 3: Complete this function

    //letter K
    for(int i=0; i<15; i++) {
        setPixel(col, row + i, YELLOW);
    }
    for(int i=0; i<8; i++) {
        setPixel(col + 1 + i, (row + 7) + i, YELLOW);
        setPixel(col + 1 + i, (row + 7) - i, YELLOW);
    }

}


