#include "Slider.h"

Slider::Slider()
{
    setOrientation(Qt::Horizontal);
}

void Slider::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
    {
        int value = event->x()*maximum()/width(); //i know right? integer can't handle media more than about 30 minutes
        emit sliderPressed(value);
        event->accept();
    }
    QSlider::mousePressEvent(event);
}

