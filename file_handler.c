#include<stdio.h>
#include "patient.h"

int saveToFile(const char *filename){
    FILE *f = fopen(filename,"wb");
    if(!f)return-1;
    if(fwrite(&patient_count,sizeof(int),1,f)!=1){fclose(f);
        return-1;}
        if(patient_count > 0){
            if(fwrite(patients,sizeof(Patient),patient_count,f)!=
            (size_t)patient_count){fclose(f);return-1;}
        }
        fclose(f);
        return 0;
}
int loadFromFile(const char*filename){
    FILE *f=fopen(filename,"rb");
    if(!f)return-1;
    int cnt=0;
    if(fread(&cnt,sizeof(int),1,f)!=1){fclose(f);return-1;}
    if(cnt<0||cnt>MAX_PATIENTS){fclose(f);return-1;}
    if(cnt>0){
        if(fread(patients,sizeof(Patient),cnt,f)!=(size_t)cnt){
            fclose(f);return-1;}
        }
        patient_count=cnt;
        fclose(f);
       return 0;
}