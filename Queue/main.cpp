#include <iostream>
#include <queue>
#include <stack>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

void printStack(stack<int> s)
{
    stack<int> tempStack;

    while (!s.empty())
    {
        tempStack.push(s.top());
        s.pop();
    }

    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        s.push(tempStack.top());
        tempStack.pop();
    }
}

void printQueue(queue<int> q)
{
    queue<int> tempQueue;

    while (!q.empty())
    {
        tempQueue.push(q.front());
        q.pop();
    }

    while (!tempQueue.empty())
    {
        cout << tempQueue.front() << " ";
        q.push(tempQueue.front());
        tempQueue.pop();
    }
}


int main()
{

    queue <int> mainQueue;
    queue<int>firstSubQueue;
    queue<int>secondSubQueue;
    stack<int>subStack;
    queue <int> lastQueue;


    for(int i=1; i<=100; i++)
    {
        mainQueue.push(i);
    }

    int size=mainQueue.size();

    srand((unsigned) time(NULL));

    for(int i=1; i<=size; i++)
    {

        int randomSelect = 1 + (rand() % 3);

        switch(randomSelect)
        {
        case 1:
            firstSubQueue.push(mainQueue.front());
            mainQueue.pop();
            break;
        case 2:
            secondSubQueue.push(mainQueue.front());
            mainQueue.pop();
            break;
        case 3:
            subStack.push(mainQueue.front());
            mainQueue.pop();
            break;
        }

    }


    cout<<"======================================="<<endl;
    cout<<"Stack Size is: "<<subStack.size()<<endl;
    cout<<"Stack Elements are: "<<endl;
    printStack(subStack);

    cout<<endl<<"======================================="<<endl;

    cout<<"First Sub Queue Size is: "<<firstSubQueue.size()<<endl;
    cout<<"First Sub Queue Elements are: "<<endl;
    printQueue(firstSubQueue);

    cout<<endl<<"======================================="<<endl;

    cout<<"Second Sub Queue Size is: "<<secondSubQueue.size()<<endl;
    cout<<"Second Sub Queue Elements are: "<<endl;
    printQueue(secondSubQueue);

    cout<<endl<<"======================================="<<endl;


    for(int i=1; i<=size; i++)
    {

        int randomDis = 1 + (rand() % 3);

        switch(randomDis)
        {
        case 1:
getFromSubStack:
            if (!subStack.empty())
            {
                lastQueue.push(subStack.top());
                subStack.pop();
            }
            else
            {

                goto getFromFirstSubQueue;
            }

            break;
        case 2:
getFromFirstSubQueue:
            if (!firstSubQueue.empty())
            {
                lastQueue.push(firstSubQueue.front());
                firstSubQueue.pop();
            }
            else
            {

                goto getFromSecondSubQueue;
            }

            break;
        case 3:
getFromSecondSubQueue:
            if
                (!secondSubQueue.empty())
            {
                lastQueue.push(secondSubQueue.front());
                secondSubQueue.pop();
            }
            else
            {

                goto getFromSubStack;
            }

            break;
        }

    }

    cout<<"Final Queue Size Is: "<<lastQueue.size();
    cout<<endl<<"======================================="<<endl;
    cout<<"Numbers After Random distribution:" <<endl<<endl;

    while (!lastQueue.empty())
    {
        cout << lastQueue.front() << "    ";
        lastQueue.pop();
    }

    cout<<endl<<"=======================================";
    return 0;
}
