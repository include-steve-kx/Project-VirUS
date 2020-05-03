#include "gametimer.h"

#include <QDebug>

GameTimer::GameTimer(QWidget* parent)
{
    game_timer = new QTimer();
    game_timer->setInterval(30000);

    QVBoxLayout* test_layout = new QVBoxLayout();

    text = new QLabel("1:00");
    text->setStyleSheet("QLabel {font: 15pt 'Press Start K'; color: darkGreen}");

    test_layout->addWidget(text);
    setLayout(test_layout);

}

GameTimer::~GameTimer()
{

}

void GameTimer::reset_timer()
{
    text->setText("1:00");
    text->setStyleSheet("QLabel {font: 15pt 'Press Start K'; color: darkGreen}");
    game_timer->start(60000);
}

QTimer *GameTimer::get_timer() const
{
    return game_timer;
}

void GameTimer::display_time()
{
    remaining_time = game_timer->remainingTime();
    text->setText("0:" + QString::number(remaining_time/1000));
    if (remaining_time > 10000){
        text->setStyleSheet("QLabel {font: 15pt 'Press Start K'; color: darkGreen}");
    }
    else {
        text->setText("0:0" + QString::number(remaining_time/1000));
        text->setStyleSheet("QLabel {font: 15pt 'Press Start K'; color: red}");
    }

    //qDebug() << remaining_time;
}
