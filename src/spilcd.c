#include "spilcd.h"
#include "bcm2835/bcm2835.h"
#include "bcm2835/gpio.h"
#include "bcm2835/spi0.h"

#include <stdio.h>
#include <unistd.h>

#define WH1602A_CS_ON		bcm2835_GPIO->GPCLR0 = GPIO_GPCLR0_GP8;
#define WH1602A_CS_OFF		bcm2835_GPIO->GPSET0 = GPIO_GPSET0_GP8;

void spi_write(unsigned char data)
{
	WH1602A_CS_ON

	spi0_unidir_poll_transfer(data);

	WH1602A_CS_OFF
}

/*!
 --------------------------------------------------------------------
 \brief
	 Бит 0 - Не используется
	 Бит 1 - RS
	 Бит 2 - E
	 Бит 3 - Не используется
	 Бит 4 - D4
	 Бит 5 - D5
	 Бит 6 - D6
	 Бит 7 - D7
 --------------------------------------------------------------------
 */
void lcd_write(char data, char di)
{
	unsigned char srd = 0;	// данные которые будут отправлены в сдвиг

	if (di == 0)
		srd &= ~0x02;
	else srd |= 0x02;

	spi_write(0);

		// Отправим старший полубайт
	srd |= (((unsigned char)(data)) & 0xF0);
	spi_write(srd);

	srd |= 0x04;
	spi_write(srd);

	srd &= ~0x04;
	spi_write(srd);

	spi_write(0);
	srd = 0;

	// Устанавливаем бит выбор регистра
	if (di == 0)
		srd &= ~0x02;
	else srd |= 0x02;

	srd |= ((((unsigned char)data) << 4) & 0xF0);

	srd |= 0x04;
	spi_write(srd);

	srd &= ~0x04;
	spi_write(srd);

	spi_write(0);
	srd = 0;
	usleep(39);
}

void SPI_LCD_Init(void)
{
	unsigned char srd = 0;
	spi_write(srd);
	WH1602A_CS_OFF

	msleep(100);

	srd = 0x20;

	spi_write(srd);

	srd |= 0x04;
	spi_write(srd);

	srd &= ~0x04;
	spi_write(srd);

	spi_write(0);
	srd = 0;

	lcd_write(LCD_FN_SET | LCD_TWO_LINES, INSTRUCTION);
	lcd_write(LCD_CTRL | LCD_ON, INSTRUCTION);
	lcd_write(LCD_CLEAR, INSTRUCTION);
	usleep(1600);
	lcd_write(LCD_MODE_SET | LCD_SET_INC, INSTRUCTION);
}

void SPI_LCD_write_string(const char * str,
	unsigned char start, int len)
{
	int i = 0;
	lcd_write(LCD_DDRAM_ADDR + start, INSTRUCTION);
	for (i = 0; i < len; i++) {
		if (*str == 0) break;
		if (i == 16) {
			lcd_write(LCD_DDRAM_ADDR + 0x40, INSTRUCTION);
		}
		lcd_write(str[i], DATA);
	}
}
