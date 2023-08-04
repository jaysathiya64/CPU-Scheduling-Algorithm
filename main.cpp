#include <iostream>

#include "scheduling_process.cpp"

#include "first_come_first_served.cpp"
#include "round_robin.cpp"
#include "shortest_remaining_time_next.cpp"
#include "shortest_job_first.cpp"

using namespace std;

int main() {
    int choice;

    cout<<endl<<"CPU SCHEDULING ALGORITHMS SIMULATION"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;

    while(true) {
        cout<<endl<<"Algorithms"<<endl;
        cout<<"1. First Come First Served"<<endl;
        cout<<"2. Round Robin"<<endl;
        cout<<"3. Shortest Remaining Time Next"<<endl;
        cout<<"4. Shortest Job First"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice == 5) exit(0);

        vector<Process> process = getProcessData();

        switch (choice)
        {
            case 1:
                fcfs(process);
                break;

            case 2:
                rr(process);
                break;

            case 3:
                srtn(process);
                break;
                
            case 4:
                sjf(process);
                break;
            
            default:
                break;
        }
    }

    return 0;
}