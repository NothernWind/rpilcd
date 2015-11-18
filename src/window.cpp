#include "window.h"

Window::Window(QWidget *parent)
	: QWidget(parent)
	, grid (new QGridLayout(this))
	, lcd (new CharacterDisplay(this))
{
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

void Window::datetime_update()
{
	QByteArray ba = QDateTime::currentDateTime()
		.toString("hh:mm:ss        dd.MM.yyyy ").toAscii();

	lcd->write_string(ba.data());
}
