#include "health.h"
#include <QFont>
#include <QDebug>

Health::Health(QGraphicsItem* parent)
{
    health = 100;
    //display health on the game scene
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("Press Start K",15));
}

void Health::decrease_health()
{
    health=health-5;
    setPlainText(QString("Health: ") + QString::number(health));
    health_decrease_player = new QMediaPlayer();
    health_decrease_player->setMedia(QUrl("qrc:/music/collide_failure.wav"));
    health_decrease_player->setVolume(30);
    health_decrease_player->play();

    if (health <= 30){
        setDefaultTextColor(Qt::yellow);
    }
    if (health <= 15){
        setDefaultTextColor(Qt::red);
    }
}

void Health::reset_health()
{
    health = 100;
    setPlainText(QString("Health: 100"));
}

int Health::get_health()
{
    return health;
}
