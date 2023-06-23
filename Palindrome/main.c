#include <stdio.h>
#include <string.h>


int main(void){ 
    
    int i, count = 0;
    char word;
    char data[20]; 

    printf("Enter a Word: ");
    scanf("%s", data);
    
    i = 0; 
    while (data[i] != '\0') {

        if(data[i] != data[strlen(data) - 1 - i]){
            count++;
        }
        
        i++;
    }
    
    if (count) 
        printf("'%s' is not a Palindrome\n", data);
    else
        printf("'%s' is a Palindrome\n", data);
    return 0;
}

