#include <iostream>
#include <fstream>
#include <string>
#include "Data.h"
/*#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "SortedLinkedList.h"*/
#include <stack>
#include <queue>
using namespace std;


int main() {

    cout << "" << endl;

    // reads from a file of your data set in CSV format,
    // stores them into a Data class object by repeatedly pushing all of the Data objects onto the head of a Stack class.
    // Data facebook;

    // use templete for stack, queue, and priority queue
    stack <Data> stack;
    queue <Data> queue;
    priority_queue <Data> priQueue;

/*
    Stack* mainstack = new Stack;
    Queue* mainqueue = new Queue;
    SortedLinkedList* finalsortedList = new SortedLinkedList;
*/

    // test file
    ofstream myfile;
    myfile.open ("../test.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();

    // in fstream
    // open input file of pseudo_facebook.csv
    ifstream inFile;
    inFile.open("../pseudo_facebook.csv");


    // reads from a file of your data set in CSV format,
    // stores them into a Data class object by repeatedly pushing all of the Data objects onto the head of a Stack class.
    // out fstream stacked, queued, sorted
    ofstream stacked;
    stacked.open("../stacked.txt");//, ofstream::out | ofstream::app);

    // ofstream stacked;
    ofstream queued;
    queued.open("../queued.txt");

    // ofstream sorted
    ofstream priQueued;
    priQueued.open("../priQueued.txt");

    // check if the input file is opened correctly
    if (!inFile.is_open()){
        cout << "Input file cannot be opened correctly" << endl;
        return 1;
    }

    // check if the stack file is opened correctly
    if (!stacked.is_open()){
        cout << "Stack file cannot be opened correctly" << endl;
        return 100;
    }

    // check if the queue file is opened correctly
    if (!queued.is_open()){
        cout << "Queue file cannot be opened correctly" << endl;
        return 10000;
    }

    // check if the sort file is opened correctly
    if (!priQueued.is_open()){
        cout << "priQueued file cannot be opened correctly" << endl;
        return 1000000;
    }


    cout << "All files are available." << endl;

    //stacked << "check";


    // print reading message
    cout << "...Reading pseudo_facebook.csv..." << endl << endl;


    // until reach the end of the file
    while (!inFile.eof()) {
        //for(int i = 0; i <= 65534 ; i++){
        //cout << "reached the middle";

        // use four string to read csv
        // gender, age, friends, likes
        // get string from csv
        // getline to get gender
        string gender1;
        getline(inFile, gender1, ',');

        // getline to get age
        string age1 ;
        getline(inFile, age1, ',');

        // getline to get friendsCount
        string friendsCount1;
        getline(inFile, friendsCount1, ',');

        // getline to get likesReceivedCount
        string likesReceivedCount1;
        getline(inFile, likesReceivedCount1);
        //cout << gender << age << endl;

        // use stoi to make string to int
        // get age, friendsCount, likesReceivedCount from stoi
        int age = stoi(age1);
        int friendsCount = stoi(friendsCount1);
        int likesReceivedCount = stoi(likesReceivedCount1);


        // create an object through
        Data nextUser = Data(gender1, age, friendsCount, likesReceivedCount);


        // for stack, we push head
        stack.push(nextUser);

        // for queue, we push tail
        queue.push(nextUser);

        // for priQueue, we just insert in priQueue
        priQueue.push(nextUser);


        //facebook = nextUser;
        //cout << (&stacked, nextUser);
        // print on console
        //cout << "reached the end" << endl;
    }


 //
    // use templete to print to stacked
    cout <<  "Writing data in stack inserted at head into stacked.txt." << endl;
    while (!stack.empty()){
        // print
        stacked << stack.top();
        stacked << endl;
        // end
        stack.pop();
    }

    // use templete()to print to queued
    cout << "Writing data in queue inserted at tail into queued.txt." << endl;
    while (!queue.empty()){
        // print
        queued << queue.front();
        queued << endl;
        // end
        queue.pop();
    }


    // use templete()to print to priQueue
    cout << "Writing data in priQueue linked list priQueue by attribute into priQueue.txt." << endl;
    while (!priQueue.empty()){
        // print
        priQueued << priQueue.top();
        priQueued << endl;
        // end
        priQueue.pop();
    }

    // close files
    inFile.close ();
    stacked.close();
    queued.close ();
    priQueued.close ();

    cout << endl << "-------- Reading and writing finished --------";
    return 0;
}