/*
Hello World v1 for PSP v2.0
(w) 24/09/2005 by Groepaz/Hitmen
http://www.hitmen-console.org

greets to Skylark, Niacin, Skywalker, xor37h, Tyranid

this is a simple example on how to use the C compiler from pspsdk for creating 
a binary that works with the exploit/loader released by someone else the other day.

its VERY basic, some C features will not work, C++ most definetly wont. you will need
to call syscalls directly (not via kernel stubs/NIDs). your program can be max 64k big.

*/


void Main(void);
void _start(void) __attribute__ ((section (".text.start")));
// this is our "crt0". not real, very fake. but enough for now :=P
void _start(void)
{
	Main();
	while(1){}; // wait forever
} 

// font data
const unsigned char font[]={

    // much better charset, by eddie!
    // this is actually the 8x8 neuromancer
    // vga/ega mode font :)
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   // 0x20 
    0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00,   // 0x21 
    0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00,   // 0x22 
    0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00,   // 0x23 
    0x30,0x7C,0xC0,0x78,0x0C,0xF8,0x30,0x00,   // 0x24 
    0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00,   // 0x25 
    0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00,   // 0x26 
    0x60,0x60,0xC0,0x00,0x00,0x00,0x00,0x00,   // 0x27 
    0x18,0x30,0x60,0x60,0x60,0x30,0x18,0x00,   // 0x28 
    0x60,0x30,0x18,0x18,0x18,0x30,0x60,0x00,   // 0x29 
    0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00,   // 0x2A 
    0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00,   // 0x2B 
    0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x60,   // 0x2C 
    0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,   // 0x2D 
    0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,   // 0x2E 
    0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00,   // 0x2F 
    0x7C,0xC6,0xCE,0xDE,0xF6,0xE6,0x7C,0x00,   // 0x30 
    0x30,0x70,0x30,0x30,0x30,0x30,0xFC,0x00,   // 0x31 
    0x78,0xCC,0x0C,0x38,0x60,0xCC,0xFC,0x00,   // 0x32 
    0x78,0xCC,0x0C,0x38,0x0C,0xCC,0x78,0x00,   // 0x33 
    0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00,   // 0x34 
    0xFC,0xC0,0xF8,0x0C,0x0C,0xCC,0x78,0x00,   // 0x35 
    0x38,0x60,0xC0,0xF8,0xCC,0xCC,0x78,0x00,   // 0x36 
    0xFC,0xCC,0x0C,0x18,0x30,0x30,0x30,0x00,   // 0x37 
    0x78,0xCC,0xCC,0x78,0xCC,0xCC,0x78,0x00,   // 0x38 
    0x78,0xCC,0xCC,0x7C,0x0C,0x18,0x70,0x00,   // 0x39 
    0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x00,   // 0x3A 
    0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x60,   // 0x3B 
    0x18,0x30,0x60,0xC0,0x60,0x30,0x18,0x00,   // 0x3C 
    0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00,   // 0x3D 
    0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00,   // 0x3E 
    0x78,0xCC,0x0C,0x18,0x30,0x00,0x30,0x00,   // 0x3F 
    0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00,   // 0x40 
    0x30,0x78,0xCC,0xCC,0xFC,0xCC,0xCC,0x00,   // 0x41 
    0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00,   // 0x42 
    0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00,   // 0x43 
    0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00,   // 0x44 
    0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00,   // 0x45 
    0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00,   // 0x46 
    0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3E,0x00,   // 0x47 
    0xCC,0xCC,0xCC,0xFC,0xCC,0xCC,0xCC,0x00,   // 0x48 
    0x78,0x30,0x30,0x30,0x30,0x30,0x78,0x00,   // 0x49 
    0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00,   // 0x4A 
    0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00,   // 0x4B 
    0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00,   // 0x4C 
    0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00,   // 0x4D 
    0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00,   // 0x4E 
    0x38,0x6C,0xC6,0xC6,0xC6,0x6C,0x38,0x00,   // 0x4F 
    0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00,   // 0x50 
    0x78,0xCC,0xCC,0xCC,0xDC,0x78,0x1C,0x00,   // 0x51 
    0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00,   // 0x52 
    0x78,0xCC,0xE0,0x70,0x1C,0xCC,0x78,0x00,   // 0x53 
    0xFC,0xB4,0x30,0x30,0x30,0x30,0x78,0x00,   // 0x54 
    0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xFC,0x00,   // 0x55 
    0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x30,0x00,   // 0x56 
    0xC6,0xC6,0xC6,0xD6,0xFE,0xEE,0xC6,0x00,   // 0x57 
    0xC6,0xC6,0x6C,0x38,0x38,0x6C,0xC6,0x00,   // 0x58 
    0xCC,0xCC,0xCC,0x78,0x30,0x30,0x78,0x00,   // 0x59 
    0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00,   // 0x5A 
    0x78,0x60,0x60,0x60,0x60,0x60,0x78,0x00,   // 0x5B 
    0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00,   // 0x5C 
    0x78,0x18,0x18,0x18,0x18,0x18,0x78,0x00,   // 0x5D 
    0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00,   // 0x5E 
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,   // 0x5F 
    0x30,0x30,0x18,0x00,0x00,0x00,0x00,0x00,   // 0x60 
    0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00,   // 0x61 
    0xE0,0x60,0x60,0x7C,0x66,0x66,0xDC,0x00,   // 0x62 
    0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x00,   // 0x63 
    0x1C,0x0C,0x0C,0x7C,0xCC,0xCC,0x76,0x00,   // 0x64 
    0x00,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00,   // 0x65 
    0x38,0x6C,0x60,0xF0,0x60,0x60,0xF0,0x00,   // 0x66 
    0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8,   // 0x67 
    0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00,   // 0x68 
    0x30,0x00,0x70,0x30,0x30,0x30,0x78,0x00,   // 0x69 
    0x0C,0x00,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,   // 0x6A 
    0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00,   // 0x6B 
    0x70,0x30,0x30,0x30,0x30,0x30,0x78,0x00,   // 0x6C 
    0x00,0x00,0xCC,0xFE,0xFE,0xD6,0xC6,0x00,   // 0x6D 
    0x00,0x00,0xF8,0xCC,0xCC,0xCC,0xCC,0x00,   // 0x6E 
    0x00,0x00,0x78,0xCC,0xCC,0xCC,0x78,0x00,   // 0x6F 
    0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0,   // 0x70 
    0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E,   // 0x71 
    0x00,0x00,0xDC,0x76,0x66,0x60,0xF0,0x00,   // 0x72 
    0x00,0x00,0x7C,0xC0,0x78,0x0C,0xF8,0x00,   // 0x73 
    0x10,0x30,0x7C,0x30,0x30,0x34,0x18,0x00,   // 0x74 
    0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00,   // 0x75 
    0x00,0x00,0xCC,0xCC,0xCC,0x78,0x30,0x00,   // 0x76 
    0x00,0x00,0xC6,0xD6,0xFE,0xFE,0x6C,0x00,   // 0x77 
    0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00,   // 0x78 
    0x00,0x00,0xCC,0xCC,0xCC,0x7C,0x0C,0xF8,   // 0x79 
    0x00,0x00,0xFC,0x98,0x30,0x64,0xFC,0x00,   // 0x7A 
    0x1C,0x30,0x30,0xE0,0x30,0x30,0x1C,0x00,   // 0x7B 
    0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00,   // 0x7C 
    0xE0,0x30,0x30,0x1C,0x30,0x30,0xE0,0x00,   // 0x7D 
    0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00,   // 0x7E    
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

#define CMAX_X 60
#define CMAX_Y 38
#define PIXELSIZE 3				//in short
#define LINESIZE 	512				//in short
#define FRAMESIZE  0xAA000			//in byte

unsigned char *vramtop=(unsigned char *)0x04000000;
unsigned long drawframe;

// get vram address for character position
unsigned char *GetVramAddr(unsigned long x,unsigned long y)
{
	return vramtop+(drawframe?FRAMESIZE:0)+x*4+y*LINESIZE*4+0x40000000;
}

// print a single character
void PutChar(unsigned long x,unsigned long y,unsigned long color,unsigned long bgcolor,unsigned char ch,char drawfg,char drawbg,char mag)
{
	unsigned char *vptr0;		//pointer to vram
	unsigned char *vptr;		//pointer to vram
	const unsigned char *cfont;		//pointer to font
	unsigned long cx,cy;
	unsigned long b;
	char mx,my;

	cfont=font+ch*8;

	vptr0=GetVramAddr(x,y);

	for (cy=0; cy<8; cy++)
	{
		for (my=0; my<mag; my++)
		{
			vptr=vptr0;
			b=0x80;
			for (cx=0; cx<8; cx++)
			{
				for (mx=0; mx<mag; mx++)
				{
					if ((*cfont&b)!=0)
					{
						if (drawfg) *(unsigned long *)vptr=color;
					} else {
						if (drawbg) *(unsigned long *)vptr=bgcolor;
					}
					vptr+=4; // PIXELSIZE*2;
				}
				b=b>>1;
			}
			vptr0+=LINESIZE*4; // 2
		}
		cfont++;
	}
}

// print a string
void Print(unsigned long x,unsigned long y,unsigned long color,const char *str)
{
	while (*str!=0 && x<CMAX_X && y<CMAX_Y) {
		PutChar(x*8,y*8,color,0,*str,1,1,1);
		str++;
		x++;
		if (x>=CMAX_X) {
			x=0;
			y++;
		}
	}
}
 
// clear video ram
void Fillvram(unsigned long color)
{
	unsigned char *vptr0;		//pointer to vram
	unsigned long i;

	vptr0=GetVramAddr(0,0);

	for (i=0; i<(FRAMESIZE/4)*2; i++) 
	{
		*(unsigned long *)vptr0=color;
		vptr0+=4;
	}
}

void Main(void)
{
//	sceDisplaySetMode(0,SCREEN_WIDTH,SCREEN_HEIGHT);

	drawframe=0;
//	sceDisplaySetFrameBuf(0,0,0,1);

	// clear the video ram
	Fillvram(0x00000000);

	// endless loop
	while(1)
	{
		Print(1,1,0x00ffffff,"Hello World v1 for PSP v2.0");

		Print(1,3,0x00ffffff,"(w) 24/09/2005 by Groepaz/Hitmen");

		Print(1,5,0x00ffffff,"http://www.hitmen-console.org");

		Print(1,7,0x00ffffff,"greets to Skylark, Niacin, Skywalker, xor37h, Tyranid");

//		sceDisplayWaitVblankStart();
		drawframe=(drawframe?0:1);
//		sceDisplaySetFrameBuf(vramtop+(drawframe?FRAMESIZE:0),LINESIZE,PIXELSIZE,0);

	}
}
