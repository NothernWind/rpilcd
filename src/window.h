#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "characterdisplay.h"
#include <QTimer>
#include <QDateTime>

#include "bcm2835/bcm2835.h"
#include "bcm2835/gpio.h"
#include "bcm2835/spi0.h"
#include "spilcd.h"

class Window : public QWidget
{
	Q_OBJECT
public:
	explicit Window(QWidget *parent = 0);
	~Window();

private slots:
	void datetime_update(void);

private:
	QGridLayout * grid;
	CharacterDisplay *lcd;
	
};

#endif // WINDOW_H
