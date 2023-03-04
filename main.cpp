#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

//by Ryan Veith
//This is a max heap


//resort heap (either up from index or if index = 1 down
void heapify(int heap[101], int index);

//cout the heap in a readable manner
void print(int heap[101], int current, int size, int tab);
//this print does not let you see children
void printBad(int heap[101]);

int main() {
  cout << "Type HELP for a list of commands" << endl;
  bool quit = false;
  char input[80];
  int num = 0;

  //our heap (101 since ignoring 0th spot)
  int heap[101];
  for (int a = 0; a < 101; a++) {
    heap[a] = 0;
  }
  
  while (quit == false) {
    cin.getline(input, 80);
    if (strcmp (input, "HELP") == 0 || strcmp (input, "?") == 0) {
      cout << "commands are ADD, DELETE, CLEAR, PRINT and QUIT" << endl;
      cout << "ADD lets you add a single number or add form a file" << endl;
      cout << "DELETE couts and removes the biggest number" << endl;
      cout << "CLEAR does delete and then heapify until list is empty" << endl;
      cout << "PRINT lets you view the heap, and QUIT exits programm" << endl;
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
	    num = 0;
	    myfile >> num;
	    //check if its emptry
	    if (num != 0) {

	      //find first empty spot and add it 
	      for (int a = 1; a < 101; a++) {
		if (heap[a] == 0) {
		  heap[a] = num;
		  //reheap
		  //cout << a << endl;
		  heapify(heap, a);
		  a = 101;
		}
	      }

	    }
	  } 
	}
	else {
	  cout << "something went wrong, ";
	  cout << "please check your spelling of the file name" << endl;
	}
      }
      else {
	cout << "enter the number you wish to add" << endl;
	//add from console
	//(don't) take up to 100 numbers
	//I am not messing with cin
	//for (int a = 0; a < 100; a++) {
	//cin.getline(input, 80);
	//if (strcmp (input, "q") != 0) {
	
	//add it
	num = 0;
        cin  >> num;
	  
	//same code as above	
	//find first empty spot and add it 
	for (int a = 1; a < 101; a++) {
	  if (heap[a] == 0) {
	    heap[a] = num;
	    //reheap
	    //cout << a << endl;
	    heapify(heap, a);
	    a = 101;
	  }
	}
	    
	//}
	//else {
	//cout << "detedted q" << endl;
	//a = 100;
	//}
	//}
      }
    }
    if (strcmp (input, "DELETE") == 0) {
      //cout << "del" << endl;
      //delete largest element and cout it
      int temp = 0;
      for(int a = 1; a < 102; a++) {
	if (heap[a] == 0) {
	  //cout << heap[a] << "at:" << a << endl;
	  temp = a-1;
	  a = 102;
	  //cout << "t" << temp << ":" << heap[temp]  << endl;
	}
      }
      cout << heap[1] << endl;
      heap[1] = heap[temp];
      heap[temp] = 0;
      //reorganize
      heapify(heap, 1);
    }
    //this is the same as delete but in a while loop
    if (strcmp (input, "CLEAR") == 0) {
      //cout << "clear" << endl;
      while (heap[1] != 0) {
	int temp = 0;
	for(int a = 1; a < 102; a++) {
	  if (heap[a] == 0) {
	    //cout << heap[a] << "at:" << a << endl;
	    temp = a-1;
	    a = 102;
	    //cout << "t" << temp << ":" << heap[temp]  << endl;
	  }
	}
	cout << heap[1] << endl;
	heap[1] = heap[temp];
	heap[temp] = 0;
	//reorganize
      heapify(heap, 1);
      }
    }
    if (strcmp (input, "PRINT") == 0) {
      print(heap, 1, 101, 0);
    }
    if (strcmp (input, "QUIT") == 0) {
      quit = true;
    }
  }
}

void heapify(int heap[101], int index) {
  //go reorganize the heap so it is biggest to smallest
  //loops will need to be added
  if (index == 1) {
    //cout << "top down" << endl;
    bool clock = true;
    while (clock == true) {
      //cout << "index: " << index << endl;
      //cout << "value: " << heap[index] << endl;
      //cout << heap[2*index] << " " << heap[2*index+1] << endl;
      
      if(heap[index] < heap[2*index] || heap[index] < heap[2*index+1]) {
	int temp;
	if (heap[2*index] > heap[2*index+1]) {
	  temp = heap[2*index];
	  heap[2*index] = heap[index];
	  heap[index] = temp;
	  

	  index = 2*index;
	}
	else {
	  temp = heap[2*index+1];
	  heap[2*index+1] = heap[index];
	  heap[index] = temp;

	  index = 2*index+1;
	}		
      }
      else {
	clock = false;
      }
    }
    //top was replaced so check each of the children
    //and swap with the bigger one (as long as it is > then you)
  }
  else {
    //cout << "recursion" << endl;
    //we are going up the heap if this is bigger then the parent swap!
    if (heap[index] > heap[(int)floor(index/2)]) {
      //swap!
      int temp = heap[index];
      heap[index] = heap[(int)floor(index/2)];
      heap[(int)floor(index/2)] = temp;
      //set new index
      index = floor(index/2);
      heapify(heap, index);
    }
  }
}


void printBad(int heap[101]) {
  //print somhow
  for (int a = 1; a < 101; a++) {
    cout << heap[a] << endl;
  }
}


void print(int heap[101], int current, int size, int tab) {
  //print it is some way that lets you see children

  if (current < size) {
    print(heap, current*2, size, tab+1);
    
    for (int a = 0; a < tab; a++) {
      cout << "    ";
    }
    cout << heap[current] << endl;
    if (current < size) {
      print(heap, current*2 + 1, size, tab+1);
    }
  }

  //my print when building this thing put in for nostalgia
  //if (current == 1) {
  //  cout << "done" << endl;
  //  printBad(heap);
  //}
}
