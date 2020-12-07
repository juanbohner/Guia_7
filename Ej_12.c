#include <stdio.h>

typedef unsigned char uchar;

uchar set_bit(uchar byte, short linea);

uchar clear_bit(uchar byte, short linea);

int main(void)
{
	uchar byte_2 = 0xCA, byte_1 = 0XA1; /*1100 1010*/	/*1010 0001*/
	short l = 3;

	byte_1 = set_bit(byte_1, 4);
	printf("%X\n", byte_1);

	byte_2 = clear_bit(byte_2, l);
	printf("%X\n", byte_2);

	return 0;
}

uchar set_bit(uchar byte, short linea) {
	return byte | (1 << linea);
}

uchar clear_bit(uchar byte, short linea){
	return byte & (~(1<<linea));
}