#include "patient.h"

float calculateTreatmentCost(int severity){
    float base = 500.0f;
    float multiplier=0.0f;
    switch(severity){
        case 1:multiplier=1.0f;
        break;
        case 2:multiplier=1.5f;
        break;
        case 3:multiplier=2.0f;
        break;
        case 4:multiplier=3.0f;
        break;
        case 5:multiplier=5.0f;
        break;
        default:multiplier=1.0f;
        break;
    }
    return base*multiplier;
}