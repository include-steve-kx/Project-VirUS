#include "levels.h"

Levels::Levels()
{
    //creating widgets for levels page
    QWidget* levels_page = new QWidget();
    easy_button = new QPushButton("EASY");
    easy_button->setFixedSize(200,60);
    easy_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    medium_button = new QPushButton("MEDIUM");
    medium_button->setFixedSize(200,60);
    medium_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    hard_button = new QPushButton("HARD");
    hard_button->setFixedSize(200,60);
    hard_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    goback_button = new QPushButton("Go Back to Home");
    goback_button->setFixedSize(200,60);
    goback_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    QVBoxLayout* levelpage_layout = new QVBoxLayout(levels_page);

    //set levels page widgets layout
    levelpage_layout->addWidget(easy_button);
    levelpage_layout->addWidget(medium_button);
    levelpage_layout->addWidget(hard_button);
    levelpage_layout->addWidget(goback_button);
    levelpage_layout->setContentsMargins(200,200,200,0);
    levelpage_layout->setAlignment(Qt::AlignCenter);
    setLayout(levelpage_layout);

}

QPushButton *Levels::get_button() const
{
    return goback_button;
}

QPushButton *Levels::get_easybutton() const
{
    return easy_button;
}

QPushButton *Levels::get_mediumbutton() const
{
    return medium_button;
}

QPushButton *Levels::get_hardbutton() const
{
    return hard_button;
}
