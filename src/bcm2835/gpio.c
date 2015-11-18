/*!
 ********************************************************************
 * \file	gpio.c
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */
#include <stdio.h>
#include "bcm2835.h"
#include "gpio.h"

t_gpio * bcm2835_GPIO;
/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
int bcm2835_gpio_map(void)
{
	printf("Map GPIO\n");
	if (bcm2835_periph_map(&gpio_dsc, BCM2835_PERIPH_BASE | GPIO_OFFSET) == -1) {
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
	bcm2835_GPIO = (t_gpio *)gpio_dsc.addr;
	printf("Success\n");
	return 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
int gpio_init(void)
{
	if (bcm2835_gpio_map() == -1) return -1;

	// Для начала настроим порты для SPI0
	printf("Config GPIO Alternate function for SPI\n");

	// 24 GPIO8  SPI0_CS0
	bcm2835_GPIO->GPFSEL0.bits.FSELn8 = GPIO_FSEL_ALT0;

	// 19 GPIO10 SPI0_MOSI
	bcm2835_GPIO->GPFSEL1.bits.FSELn0 = GPIO_FSEL_ALT0;

	// 23 GPIO11 SPI_SCLK
	bcm2835_GPIO->GPFSEL1.bits.FSELn1 = GPIO_FSEL_ALT0;

	return 0;
}

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
void gpio_deinit(void)
{
	printf("Deinit GPIO\n");
	bcm2835_GPIO->GPFSEL1.bits.FSELn0 = GPIO_FSEL_INPUT; // 19 GPIO10 SPI0_MOSI
	bcm2835_GPIO->GPFSEL1.bits.FSELn1 = GPIO_FSEL_INPUT; // 23 GPIO11 SPI_SCLK
	bcm2835_GPIO->GPFSEL0.bits.FSELn8 = GPIO_FSEL_INPUT;

	printf("Unmap GPIO\n");
	bcm2835_periph_unmap(&gpio_dsc);
}
