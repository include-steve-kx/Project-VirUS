#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>


class Results: public QWidget
{
    Q_OBJECT;
public:
    Results(QWidget*parent=0);
    QPushButton* get_button() const;
    void setScore(int score);

private:
    QLabel* results = nullptr;
    QLabel* score_results = nullptr;
    QWidget* results_page=nullptr;
    QGridLayout* resultspage_layout=nullptr;
    QPushButton* quit_button=nullptr;
};

#endif // RESULTS_H
