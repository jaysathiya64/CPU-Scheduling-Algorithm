#include<bits/stdc++.h>
using namespace std;
void avgtat(int n, vector<int> arr_time, vector<int> &tat_time, vector<int> c_time) {
    int total = 0;
    for(int i=0; i<n; i++)
    {
        tat_time.push_back(c_time[i] - arr_time[i]);
        total += tat_time[i];
    }
    cout<<"Average Turn Around Time = "<<(float)total/n;
}
void avgwt(int n, vector<int> tat_time, vector<int> bt_time_cp) {
    vector<int> wt_time;
    int total = 0;
    for(int i=0; i<n; i++)
    {
        wt_time.push_back(tat_time[i] - bt_time_cp[i]);
        total += wt_time[i];
    }
    cout<<"     ||      Avg waiting time = "<<(float)total/n;
}

void avgrt(int n, vector<int> arr_time, vector<int> gotcpu) {
    vector<int> responseArr;
    int total = 0;
    for(int i=0; i<n; i++)
    {
        responseArr.push_back(gotcpu[i] - arr_time[i]);
        total += responseArr[i];
    }
    cout<<"     ||      Avg response time = "<<(float)total/n;
}

void throughput(int n, int minarr, int tot_time)
{
    float throughput_val = (float) n / (tot_time - minarr);
    cout<<"     ||      Overall Throughput = "<<throughput_val<<endl;
}

void setarrival(int n, vector<int> &arr_time, vector<int> &bt_time, vector<int> &bt_time_cp, vector<string> &pid) {
    int temp,min;
    string tempstr;
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr_time[j] > arr_time[j+1])
            {
                temp = arr_time[j];
                arr_time[j] = arr_time[j+1];
                arr_time[j+1] = temp;

                temp = bt_time[j];
                bt_time[j] = bt_time[j+1];
                bt_time[j+1] = temp;

                temp = bt_time_cp[j];
                bt_time_cp[j] = bt_time_cp[j+1];
                bt_time_cp[j+1] = temp;

                tempstr = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = tempstr;
            }
        }
   }
}

void set_burst_time(int n, vector<int> &arr_time, vector<int> &bt_time, vector<int> &bt_time_cp, vector<string> &pid) {
    int temp;
    string tempstr;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr_time[i] == arr_time[j])
            {
                if(bt_time[i] > bt_time[j])
                {
                    temp = arr_time[j];
                    arr_time[j] = arr_time[i];
                    arr_time[i] = temp;

                    temp = bt_time[j];
                    bt_time[j] = bt_time[i];
                    bt_time[i] = temp;

                    temp = bt_time_cp[j];
                    bt_time_cp[j] = bt_time_cp[i];
                    bt_time_cp[i] = temp;

                    tempstr = pid[j];
                    pid[j] = pid[i];
                    pid[i] = tempstr;
                }
            }
        }
    }
}

void set_burst_SJF(int n, vector<int> &arr_time, vector<int> &bt_time, vector<int> &bt_time_cp, vector<string> &pid, int curr, int start) {
    int temp;
    string tempstr;

    for(int i=start; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr_time[i] <= curr && arr_time[j] <= curr)
            {
                if(bt_time[i] > bt_time[j])
                {
                    temp = arr_time[j];
                    arr_time[j] = arr_time[i];
                    arr_time[i] = temp;

                    temp = bt_time[j];
                    bt_time[j] = bt_time[i];
                    bt_time[i] = temp;

                    temp = bt_time_cp[j];
                    bt_time_cp[j] = bt_time_cp[i];
                    bt_time_cp[i] = temp;

                    tempstr = pid[j];
                    pid[j] = pid[i];
                    pid[i] = tempstr;
                }
            }
        }
    }
}

void newait_queue(vector<int> &arr_time_cp, vector<int> &wait_queue, int arrival, int n)
{
    while(arr_time_cp.size()>0 && arr_time_cp[0]<=arrival)
    {
        wait_queue.push_back(n-arr_time_cp.size());
        arr_time_cp.erase(arr_time_cp.begin());
    }
}

