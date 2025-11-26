#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

Patient patients[MAX_PATIENTS];
int patient_count=0;

int main(){
    int choice;
    loadFromFile("patients.dat");

    while(1){
        printf("\nHospital Patient Record System\n");
        printf("1.Add patient\n");
        printf("2.Display all patients\n");
        printf("3.Search patient by ID\n");
        printf("4.Search patient by Name\n");
        printf("5.Update patient\n");
        printf("6.Save to file\n");
        printf("Load from file\n");
        printf("8.Exit\n");
        printf("Enter choice:");
        if(scanf("%d",&choice)!= 1){while(getchar()!='\n');
                printf("Invalid input.\n");
                continue;
            
        }
        while(getchar()!='\n');

        switch(choice){
            case 1:{
                addPatient();
                break;
            }
            case 2:{
                displayPatients();
                break;
            }
            case 3:{
                int id;
                printf("Enter ID:");
                if(scanf("%d",&choice)!= 1){while(getchar()!='\n');
                printf("Invalid.\n");
                break;
                }
                int idx=searchPatientByID(id);
                if(idx>=0){
                    printf("Patient found:\n");
                    printf("ID:%d\nName:%s\nAge:%d\nDisease:%s\nDoctor:%s\nSeverity:%d\nCost:%.2f\n",patients[idx].id,patients[idx].name,patients[idx].age,patients[idx].disease,patients[idx].doctor,patients[idx].severity,patients[idx].treatment_cost);

                }
                else{
                    printf("Patient with ID %d not found.\n",id);
                
                }
                break;
            }    
            case 4:{
                char name[NAME_LEN];
                printf("Enter name:");
                fgets(name,NAME_LEN,stdin);
                name[strcpn(name,"\n")]='\0';
                int idx=searchPatientByName(name);
                if(idx>=0){
                    printf("Patient found at index%d.\n",idx);
                    displayPatients();
                }
                else{
                    printf("No match for '%s'\n",name);
                }
                break;
            }
            case 5:{
                int id;
                printf("Enter ID to update:");
                if(scanf("%d",&id)!= 1){while(getchar()!='\n');
                printf("Invalid.\n");
                break;
                }
                int idx=searchPatientByID(id);
                if (idx >= 0) {
                    updatePatient(idx);
                }    
                else {
                    printf("Patient not found.\n");
                }    
                break;
            }
            case 6:{
                if (saveToFile("patients.dat")==0) {
                    printf("Saved successfully.\n"); 
                }    
                else {
                    printf("Error saving.\n"); 
                }    
                break;
            }    
            case 7:{
                if (loadFromFile("patients.dat")==0){
                    printf("Loaded successfully.\n");
                }     
                else{
                    printf("Error loading.\n"); 
                }
                break;
            }    
            case 8:{
                 saveToFile("patients.dat"); 
                 printf("Exiting.\n");
                  exit(0);
            }      
            default:{
                 printf("Invalid choice.\n");
            }     
}
}
    return 0;

}

