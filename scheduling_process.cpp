#ifndef SCHEDULING_PROCESS
#define SCHEDULING_PROCESS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Process {
    private:
        int pid;
        int arrivalTime;
        int burstTime;
        int turnaroundTime;
        int waitingTime;
        int completionTime;
        int remainingBurstTime;
    
    public:
        int getPid() {
            return pid;
        }
        int getArrivalTime() {
            return arrivalTime;
        }
        int getBurstTime() {
            return burstTime;
        }
        int getTurnaroundTime() {
            return turnaroundTime;
        }
        int getWaitingTime() {
            return waitingTime;
        }
        int getCompletionTime() {
            return completionTime;
        }
        int getRemainingBurstTime() {
            return remainingBurstTime;
        }

        int setPid(int pid) {
            this->pid = pid;
        }
        int setArrivalTime(int arrivalTime) {
            this->arrivalTime = arrivalTime;
        }
        int setBurstTime(int burstTime) {
            this->burstTime = burstTime;
        }
        int setTurnaroundTime(int turnaroundTime) {
            this->turnaroundTime = turnaroundTime;
        }
        int setWaitingTime(int waitingTime) {
            this->waitingTime = waitingTime;
        }
        int setCompletionTime(int completionTime) {
            this->completionTime = completionTime;
        }
        int setRemainingBurstTime(int remainingBurstTime) {
            this->remainingBurstTime = remainingBurstTime;
        }
};

void resetRemainingBurstTime(vector<Process> process) {
    for(int i=0; i<process.size(); i++) {
        process[i].setRemainingBurstTime(process[i].getBurstTime());
    }
}

bool sortByPid(Process p1, Process p2) {
    return p1.getPid() < p2.getPid();
}

bool sortByArrival(Process p1, Process p2) {
    return p1.getArrivalTime() < p2.getArrivalTime();
}

class sortByBurstTime {
    public:
    bool operator() (Process* p1, Process* p2) {
        return (*p1).getRemainingBurstTime() > (*p2).getRemainingBurstTime();
    }
};

vector<Process> getProcessData() {
    cout<<endl<<"Enter Process Details:"<<endl<<endl;

    int totalProcess;

    cout<<"Enter total no. of Processes: ";
    cin>>totalProcess;

    vector<Process> process(totalProcess);

    int arrival, burst;
    for(int i=0; i<totalProcess; i++) {
        process[i].setPid(i+1);
        cout<<"Process ID: "<<i+1<<endl;

        cout<<"Enter arrival time: ";
        cin>>arrival;
        process[i].setArrivalTime(arrival);

        cout<<"Enter burst time: ";
        cin>>burst;
        process[i].setBurstTime(burst);
        process[i].setRemainingBurstTime(burst);
    }

    return process;
}

void avgTurnaroundBurst(vector<Process> &process) {
    float totTurnaroundTime = 0, totWaitingTime = 0;
    float avgTurnaroundTime, avgWaitingTime;
    int n = process.size();

    for(int i=0; i<n; i++) {
        totTurnaroundTime += process[i].getTurnaroundTime();
        totWaitingTime += process[i].getWaitingTime();
    }

    avgTurnaroundTime = totTurnaroundTime / n;
    avgWaitingTime = totWaitingTime / n;

    cout<<endl<<"Average Turnaround Time: "<<avgTurnaroundTime<<endl;
    cout<<"Average Waiting Time: "<<avgWaitingTime<<endl<<endl;
}

void displayProcessData(vector<Process> &process) {
    sort(process.begin(), process.end(), sortByPid);

    cout<<endl<<endl<<"----------------------------------------- Process Data -----------------------------------------"<<endl;
    cout<<"Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\tCompletion Time"<<endl;

    for(int i=0; i<process.size(); i++) {
        cout<<process[i].getPid()<<"\t\t"<<process[i].getArrivalTime()<<"\t\t"<<process[i].getBurstTime()<<"\t\t";
        cout<<process[i].getTurnaroundTime()<<"\t\t"<<process[i].getWaitingTime()<<"\t\t"<<process[i].getCompletionTime()<<endl;
    }
    avgTurnaroundBurst(process);
}

#endif