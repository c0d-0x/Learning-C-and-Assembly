#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int day, mon, yr;
} date;

typedef struct{
    long ID;
    char Fname[15];
    char Lname[15];
    date dob;
    date admisDate;
    char field[35];
    char addr[35];
    } STDE;


void Createstudent(STDE * ptr){
    int n, i;
    printf("Number of Students: ");
    scanf("%d", &n);
        printf("ID: ");
        scanf("%ld", &ptr[i].ID);

        printf("\nFirst Name: ");
        scanf("%s", ptr[i].Fname);

        printf("\nLast Name: ");
        scanf("%s", ptr[i].Lname);
      
        printf("\nDate of Birth(day/mon/yr): ");
        scanf("%d/%d/%d", &ptr[i].dob.day, &ptr[i].dob.mon, &ptr[i].dob.yr );
        printf("%d/%d/%d", ptr[i].dob.day, ptr[i].dob.mon, ptr[i].dob.yr );

        printf("\nDate of Admission(day/mon/yr): ");
        scanf("%d/%d/%d",&ptr[i].admisDate.day, &ptr[i].admisDate.mon, &ptr[i].admisDate.yr );
        printf("%d/%d/%d",ptr[i].admisDate.day, ptr[i].admisDate.mon, ptr[i].admisDate.yr );

        printf("\nField of studies: ");
        scanf("%s[^\n]", ptr[i].field);
        printf("%s", ptr[i].field);
        printf("\nAddress: ");
        scanf("%s", ptr[i].addr);




}


int main(void){
    int option;
        STDE * ptr;
    printf("\t\t[!] Options\n");
    printf("\t\t\t[1] List All Students\n");
    printf("\t\t\t[2] Create Student Profile\n");
    printf("\t\t\t[3] Edit Student Profile\n");
    printf("\t\t\t[4] Search for a Student\n");

    scanf("%d", &option);

    switch (option) {
        case 1:
            break;
        case 2:
            Createstudent(ptr);
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("Choose an option from 1-4");
 }
    return 0;

}

