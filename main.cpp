/****************************************************************************
** A Music Player is to play musics using Qt Framework (C++)
** Written by Agung Hartono
** This code is free to be used to anyone
** But please notice me if you want to distribute the whole part of this code
** Also any comments to the code, let me know
** email: agunghartono1000@gmail.com
****************************************************************************/

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;
    window.setWindowTitle("Music Player");
    window.show();
    return app.exec();
}
