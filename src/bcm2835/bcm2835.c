/*!
 ********************************************************************
 * \file	bcm2835.c
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */
#include "bcm2835.h"

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// Variables --------------------------------------------------------
struct bcm2835_periph gpio_dsc = {BCM2835_PERIPH_BASE | GPIO_OFFSET, 0, 0, 0};
struct bcm2835_periph spi_dsc = {BCM2835_PERIPH_BASE | SPI_OFFSET, 0, 0, 0};

/*!
 ********************************************************************
 * \brief
 * 
 ********************************************************************
 */
int bcm2835_periph_map(struct bcm2835_periph * pr, unsigned long addr)
{
	if ((pr->fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
		printf("Failed to open /dev/mem, try checking premissions.\n");
		return -1;
	}

	pr->paddr = addr;
		
	pr->map = mmap(
		NULL,
		4096,
		PROT_READ | PROT_WRITE,
		MAP_SHARED,
		pr->fd,
		pr->paddr);
	
	if (pr->map == MAP_FAILED) {
		perror("mmap");
		printf("Map failed\n");
		return -1;
	}
	
	pr->addr = (volatile unsigned int *)pr->map;	
	return 0;
}

/*!
 ********************************************************************
 * \brief
 * 
 ********************************************************************
 */
void bcm2835_periph_unmap(struct bcm2835_periph * pr)
{
	munmap(pr->map, 4096);
	close(pr->fd);
}
