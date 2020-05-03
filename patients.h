#ifndef PATIENTS_H
#define PATIENTS_H

#include "patient.h"
#include <QWidget>
#include <QVector>
#include <QGraphicsScene>
#include <QTimer>

#include "doctor.h"

#include <QGraphicsTextItem>

class patients : public QObject
{
    Q_OBJECT
public:
    patients();
    patients(QGraphicsScene& scene, Doctor& doctor, QGraphicsTextItem& patient_code, QGraphicsTextItem& user_input);
    QString get_nearest_patient_string() const;
    void remove_all_patients();
signals:
    void zero_health();
public slots:
    void add_patient();
    void update_nearest_patient_string();
    void update_user_input(QString);
    void check_input(QString);
    void highlight_effect();
    void set_patients_string_size(int);
private:
    QVector<patient*> roster;
    QGraphicsScene* scene_ptr;
    Doctor* doctor_ptr;
    QGraphicsTextItem* patient_code_ptr;
    QGraphicsTextItem* user_input_ptr;

    QTimer* timer1;
    int nearest_distance = 1000;
    int nearest_index = 0;
    QString nearest_patient_string;
    double distance_boundary = 70;

    int patients_string_size;
};

#endif // PATIENTS_H
