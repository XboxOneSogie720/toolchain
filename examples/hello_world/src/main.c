/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Put function prototypes here */
void printText(const char *text, uint8_t x, uint8_t y);
void printTextSmall(const char *text, uint8_t xpos, uint8_t ypos);

/* Put all your code here */
void main(void) {
    /* uint8_t is an unsigned integer that can range from 0-255. */
    /* It performs faster than just an int, so try to use it (or int8_t) when possible */
    uint8_t count;

    /* Initialize some strings */
    const char *HelloWorld = "Hello World!";
    const char *Welcome = "Welcome to C!";

    /* This function cleans up the screen */
    prgm_CleanUp();
    
    /* Print a few strings */
    printText( HelloWorld, 0, 0 );
    printText( Welcome, 0, 1 );
    
    /* Wait for a key press */
    while( !os_GetCSC() );
    
    /* Clean up, and finish */
    prgm_CleanUp();
}

/* Draw text on the homescreen at the given X/Y location */
void printText(const char *text, uint8_t xpos, uint8_t ypos) {
    os_SetCursorPos(ypos, xpos);
    os_PutStrFull(text);
}

/* Draw small text at the given X/Y location */
void printTextSmall(const char *text, uint8_t xpos, uint8_t ypos) {
    os_FontDrawText(text, xpos, ypos);
}

