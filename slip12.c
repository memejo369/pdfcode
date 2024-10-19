#include <stdio.h>

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int ct;
} Process;

void ct(Process p[],int n){
    for(int i=0;i<n;i++)
    {
        p[i].ct=p[i].arrival_time+p[i].burst_time;
    }
}
void calculateWaitingTime(Process processes[], int n) {
    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].arrival_time+processes[i].burst_time;
        // Adjust if the next process arrives after the current process finishes
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    ct(processes,n);
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].ct + processes[i].arrival_time;
    }
}

void findAverageTime(Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    calculateTurnaroundTime(processes, n);
    calculateWaitingTime(processes, n);
    

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void printGanttChart(Process processes[], int n) {
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", processes[i].process_id);
    }
    printf("\n");

    printf("0");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        printf(" %d", time);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    findAverageTime(processes, n);
    printGanttChart(processes, n);

    return 0;
}
