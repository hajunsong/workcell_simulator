#ifndef QCLICKLABEL_H
#define QCLICKLABEL_H

#include <QLabel>
#include <QMouseEvent>

class QClickLabel : public QLabel
{
	Q_OBJECT

public:
	explicit QClickLabel(QWidget *parent = nullptr);

	void mouseMoveEvent(QMouseEvent *ev);
	void mousePressEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);

	int x, y;

signals:
	void mousePressed();
	void mouseReleased();
	void mousePos();
};

#endif // QCLICKLABEL_H
