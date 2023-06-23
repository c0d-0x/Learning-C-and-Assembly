#include <stdio.h>
#include <string.h>
#include <math.h>
#include "modules.h"



int main(){
    int numb1, numb2, result;
    char operation;

    printf("[*]Opearations: addidion(+), substraction(-), mulication(*), division(/)\n");
    /* printf("[!!]press 'q' to exit!!\n"); */
    printf("Expression format a + b:\n");
    printf("Enter Expression: ");
    scanf("%d %c %d", &numb1, &operation, &numb2);
    
        switch (operation) {
            case '+':
                result = add(numb1, numb2);
                printf("%d + %d = %d\n",numb1, numb2, result);
                break; 
            case '-':
                result = subtract(numb1, numb2);
                printf("%d - %d = %d\n",numb1, numb2, result);
                break; 
           case '*':
                result = multipy(numb1, numb2);
                printf("%d * %d = %d\n",numb1, numb2, result);
                break; 
           case '/':
                result = divide(numb1, numb2);
                printf("%d / %d = %d\n",numb1, numb2, result);
                break; 
        }
    return 0;
}
