#include "instructions.h"

Instructions::Instructions()
{
    //creating widgets for levels page
    instru_page = new QWidget();
    goback_button=new QPushButton("I'm Ready");
    goback_button->setStyleSheet("QPushButton{font: 12pt  'Press Start K';}");
    text=new QLabel("*********************************************************"
                    "\n"
                    "\n"
                    "Welcome to virUS, you are now the doctor who has the power to cure patients suffering from the COVID-19 virus."
                    "This is a chance to save US as human beings. "
                    "To begin your combat, press START or choose which difficulty level you like. "
                    "Use the arrow keys to control the doctor. "
                    "As soon as walking close enough to a patient, the selected patient will be highlighted in red."
                    "Type in the code displayed at the bottom of the screen to defeat virus existed in the patient."
                    "Your score will be increased if you input the right code, else you will lose your health."
                    "The goal of this game is to heal as many patients as possible "
                    "without sacrificing yourself within the 1-minute game time."
                    " Are you ready?"
                    "\n"
                    "\n"
                    "*********************************************************");
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignJustify);
    text->setMargin(100);
    text->setStyleSheet("QLabel {font: 18pt  'Times New Roman'; color: gold; }");
    instrupage_layout = new QVBoxLayout(instru_page);

    //set levels page widgets layout
    instrupage_layout->addWidget(text);
    instrupage_layout->addWidget(goback_button);
    instrupage_layout->setContentsMargins(220,110,200,0);
    setLayout(instrupage_layout);
}

QPushButton *Instructions::get_button()
{
    return goback_button;
}
