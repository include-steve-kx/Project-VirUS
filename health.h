#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem* parent=0);
    void decrease_health();
    void reset_health();
    int get_health();


private:
    int health;
    QMediaPlayer* health_decrease_player = nullptr;
};

#endif // HEALTH_H
