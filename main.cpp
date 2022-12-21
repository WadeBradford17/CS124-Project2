/*
 * Wade Bradford
 * CS 124
 * Project 2
 */

using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include "Streamer.h"
#include "Queue.h"
#include "Stack.h"


int main() {


    vector<Streamer> streamers;
    // using ../ doesn't read the file for me (?)
    string fn = "twitchdata-update.csv";
    cout << endl;

    // reads file and stores into vector
    if (readDataFromFile(fn, streamers)) {
        cout << streamers.size() << " steamers read from file" << std::endl;
        string firstName = streamers.front().getStreamerName();
        cout << "The first streamer read was " << firstName << endl;
        string lastName = streamers.back().getStreamerName();
        cout << "The last streamer read was " << lastName << endl;
    }
    else {
        cout << "Something went wrong." << endl;
    }

    cout << endl;

    // two Queue objects
    Queue<int> intTest;
    Queue<string> stringTest;

    cout << "QUEUE METHODS DEMONSTRATION" << endl;

    // demonstration of int Queue methods
    intTest.enqueue(47);
    intTest.enqueue(77);
    intTest.enqueue(81);
    intTest.enqueue(31);
    intTest.enqueue(20);
    intTest.dequeue();
    intTest.enqueue(95);
    intTest.print();


    if (intTest.search(95)) {
    cout << "95 has been found in the Queue." << endl;
    }
    else {
        cout << "95 has not been found in the Queue." << endl;
    }

    cout << endl;

    // demonstration of string Queue methods
    stringTest.enqueue("Goat");
    stringTest.enqueue("Watermelon");
    stringTest.dequeue();
    stringTest.enqueue("Laptop");
    stringTest.enqueue("Mirrorball");
    stringTest.enqueue("Kevlar");
    stringTest.enqueue("Sticker");
    stringTest.print();

    if (stringTest.search("Bear")) {
        cout << "Bear has been found in the Queue." << endl;
    }
    else {
        cout << "Bear has not been found in the Queue." << endl;
    }

    cout << endl;



    // third queue and stack for streamer names
    Queue<Streamer> streamerQueue;
    Stack<Streamer> streamerStack;


    // loop to print and enqueue the first 10 streamers
    for (int i = 0; i < 9; i++) {
        streamerQueue.enqueue(streamers.at(i));
    }
        streamerQueue.print();
        cout << endl;

    // loop to dequeue the 10 objects and push them to stack
    for (int i = 0; i < 9; i++) {
         streamerStack.push(streamerQueue.dequeue());
    }


    // loop to pop off stack and print
    cout << "Top of Stack" << endl;
    for (int i = 0; i < 9; i++) {
    cout << streamerStack.pop() << endl;
    }
    cout << "Bottom of Stack" << endl;
    cout << endl;












    return 0;
}


