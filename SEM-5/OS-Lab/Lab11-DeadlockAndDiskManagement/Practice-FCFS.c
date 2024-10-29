// Simulating FCFS disk scheduling algorithm

#include<stdio.h>
#include<conio.h>

void main(){
  int queue[100], n, head, seek = 0, diff;
  float avg;
  printf("****FCFS Disk Scheduling Algorithm****\n");
  printf("Enter the size of the queue\t");
  scanf("%d",&n);
  printf("Enter the queue\t");
  for(int i = 1; i <= n; i++) scanf("%d", &queue[i]);
  printf("Enter the initial head position\t");
  scanf("%d", &head);
  queue[0] = head;
  printf("\n");
  for(int j = 0 ; j<=n-1 ; j++){
    diff = abs(queue[j+1]- queue[j]);
    seek += diff;
    printf("Move from %d to %d with seek %d\n", queue[j], queue[j+1], diff);
  }
  printf("Total Seek Time is %d\t", seek);
  avg = seek/ (float)n;
  printf("\n Average seek time is %f\t", avg);
  getch();
}