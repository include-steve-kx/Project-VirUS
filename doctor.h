#ifndef DOCTOR_H
#define DOCTOR_H

#include "score.h"
#include "health.h"

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include <QGraphicsTextItem>


class Doctor: public QWidget, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Doctor(Score& score, Health& health, QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    double get_x() const;
    double get_y() const;
    void animation_controller(QString direction);
    Score* get_score_ptr() const;
    Health* get_health_ptr() const;

signals:
    void number_pressed(QString);
    void enter_pressed(QString);
    void esc_pressed();
private:
    QString user_input = "";
    int animation_state = 0;
    Score* score_ptr = nullptr;
    Health* health_ptr = nullptr;
};

#endif // DOCTOR_H
