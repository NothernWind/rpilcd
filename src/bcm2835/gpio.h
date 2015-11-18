/*!
 ********************************************************************
 * \file		gpio.h
 * \author	NothernWind
 * \version	0.0.3
 * \date	05.07.2015
 * \brief
 *
 ********************************************************************
 */
#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

// Defines ----------------------------------------------------------
#define GPIO_FSEL_INPUT		0x00
#define GPIO_FSEL_OUTPUT	0x01
#define GPIO_FSEL_ALT0		0x04
#define GPIO_FSEL_ALT1		0x05
#define GPIO_FSEL_ALT2		0x06
#define GPIO_FSEL_ALT3		0x07
#define GPIO_FSEL_ALT4		0x03
#define GPIO_FSEL_ALT5		0x02

#define GPIO_GPSET0_GP0		0x00000001
#define GPIO_GPSET0_GP1		0x00000002
#define GPIO_GPSET0_GP2		0x00000004
#define GPIO_GPSET0_GP3		0x00000008
#define GPIO_GPSET0_GP4		0x00000010
#define GPIO_GPSET0_GP5		0x00000020
#define GPIO_GPSET0_GP6		0x00000040
#define GPIO_GPSET0_GP7		0x00000080
#define GPIO_GPSET0_GP8		0x00000100
#define GPIO_GPSET0_GP9		0x00000200
#define GPIO_GPSET0_GP10	0x00000400
#define GPIO_GPSET0_GP11	0x00000800
#define GPIO_GPSET0_GP12	0x00001000
#define GPIO_GPSET0_GP13	0x00002000
#define GPIO_GPSET0_GP14	0x00004000
#define GPIO_GPSET0_GP15	0x00008000
#define GPIO_GPSET0_GP16	0x00010000
#define GPIO_GPSET0_GP17	0x00020000
#define GPIO_GPSET0_GP18	0x00040000
#define GPIO_GPSET0_GP19	0x00080000
#define GPIO_GPSET0_GP20	0x00100000
#define GPIO_GPSET0_GP21	0x00200000
#define GPIO_GPSET0_GP22	0x00400000
#define GPIO_GPSET0_GP23	0x00800000
#define GPIO_GPSET0_GP24	0x01000000
#define GPIO_GPSET0_GP25	0x02000000
#define GPIO_GPSET0_GP26	0x04000000
#define GPIO_GPSET0_GP27	0x08000000
#define GPIO_GPSET0_GP28	0x10000000
#define GPIO_GPSET0_GP29	0x20000000
#define GPIO_GPSET0_GP30	0x40000000
#define GPIO_GPSET0_GP31	0x80000000

#define GPIO_GPCLR0_GP0		0x00000001
#define GPIO_GPCLR0_GP1		0x00000002
#define GPIO_GPCLR0_GP2		0x00000004
#define GPIO_GPCLR0_GP3		0x00000008
#define GPIO_GPCLR0_GP4		0x00000010
#define GPIO_GPCLR0_GP5		0x00000020
#define GPIO_GPCLR0_GP6		0x00000040
#define GPIO_GPCLR0_GP7		0x00000080
#define GPIO_GPCLR0_GP8		0x00000100
#define GPIO_GPCLR0_GP9		0x00000200
#define GPIO_GPCLR0_GP10	0x00000400
#define GPIO_GPCLR0_GP11	0x00000800
#define GPIO_GPCLR0_GP12	0x00001000
#define GPIO_GPCLR0_GP13	0x00002000
#define GPIO_GPCLR0_GP14	0x00004000
#define GPIO_GPCLR0_GP15	0x00008000
#define GPIO_GPCLR0_GP16	0x00010000
#define GPIO_GPCLR0_GP17	0x00020000
#define GPIO_GPCLR0_GP18	0x00040000
#define GPIO_GPCLR0_GP19	0x00080000
#define GPIO_GPCLR0_GP20	0x00100000
#define GPIO_GPCLR0_GP21	0x00200000
#define GPIO_GPCLR0_GP22	0x00400000
#define GPIO_GPCLR0_GP23	0x00800000
#define GPIO_GPCLR0_GP24	0x01000000
#define GPIO_GPCLR0_GP25	0x02000000
#define GPIO_GPCLR0_GP26	0x04000000
#define GPIO_GPCLR0_GP27	0x08000000
#define GPIO_GPCLR0_GP28	0x10000000
#define GPIO_GPCLR0_GP29	0x20000000
#define GPIO_GPCLR0_GP30	0x40000000
#define GPIO_GPCLR0_GP31	0x80000000

#define GPIO_MARK1_CLR	bcm2835_GPIO->GPCLR0 = GPIO_GPCLR0_GP5;
#define GPIO_MARK1_SET	bcm2835_GPIO->GPSET0 = GPIO_GPSET0_GP5;

