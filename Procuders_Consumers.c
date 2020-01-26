//Nate Ramey Student at GCU Class 221 
#include <stdio.h>
#define MAXSIZE 10

int main()
{
    int count = 0;
    void producer(){ //Producer 
        int i;
        if(count == MAXSIZE)sleep(); //Tells console when to "standy" refering to the MAXSIZE
        while(1){
            i = produce();
            put(i);
        }       
        count++; 
        if(count == 1)wakeup(consumer()); //tells Producer when to be idle
    }
    void consumer(){ //Consumer 
        int i;
        if(count == 0)sleep(); //tells consumer when to "standby" 
        while(1){
            i = get();
            consume(i);
        }
        count--;
        if(count == MAXSIZE -1)wakeup(producer); //tells consumer when it needs to "consume"
    }
    int theProduct; //Product 
    int produce(){ 
        return theProduct++;
    }
    void consume(int i){
        printf("%i", i); //displays the actions in the console Window
    }
}