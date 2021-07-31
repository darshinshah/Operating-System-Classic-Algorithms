#include <cstdlib>
#include <iostream>
using namespace std;

void bubblesort(int proc[], int art[], int bt[], int numproc){
    int i = 0, j = 0, ctr = 0;
    for(int i = 0; i < numproc; i++){
        for(j = 0; j < numproc-i-1; j++){
            if(bt[j] > bt[j+1]){
                int temp;
                temp = art[j];
                art[j] = art[j+1];
                art[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
                ctr++;
            }
        }
        if(ctr == 0){
            break;
        }
    }
}


int main(){
    int bt[5], wt[5], art[5], tat[5], artm[5], numproc = 0;
    int proc[5] = {1,2,3,4,5};
    //artm[] is used for saving value of starting time of each process in the Gantt Chart. Then we can easily subtract arrival time of a process from its corresponding artm value to find its waiting time.
    float totalwt = 0, totaltat = 0, avgwt = 0, avgtat = 0;
    cout<<"Enter the number of processes:";
    cin>>numproc;
    for(int i = 0; i<numproc; i++){
        //cout<<"Enter arrival time of the process:";
        art[i]=0;
        cout<<"Enter burst time of the process:";
        cin>>bt[i];
    }
    bubblesort(proc, art, bt, numproc);
    artm[0] = art[0];
    for(int i = 1; i < numproc; i++){
        artm[i] = artm[i-1] + bt[i-1];
    }
    cout<<"Process\t Waiting time\t Burst Time\t Turn Around Time"<<endl;
    for(int i =0 ;i < numproc; i++){
        wt[i] = artm[i] - art[i];
        tat[i] = bt[i] + wt[i];
        totalwt += wt[i];
        totaltat += tat[i];
        cout<<"P["<<proc[i]<<"]"<<"\t\t"<<wt[i]<<"\t\t"<<bt[i]<<"\t\t"<<tat[i]<<endl;
    }
    avgwt = totalwt/numproc;
    avgtat = totaltat/numproc;
    cout<<"Average waiting time = "<<avgwt<<"\n"<<"Average turn around time="<<avgtat<<endl;
}
