#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "util.h"
#include "stdlib/stdio.h"
#include "keyboard.h"
#include "malloc.h"
#include "bitter.h"

void main();

void set_screen_color(uint8_t color);

void set_screen_color(uint8_t color) {
    uint8_t* video_memory = (uint8_t*)0xB8000;

    for (int i = 0; i < width * height * 2; i += 2) {
        video_memory[i + 1] = color; // Set the background color byte
    }
}


void main() {
    initGdt();
    initIdt();
    initTimer();
    initKeyboard();
    print("######################\n");
    print("#        ETHOS       #\n");
    print("######################\n");
    print("ethos-->");
    set_screen_color(0x1F);

    // malloc //
    uint32_t mem;
    uint32_t* page = malloc(20);
    bitmap_init();
    pmm_init();
    // paging //
    //char *ptr = (char *)0x000000001;

    //*ptr = 'a';

    //printf("%c\n", *ptr);
    for(;;);
}
