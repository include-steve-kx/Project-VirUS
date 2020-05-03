#include "patient.h"
#include <QDebug>

patient::patient(Doctor& doctor, int size, QWidget *parent) : QObject(parent), QGraphicsPixmapItem()
{
    doctor_ptr = &doctor;
    //set initial position
    setPos(600, 600);
    string_size = size;
    generate_code_string();
    //set highlight effect
    effect = new QGraphicsColorizeEffect();
    effect->setColor(Qt::red);
    effect->setEnabled(false);
    this->QGraphicsPixmapItem::setGraphicsEffect(effect);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(reset_parameters()));
    timer->start(interval);

    timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(random_walk()));
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(animation_controller()));
    timer2->start(300);

    timer3 = new QTimer();
    QObject::connect(timer3, SIGNAL(timeout()), this, SLOT(distance_calc()));
    timer3->start(50);

}

patient::~patient()
{

}

void patient::paint(QPainter *painter, QStyleOptionGraphicsItem *, QWidget *)
{
    Q_UNUSED(painter);
}

void patient::generate_code_string()
{
    for (int i = 0; i < string_size; ++i){
        int temp = std::rand() % 10;
        code_string += QString::number(temp);
    }
}

QString patient::get_code_string() const
{
    return code_string;
}

int patient::get_distance() const
{
    return distance;
}



void patient::distance_calc()
{
    //double distance = qSqrt(x() * doctor_ptr->get_x() + y() * doctor_ptr->get_y());
    //double doc_x = doctor_ptr->get_x();
    //double doc_y = doctor_ptr->get_y();
    distance = qSqrt(qPow(horizontal - doctor_ptr->get_x(), 2) + qPow(vertical - doctor_ptr->get_y(), 2));
    //qDebug() << "doc:( "<<doc_x<<" , "<<doc_y<<" ), pat:( " << horizontal<<" , "<<vertical<<" ), "<< "dist: " << distance;
}

QGraphicsColorizeEffect* patient::get_effect()
{
    return effect;
}

void patient::reset_parameters(){
    interval = 1000 + std::rand() % 4000;
    timer->setInterval(interval);

    if(horizontal <= 50){
        horizontal_change = std::rand() % 2;
        if(vertical <= 500){
            vertical_change = 0;
        }
        else if(vertical >= 700){
            vertical_change = 0;
        }
        else{
            vertical_change = (horizontal_change == 0) ? -1 + std::rand() % 3 : 0;
        }
    }
    else if(horizontal >= 950){
        horizontal_change = -1 + std::rand() % 2;
        if(vertical <= 500){
            vertical_change = 0;
        }
        else if(vertical >= 700){
            vertical_change = 0;
        }
        else{
            vertical_change = (horizontal_change == 0) ? -1 + std::rand() % 3 : 0;
        }
    }
    else{
        horizontal_change = -1 + std::rand() % 3;
        vertical_change = (horizontal_change == 0) ? -1 + std::rand() % 3 : 0;
    }
}


void patient::animation_controller()
{
    if(horizontal_change > 0){
        if(animation_state == 0){
            setPixmap(QPixmap(":/patient pictures/model 1 right 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/patient pictures/model 1 right 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/patient pictures/model 1 right 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/patient pictures/model 1 right 4.png"));
            animation_state = 0;
        }
    }
    else if(horizontal_change < 0){
        if(animation_state == 0){
            setPixmap(QPixmap(":/patient pictures/model 1 left 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/patient pictures/model 1 left 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/patient pictures/model 1 left 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/patient pictures/model 1 left 4.png"));
            animation_state = 0;
        }
    }
    else if(vertical_change > 0){
        if(animation_state == 0){
            setPixmap(QPixmap(":/patient pictures/model 1 front 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/patient pictures/model 1 front 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/patient pictures/model 1 front 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/patient pictures/model 1 front 4.png"));
            animation_state = 0;
        }
    }
    else if(vertical_change < 0){
        if(animation_state == 0){
            setPixmap(QPixmap(":/patient pictures/model 1 back 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/patient pictures/model 1 back 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/patient pictures/model 1 back 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/patient pictures/model 1 back 4.png"));
            animation_state = 0;
        }
    }
}

void patient::random_walk(){
    horizontal += horizontal_change * speed;
    vertical += vertical_change * speed;
    setPos(horizontal, vertical);
}
