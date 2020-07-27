#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label.setText("<h1><B>Music Player</h1></B>");
    label.setAlignment(Qt::AlignHCenter);

    progressbar.setStyleSheet("QProgressBar {border: 2px solid grey;"
                              "border-radius: 5px;"
                              "text-align: center;}");

    slider.setOrientation(Qt::Horizontal);

    open.setIcon(style()->standardPixmap(QStyle::SP_DirIcon));
    play.setIcon(style()->standardPixmap(QStyle::SP_MediaPlay));
    pause.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    stop.setIcon(style()->standardPixmap(QStyle::SP_MediaStop));
    soundbutton.setIcon(style()->standardPixmap(QStyle::SP_MediaVolume));

    vboxlayout.addWidget(&label);
    vboxlayout.addWidget(&progressbar);
    vboxlayout.addWidget(&slider);

    hboxlayout.addWidget(&open);
    hboxlayout.addWidget(&play);
    hboxlayout.addWidget(&pause);
    hboxlayout.addWidget(&stop);
    hboxlayout.addStretch(0);
    hboxlayout.addWidget(&soundbutton);

    vboxlayout.addLayout(&hboxlayout);
    vboxlayout.addWidget(&listwidget);

    mediaplayer.setPlaylist(&mediaplaylist);
    mediaplaylist.setPlaybackMode(QMediaPlaylist::Loop);

    setLayout(&vboxlayout);

    connect(&open, SIGNAL(clicked()), this, SLOT(OpenFile()));
    connect(&play, SIGNAL(clicked()), &mediaplayer, SLOT(play()));
    connect(&pause, SIGNAL(clicked()), &mediaplayer, SLOT(pause()));
    connect(&stop, SIGNAL(clicked()), &mediaplayer, SLOT(stop()));

    connect (&mediaplayer, &QMediaPlayer::durationChanged, &slider, &QSlider::setMaximum);
    connect (&mediaplayer, &QMediaPlayer::durationChanged, &progressbar, &QProgressBar::setMaximum);
    connect (&mediaplayer, &QMediaPlayer::positionChanged, &slider, &QSlider::setValue);
    connect (&mediaplayer, &QMediaPlayer::positionChanged, &progressbar, &QProgressBar::setValue);
    connect (&slider, &QSlider::sliderMoved, &mediaplayer, &QMediaPlayer::setPosition);

    connect(&listwidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(FromListWidget(QListWidgetItem*)));
    connect(&mediaplaylist, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(OnMediaChanged(QMediaContent)));
//    connect(&slider, &Slider::sliderPressed, this, &Widget::SliderOnTest);
    connect(&slider, &Slider::sliderPressed, &mediaplayer, &QMediaPlayer::setPosition);
//    connect(&slider, SIGNAL())
}

Widget::~Widget()
{
}

void Widget::OpenFile()
{
    QStringList filestringlist = QFileDialog::getOpenFileNames(this, "Open Music Files", "", "Music Files (*.mp3)");

    if (!filestringlist.isEmpty())
    {
        QFileInfo fileinfo;
        foreach (QString filestring, filestringlist) {
            mediaplaylist.addMedia(QUrl::fromLocalFile(filestring));
            fileinfo=filestring;
            listwidget.addItem(fileinfo.fileName());
        }
    }
}

void Widget::FromListWidget(QListWidgetItem *listwidgetitem)
{
    mediaplaylist.setCurrentIndex(listwidget.row(listwidgetitem));
}

void Widget::OnMediaChanged(QMediaContent content)
{
    setWindowTitle(content.canonicalUrl().fileName());
}

void Widget::SliderOnTest(int number)
{
    qDebug()<<number;
}

