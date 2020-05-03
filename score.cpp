#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent)
{
    Q_UNUSED(parent);
    score=0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("Press Start K",15));

}

void Score::increase_score()
{
    score=score+5;
    setPlainText(QString("Score: ") + QString::number(score));
    score_increase_player = new QMediaPlayer();
    score_increase_player->setMedia(QUrl("qrc:/music/collide_sussess.wav"));
    score_increase_player->setVolume(30);
    score_increase_player->play();
}

void Score::reset_score()
{
    score = 0;
    setPlainText(QString("Score: 0"));
}

int Score::get_score()
{
    return score;
}
