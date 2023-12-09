#include "functions.c"
int main(void) {
  student_t *head;
  head = intStd_Ptr();

  Createstudent(&head);
  Createstudent(&head);
  Createstudent(&head);
  Createstudent(&head);
  deleteStudent(&head, 1820);
  displayStudent(head);
  return 0;
}
