#include <stdio.h>
#include <time.h>
#define QUEMAX 256
    int que[QUEMAX];
    int count = 0;

int enqueue(int val){
    if(count == QUEMAX) {
        fprintf(stderr, "queue is full!");
        return 1;}
    que[count] = val;
    count++;
    return 0;
}


int dequeue(){
    int i, val;
    if (count == 0){
        fprintf(stderr, "\nqueue empty!");
        return -1;
    }
    val = que[0];
    for(i = 0; i < count - 1; i++){
        que[i] = que[i + 1];
    }
    count--;
    return val;
}

int main(void){
    int j;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    int tmp = count;

    for(j = 0; j < tmp ; j++){
        fprintf(stdout, "%d ", dequeue());
    }


    return 0;
}
