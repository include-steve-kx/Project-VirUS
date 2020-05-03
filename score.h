#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent=0);
    void increase_score();
    void reset_score();
    int get_score();

private:
    int score;
    QMediaPlayer* score_increase_player = nullptr;
};

#endif // SCORE_H
