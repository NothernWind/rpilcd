#ifndef SPILCD_H
#define SPILCD_H

#define DATA				1
#define INSTRUCTION			0
#define LCD_CLEAR			0x01
#define LCD_RET_HOME		0x02
#define LCD_MODE_SET		0x04
#define LCD_SET_INC			0x02
#define LCD_CTRL			0x08
#define LCD_ON				0x04
#define LCD_FN_SET			0x20
#define LCD_TWO_LINES		0x08
#define LCD_CGRAM_ADDR		0x40
#define LCD_DDRAM_ADDR		0x80

void SPI_LCD_Init(void);
void SPI_LCD_write_string(const char * str,
	unsigned char start, int len);

#endif // SPILCD_H
