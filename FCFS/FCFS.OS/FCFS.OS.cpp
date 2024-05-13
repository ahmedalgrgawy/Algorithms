#include <iostream>
#include<vector>
using namespace std;

struct Process {
    int id;
    double ArrivalTime;
    double BurstTime;
    double CompletionTime;
    double WaitingTime;
    double TurnAroundTime;
};
void sortbyArrival(vector<Process>& p) {
    Process temp;
    for (int i = 0;i < p.size() - 1;i++) {
        for (int j = 0;j < p.size() - i - 1;j++) {
            if (p[j].ArrivalTime > p[j + 1].ArrivalTime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

            }
        }
    }
}
void calculateCompletion(vector<Process>& p) {
    int currentTime = 0;
    for (int i = 0;i < p.size();i++) {
        if (currentTime < p[i].ArrivalTime) {
            currentTime = p[i].ArrivalTime;
        }
        currentTime += p[i].BurstTime;
        p[i].CompletionTime = currentTime;
    }
}
void calculateTAT(vector<Process>& p) {
    for (int i = 0;i < p.size();i++) {
        p[i].TurnAroundTime = p[i].CompletionTime - p[i].ArrivalTime;
    }
} //TAT=CT-AT
void calculatewaiting(vector<Process>& p) {
    for (int i = 0;i < p.size();i++) {
        p[i].WaitingTime = p[i].TurnAroundTime - p[i].BurstTime;

    }
} //wt=TAT-BT
void calculateAverages(vector<Process>& p) {
    double totalwaiting = 0, totalTAT = 0, totalcompleting = 0;
    for (int i = 0;i < p.size();i++) {
        totalwaiting += p[i].WaitingTime;
        totalTAT += p[i].TurnAroundTime;
        totalcompleting += p[i].CompletionTime;
    }
    cout << "Average waiting time = " << totalwaiting / p.size() << endl;
    cout << "Average completing time = " << totalcompleting / p.size() << endl;
    cout << "Average turn around time = " << totalTAT / p.size() << endl;
}
int main()
{
    int ProNum;
    cout << "Enter the number of Process..." << endl;
    cin >> ProNum;
    vector<Process> p(ProNum);
    cout << "Enter the arrival and burst time for each process... " << endl;
    for (int i = 0;i < ProNum;i++) {
        cout << "Arrival time of p" << i + 1 << ":";
        cin >> p[i].ArrivalTime;
        cout << "Burst time of p" << i + 1 << ":";
        cin >> p[i].BurstTime;
        p[i].id = i + 1;
        cout << "-------------------------------" << endl;
    }
    cout << "----------------------------------------------" << endl;
    sortbyArrival(p);
    calculateCompletion(p);
    calculateTAT(p);
    calculatewaiting(p);
    for (int i = 0;i < ProNum;i++) {
        cout << " p" << p[i].id << " |" << "  arrival tiem :" << p[i].ArrivalTime << " |" << " " << "burt time :" << p[i].BurstTime << " |" << " waiting time :" << p[i].WaitingTime << " |"
            << " completion time :" << p[i].CompletionTime << " |" << " TAT :" << p[i].TurnAroundTime << endl;

    }
    cout << "----------------------------------------------" << endl;
    calculateAverages(p);


}
