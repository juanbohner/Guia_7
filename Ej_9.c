#include <stdio.h>

typedef enum
{
	LO,
	HI
}	bit_t;

typedef enum
{
	TRUE,
	FALSE
}	bool_t;

#define MASK_TXCIE 		0x40	/*0100	0000*/

bit_t transmision_completa(unsigned char reg);

void transmision_completa_1(unsigned char reg, bit_t *tx);

int main(void)
{
	unsigned char reg = 0xDA;	/*1101	1010*/
	bit_t tx_sent;
	bit_t tx_sent_2;

	tx_sent = transmision_completa(reg);

	printf ("%d\n", tx_sent);

	transmision_completa_1(reg, &tx_sent_2);

	printf ("%d\n", tx_sent_2);


	return 0;
}

bit_t transmision_completa(unsigned char reg)
{
	return (reg & MASK_TXCIE) ? HI : LO;
}

/*El bit de transmision es el *tx */
void transmision_completa_1(unsigned char reg, bit_t *tx)
{
	/*Si fue transmitido, devuelve HI, si no fue devuelve un LO*/
    *tx = (reg & MASK_TXCIE) ? HI : LO;
}