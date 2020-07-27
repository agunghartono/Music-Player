#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>
#include <QMouseEvent>

class Slider:public QSlider
{
    Q_OBJECT
public:
    Slider();
    void mousePressEvent(QMouseEvent*);
signals:
    void sliderPressed(int);
};

#endif // SLIDER_H
