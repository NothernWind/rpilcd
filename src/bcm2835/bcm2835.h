/*!
 ********************************************************************
 * \file	bcm2835.h
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */
#ifndef BCM2835_H
#define BCM2835_H

#ifdef __cplusplus
extern "C" {
#endif

// Defines ----------------------------------------------------------
#define CPU_CORE_CLOCK			250000000
/*!
 ********************************************************************
 * Physical addresses range from 0x20000000 to 0x20FFFFFF for 
 * peripherals. The bus addresses for peripherals are set up to map 
 * onto the peripheral bus address range starting at 0x7E000000. 
 * Thus a peripheral advertised here at bus address 0x7Ennnnnn is 
 * available at physical address 0x20nnnnnn.
 ********************************************************************
 */
#define BCM2835_PERIPH_BASE		0x20000000

#define SYS_TIM_OFFSET			0x00003000
#define DMA_OFFSET				0x00007000
#define TIM_OFFSET				0x0000B000

#define CM_GPCTL_OFFSET			0x00101000

#define GPIO_OFFSET				0x00200000
#define UART_OFFSET				0x00201000
#define PCM_OFFSET				0x00203000
#define SPI_OFFSET				0x00204000
#define BSC0_OFFSET				0x00205000
#define PWM_OFFSET				0x0020C000

#define BSC_SPI_OFFSET			0x00214000

#define AUX_OFFSET				0x00215000
#define AUX_MU_OFFSET			0x00215040
#define AUX_SPI1_OFFSET			0x00215080
#define AUX_SPI2_OFFSET			0x002150C0

#define EMMC_OFFSET				0x00300000

#define BSC1_OFFSET				0x00804000
#define BSC2_OFFSET				0x00805000

// Typedefs ---------------------------------------------------------
struct bcm2835_periph {
	unsigned long paddr;
	int fd;
	void *map;
	volatile unsigned int *addr;
};

// Extern Variables -------------------------------------------------
extern struct bcm2835_periph gpio_dsc;
extern struct bcm2835_periph spi_dsc;

// Public Prototypes ------------------------------------------------
int bcm2835_periph_map(struct bcm2835_periph * pr, unsigned long addr);
void bcm2835_periph_unmap(struct bcm2835_periph * pr);

#ifdef __cplusplus
}
#endif

#endif // BCM2835_H
