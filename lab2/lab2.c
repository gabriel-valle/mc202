#include <stdio.h>

int main(void) {
    int avail, n;
    int time[1000], duration[1000], wait[1000];
    int avg = 0, t = 0, t_queue = 0, lower = -1;
    scanf("%d %d", &avail, &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &time[i], &duration[i]);

    for(int i = 0; i < n; i++)
        wait[i] = 0;

    printf("everything read");

    while((t_queue!=n-1)||(lower!=n-1)||(duration[n-1]!=0)){
        printf("t: %d, t_queue: %d, lower: %d\n", t, t_queue, lower);
        while(t_queue < n-1 && time[t_queue+1] <= t)
            t_queue++;  //advances t_queue marker
        int att = avail;    //set the number of available attendents
        int i;
        for(i = lower; i <= t_queue; i++){  
            if(att == 0)    //decrements duration from each client
                break;
            if(duration[i] == 0)
                continue;
            duration[i]--;
            att--;
        }
        while(i <= t_queue){    //calculates waiting time
            if(duration > 0)
                wait[i]++;
        }
        while(lower < n-1 && duration[lower] == 0) //advances lower
            lower++;
        t++;
    }
    return 0;
}