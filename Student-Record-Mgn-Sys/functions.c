#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int DD, MM, YY;
} date;

typedef struct student {
  int ID;
  char Lname[15];
  char Fname[15];
  date DoB;
  char major[20];
  date yr_oG; // year of graduation
} student;

typedef struct student_t {
  student info;
  struct student_t *next;
} student_t;

student_t *intStd_Ptr(void) { return NULL; };

void Createstudent(student_t **ptr) {
  student_t *new;
  new = malloc(sizeof(student_t));

  printf("First Name: ");
  fgets(new->info.Fname, 15, stdin);

  printf("Last Name: ");
  fgets(new->info.Lname, 15, stdin);

  printf("Major: ");
  fgets(new->info.major, 20, stdin);

  printf("DoB(dd/mm/yy): ");
  scanf("%d/%d/%d", &new->info.DoB.DD, &new->info.DoB.MM, &new->info.DoB.YY);

  printf("DoB(dd/mm/yy): ");
  scanf("%d/%d/%d", &new->info.yr_oG.DD, &new->info.yr_oG.MM,
        &new->info.yr_oG.YY);

  printf("Student ID: ");
  fscanf(stdin, "%d", &new->info.ID);

  new->next = (*ptr);
  (*ptr) = new;
}

void deleteStudent(student_t **ptr, int ID) {
  student_t *temp, *prev;
  if ((*ptr)->info.ID == ID) {
    if ((*ptr)->next == NULL) {
      free((*ptr));
      (*ptr) = NULL;
    } else {
      temp = (*ptr)->next;
      free((*ptr));
      (*ptr) = temp;
    }
  } else {

    temp = (*ptr);
    prev = (*ptr);

    while (temp != NULL) {
      if (temp->info.ID == ID) {
        prev->next = temp->next;
        free(temp);
        temp = prev;
        break;
      }
      prev = temp;
      temp = temp->next;
    }
  }
}

void displayStudent(student_t *head) {


  student_t *tmp = malloc(sizeof(student_t ));
  tmp = head;
  while (tmp != NULL) {
    printf("ID: %d\nName %s %s", tmp->info.ID, tmp->info.Fname,
           tmp->info.Lname);
    tmp = tmp->next;
    }
    student_t *tmp = malloc(sizeof(student_t *));
    tmp = head;
    while (tmp != NULL) {
        printf("ID: %d\nName: %s %s", tmp->info.ID, tmp->info.Fname, tmp->info.Lname);      
        tmp = tmp->next;
    }
};
