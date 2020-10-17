#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define print(x) cout<<x<<endl;
#define printl(x) cout<<x;



const int MAX_SIZE = 100; // max array size

int heap[MAX_SIZE]; // the heap
int heapSize = -1; //size of the heap



void printHeap(int); // prints the heap array
void insert(int);  // inserts an element to the heap
void decreaseKey(int, int); // Decrease Key of the element at array position x to value y
void extractMin(); // returns the root, which is the min
void floatUp(int); //moves an element up the tree if it is smaller than its parent
void sinkDown(int);  // moves an element down the tree if its greater than its children



int main()
{
    

    ifstream readFile("inputFile.txt");
    string inputCommand;

    int element;
    int index;
    int indexOfSpace;

    // a loop used to read the inputFile for commands to performed on the geap
    // IN command: invokes insert
    // EM command: invokes extractMin
    // Dk command: invokes decreaseKey
    while(readFile >> inputCommand)
    {
    
        // case 1: insert
        if(inputCommand == "IN")
        {
            readFile >> inputCommand;
            element = stoi(inputCommand);
            insert(element);
            cout<<endl; 
        }
        //case 2: extract min
        else if (inputCommand == "EM")
        {
            extractMin();
            cout<<endl; 
        }
        //case 3 decrease key
        else if (inputCommand == "DK")
        {
            readFile >> inputCommand;
            index =  stoi(inputCommand);

            readFile >> inputCommand;
            element = stoi(inputCommand);
            decreaseKey(index, element);
            cout<<endl; 
        }
        else
        {
            
        } 
    }
}


void printHeap()
{
    for(int i = 0; i <= heapSize; i++)
    {
        cout<<heap[i]<<" ";
    }
};

void insert(int element)
{
    heap[++heapSize] = element;
    floatUp(heapSize);
    printHeap(); 
};

void decreaseKey(int index, int element)
{
    heap[index] = element;
    floatUp(index);
    printHeap(); 
};


void extractMin()
{
    std::cout <<"Minimum:"<<heap[0]<<std::endl; 
    heap[0] = heap[heapSize--];
    sinkDown(0);
    printHeap(); 

};

void floatUp(int currIndex)
{
   
    if(currIndex == 0)
    {
        return;
    }
        
        
    int parentPosition = (currIndex-1) / 3;
    
    if(heap[currIndex] < heap[parentPosition])
    {
        int temp = heap[currIndex];
        heap[currIndex] = heap[parentPosition];
        heap[parentPosition] = temp;
        floatUp(parentPosition);
    }
};



void sinkDown(int currentIndex)
{
    int left = 3 * currentIndex + 1;
    int mid = 3 * currentIndex + 2;
    int right = 3 * currentIndex + 3;

    int min = currentIndex;
    if (left <= heapSize && heap[left] < heap[min]) 
    {
        min = left;
    }
    if (right <= heapSize && heap[right] < heap[min]) 
    {
         min = right;
    }
    if(mid <= heapSize && heap[mid] < heap[min])
    {
        min = mid; 
    }

    int temp = heap[min];
    heap[min] = heap[currentIndex];
    heap[currentIndex] = temp;

    if (min != currentIndex) 
    {
        sinkDown(min);
    }
};

