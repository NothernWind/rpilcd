/*!
 ********************************************************************
 * \file	spi0.h
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */
#ifndef SPI0_H
#define SPI0_H

#ifdef __cplusplus
extern "C" {
#endif

// Defines ----------------------------------------------------------
#define SPI0_CHPA_MIDDLE	0x00000000
#define SPI0_CHPA_BEGINN	0x00000002
#define SPI0_CPOL_LOW		0x00000000
#define SPI0_CPOL_HIGH		0x00000004

typedef union _t_spi_cs {
	unsigned int all;
	struct {
		unsigned CS:2;			//!< (RW) Chip Select
		unsigned CHPA:1;		//!< (RW) Clock Phase
		unsigned CPOL:1;		//!< (RW) Clock Polarity
		unsigned CLEAR:2;		//!< (RW) FIFO Clear
		unsigned CSPOL:1;		//!< (RW) Chip Select Polarity
		unsigned TA:1;			//!< (RW) Transfer Active
		unsigned DMAEN:1;		//!< (RW) DMA Enable
		unsigned INTD:1;		//!< (RW) Interrupt on Done
		unsigned INTR:1;		//!< (RW) Interrupt on RXR
		unsigned ADCS:1;		//!< (RW) Automatically Deassert Chip Select
		unsigned REN:1;			//!< (RW) Read Enable
		unsigned LEN:1;			//!< (RW) LoSSI enable
		unsigned LMONO:1;		//!< (RW) Unused
		unsigned TE_EN:1;		//!< (RW) Unused
		unsigned DONE:1;		//!< (RO) transfer Done
		unsigned RXD:1;			//!< (RO) RX FIFO contains Data
		unsigned TXD:1;			//!< (RO) TX FIFO can accept Data
		unsigned RXR:1;			//!< (RO) RX FIFO needs Reading ( full)
		unsigned RXF:1;			//!< (RO) RX FIFO Full
		unsigned CSPOL0:1;		//!< (RW) Chip Select 0 Polarity
		unsigned CSPOL1:1;		//!< (RW) Chip Select 1 Polarity
		unsigned CSPOL2:1;		//!< (RW) Chip Select 2 Polarity
		unsigned DMA_LEN:1;		//!< (RW) Enable DMA mode in Lossi mode
		unsigned LEN_LONG:1;	/*!< (RW) Enable Long data word in Lossi
									 mode if DMA_LEN is set */
		unsigned :6;
	} bits;
} t_spi_cs;

typedef union _t_spi_dc {
	unsigned int all;
	struct {
		unsigned char TDREQ;
		unsigned char TPANIC;
		unsigned char RDREQ;
		unsigned char RPANIC;
	} rq;
} t_spi_dc;

typedef struct _t_spi {
	volatile t_spi_cs CSR;
	volatile unsigned int FIFO;
	volatile unsigned int CLR;
	volatile unsigned int DLEN;
	volatile unsigned int LTOH;
	volatile t_spi_dc DCR;
} t_spi;

extern t_spi * bcm2835_SPI;

// Prototypes -------------------------------------------------------
int spi0_unidir_poll_init(int ckdiv, int flags);
void spi0_unidir_poll_deinit(void);
unsigned char spi0_unidir_poll_transfer(unsigned char data);
void spi0_unidir_poll_block_transfer(
	const char *out_block, char * in_block, int size);
void spi0_unidir_poll_block_rx(char *block, int size);
void spi0_unidir_poll_block_tx(const char *block, int size);
int spi0_wait_process(void);

#ifdef __cplusplus
}
#endif

#endif // SPI_H
