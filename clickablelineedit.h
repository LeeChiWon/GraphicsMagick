#ifndef CLICKABLELINEEDIT_H
#define CLICKABLELINEEDIT_H

#include <QtWidgets>

class ClickableLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ClickableLineEdit(QWidget *parent = 0);
    ~ClickableLineEdit();

signals:
    void clicked();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
public slots:
};

#endif // CLICKABLELINEEDIT_H
