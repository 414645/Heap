#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//by Ryan Veith
//This is a max heap

//void blank();

int main() {
  cout << "hello world" << endl;
  bool quit = false;
  char input[80];

  //our heap (101 since ignoring 0th spot)
  int heap[101];
  while (quit == false) {
    cin.getline(input, 80);
    if (strcmp (input, "HELP") == 0) {
      cout << "commands are ADD, DELETE, CLEAR, and QUIT" << endl;
    }
    if (strcmp (input, "ADD") == 0) {
      cout << "would you like add from a file? (y/n)" << endl;
      cin.getline(input, 80);
      if (strcmp(input, "Y") == 0 || strcmp(input, "Yes") == 0 ||
	  strcmp(input, "y") == 0 || strcmp(input, "yes") == 0 ||
	  strcmp(input, "YES") == 0) {
	cout << "file" << endl;
	//add from a file
      }
      else {
	cout << "console" << endl;
	//add from a file
      }
    }
    if (strcmp (input, "DELETE") == 0) {
      cout << "del" << endl;
      //delete largest element and cout it
    }
        if (strcmp (input, "CLEAR") == 0) {
      cout << "clear" << endl;
      //delete largest element and cout it until heap is empty
    }
    
    if (strcmp (input, "QUIT") == 0) {
      quit = true;
    }
  }
}