int main()
{
    while(1)
    {
        int i,j,k,n,ch,c,p_completed=0, curr_time=0, cp=0, count=0, max=2000, t=0, arrival=0, q_time, f=0, minarr=0;
        string s;
        vector<string> pid;
        vector<int> arr_time,arr_time_cp,bt_time,bt_time_cp,tat_time,gotcpu,wait_queue;
        i=0;
        {
            ifstream cin("input.txt");
            while(cin>>s>>j>>k)
            {
                pid.push_back(s);
                arr_time.push_back(j);
                bt_time.push_back(k);
                bt_time_cp.push_back(k);
                i++;
            }
        }

        n = bt_time.size();
        vector<int> c_time(n),gcpu(n);
        vector<string> gantt_chart(100);
        setarrival(n, arr_time, bt_time, bt_time_cp, pid);
        cout<<"1. FCFS"<<endl;
        cout<<"2. SJF"<<endl;
        cout<<"3. SRTN"<<endl;
        cout<<"4. RR"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>ch;
        cout<<endl;
        switch (ch)
        {
            case 1:
                cout<<"FCFS:"<<endl<<endl<<"Gantt Chart:"<<endl;
                c=0;
                minarr = arr_time[0];
                for(i=0; i<n; i++)
                {
                    if(c < arr_time[i])
                    {
                        while(c < arr_time[i])
                        {
                            cout<<"I";
                            c++;
                        }
                    }
                    gotcpu.push_back(c);
                    for(j=0; j<bt_time[i]; j++)
                    {
                        cout<<pid[i];
                        c++;
                    }
                    c_time[i]=c;
                }
                cout<<endl;
                avgtat(n, arr_time, tat_time, c_time);
                avgwt(n, tat_time, bt_time_cp);
                avgrt(n, arr_time, gotcpu);
                throughput(n, minarr, c);
                break;

            case 2:
                cout<<"SJF(NP):"<<endl<<endl<<"Gantt Chart:"<<endl;
                c = 0;
                minarr = arr_time[0];
                set_burst_time(n, arr_time, bt_time, bt_time_cp, pid);
                for(i=0; i<n; i++)
                {
                    if(c < arr_time[i])
                    {
                        while(c < arr_time[i])
                        {
                            cout<<"I";
                            c++;
                        }
                    }
                    gotcpu.push_back(c);
                    for(j=0; j<bt_time[i]; j++)
                    {
                        cout<<pid[i];
                        c++;
                    }
                    c_time[i] = c;
                    set_burst_SJF(n,arr_time,bt_time,bt_time_cp,pid,c,i+1);
                }
                cout<<endl;
                avgtat(n, arr_time, tat_time, c_time);
                avgwt(n, tat_time, bt_time_cp);
                avgrt(n, arr_time, gotcpu);
                throughput(n, minarr, c);
                break;

            case 3:
                cout<<"SRTF"<<endl<<endl<<"Gantt Chart:"<<endl;
                set_burst_time(n, arr_time, bt_time, bt_time_cp, pid);
                minarr = arr_time[0];
                for(i=0; i<n; i++) {
                    if(arr_time[i] <= curr_time)
                    {
                        if(bt_time[i] < max && bt_time[i] != 0)
                        {
                            cp = i;
                            max = bt_time[i];
                            if(bt_time[i] == bt_time_cp[i])
                            {
                                gotcpu.push_back(curr_time);
                            }
                        }
                    }
                }
                while(p_completed == 0)
                {
                    if(curr_time < arr_time[cp])
                    {
                        while(curr_time < arr_time[cp])
                        {
                            cout<<"I";
                            curr_time++;
                        }
                    }
                    if(count == n)
                    {
                        p_completed = 1;
                        break;
                    }
                    cout<<pid[cp];
                    curr_time++;
                    if(bt_time[cp] > 0)
                    {
                        bt_time[cp]--;
                        max = bt_time[cp];
                        if(bt_time[cp] == 0)
                        {
                            count++;
                            c_time[cp] = curr_time;
                            max=2000;
                        }
                    }
                    for(i=0; i<n; i++)
                    {
                        if(arr_time[i] <= curr_time)
                        {
                            if(bt_time[i] < max && bt_time[i] != 0)
                            {
                                cp = i;
                                max = bt_time[i];

                                if(bt_time[i] == bt_time_cp[i])
                                {
                                    gotcpu.push_back(curr_time);
                                }
                            }
                        }
                    }
                }
                cout<<endl;
                avgtat(n, arr_time, tat_time, c_time);
                avgwt(n, tat_time, bt_time_cp);
                avgrt(n, arr_time, gotcpu);
                throughput(n, minarr, curr_time);
                break;

            case 4:
                cout<<"Round Robin:"<<endl;
                cout<<"Enter time q_time: ";
                cin>>q_time;
                cout<<endl<<endl<<"Gantt Chart:"<<endl;
                minarr = arr_time[0];
                for(i=0;i<n;i++) arr_time_cp.push_back(arr_time[i]);
                c=0;
                wait_queue.push_back(0);
                arr_time_cp.erase(arr_time_cp.begin());

                while(t < arr_time[0])
                {
                    gantt_chart[t] = "I";
                    t++;
                }
                while(wait_queue.size()>0 || arr_time_cp.size()>0)
                {
                    f=0;
                    p_completed=1;
                    if(wait_queue.size()>0)
                    {
                        i=wait_queue[0];
                        if(bt_time[i] > 0)
                        {
                            p_completed=0;
                            if(bt_time[i] > q_time && arr_time[i] <= t)
                            {
                                if(bt_time[i] == bt_time_cp[i])
                                {
                                    gcpu[i] = t;
                                }
                                f=1;
                                for(j=0; j<q_time; j++)
                                {
                                    gantt_chart[t] = pid[i];
                                    t++;
                                }
                                bt_time[i] -= q_time;
                            }
                            else
                            {
                                if(arr_time[i] <= t)
                                {
                                    if(bt_time[i] == bt_time_cp[i])
                                    {
                                        gcpu[i] = t;
                                    }
                                    f=2;
                                    for(j=0; j<bt_time[i]; j++)
                                    {
                                        gantt_chart[t] = pid[i];
                                        t++;
                                    }
                                    bt_time[i] = 0;
                                    c_time[i] = t;
                                }
                            }
                        }
                    }
                    if(f==0)
                    {
                        gantt_chart[t] = "I";
                        t++;
                    }
                    newait_queue(arr_time_cp, wait_queue, t, n);
                    if(f==1)
                    {
                        wait_queue.push_back(i);
                        wait_queue.erase(wait_queue.begin());
                    }
                    else if(f==2)
                    {
                        wait_queue.erase(wait_queue.begin());
                    }
                }

                for(i=0; i<t; i++)
                {
                    cout<<gantt_chart[i];
                }
                cout<<endl<<endl;
                avgtat(n, arr_time, tat_time, c_time);
                avgwt(n, tat_time, bt_time_cp);
                avgrt(n, arr_time, gcpu);
                throughput(n, minarr, t);
                break;

            case 5:
                exit(0);

            default:
                cout<<"Invalid choice";
                break;
        }
    }
    return 0;
}
