#include "mainscreen.h"

#include <cstdlib>
#include <ctime>

#include <QLineEdit>
#include <QGraphicsTextItem>
#include <QDebug>

Mainscreen::Mainscreen(QWidget *parent)
{
    Q_UNUSED(parent);

    //set main game background image
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setSceneRect(280, 200, 400, 400);
    QPixmap background(":/Pictures/main_game_bg-min.png");
    view->setBackgroundBrush(background);

    //set the main page loyout
    mainpage_layout = new QVBoxLayout();
    setLayout(mainpage_layout);

    //add health to the game
    health = new Health();
    health->setPos(30, 50);
    scene->addItem(health);

    //add score to the game
    score = new Score();
    score->setPos(30, 80);
    scene->addItem(score);

    //add patient code bar
    patient_code = new QGraphicsTextItem();
    scene->addItem(patient_code);
    patient_code->setPlainText(QString("Patient code:"));
    patient_code->setPos(30, 730);
    patient_code->setFont(QFont("Press Start K", 15));

    //add user input bar
    user_input = new QGraphicsTextItem();
    scene->addItem(user_input);
    user_input->setPlainText(QString("User input:"));
    user_input->setFont(QFont("Press Start K",15));
    user_input->setPos(530, 730);

    //add game timer to the game
    game_timer = new GameTimer();
    game_timer->setGeometry(780, 50, 100, 50);
    scene->addWidget(game_timer);
    update_timer = new QTimer();
    update_timer->start(1000);
    connect(update_timer, SIGNAL(timeout()), game_timer, SLOT(display_time()));
    connect(game_timer->get_timer(), SIGNAL(timeout()), this, SLOT(time_out_handler()));
    connect(game_timer->get_timer(), SIGNAL(timeout()), this, SLOT(clean_game()));
    qDebug() << "Timers are driving me nuts!";

    mainpage_layout->addWidget(view);
}

Mainscreen::~Mainscreen()
{

}

//void Mainscreen::paintEvent(QPaintEvent *e)
//{
//    Q_UNUSED(e);
//    QPainter painter(this);
//    //painter.begin(this);
//    background = QPixmap(":/Pictures/main_game_bg.png");
//    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
//    painter.setBackground(background);
//    painter.setBrush(background);
////    palette.setBrush(QPalette::Background, background);
////    this->setPalette(palette);
//    //painter.end();
//}

void Mainscreen::start_game()
{

    //reset game timer
    game_timer->reset_timer();

    //add doctor to the game
    doctor = new Doctor(*score, *health);
    //doctor->setPos(100,100); //coordinates
    scene->addItem(doctor);
    //make the item focusable
    doctor->QGraphicsPixmapItem::setFlag(QGraphicsItem::ItemIsFocusable);
    doctor->QGraphicsPixmapItem::setFocus();

    connect(doctor, SIGNAL(esc_pressed()), this, SLOT(escape_game()));
    connect(doctor, SIGNAL(esc_pressed()), this, SLOT(clean_game()));

    //add patients to the game
    std::srand(std::time(0));
    new_patients = new patients(*scene, *doctor, *patient_code, *user_input);
    connect(this, SIGNAL(easy_value(int)), new_patients, SLOT(set_patients_string_size(int)));
    connect(this, SIGNAL(medium_value(int)), new_patients, SLOT(set_patients_string_size(int)));
    connect(this, SIGNAL(hard_value(int)), new_patients, SLOT(set_patients_string_size(int)));
    patient_generating_timer = new QTimer();
    QObject::connect(patient_generating_timer, SIGNAL(timeout()), new_patients, SLOT(add_patient()));
    patient_generating_timer->start(1000);

    QObject::connect(new_patients, SIGNAL(zero_health()), this, SLOT(time_out_handler()));
    QObject::connect(new_patients, SIGNAL(zero_health()), this, SLOT(clean_game()));
    qDebug() << "Patients are driving me nuts!";
}

void Mainscreen::clean_game()
{
    patient_generating_timer->stop();
    game_timer->get_timer()->stop();
    new_patients->remove_all_patients();
    score->reset_score();
    health->reset_health();
    scene->removeItem(doctor);
    //doctor->deleteLater();
    new_patients->deleteLater();
    qDebug() << "step 2";
}

void Mainscreen::escape_game()
{
    qDebug() << "step 3";
    emit escape_key_pressed();
}

void Mainscreen::time_out_handler()
{
    qDebug() << "time out!!!";
    emit time_out(score->get_score());
}

void Mainscreen::easy_value_handler()
{
    emit easy_value(3);
}

void Mainscreen::medium_value_handler()
{
    emit medium_value(6);
}

void Mainscreen::hard_value_handler()
{
    emit hard_value(9);
}
