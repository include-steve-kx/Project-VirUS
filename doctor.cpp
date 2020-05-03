#include "doctor.h"
#include <QDebug>

Doctor::Doctor(Score& score, Health& health, QWidget* parent): QWidget(parent)
{
    score_ptr = &score;
    health_ptr = &health;
    setPos(450, 450);
    setPixmap(QPixmap(":/doctor pictures/doctor front 1.png"));
}

void Doctor::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        animation_controller("left");
        setPos(QGraphicsPixmapItem::x()-10, QGraphicsPixmapItem::y());
    }
    else if (event->key()==Qt::Key_Right){
        animation_controller("right");
        setPos(QGraphicsPixmapItem::x()+10, QGraphicsPixmapItem::y());
    }
    else if (event->key()==Qt::Key_Up){
        animation_controller("up");
        setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y()-10);
    }
    else if (event->key()==Qt::Key_Down){
        animation_controller("down");
        setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y()+10);
    }
    else if (event->key()==Qt::Key_0){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_1){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_2){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_3){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_4){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_5){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_6){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_7){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_8){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_9){
        user_input += event->text();
        emit(number_pressed(user_input));
    }
    else if (event->key()==Qt::Key_Backspace){
        user_input = user_input.left(user_input.size()-1);
        //qDebug() << user_input;
        emit(number_pressed(user_input));
    }
    else if(event->key() == Qt::Key_Return){
        //qDebug() << user_input;
        emit enter_pressed(user_input);
        user_input = "";
    }
    else if(event->key() == Qt::Key_Escape){
        emit esc_pressed();
    }
}

double Doctor::get_x() const
{
    return QGraphicsPixmapItem::x();
}

double Doctor::get_y() const
{
    return QGraphicsPixmapItem::y();
}

void Doctor::animation_controller(QString direction)
{
    if(direction == "left"){
        if(animation_state == 0){
            setPixmap(QPixmap(":/doctor pictures/doctor left 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/doctor pictures/doctor left 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/doctor pictures/doctor left 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/doctor pictures/doctor left 4.png"));
            animation_state = 0;
        }
    }
    else if(direction == "right"){
        if(animation_state == 0){
            setPixmap(QPixmap(":/doctor pictures/doctor right 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/doctor pictures/doctor right 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/doctor pictures/doctor right 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/doctor pictures/doctor right 4.png"));
            animation_state = 0;
        }
    }
    else if(direction == "up"){
        if(animation_state == 0){
            setPixmap(QPixmap(":/doctor pictures/doctor back 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/doctor pictures/doctor back 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/doctor pictures/doctor back 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/doctor pictures/doctor back 4.png"));
            animation_state = 0;
        }
    }
    else if(direction == "down"){
        if(animation_state == 0){
            setPixmap(QPixmap(":/doctor pictures/doctor front 1.png"));
            ++animation_state;
        }
        else if(animation_state == 1){
            setPixmap(QPixmap(":/doctor pictures/doctor front 2.png"));
            ++animation_state;
        }
        else if(animation_state == 2){
            setPixmap(QPixmap(":/doctor pictures/doctor front 3.png"));
            ++animation_state;
        }
        else if(animation_state == 3){
            setPixmap(QPixmap(":/doctor pictures/doctor front 4.png"));
            animation_state = 0;
        }
    }
}

Score *Doctor::get_score_ptr() const
{
    return score_ptr;
}

Health *Doctor::get_health_ptr() const
{
    return health_ptr;
}

