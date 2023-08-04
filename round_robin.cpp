#include <algorithm>
#include <vector>
#include <queue>
#include "scheduling_process.cpp"

void rr(vector<Process> &process) {
    int time_quantum;
    int totalProcesses = process.size();
    int time=0, currProcess, completedCount=0;
    float total_tt=0, total_wt=0;

    vector<int> newProcess(totalProcesses);
    queue<int> readyQueue;

    vector<char> ganttChart;

    fill(newProcess.begin(), newProcess.end(), 1);
    sort(process.begin(), process.end(), sortByArrival);

    resetRemainingBurstTime(process);

    cout<<endl<<"Enter time quantum: ";
    cin>>time_quantum;

    while(completedCount!=totalProcesses) {

        for(int i=0; i<totalProcesses; i++) {
            if(newProcess[i] && process[i].getArrivalTime() <= time) {
                readyQueue.push(i);
                newProcess[i] = 0;
            }
        }

        if(readyQueue.empty()) {
            time++;
            ganttChart.push_back('I');
            continue;
        }

        currProcess = readyQueue.front();
        readyQueue.pop();
        
        int minTime = min(process[currProcess].getRemainingBurstTime(), time_quantum);

        process[currProcess].setRemainingBurstTime(process[currProcess].getRemainingBurstTime() - minTime);
        time += minTime;

        for(int i=0; i<minTime; i++) ganttChart.push_back('0' + process[currProcess].getPid());

        for(int i=0; i<totalProcesses; i++) {
            if(newProcess[i] && process[i].getArrivalTime() <= time) {
                readyQueue.push(i);
                newProcess[i] = 0;
            }
        }

        if(process[currProcess].getRemainingBurstTime() == 0) {
            process[currProcess].setCompletionTime(time);
            process[currProcess].setTurnaroundTime(time - process[currProcess].getArrivalTime());
            process[currProcess].setWaitingTime(process[currProcess].getTurnaroundTime() - process[currProcess].getBurstTime());
            completedCount++;
        } else {
            readyQueue.push(currProcess);
        }
    }

    cout<<endl<<"Gantt Chart:"<<endl;
    for(int i=0; i<ganttChart.size(); i++) cout<<ganttChart[i]<<" ";

    displayProcessData(process);
}