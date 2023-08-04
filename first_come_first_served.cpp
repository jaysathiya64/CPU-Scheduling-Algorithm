#include <algorithm>
#include <vector>
#include "scheduling_process.cpp"

void fcfs(vector<Process> &process) {
    int time=0;
    vector<char> ganttChart;

    sort(process.begin(), process.end(), sortByArrival);

    for(int i=0; i<process.size(); i++) {
        while(time < process[i].getArrivalTime()) {
            time++;
            ganttChart.push_back('I');
        }

        time += process[i].getBurstTime();

        for(int j=0; j<process[i].getBurstTime(); j++) {
            ganttChart.push_back('0' + process[i].getPid());
        }

        process[i].setCompletionTime(time);
        process[i].setTurnaroundTime(time - process[i].getArrivalTime());
        process[i].setWaitingTime(process[i].getTurnaroundTime() - process[i].getBurstTime());
    }

    cout<<endl<<"Gantt Chart:"<<endl;
    for(int i=0; i<ganttChart.size(); i++) cout<<ganttChart[i]<<" ";

    displayProcessData(process);
}
