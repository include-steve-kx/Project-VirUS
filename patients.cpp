#include "patients.h"
#include <QDebug>

patients::patients()
{

}

patients::patients(QGraphicsScene& scene, Doctor& doctor, QGraphicsTextItem& patient_code, QGraphicsTextItem& user_input)
{
    scene_ptr = &scene;
    doctor_ptr = &doctor;
    patient_code_ptr = &patient_code;
    user_input_ptr = &user_input;
    timer1 = new QTimer();
    QObject::connect(timer1, SIGNAL(timeout()), this, SLOT(update_nearest_patient_string()));
    QObject::connect(timer1, SIGNAL(timeout()), this, SLOT(highlight_effect()));
    timer1->start(50);

    QObject::connect(doctor_ptr, SIGNAL(number_pressed(QString)), this, SLOT(update_user_input(QString)));
    QObject::connect(doctor_ptr, SIGNAL(enter_pressed(QString)), this, SLOT(check_input(QString)));
}


void patients::add_patient()
{
    if(roster.size() < 10){
        patient* new_patient = new patient(*doctor_ptr, patients_string_size);
        scene_ptr->addItem(new_patient);
        roster.push_back(new_patient);
        //qDebug() << roster.size() << " patient is created!";
    }
}

QString patients::get_nearest_patient_string() const
{
    return nearest_patient_string;
}

void patients::remove_all_patients()
{
    for(int i = 0; i < roster.size(); ++i){
        //qDebug() << i+1 << " should be removed!!!";
        scene_ptr->removeItem(roster[i]);
        //roster[i]->deleteLater();
    }
}

void patients::update_user_input(QString user_input)
{
    user_input_ptr->setPlainText((QString("User input:")) + user_input);
}

void patients::check_input(QString user_input)
{
    if(user_input == roster[nearest_index]->get_code_string()){
        user_input_ptr->setPlainText("User input: Correct!!!");
        scene_ptr->removeItem(roster[nearest_index]);

        // Here's where it gets buggy. It won't let me delete anything
        delete roster[nearest_index];

        roster.remove(nearest_index);
        doctor_ptr->get_score_ptr()->increase_score();
    }
    else{
        user_input_ptr->setPlainText("User input: Wrong!!!");
        doctor_ptr->get_health_ptr()->decrease_health();
    }
    if(doctor_ptr->get_health_ptr()->get_health() == 0){
        qDebug() << "step 1";
        emit zero_health();
    }
}

void patients::highlight_effect()
{
    if(nearest_distance < distance_boundary){
        roster[nearest_index]->get_effect()->setEnabled(true);
    }
    else{
        for(int i = 0; i < roster.size(); ++i){
            roster[i]->get_effect()->setEnabled(false);
        }
        //qDebug() << "decolorized!!!";
    }
}

void patients::set_patients_string_size(int size)
{
    patients_string_size = size;
}

void patients::update_nearest_patient_string()
{
    nearest_distance = 1000;
    nearest_index = 0;
    for(int i = 0; i < roster.size(); ++i){
        int temp_distance = roster[i]->get_distance();
        if(temp_distance < nearest_distance){
            nearest_distance = temp_distance;
            nearest_index = i;
        }
    }
    //qDebug() << "nearest_index: " << nearest_index << "nearest_distance: " << nearest_distance;
    if(nearest_distance < distance_boundary){
        //qDebug() << "Patient code: " << roster[nearest_index]->get_code_string();
        patient_code_ptr->setPlainText((QString("Patient code:")) + roster[nearest_index]->get_code_string());
    }
    else{

        patient_code_ptr->setPlainText("Patient code: too far away!!!");
    }
//    if(nearest_distance < distance_boundary) nearest_patient_string = roster[nearest_index]->get_code_string();
    //    else nearest_patient_string = "too far away!";
}

