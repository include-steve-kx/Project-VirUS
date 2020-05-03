#ifndef LEVELS_H
#define LEVELS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Levels: public QWidget
{
    Q_OBJECT

public:
    Levels();

    QPushButton* get_button() const;
    QPushButton* get_easybutton() const;
    QPushButton* get_mediumbutton() const;
    QPushButton* get_hardbutton() const;
private:
    QPushButton* goback_button = nullptr;
    QPushButton* easy_button = nullptr;
    QPushButton* medium_button = nullptr;
    QPushButton* hard_button = nullptr;
};

#endif // LEVELS_H
