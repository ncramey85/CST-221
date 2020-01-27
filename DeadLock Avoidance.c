//Nate R. GCU Student Assignment Deadlock Avoidance CST-221


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int avail_Resources = 3;
int p1_Needs = 8;
int p1_avail = 3;
int p2_Needs = 8;
int p2_avail = 3;
int seconds = 0;


int main(){ //methods for process 1 
    while(p1_avail < p1_Needs){  //available & needs
        if(avail_Resources <= 0){
            printf("Resources are not available. \n"); 
            while(seconds <= 2){ //2 second delay
                printf("%d Seconds\n", seconds);
                sleep(1);
                seconds++;
            }
        }else{
            p1_avail++;
            avail_Resources--;
            printf("Process 1 has %d resources and needs %d resources\n", p1_avail, p1_Needs); //what resoucres are left
            printf("Process 1 requires more resources.\n"); //how many more resoucres are required
            printf("Process 1 has %d resources and needs %d resources.\n Available %d resources left.\n", p1_avail, p1_Needs, avail_Resources);
        }
    }
    printf("Process 1 now has the available resources to execute, will release its resources after completion.\n");
    avail_Resources = avail_Resources + p1_avail;
    
    while(p2_avail < p2_Needs){ //available & needs for process 2
        if(avail_Resources <= 0){
            printf("Resources are not available.\n");
            while (seconds <= 2){ // 2 second delay
                printf("%d Seconds\n", seconds);
                sleep(1);
                seconds++;
            }
        }else{
            p2_avail++; 
            avail_Resources--;
            printf("Process 2 has %d resources and needs %d resources\n", p2_avail, p2_Needs); //What resources are needed
            printf("Process 2 requires more resources.\n"); //how many more resources are needed
            printf("Process 2 now has %d resources and needs %d resources.\n Available %d resources left.\n", p2_avail, p2_Needs, avail_Resources); 
        }
    }
    printf("Process 2 now has the available resources to execute, will release its resources after completion.\n");
    avail_Resources = p2_avail + avail_Resources;
}