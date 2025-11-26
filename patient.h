#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100
#define NAME_LEN 50
#define DISEASE_LEN 100
#define DOCTOR_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    char disease[DISEASE_LEN];
    char doctor[DOCTOR_LEN];
    int severity;
    float treatment_cost;

}Patient;

extern Patient patients[MAX_PATIENTS];
extern int patient_count;

void addPatient();
void displayPatients();
int searchPatientByID(int id);
int searchPatientByName(const char*name);
void updatePatient(int index);
float calculateTreatmentCost(int severity);
int saveToFile(const char*filename);
int loadFromFile(const char*filename);

#endif