#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"

void updatePatient(int index){
    if(index<0 || index>=patient_count){printf("invalid index.\n");return;}
    Patient*p=&patients[index];
    printf("Updating patient ID %d (leave blank ot keep current)\n",p->id);
    
    char buffer[128];

    printf("Current name :%s\nNew name:",p->name);
    fgets(buffer,sizeof(buffer),stdin);
    
    if(buffer[0]!='\n'){buffer[strcspn(buffer,"\n")]='\0';strncpy(p->name,buffer,NAME_LEN);}

    printf("Current age :%d\nNew age(0 to keep):",p->age);
    if(fgets(buffer,sizeof(buffer),stdin)){
        int val=atoi(buffer);
        if(val>0)p->age=val;
    }

    printf("Current disease:%s\nNew disease:",p->disease);
    fgets(buffer,sizeof(buffer),stdin);

    if(buffer[0]!='\n'){buffer[strcspn(buffer,"\n")]='\0';strncpy(p->disease,buffer,DISEASE_LEN);}

    printf("Current doctor:%s\nNew doctor:",p->doctor);
    fgets(buffer,sizeof(buffer),stdin);
    
    if(buffer[0]!='\n'){buffer[strcspn(buffer,"\n")]='\0';strncpy(p->doctor,buffer,DOCTOR_LEN);}

    printf("Current severity:%d\nNew severity(1-5,0 to keep):",p->severity);
    if(fgets(buffer,sizeof(buffer),stdin)){

        int s=atoi(buffer);
        if(s>=1 && s<=5){
            p->severity=s;
            p->treatment_cost=calculateTreatmentCost(s);

        }
       
    }
     printf("Patient updated.\n");

}