#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "characterdisplay.h"
#include <QTimer>
#include <QDateTime>

class Window : public QWidget
{
	Q_OBJECT
public:
	explicit Window(QWidget *parent = 0);

private slots:
	void datetime_update(void);

private:
	QGridLayout * grid;
	CharacterDisplay *lcd;
	
};

#endif // WINDOW_H
