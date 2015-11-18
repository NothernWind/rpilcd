/*!
 --------------------------------------------------------------------
 \file
 \author
 \version
 \date
 \brief
 --------------------------------------------------------------------
 */
#ifndef CHARACTERDISPLAY_H
#define CHARACTERDISPLAY_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QPainter>

enum DisplayColors{
	BACKGROUNG,
	FRAME,
	CHARACTER,
	CHAR_GRID,
	SELECTED_CHAR,
	SELECT_FRAME
};

/*!
 --------------------------------------------------------------------
 \brief

 --------------------------------------------------------------------
 */
class CharacterDisplay : public QWidget
{
    Q_OBJECT
public:
	explicit CharacterDisplay(QWidget *parent = 0);

	QSize minimumSizeHint() const {
		return QSize(n_char * 18 + 20, n_str * 27 + 20); }

	QSize sizeHint() const {
		return QSize(n_char * 18 + 20, n_str * 27 + 20); }

	void set_read_only(bool state) {read_only = state;}

	void setDispalySize(int col, int row) {
		delete display_str;n_char = col;n_str = row;
		display_str = new char[col * row + 1];
		display_str[n_str * n_char] = 0x00;
		setMinimumSize(n_char * 18 + 20, n_str * 27 + 20);
		update(); }

	void setDispalyColors(QColor bg, QColor cbg, QColor cfg, QColor f){
		bg_color = bg; cbg_color = cbg; cfg_color = cfg; frame_color = f;
		update(); }

	void setDispalyColors(DisplayColors colors, QColor color);

	void set_blink_interval(int interval){cursor_blink_interval = interval;}

	void write_string(char *str){
		for(int i = 0; i < 32; i++)
			display_str[i] = str[i];
		update(); }

	void clear_screen(void){
		for(int i = 0; i < n_char*n_str;i++)
			display_str[i] = ' ';
		update();
	}

signals:
	void changed(char *str);// Изменили символ

	void clicked(int ch); // тыкнули в символ

public slots:
	void setPen(const QPen &pen){this->pen = pen;update();}

private slots:
	void blink_cursor(void);

protected:
	void paintEvent(QPaintEvent *enent);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	char * display_str;			// массив символов выводимый на экран
	int n_char;					// количество символов в строке
	int n_str;					// количество строк экрана
	int selected_char;			// выделенный символ
	int selected_str;			// выделенная строка
	int cursor_char;			// в каком символе находится курсор
	int cursor_str;				// в какой строке находится курсор
	int cursor_blink_interval;	// интервал мерцания курсора
	bool cursor_on;				// также предполагается наличие курсора
	bool cursor_state;			// = true;
	bool timer_state;			// = false;
	bool shift;					// нажата клавиша шифт
	bool read_only;				// только чтение
	int character;				// нажатая кнопка на клавиатуре
	QColor bg_color;			// цвет фона
	QColor frame_color;			// цвет рамки экрана
	QColor cbg_color;			// цвет фона символа
	QColor cfg_color;			// цвет символа
	QColor bg_select_color;		// фон цвета выделения
	QColor frame_select_color;	// цвет рамки выделения
	QPen pen;					// пень

	void move_left(void);
	void move_right(void);

	bool in_zone(int value, int min, int max){
		return (value > min) ? ((value < max) ? true : false) : false;
	}
};

#endif // CHARACTERDISPLAY_H
