#ifndef WIDGET_H
#define WIDGET_H

#include "Slider.h"
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QLabel>
#include <QProgressBar>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QToolButton>
#include <QStyle>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void OpenFile();
    void FromListWidget(QListWidgetItem*);
    void OnMediaChanged(QMediaContent);
    void SliderOnTest (int);
private:
    QVBoxLayout vboxlayout;
    QHBoxLayout hboxlayout;
    QMediaPlayer mediaplayer;
    QMediaPlaylist mediaplaylist;
    QLabel label;
    QProgressBar progressbar;
    Slider slider;
    QToolButton open, play, pause, stop, soundbutton;
    QListWidget listwidget;
};
#endif // WIDGET_H
