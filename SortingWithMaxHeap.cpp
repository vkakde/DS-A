/*

Heaps used for Sorting Lab
 
User is requested 10 numbers from the screen, 1 line at a time. 
Output is displayed to the user in descending order,
one line at at time, by repeatedly retrieving and deleting the largest item from the heap.

We have implemented max-heap using an int array to solve this problem 

*/


#include <iostream>
#include <windows.h>

using namespace std;

void sort_heap(int *HeapArray, int index, int numberofelements)

{

    int tempindex , swap_variable;

    swap_variable = HeapArray[index];

    tempindex = 2 * index;

    while (tempindex <= numberofelements)

    {

		//Checking if variable is inside the Array limits
		
        if (tempindex < numberofelements && HeapArray[tempindex+1] > HeapArray[tempindex])

            tempindex = tempindex + 1;

		
        if (swap_variable > HeapArray[tempindex])

            break;

        else if (swap_variable <= HeapArray[tempindex])

        {

            HeapArray[tempindex / 2] = HeapArray[tempindex];

            tempindex = 2 * tempindex;

        }

    }

    HeapArray[tempindex/2] = swap_variable;

    return;

}

void insert_into_max_heap(int *HeapArray, int numberofelements)
{
    int index;

    for(index = numberofelements/2; index >= 1; index--)
    {
        sort_heap(HeapArray,index,numberofelements);
    }
}

void delete_max_from_heap(int *HeapArray, int numberofelements)
{
    int largest_element;
	int counter;
	int root_position = 1;
	int Max_Index;
    
	Max_Index = numberofelements;
	
	for(counter = 1; counter <= numberofelements;counter++)
	{
	// largest element will always be at the top in a mac heap 
	largest_element = HeapArray[root_position];
	
	//swapping last element to root of the heap
	HeapArray[root_position]=HeapArray[Max_Index];
	
	//As one element will be deleted, reducing the max index of array
	--Max_Index;
	
	cout <<"\nLargest Element Deleted from Heap : " << largest_element <<"\n";
    
	//calling sort_heap to sort the array into heap form
	
	sort_heap(HeapArray, root_position, Max_Index);
	}
	
}

int main()

{

    int numberofelements = 10, index;

    int HeapArray[12]; 
	
	cout << "\n!!!! Welcome to Heap Create and Delete Lab !!!! \n";
	cout << "\n";
	
    for (index = 1; index <= numberofelements; index++)

    {
		//Receiving input from user
       
	   cout<<"Enter element "<<(index) << " to be added to Heap :: ";
       cin>>HeapArray[index];
	   cout << "\n";
	   
		//Building Heap for as each element is entered
	   insert_into_max_heap(HeapArray,index);
    }
	
    cout<<"\nMax Heap Created\n\n";
	
	for (index = 1; index <= numberofelements ; index++)
    {
		//displaying Heap in an array form
        cout<<HeapArray[index] << " " ;

    }
	
	cout <<"\n";
	
	delete_max_from_heap(HeapArray, numberofelements);
	
	Sleep(8000);
	
return 0;
}

