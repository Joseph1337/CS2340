#include "myLib.h"
#include "treeswithStars.h"
#include "bushes.h"
// TODO 2.0

// TODO 4.0

// Prototypes
void initialize();
void game();

// Button Variables
unsigned short buttons;
unsigned short oldButtons;

// Horizontal Offset
unsigned short hOff;

int main() {

    initialize();

    while(1) {

        game();

        oldButtons = buttons;
        buttons = BUTTONS;
	}
}

// Initialize the game on first launch
void initialize() {

    // TODO 2.1 - set up display control register
    REG_DISPCTL = MODE0 | BG1_ENABLE;
    // TODO 4.1 - edit display control register to ALSO enable bg 0
    REG_DISPCTL = MODE0 | BG1_ENABLE | BG0_ENABLE;
    // TODO 2.2 - load tile palette
    DMANow(3, treeswithStarsPal, PALETTE, 256);
    // TODO 2.3 - set up bg 1 control register
    REG_BG1CNT = BG_4BPP | BG_CHARBLOCK(0) | BG_SCREENBLOCK(28) | BG_SIZE_WIDE;
    // TODO 2.4 - load furtherTrees tiles to charblock
    DMANow(3, treeswithStarsTiles, &CHARBLOCK[0], treeswithStarsTilesLen/2);
    // TODO 2.5 - load furtherTrees map to screenblock
    DMANow(3, treeswithStarsMap, &SCREENBLOCK[28], 2048);
    // TODO 4.2 - set up bg 0 control register
    REG_BG0CNT = BG_4BPP | BG_CHARBLOCK(1) | BG_SCREENBLOCK(29) | BG_SIZE_SMALL;
    // TODO 4.3 - load trees tiles to charblock
    DMANow(3, bushesTiles, &CHARBLOCK[1], bushesTilesLen/2);
    // TODO 4.4 - load trees map to screenblock
    DMANow(3, bushesMap, &SCREENBLOCK[29], 1024);

    
    hOff = 0;

    buttons = BUTTONS;
}

// Update game each frame
void game() {

    // Scroll the background
    if(BUTTON_HELD(BUTTON_LEFT)) {
        hOff--;
    }
    if(BUTTON_HELD(BUTTON_RIGHT)) {
        hOff++;
    }

    waitForVBlank();

    // Update the offset registers with the actual offsets
    // TODO 5.0 - change to implement parallax
    REG_BG0HOFF = 2 * hOff;
    REG_BG1HOFF = hOff;
}