// Typedefs ---------------------------------------------------------
typedef union _t_gpsn {
	unsigned int all;
	struct {
		unsigned FSELn0:3;
		unsigned FSELn1:3;
		unsigned FSELn2:3;
		unsigned FSELn3:3;
		unsigned FSELn4:3;
		unsigned FSELn5:3;
		unsigned FSELn6:3;
		unsigned FSELn7:3;
		unsigned FSELn8:3;
		unsigned FSELn9:3;
		unsigned :2;
	}bits;
} t_gpsn;

typedef union _t_gp0 {
	unsigned int all;
	struct {
		unsigned GPIO0:1;
		unsigned GPIO1:1;
		unsigned GPIO2:1;
		unsigned GPIO3:1;
		unsigned GPIO4:1;
		unsigned GPIO5:1;
		unsigned GPIO6:1;
		unsigned GPIO7:1;
		unsigned GPIO8:1;
		unsigned GPIO9:1;
		unsigned GPIO10:1;
		unsigned GPIO11:1;
		unsigned GPIO12:1;
		unsigned GPIO13:1;
		unsigned GPIO14:1;
		unsigned GPIO15:1;
		unsigned GPIO16:1;
		unsigned GPIO17:1;
		unsigned GPIO18:1;
		unsigned GPIO19:1;
		unsigned GPIO20:1;
		unsigned GPIO21:1;
		unsigned GPIO22:1;
		unsigned GPIO23:1;
		unsigned GPIO24:1;
		unsigned GPIO25:1;
		unsigned GPIO26:1;
		unsigned GPIO27:1;
		unsigned GPIO28:1;
		unsigned GPIO29:1;
		unsigned GPIO30:1;
		unsigned GPIO31:1;
	} bits;
} t_gp0;

typedef union _t_gp1 {
	unsigned int all;
	struct {
		unsigned GPIO32:1;
		unsigned GPIO33:1;
		unsigned GPIO34:1;
		unsigned GPIO35:1;
		unsigned GPIO36:1;
		unsigned GPIO37:1;
		unsigned GPIO38:1;
		unsigned GPIO39:1;
		unsigned GPIO40:1;
		unsigned GPIO41:1;
		unsigned GPIO42:1;
		unsigned GPIO43:1;
		unsigned GPIO44:1;
		unsigned GPIO45:1;
		unsigned GPIO46:1;
		unsigned GPIO47:1;
		unsigned GPIO48:1;
		unsigned GPIO49:1;
		unsigned GPIO50:1;
		unsigned GPIO51:1;
		unsigned GPIO52:1;
		unsigned GPIO53:1;
		unsigned :10;
	} bits;
} t_gp1;

typedef struct _t_gpio {
	volatile t_gpsn GPFSEL0;
	volatile t_gpsn GPFSEL1;
	volatile t_gpsn GPFSEL2;
	volatile t_gpsn GPFSEL3;
	volatile t_gpsn GPFSEL4;
	volatile t_gpsn GPFSEL5;
	volatile unsigned int r1;
	volatile unsigned int GPSET0;
	volatile unsigned int GPSET1;
	volatile unsigned int r2;
	volatile unsigned int GPCLR0;
	volatile unsigned int GPCLR1;
	volatile unsigned int r3;
	volatile t_gp0 GPLEV0;
	volatile t_gp1 GPLEV1;
	volatile unsigned int r4;
	volatile t_gp0 GPEDS0;
	volatile t_gp1 GPEDS1;
	volatile unsigned int r5;
	volatile t_gp0 GPREN0;
	volatile t_gp1 GPREN1;
	volatile unsigned int r6;
	volatile t_gp0 GPFEN0;
	volatile t_gp1 GPFEN1;
	volatile unsigned int r7;
	volatile t_gp0 GPHEN0;
	volatile t_gp1 GPHEN1;
	volatile unsigned int r8;
	volatile t_gp0 GPLEN0;
	volatile t_gp1 GPLEN1;
	volatile unsigned int r9;
	volatile t_gp0 GPAREN0;
	volatile t_gp1 GPAREN1;
	volatile unsigned int r10;
	volatile t_gp0 GPAFEN0;
	volatile t_gp1 GPAFEN1;
	volatile unsigned int r11;
	volatile unsigned int GPPUD;
	volatile t_gp0 GPPUDCLK0;
	volatile t_gp1 GPPUDCLK1;
	volatile unsigned int r12;
	volatile unsigned int test;
} t_gpio;

extern t_gpio * bcm2835_GPIO;

int gpio_init(void);
void gpio_deinit(void);

#ifdef __cplusplus
}
#endif

#endif // GPIO_H
