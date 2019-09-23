//#define VGABUF ((volatile char *) 0xb8000)
static int *VGABUF = (int*)0xb8000;
/*
static void vga_write(const char *s, int linea, int color){
	//La pantalla tiene 80 Caracteres de ancho y 24 de alto.
	int i = 0;
	if(linea < 0){
		while(linea < 0){
			linea++;
			i++;
		}
		linea = (24-i);
	}

	volatile char *buf = VGABUF+(160*linea);

	while(*s != 0){
		*buf++ = *s++;
		*buf++ = color;
	}
}
*/
void comienzo(void) {
	//79 = 4F Hexa = 'O'; 47 = 2F Hexa = Verde; 75 = 4B Hexa = 'K'
	//HOLA : H = 48 (Hexa); O = 4F (Hexa); L = 4C; A = 41 (Hexa)
	// Fondo amarillo (Hexa) = EF 
	volatile unsigned *p = VGABUF;
	*p = 0x2F4B2F4F;
	volatile long long int *p2 = VGABUF + 160;
	*p2 = 0xEF41EF4CEF4FEF48;
	while (1)
		asm("hlt");
}