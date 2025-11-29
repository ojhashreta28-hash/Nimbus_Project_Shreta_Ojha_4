#include <stdio.h>
#include <string.h>
#include "patient.h"


void addPatient(void){
    if(patient_count>= MAX_PATIENTS){
        printf("Patient list full.\n");
    return;
    }
Patient *p=&patients[patient_count];

printf("Enter ID:");
if(scanf("%d", &p->id)!=1){
    printf("Invalid ID.\n");
    while(getchar()!='\n');
    return;
}
while(getchar()!='\n');
printf("Enter Name: ");
fgets(p->name,NAME_LEN,stdin);
p->name[strcspn(p->name,"\n")]='\0';
printf("Enter Age:");
if(scanf("%d", &p->age)!=1){
    printf("Invalid age.\n");
    while(getchar()!='\n');
    return;
}
while (getchar()!='\n');
printf("Enter Disease:");
fgets(p->disease,DISEASE_LEN,stdin);
p->disease[strcspn(p->disease,"\n")]='\0';
printf("Enter Doctor:");
fgets(p->doctor, DOCTOR_LEN,stdin);
p->doctor[strcspn(p->doctor,"\n")]='\0';
printf("Enter Severity (1-5):");
if(scanf("%d",&p->severity)!=1)
{
    printf("Invalid Severity\n");
    while(getchar()!='\n');
    return;
    if(p->severity<1)p->severity=1;
    if(p->severity>5)p->severity=5;
    p->treatment_cost=calculateTreatmentCost(p->severity);
    printf("Patient added sucessfully.\n");
}
    patient_count++;

}
