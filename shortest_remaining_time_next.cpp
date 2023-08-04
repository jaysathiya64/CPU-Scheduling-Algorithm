#include <vector>
#include <queue>
#include "scheduling_process.cpp"

void srtn(vector<Process> &process) {
    int totalProcesses = process.size();
    int time = 0, completedCount = 0;
    Process *currProcess;

    priority_queue <Process *, vector<Process *>, sortByBurstTime> minheapQueue;

    vector<char> ganttChart;

    resetRemainingBurstTime(process);

    for(time=0; completedCount!=totalProcesses; time++) {
        for(int i=0; i<totalProcesses; i++) {
            if(process[i].getArrivalTime() == time) {
                minheapQueue.push(&process[i]);
            }
        }

        if(minheapQueue.empty()) ganttChart.push_back('I');
        else {
            currProcess = minheapQueue.top();
            minheapQueue.pop();
            (*currProcess).setRemainingBurstTime((*currProcess).getRemainingBurstTime()-1);

            ganttChart.push_back('0' + (*currProcess).getPid());

            if((*currProcess).getRemainingBurstTime() == 0) {
                completedCount++;
                (*currProcess).setTurnaroundTime(time + 1 - (*currProcess).getArrivalTime());
                (*currProcess).setWaitingTime((*currProcess).getTurnaroundTime() - (*currProcess).getBurstTime());
                (*currProcess).setCompletionTime(time + 1);
            } else {
                minheapQueue.push(currProcess);
            }
        }
    }

    cout<<endl<<"Gantt Chart:"<<endl;
    for(int i=0; i<ganttChart.size(); i++) cout<<ganttChart[i]<<" ";

    displayProcessData(process);
}