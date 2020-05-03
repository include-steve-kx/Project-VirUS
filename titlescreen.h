#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "levels.h"
#include "instructions.h"
#include "mainscreen.h"
#include "results.h"

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPalette>
#include <QTimer>

class Titlescreen : public QWidget
{
    Q_OBJECT


public:
    Titlescreen(QWidget*nparent = nullptr);
    ~Titlescreen();

    void paintEvent(QPaintEvent* e) override;
    QStackedWidget* get_stacked();



public slots:
    void get_titlescreen();
    void get_started();
    void get_levels();
    void get_instru();
    void get_results(int);
    void quit();

private:
    QWidget* title_page = nullptr;
//    Instructions* test_page;
//    Levels* test_page_2;
    Mainscreen* main_page = nullptr;
    Results* results_page = nullptr;
    QStackedWidget* titlescreen_stacked = nullptr;
    QPixmap background;
    QPalette palette;
    QSlider* volume = nullptr;
    QLabel* volume_label = nullptr;
    QMediaPlayer* result_screen_player = nullptr;
    QMediaPlayer* bgm_music=nullptr;
    QMediaPlaylist* bgm_playlist = nullptr;



};
#endif // TITLESCREEN_H
