#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QGraphicsItem>
#include <QTimer>
#include <QFont>
#include <QGraphicsTextItem>

class GameTimer: public QLabel
{
    Q_OBJECT;
public:
    GameTimer(QWidget* parent = nullptr);
    ~GameTimer();
    void reset_timer();
    QTimer* get_timer() const;
public slots:
    void display_time();
private:
    QLabel* text = nullptr;
    QTimer* game_timer = nullptr;
    int remaining_time;
};

#endif // GAMETIMER_H
