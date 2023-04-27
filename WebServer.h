#pragma once
#include "Request.h"

// A webserver class implemented as a Deque "deck" Data Strucuture
class WebServer {
private:
    deque<Request> dq;

public:
    WebServer() {}

    // STACK ADD
    void push_front(Request val) {
        dq.push_front(val);
    }

    // QUEUE ADD
    void push_back(Request val) {
        val.setStartTime(steady_clock::now());
        dq.push_back(val);
    }

    // QUEUE REMOVE
    void pop_front() {
        // if the back surpassed 30 seconds, switch to stack
        
        auto entryTime = dq.back().getStartTime();
        auto exitTime = steady_clock::now();
        auto elapsedBack = duration_cast<seconds>(exitTime - entryTime);


        // if time passed > 1 second, print contents of the back and remove from back
        if (elapsedBack.count() > 1) {

            cout << endl << "++++++++++++++++++++++ ELAPSED > 1 SEC ++++++++++++++++=+++++++" << endl;
            cout << endl << "REMOVED FROM THE BACK (pop_back() STACK MODE)" << endl << endl;

            string contents = dq.back().getFileName();
            ifstream file(contents);
            string str;
            if (file.is_open()) {
                while (getline(file, str)) {
                    cout << str << endl;
                }
                file.close();
            }
            else {
                cout << "Failed to open file!" << endl;
            }

            dq.back().setDoneTime();

            auto elapsed = duration_cast<seconds>(dq.back().getDoneTime() - dq.back().getStartTime());

            cout << "Object: " << dq.back().getID() << endl;
            cout << "Entry time: " << duration_cast<milliseconds>(dq.back().getStartTime().time_since_epoch()).count() << " ms" << endl;
            cout << "Exit time: " << duration_cast<milliseconds>(dq.back().getDoneTime().time_since_epoch()).count() << " ms" << endl;
            cout << "Elapsed time: " << elapsed.count() << " s" << endl;

            dq.pop_back();
        }
        else { // otherwise, print contents of the front and remove from front
            cout << endl << "REMOVED FROM THE FRONT (pop_front() QUEUE MODE)" << endl << endl;

            string contents = dq.front().getFileName();
            ifstream file(contents);
            string str;
            if (file.is_open()) {
                while (getline(file, str)) {
                    cout << str << endl;
                }
                file.close();
            }
            else {
                cout << "Failed to open file!" << endl;
            }

            dq.front().setDoneTime();

            auto elapsed = duration_cast<seconds>(dq.front().getDoneTime() - dq.front().getStartTime());

            cout << "Object: " << dq.front().getID() << endl;
            cout << "Entry time: " << duration_cast<milliseconds>(dq.front().getStartTime().time_since_epoch()).count() << " ms" << endl;
            cout << "Exit time: " << duration_cast<milliseconds>(dq.front().getDoneTime().time_since_epoch()).count() << " ms" << endl;
            cout << "Elapsed time: " << elapsed.count() << " s" << endl;

            dq.pop_front();
        }
    }

    // STACK REMOVE
    void pop_back() {
        // doneTimer also ends here
        dq.back().setDoneTime();
        dq.pop_back();
    }

    Request front() {
        return dq.front();
    }

    Request back() {
        return dq.back();
    }

    bool empty() {
        return dq.empty();
    }

    int size() {
        return dq.size();
    }

    


};