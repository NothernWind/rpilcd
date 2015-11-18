/*!
 ********************************************************************
 * \file	spi0.c
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */

#include <stdio.h>
#include <unistd.h>

#include "bcm2835.h"

#include "spi0.h"
#include "gpio.h"

t_spi * bcm2835_SPI;

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
int bcm2835_spi0_map(void)
{
	printf("Map SPI0\n");
	if (bcm2835_periph_map(&spi_dsc, BCM2835_PERIPH_BASE | SPI_OFFSET) == -1) {
		printf("Failed to map the physical SPI registers into the virtual memory space.\n");
		return -1;
	}
	bcm2835_SPI = (t_spi *)spi_dsc.addr;
	printf("Success\n");
	return 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
int spi0_unidir_poll_init(int ckdiv, int flags)
{
	if (bcm2835_spi0_map() == -1) return -1;
	
	printf("Configure SPI:\n");

	if (flags & SPI0_CHPA_BEGINN)
		bcm2835_SPI->CSR.bits.CHPA = 1;

	if (flags & SPI0_CPOL_HIGH)
		bcm2835_SPI->CSR.bits.CPOL = 1;
	
	bcm2835_SPI->CSR.bits.CLEAR = 0x3;
	bcm2835_SPI->CLR = ckdiv;
	bcm2835_SPI->CSR.bits.TE_EN = 1;
	
	printf(
		"CHPA = %d;\n"
		"CPOL = %d;\n"
		"F(CK) = %f Hz;\n",
		bcm2835_SPI->CSR.bits.CHPA,
		bcm2835_SPI->CSR.bits.CPOL,
		((double)250000000) / ((double)ckdiv)
	);


	return 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
void spi0_unidir_poll_deinit(void)
{
	printf("Deinit SPI\n");
	bcm2835_SPI->CSR.all = 0;
	printf("Unmap SPI\n");
	bcm2835_periph_unmap(&spi_dsc);
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
unsigned char spi0_unidir_poll_transfer(unsigned char data)
{
	unsigned char temp;
	bcm2835_SPI->CSR.bits.TA = 1;
	bcm2835_SPI->FIFO = data;
	while (bcm2835_SPI->CSR.bits.DONE == 0);
	temp = (unsigned char)(bcm2835_SPI->FIFO);
	bcm2835_SPI->CSR.bits.TA = 0;
	return temp;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
void spi0_unidir_poll_block_transfer(
	const char *out_block, char * in_block, int size)
{
	int i;
	bcm2835_SPI->CSR.bits.TA = 1;

	for (i = 0; i < size; i++) {
		bcm2835_SPI->FIFO = out_block[i];
		while (bcm2835_SPI->CSR.bits.DONE == 0);
		in_block[i] = (unsigned char)(bcm2835_SPI->FIFO);
	}
	bcm2835_SPI->CSR.bits.TA = 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
void spi0_unidir_poll_block_rx(char *block, int size)
{
	int i;
	bcm2835_SPI->CSR.bits.TA = 1;
	for (i = 0; i < size; i++) {
		bcm2835_SPI->FIFO = 0xFF;
		while (bcm2835_SPI->CSR.bits.DONE == 0);
		block[i] = (unsigned char)(bcm2835_SPI->FIFO);
	}
	bcm2835_SPI->CSR.bits.TA = 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
void spi0_unidir_poll_block_tx(const char *block, int size)
{
	int i;
	char temp;

	bcm2835_SPI->CSR.bits.TA = 1;
	for (i = 0; i < size; i++) {
		bcm2835_SPI->FIFO = block[i];

		while (bcm2835_SPI->CSR.bits.DONE == 0);

		temp = (unsigned char)(bcm2835_SPI->FIFO);
	}
	bcm2835_SPI->CSR.bits.TA = 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
int spi0_wait_process(void)
{
	int timeout = 0;
	while (bcm2835_GPIO->GPLEV0.bits.GPIO24 == 1) {
		usleep(1);
		timeout++;
		if (timeout > 100000) return -1;
	}
	return 0;
}
