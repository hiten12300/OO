#include "Tesla.h"

Tesla::Tesla(): model(0), Car(0), batteryPercentage(100) {};
Tesla::Tesla(char model, int price): model(model), Car(price), batteryPercentage(100) {}

int Tesla::get_model() { return this->model; }
int Tesla::set_model(char model) { this->model = model; }

int Tesla::get_batteryPercentage() { return this->batteryPercentage; }
int Tesla::set_batteryPercentage(int batteryPercentage) { 

    if (batteryPercentage < 0){
        this->batteryPercentage = 0;
    } 
    else if(batteryPercentage > 100){
        this->batteryPercentage = 100;
    } 
    else{
        this->batteryPercentage = batteryPercentage;
    }
}
void Tesla::chargeBattery(int mins) {

    for (int i = 0; i < mins; i++){

        if (batteryPercentage >= 100){
            break;
        }

        set_batteryPercentage((batteryPercentage + 0.5));
    }
}

void Tesla::drive(int kms) {
    for (int i = 0; i < kms; i++){

        if (batteryPercentage <= 0){
            break;
        } 

        if ((i+1) % 5 == 0){
            set_batteryPercentage((batteryPercentage - 1));
        }

        emissions += 74;
    }
};