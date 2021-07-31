#include<iostream>

using namespace std;

void displayprocess(int process[100][2], int num)
{
    for(int i=1; i<=num ; i++)
    {
                cout<<"\nProcess P"<<process[i][0]<<" ==> State : "<<process[i][1];
                cout<<"";
    }
    cout<<"\n";
}


void display(int array1[],int num)
{
    for(int i=0; i<num ; i++)
    {
        cout<<array1[i]<<"------>";
    }
    cout<<"END\n";
}

int deletearray(int arr[],int x,int n) //ready running r
{
int i;
   for (i=0; i<n; i++)
      if (arr[i] == x)
         break;

   // If x found in array
   if (i < n)
   {
     // reduce size of array and move all
     // elements on space ahead
     n = n - 1;
     for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
   }

   return n;
}

int main()
{
    //declare states
    int no;
    int proc[100][2];
    int running=0;
    int blocked[100];int b=0;
    int ready[100];int r=0;
    int terminate[100];int t=0;
    int select;
    int selState;
    int exit=0;
    int nextState;

    cout<<"Enter Total no. of processes:";
    cin>> no ;

    for(int i=1; i<=no; i++)
    {
        proc[i][0]=i;
        int press;
        cout<<"\n\nPress :\n1. Running";
        cout<<"\n2. Ready";
        cout<<"\n3. Blocked";
        cout<<"\nEnter your choice for process P"<<i<<" from the above menu \t";
        cin>>press;

        if (press==1)
        {
            if(running==0)
            {
                proc[i][1]=1;
                running=proc[i][0];
            }
            else
                {
                    cout<<"\nInvalid choice :\n A process already exist in running state choose a new state: \t";
                    i--;
                }
        }
        else if (press==2)
        {
            proc[i][1]=2;
            ready[r]=proc[i][0];
            r++;
        }
        else if(press==3)
        {
            proc[i][1]=3;
            blocked[b]=proc[i][0];
            b++;
        }
        else {cout<<"\nInvalid choice : Please Choose again \t"; i--;}
    }

    displayprocess(proc,no);

            cout<<"\n\nBlocked process : ";
            display(blocked,b);
            cout<<"\nTerminated process : ";
            display(terminate,t);
            cout<<"\nReady process : ";
            display(ready,r);
            cout<<"Currently Running is : "<<running;
            cout<<"\n\n";

    do
    {
    cout<<"\n Select a process to start transition ";
    cin>>select;
    //cout<<proc[select][1];

    selState=proc[select][1];

    switch(selState)
    {
      case 1:
      {
            cout<<"\nThe process number you have entered is running\nNext possible states are Blocked or Terminate";
            cout<<"\n1. Terminate";
            cout<<"\n2. Blocked";
            cin>>nextState;
            running=0;
            if(nextState==1)
            {
                terminate[t]=select;
                t++;
                proc[select][1]=4;
            }
            if(nextState==2)
            {
                blocked[b]=select;
                b++;
                proc[select][1]=3;
            }

            cout<<"\n\nBlocked process : ";
            display(blocked,b);
            cout<<"\nTerminated process : ";
            display(terminate,t);
            cout<<"\nReady process : ";
            display(ready,r);
            cout<<"\nCurrently Running is : "<<running;
            cout<<"\n\n";
            break;
            }

      case 2: {
            cout<<"\nThe process number you have entered is in the Ready Queue";
            if(running!=0)
            {
                cout<<"\nYou will have to move the current running process to blocked state !";
                blocked[b]=running;
                b++;
                proc[running][1]=3;
                running=select;
                proc[select][1]=1;
            }
            if(running==0)
            {
                running=select;
                proc[select][1]=1;
            }

            r=deletearray(ready,running,r);


            cout<<"\n\nBlocked process : ";
            display(blocked,b);
            cout<<"\nTerminated process : ";
            display(terminate,t);
            cout<<"\nReady process : ";
            display(ready,r);
            cout<<"\nCurrently Running is : "<<running;
            cout<<"\n\n";
            break;
      }

      case 3:
    {
            cout<<"\nThe process number you have entered is in the Blocked State and can be now moved to : ";
            cout<<"\n1. Ready";
            cout<<"\n2. Terminate";
            cin>>nextState;

            if(nextState==1)
            {
                ready[r]=select;
                r++;
                proc[select][1]=2;
            }

            if(nextState==2)
            {
                terminate[t]=select;
                t++;
                proc[select][1]=4;
            }
            b=deletearray(blocked,select,b);

            cout<<"\n\nBlocked process : ";
            display(blocked,b);
            cout<<"\nTerminated process : ";
            display(terminate,t);
            cout<<"\nReady process : ";
            display(ready,r);
            cout<<"\nCurrently Running is : "<<running;
            cout<<"\n\n";
            break;

      }

      case 4:
        {
            cout<<"The Process is already run ! It is in the terminated state and cant be run again !";

        }

        default: cout<<"Invalid Choice !";
    }


    cout<<"\n Choose 5 to exit else continue:";
    cin>>exit;
    }
    while(exit!=5);



}
