#define VGABUF ((volatile char *) 0xb8000)

static void vga_write(const char *s, int linea, int color){
	volatile char *buf = VGABUF;
	while(*s != 0){
		*buf++ = *s++;
		*buf++ = color;
	}
}


void comienzo(void) {
	volatile char *buf = VGABUF;
/*
	*buf++ = 79;
	*buf++ = 47;
	*buf++ = 75;
	*buf++ = 47;
*/
	char *string="HOLA MUNDO";

	vga_write("Hola Mundo", 2, 2);


    while (1)
        asm("hlt");
}