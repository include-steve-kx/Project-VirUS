#ifndef PATIENT_H
#define PATIENT_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsEffect>
#include <QGraphicsColorizeEffect>
#include <QTimer>

#include <QPainter>
#include <QPixmap>

#include "doctor.h"
#include <QtMath>


class patient : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    patient(Doctor& doctor, int size, QWidget *parent = nullptr);
    ~patient();

    void paint(QPainter* painter, QStyleOptionGraphicsItem*, QWidget*);
    //patient code related functions
    void generate_code_string();
    QString get_code_string() const;

    int get_distance() const;
    QGraphicsColorizeEffect* get_effect();

public slots:
    void random_walk();
    void reset_parameters();

    void animation_controller();

    //change color transparency when within a certain distance from doctor
    void distance_calc();

private:
    int index = 0;
    QTimer* timer;
    QTimer* timer2;
    QTimer* timer3;
    //original position & time interval
//    int horizontal = 225 + std::rand() % 400;
//    int vertical = 225 + std::rand() % 400;
    int horizontal = 50 + std::rand() % 900;
    int vertical = 200 + std::rand() % 500;
    int interval = 1000 + std::rand() % 4000;
    //control random walk speed & directions
    double speed = 5;
    int horizontal_change = -1 + std::rand() % 3;
    int vertical_change = (horizontal_change == 0) ? -1 + std::rand() % 3 : 0;
    //control patient's animation
    int animation_state = 0;
    //distance with doctor
    Doctor* doctor_ptr;
    double distance = 1000;
    //patient code generated
    int string_size;
    QString code_string;
    //highlight effect
    QGraphicsColorizeEffect* effect;
};

#endif // PATIENT_H
