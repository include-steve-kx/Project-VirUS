#include "titlescreen.h"
#include "doctor.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Titlescreen titlescreen_window;
    titlescreen_window.show();

    //set the size of the window
    titlescreen_window.setMinimumSize(1000,800);
    titlescreen_window.setMaximumSize(1000,800);

    return a.exec();
}
