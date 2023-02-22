#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//by Ryan Veith
//This is a max heap

void remove(int &heap);
void heapify(int &heap);
void print(int heap);

int main() {
  cout << "hello world" << endl;
  bool quit = false;
  char input[80];

  //our heap (101 since ignoring 0th spot)
  int heap[101];
  while (quit == false) {
    cin.getline(input, 80);
    if (strcmp (input, "HELP") == 0 || strcmp (input, "?") == 0) {
      cout << "commands are ADD, DELETE, CLEAR, and QUIT" << endl;
    }
    if (strcmp (input, "ADD") == 0) {
      cout << "would you like add from a file? (y/n)" << endl;
      cin.getline(input, 80);
      if (strcmp(input, "Y") == 0 || strcmp(input, "Yes") == 0 ||
	  strcmp(input, "y") == 0 || strcmp(input, "yes") == 0 ||
	  strcmp(input, "YES") == 0) {
	cout << "what is the name of the file" << endl;
	//add from a file
	cin.getline(input, 80);
	ifstream myfile (input);
	if (myfile.is_open()) {
	  for (int a = 0; a < 100; a++) {
	    //clear input first since if we reach end of file
	    //input will not be overriden
	    strcpy (input, "");
	    myfile >> input;
	    
	    //add it
	    //for final thing have an if input != to "" before adding
	    cout << input << endl;
	    //reheap
	  } 
	}
	else {
	  cout << "something went wrong, ";
	  cout << "please check your spelling of the file name" << endl;
	}
      }
      else {
	cout << "enter the numbers you wish to add (q to exit)" << endl;
	//add from console
	//take up to 100 numbers
	for (int a = 0; a < 100; a++) {
	  cin.getline(input, 80);
	  if (strcmp (input, "q") != 0) {
	    //add it
	    cout << input << endl;
	    //reheap
	    
	  }
	  else {
	    a = 100;
	  }
	}
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


void remove(int &heap) {
  //remove biggest thing and cout it 
}

void heapify(int &heap) {
  //go reorganize the heap so it is biggest to smallest
}

void print(int heap) {
  //print it is some way that lets you see children
}
