#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTextBlock>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QTextDocument>

class Instructions: public QWidget
{
public:
    Instructions();

    QPushButton* get_button();

private:
    QWidget* instru_page=nullptr;
    QLabel* text= nullptr;
    QVBoxLayout* instrupage_layout=nullptr;
    QPushButton* goback_button=nullptr;
};

#endif // INSTRUCTIONS_H
