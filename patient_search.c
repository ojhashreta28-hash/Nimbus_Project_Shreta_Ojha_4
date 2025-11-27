# include <string.h>
# include "patient.h"

int searchPatientByID(int id){
    for(int i=0; i<patient_count; ++i)if(patients[i].id==id) return i;
    return -1;
}

int searchPatientByName(const char*name){
    for(int i=0; i<patient_count; ++i)if(strcmp(patients[i].name,name)==0)return i;
    return -1;
}