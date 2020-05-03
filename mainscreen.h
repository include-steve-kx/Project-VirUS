#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "doctor.h"
#include "health.h"
#include "score.h"
#include "gametimer.h"
#include "patient.h"
#include "patients.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QGraphicsWidget>

class Mainscreen: public QWidget
{
    Q_OBJECT

public:
    Mainscreen(QWidget *parent = nullptr);
    ~Mainscreen();
    //void paintEvent(QPaintEvent* e) override;

signals:
    void escape_key_pressed();
    void time_out(int);

    void easy_value(int);
    void medium_value(int);
    void hard_value(int);

public slots:
    void start_game();
    void clean_game();
    void escape_game();
    void time_out_handler();

    void easy_value_handler();
    void medium_value_handler();
    void hard_value_handler();

private:
    QPixmap background;
    QPalette palette;
    QTimer* patient_generating_timer;

    QVBoxLayout* mainpage_layout=nullptr;
    QGraphicsScene* scene=nullptr;
    QGraphicsView * view=nullptr;
    QGraphicsTextItem* patient_code=nullptr;
    QGraphicsTextItem* user_input=nullptr;
    patients* new_patients=nullptr;

    Doctor* doctor=nullptr;
    Health* health=nullptr;
    Score* score = nullptr;
    GameTimer* game_timer = nullptr;
    QTimer* update_timer = nullptr;
};

#endif // MAINSCREEN_H
