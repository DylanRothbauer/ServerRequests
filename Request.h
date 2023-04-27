#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <fstream>
#include <chrono>

#include <ctime>
#include <ratio>
using namespace std::chrono;
using namespace std;


class Request {
private:
	string filename;
	steady_clock::time_point startTime;
	steady_clock::time_point doneTime;

	//double doneTime;
	int id;

public:
	Request() {}

	Request(string filename, int id) {
		this->filename = filename;
		this->id = id;
	}

	void setStartTime(steady_clock::time_point startTime) {
		this->startTime = startTime;
	}

	steady_clock::time_point getStartTime() {
		return startTime;
	}

	steady_clock::time_point getDoneTime() {
		return doneTime;
	}

	string getFileName() {
		return filename;
	}

	int getID() {
		return id;
	}

	void setDoneTime() { doneTime = steady_clock::now(); }

};
