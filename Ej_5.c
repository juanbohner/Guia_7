#include <stdio.h>

#define MASK_BYTE			0xFF /* 1111  1111 */

#define MSG_ERROR_NULL_POINTER		"Puntero null"

#define MAX_SIZE 65

typedef unsigned int uint; 

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	MAX_ERRORS
} status_t;

void print_num(uint num);

status_t big_endian_conversor(uint v[], uint num);

int main(void)
{
	status_t st;
	size_t i;
	uint num =  271590900;

	uint v[4];

	print_num(num);
	putchar('\n');


	if((st = big_endian_conversor(v, num)) != OK)
	{
		fprintf(stderr, "%s%s\n", "Error:", MSG_ERROR_NULL_POINTER);
		return st;
	}

	return OK;

}



void print_num_in_binary(uint num)
{
	size_t i;
	char v[MAX_SIZE];


	for (i = 0; i < sizeof(uint) * 8; i++)
	{
		v[i] = num & (1 << (sizeof(uint) * 8 - 1 -i)) ? '1' : '0';
	}
	v[i] = putchar('\0'); 
	puts(v);

	return ;
}




/*Big endian es dividir un numero de varios bytes en binario en sus fragmetos de bytes, escribiendo primero el byte mas significativo en hexa y ultimo el menos significativo en hexa.*/
status_t big_endian_conversor(uint v[], uint num)
{
	size_t i;

	if (v == NULL)	
		return ERROR_NULL_POINTER;
	
	for ( i = 0; i < sizeof(uint); i++)
	{	

		/*En el desplazamiento, pongo a -1 y -i adentro del parentesis que multiplica el 8, debido a que yo me quiero ir moviendo de 8 en 8, no de 1 en 1. 
		Primero tengo lo siguiente:
		El numero original
		0001 0000	0011 0000	0010 0101	1111 0100
		---------

		Entro al ciclo y lo muevo 32 - 8 lugares hacia la drecha
		obtengo:
		0000 0000	0000 0000	0000 0000	0001 0000
											---------
	
		Ahora comparo con la mascara que es 1111 1111
		Uso el &(AND), me quedan unicamente los bits encendidos, es decir 0001 0000. Eso es 16 en decimal o 10 en hexa.
		Lo guardo en la primer posicion de v.

		Ahora Etro al segundo ciclo
		Hago lo siguiente,
		Tomo el mismo numero inicial:
		0001 0000	0011 0000	0010 0101	1111 0100
		---------	---------
		Pero me despalzo 32 - 8 -8 lugares hacia la derecha. Obtengo lo siguiente:
		0000 0000	0000 0000	0001 0000	0011 0000
								---------	---------

		Al aplicarle AND con la mascara que es 1111 1111 seria:

		0000 0000	0000 0000	0001 0000	0011 0000
		&
		0000 0000	0000 0000	0000 0000	1111 1111
		---------------------------------------------
		0000 0000	0000 0000	0000 0000	0011 0000

		Este valor lo gaardo en la posicion 1 (segundo elemento) del arreglo v, que es equivalente a 48, o en hexa 30.

		Ahora se repite para los demas ciclos, lo que hago es que me quedo con los valores de cada byte de la palabra original, que tenia varios bytes y guardo cada byte en una posicon distinta del arreglo. Del byte mas significativo al menos.
		
		*/
		v[i] = MASK_BYTE & (num >> ((sizeof(uint) - 1 - i) * 8)); 
	}

	for( i = 0; i < 4; i++)
	{
		printf("%x\n", v[i]);
	}
	return OK;
}