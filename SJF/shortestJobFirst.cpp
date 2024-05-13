#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
    int pid;
    int burstTime;
    int arrivalTime;
};

void insert(vector<node>& process)
{
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;
    process.resize(n);
    for(int i =0 ; i < n ; i++)
    {
        cout<<"Enter process id : ";
        cin>>process[i].pid;
        cout<<"Enter arrival time : ";
        cin>>process[i].arrivalTime;
        cout<<"Enter burst time : ";
        cin>>process[i].burstTime;
    }
}

//define the sorting criteria for the processes based on their burst time and arrival time
bool burstTimeSort(const node& a, const node& b)
{
    return a.burstTime < b.burstTime;
}

bool arrivalTimeSort(const node& a, const node& b)
{
    return a.arrivalTime < b.arrivalTime;
}

//calculates the average completion time of the processes
float completionTime(const vector<node>& process)
{
    float totalCompletionTime = 0;
    int n = process.size();
    for(int i = 0; i < n ; i++)
    {
        totalCompletionTime += process[i].burstTime;
    }
    return totalCompletionTime / n;
}

void display(const vector<node>& process)
{
    vector<node> a = process;
    sort(a.begin(),a.end(),burstTimeSort);
    sort(a.begin(),a.end(),arrivalTimeSort);

    int currentTime = 0 ;
    int n = a.size();
    vector<int> tArray(n);                    //store the completion time of the processes
    float averageCompletionTime = 0;           //store the sum of the completion times
    for(int i = 0 ; i < n ; i++)
    {
        int j = i ;   //ensure only processes that arrived by the current time are considered for scheduling
        while(a[j].arrivalTime <= currentTime && j != n)
        {
            j++;
        }
        sort(a.begin()+ i , a.begin()+ j ,burstTimeSort);  //sorted based on the shortest burst time
        tArray[i] = currentTime;     //completion time is sorted in tArray
        currentTime += a[i].burstTime;
        averageCompletionTime += currentTime;  //calculate the sum of completion times.
    }
    tArray[n]=currentTime;   //sort the completion time of the last process

    float averageWaitingTime = 0;
    float averageTAT = 0 ;
    cout<<"\n";
    cout<<"P.ID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i].pid << "\t";
        cout<<a[i].arrivalTime << "\t";
        cout<<a[i].burstTime << "\t";
        cout<<tArray[i + 1] << "\t";                       //print the completion time of the current process
        cout<<tArray[i] - a[i].arrivalTime + a[i].burstTime << "\t";  //print the turnaround time of the current process (at + bt)
        averageTAT += tArray[i] - a[i].arrivalTime + a[i].burstTime;
        cout<<tArray[i] - a[i].arrivalTime << "\t";       //print the waiting time (ct - at)
        averageWaitingTime += tArray[i] - a[i].arrivalTime;
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Gantt Chart \n" ;
    for (int i = 0; i < n; i++) {
        cout << "|   " << a[i].pid << "   ";
    }
    cout << "\n";
    for (int i = 0; i < n + 1; i++) {
        cout << tArray[i] << "\t";
    }
    cout<<"\n";
    cout << "Average Waiting time: " << (float)averageWaitingTime / (float)n << endl;
    cout << "Average TAT: " << (float)averageTAT / (float)n << endl;
    cout << "Average Completion time: " << averageCompletionTime / n << endl;
}

int main() {
    vector<node> process;
    insert(process);
    display(process);
    return 0;
}








