#include<iostream>
#include<algorithm>
using namespace std;

struct process
{
    int no;
    int av;
    int bt;
    int wt;
    int tat;
};

int main()
{
    int pno;int totalbt=0;int ctr=0;int mapp;int k=0;
    cout<<"Enter the no of processes : ";
    cin>>pno;

    process *pointer = new process[pno];

        for(int i=0;i<pno;i++)
        {
            pointer[i].no=i+1;
            cout<<"Enter Arrival time for process "<<i+1<<" : ";
            cin>>pointer[i].av;
            cout<<"\nEnter Burst time for process "<<i+1<<" : ";
            cin>>pointer[i].bt;
            totalbt+=pointer[i].bt;
        }
        int ganttchart[totalbt]={0};

        sort(pointer, pointer+pno, [](process const &a, process const &b){ return a.av < b.av; }); //according to arrival time
        sort(pointer, pointer+pno, [](process const &a, process const &b){ return a.bt < b.bt; }); //according to burst time

        for(int i=0;i<totalbt;i++)
        {
            ganttchart[i]=pointer[k].no;
            pointer[k].bt=pointer[k].bt-1;
            if(pointer[k].bt==0)
                {
                    pno=pno-1;
                    swap(pointer[k].av,pointer[pno].av);
                    swap(pointer[k].bt,pointer[pno].bt);
                    swap(pointer[k].wt,pointer[pno].wt);
                    swap(pointer[k].no,pointer[pno].no);
                }
            else
            {
            for(int i=0;i<pno;i++)
            {
                    pointer[i].wt+=1;
            }
            }


            /*for(int i=0;i<pno;i++)  //for display
                {
                    cout<<"\n"<<pointer[i].no<<"   "<<pointer[i].av<<"   "<<pointer[i].bt;
                }
                cout<<"\n\n";*/

            sort(pointer, pointer+pno, [](process const &a, process const &b){ return a.av < b.av; }); //according to arrival time
            sort(pointer, pointer+pno, [](process const &a, process const &b){ return a.bt < b.bt; }); //according to burst time

            for(int j=0;j<pno-ctr;j++)
            {
                if(pointer[j].av<=i+1)
                {
                 k=pointer[j].no;
                }
            }

        }

       for(int i=0;i<totalbt;i++)
        {
            cout<<ganttchart[i]<<"  ";
        }
}
