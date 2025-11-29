#include<stdio.h>
#include "patient.h"

void displayPatients(){
    if(patient_count==0){
        printf("No patients to display.\n");
        return;
    }
for(int i=0;i<patient_count;i++){
    Patient *p=&patients[i];
    printf("--------------------\n");
    printf("ID: %d\n", p->id);
    printf("Name:%s\n",p->name);
    printf("Age:%d\n",p->age);
    printf("Disease:%s\n",p->disease);
    printf("Doctor:%s\n",p->doctor);
    printf("Severity:%d\n",p->severity);
    printf("Treatment cost: %.2f\n", p->treatment_cost);
}
}
