#include "results.h"
#include <QDebug>

Results::Results(QWidget*parent): QWidget(parent)
{
    //creating widgets for levels page
    results_page = new QWidget();
    results=new QLabel(
                    "*********************************************************"
                    "\n"
                    "\n"
                    "Thank you for playing virUS. We hope to spread the idea that health is not about nationality. "
                    "Health is not about race."
                    "Health is an issue that should be taken seriously across the whole world. "
                    "In the face of the novel virus, we shall stand together "
                    "in one line as there is one thing we deeply shared: humanity."
                    "\n"
                    "\n"
                    "*********************************************************");
    results->setWordWrap(true);
    results->setAlignment(Qt::AlignCenter);
    results->setStyleSheet("QLabel {font: 18pt  'Press Start K'; color: gold;}");

    score_results = new QLabel();
    score_results->setAlignment(Qt::AlignCenter);
    score_results->setStyleSheet("QLabel {font: 18pt  'Press Start K'; color:gold;}");

    resultspage_layout = new QGridLayout(results_page);
    quit_button = new QPushButton("QUIT");

    results_page->setStyleSheet("QLabel {font: 18pt  'Press Start K'; }");
    quit_button->setStyleSheet("QPushButton {font: 18pt  'Press Start K'; }");

    //set levels page widgets layout
    resultspage_layout->addWidget(results,1,1);
    resultspage_layout->addWidget(score_results,2,1);
    resultspage_layout->addWidget(quit_button,3,1);
    resultspage_layout->setContentsMargins(250,200,250,0);
    setLayout(resultspage_layout);
}

QPushButton *Results::get_button() const
{
    return quit_button;
}

void Results::setScore(int result_score)
{
    qDebug() << result_score;
    score_results->setText("This is your score: " + QString::number(result_score));
}
