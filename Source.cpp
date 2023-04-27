#include "WebServer.h"
#include "Request.h"

int main() {

	WebServer ws;


	int x = 14;
	int idNum = 1;
	while (x > 0) {
		Request r{ "/Users/RothbauerDylan/Documents/Document.txt", idNum };
		ws.push_back(r);
		x--;
		idNum++;
	}


	while (!ws.empty()) {
		ws.pop_front();
	}

}