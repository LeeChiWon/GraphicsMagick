#include "clickablelineedit.h"

ClickableLineEdit::ClickableLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

ClickableLineEdit::~ClickableLineEdit()
{

}

void ClickableLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit clicked();
}
