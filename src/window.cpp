#include "window.h"

char lcdstr[33];

Window::Window(QWidget *parent)
	: QWidget(parent)
	, grid (new QGridLayout(this))
	, lcd (new CharacterDisplay(this))
{
	if (gpio_init() != 0) {
		exit(-1);
	}

	if (spi0_unidir_poll_init(250,
		SPI0_CHPA_BEGINN | SPI0_CPOL_HIGH) != 0) {
		exit(-1);
	}

	printf("Device Ready!\n");

	SPI_LCD_Init();

	memset(lcdstr, ' ', 32);
	lcdstr[32] = 0;


	setWindowTitle("HD44780 Display");

	lcd->set_read_only(true);

	setLayout(grid);
	grid->addWidget(lcd, 0, 0);
	grid->setMargin(0);

	adjustSize();
	setFixedSize(size());

	QTimer * timer = new QTimer(this);
	timer->setInterval(1000);
	connect(timer, SIGNAL(timeout()),
		this, SLOT(datetime_update()));
	timer->start(1000);
}

Window::~Window()
{
	gpio_deinit();
	spi0_unidir_poll_deinit();
}

void Window::datetime_update()
{
	QByteArray ba = QDateTime::currentDateTime()
		.toString("hh:mm:ss        dd.MM.yyyy      ").toAscii();

	lcd->write_string(ba.data());

	strcpy(lcdstr, ba.data());
	SPI_LCD_write_string(lcdstr, 0, 32);
}
