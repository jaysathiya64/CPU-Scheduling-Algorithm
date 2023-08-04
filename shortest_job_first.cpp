#include <vector>
#include <queue>
#include "scheduling_process.cpp"

void sjf(vector<Process> &process) {
    int totalProcesses = process.size();
    int time=0, completedCount=0;
    Process *currProcess;

    priority_queue <Process *, vector<Process *>, sortByBurstTime> minheapQueue;

    vector<char> ganttChart;

    vector<int> newProcess(totalProcesses+1);
    fill(newProcess.begin(), newProcess.end(), 1);

    while(completedCount != totalProcesses) {

        for(int i=0; i<totalProcesses; i++) {
            if(process[i].getArrivalTime() <= time && newProcess[i]) {
                minheapQueue.push(&process[i]);
                newProcess[i] = 0;
            }
        }

        if(minheapQueue.empty()) {
            time++;
            ganttChart.push_back('I');
            continue;
        }

        currProcess = minheapQueue.top();
        minheapQueue.pop();

        time += (*currProcess).getBurstTime();

        for(int i=0; i<(*currProcess).getBurstTime(); i++) ganttChart.push_back('0' + (*currProcess).getPid());

        (*currProcess).setTurnaroundTime(time - (*currProcess).getArrivalTime());
        (*currProcess).setWaitingTime((*currProcess).getTurnaroundTime() - (*currProcess).getBurstTime());
        (*currProcess).setCompletionTime(time);

        completedCount++;
    }

    cout<<endl<<"Gantt Chart:"<<endl;
    for(int i=0; i<ganttChart.size(); i++) cout<<ganttChart[i]<<" ";

    displayProcessData(process);
}