/*@desc Topological Sorting of a DAG 
 *@author Rahul_Sharma, Vishwajeet_Kakde
 *@remark This program uses the adjacency matrix to represent the directed acyclic graph
 * Input is read from input.dat and the input adjancency matrix is printed
 * 1 represents a directed edge between the nodes, 0 represents lack of edge between nodes
 * The topological sort works on an acyclic directed graph and prints 2 valid traversal paths through the graph nodes which are printed on
 * the screen
 * A test input.dat file has been attached in the submission
 * Nodes are represented when the adjacency matrix is printed on screen. The same Nodes are represented in the final output.
 * Names to nodes are assigned automatically as A, B, C, D ..
 * NOTE: IF BOTH THE SORTED OUTPUTS ARE MATCHING, IT IMPLIES ONLY ONE POSSIBLE SORTING ORDER ON THE INPUT GRAPH.
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <algorithm>
#include <malloc.h>
#include <queue> 
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include <stack>
#include <list>

using namespace std;

stack<int> sortedNodes;

void topologicalSortUtil(vector<int>& adjacencyMatrix, int adjacencyMatrixSize, int vertex, bool visitedNodesBinary[]){
    // mark the current node as visited true
    visitedNodesBinary[vertex] = true;
    
    // Recur for all nodes adjacent to this vertex
    list<int>::iterator it;
    for (int i = vertex*adjacencyMatrixSize; i <= ((vertex+1)*adjacencyMatrixSize)-1; i++){
        if (!visitedNodesBinary[i%adjacencyMatrixSize] && adjacencyMatrix[i] == 1){
            topologicalSortUtil(adjacencyMatrix, adjacencyMatrixSize, i%adjacencyMatrixSize, visitedNodesBinary);
        }
    }    
 
    // Push current vertex to stack which stores result
    sortedNodes.push(vertex);
}

void topologicalSort(vector<int>& adjacencyMatrix, int adjacencyMatrixSize, int sortOrderSequence){
    bool *visitedNodesBinary = new bool[adjacencyMatrixSize];
    
    for(int i=0; i<adjacencyMatrixSize; i++){           // initially, all nodes are unvisited
        visitedNodesBinary[i]=false;
    }
    
    // initiate ordering based on sort order sequence
    switch(sortOrderSequence){
        case 1: for(int i=0; i<adjacencyMatrixSize; i++){
                    if(visitedNodesBinary[i] == false){
                        topologicalSortUtil(adjacencyMatrix, adjacencyMatrixSize, i, visitedNodesBinary);
                    }
                }
                break;
                
        case 2: for(int i=adjacencyMatrixSize-1; i>=0; i--){
                    if(visitedNodesBinary[i] == false){
                        topologicalSortUtil(adjacencyMatrix, adjacencyMatrixSize, i, visitedNodesBinary);
                    }
                }
                break;        
    }
    
    // print the sorted graph
    cout<<"\n\nSorted graph according to sort order sequence "<<sortOrderSequence<<":  ";
    while(!sortedNodes.empty()){
        cout<<(char)(65+sortedNodes.top())<<"   ";
        sortedNodes.pop();
    }
    
    Sleep(5000);
}    

int main(){
    ifstream inFile;
    int adjacencyMatrixSize = 0;
    vector<int> adjacencyMatrix;
    vector<char> ReadFileVector; 

    std::fstream myFile; //change to outputfile
    string inputFilePath;
    
    cout <<"\n\n>>>>>>>>>>>-    WELCOME TO TOPOLOGICAL SORTER    -<<<<"<<"\n\nEnter full input DAT file path+name (example- C:\\Users\\User1\\Desktop\\input.dat):  ";
    cin>>inputFilePath;
    inFile.open(inputFilePath.c_str(), ios::binary); 
    while(!inFile.is_open()){
        cout<<"\n\nFile open failed. Try again!";
        cout<<"\n\nEnter full input DAT file path+name (example- C:\\Users\\User1\\Desktop\\input.dat):  ";
        cin>>inputFilePath;
        inFile.open(inputFilePath.c_str(), ios::binary); 
    }

    // get length of input file
    inFile.seekg(0, std::ios::end);
    size_t file_size_in_byte = inFile.tellg();
    ReadFileVector.resize(file_size_in_byte);
    inFile.seekg(0, std::ios::beg);
    inFile.read(&ReadFileVector[0], file_size_in_byte);
    
    inFile.close();
    
    // translate char vector contents into a integer vector
    int readFileVectorIndex = 0;
    for(readFileVectorIndex=0; readFileVectorIndex < ReadFileVector.size(); readFileVectorIndex++){
        char element = ReadFileVector[readFileVectorIndex];
        
        if(element == ' ' || element == ','){     // ignore white spaces or commas
            continue;
        }
        
        else if(element == '1' || element =='0'){
            while(element != '\r'){                     // '\r' is the carriage return character, signifies new line
                if(element == ' ' || element == ','){    // ignore white spaces or commas    
                    readFileVectorIndex++;
                    element = ReadFileVector[readFileVectorIndex];
                    continue;
                }
                else if(element == '1' || element =='0'){
                    adjacencyMatrix.push_back((int)element - 48);
                    adjacencyMatrixSize++;
                    readFileVectorIndex++;
                    if(readFileVectorIndex < ReadFileVector.size()){
                        element = ReadFileVector[readFileVectorIndex];
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

    adjacencyMatrixSize = sqrt(adjacencyMatrixSize);
    cout<<"\n\nInput Adjacency Matrix Size:  "<<adjacencyMatrixSize;
    Sleep(2000);
    
    cout<<"\n\nInput Adjacency Matrix contents:  \n\n";
    cout<<" ";
    for(int i=0; i<adjacencyMatrixSize; i++){
        cout<<"  "<<(char)(65+i);
    }
    cout<<"\n\n";
    
    for(int i=0; i<adjacencyMatrix.size(); i++){
        if(i%adjacencyMatrixSize==0){
            cout<<(char)(65+i/adjacencyMatrixSize)<<"  ";
        }
        cout<<adjacencyMatrix.at(i)<<"  ";
        if((i+1)%adjacencyMatrixSize == 0){
          cout<<"\n";
        }
    }
    Sleep(2500);
    
    // topological sort - order sequence #1 (start sorting from node 1, go forwards)
    topologicalSort(adjacencyMatrix, adjacencyMatrixSize, 1);
    
    // topological sort - order sequence #2 (start sorting from node n-1, go backwards)
    topologicalSort(adjacencyMatrix, adjacencyMatrixSize, 2);   
    
}


