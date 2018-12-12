/*author: Vishwajeet_Kakde, Rahul Sharma
 * @remark: input needed is an input.dat file containing adjacency matrix representing graph
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

queue< pair<int, int> > BFSNumbers;

GenerateBFSNumbers(vector<int> adjacencyMatrix, int numberOfNodes){
    int BFS_Number_Current = 0;
    queue<int> visitedQueue;
    int visitedArray[numberOfNodes];
    queue<int> exploredQueue;
    int exploredArray[numberOfNodes];
    
    // initialize all nodes as un-visited and un-explored
    for(int i=0; i<numberOfNodes; i++){
        visitedArray[i] = 0;                 // 0 = not visited, 1 = visited
        exploredArray[i] = 0;                // 0 = not explored, 1 = explored
    }
    
    // loop through all unvisited nodes and perform breadth first search
    int vertex = 0;
    visitedArray[vertex] = 1;
    visitedQueue.push(vertex);
    BFSNumbers.push( make_pair(vertex, BFS_Number_Current) );
    BFS_Number_Current++;
                    
    while(!visitedQueue.empty() && sizeof(exploredQueue)!=numberOfNodes){            // if size of exploredQueue equals number of nodes/vertices, 
                                                            // that implies all nodes/vertices have been visited
        // mark the current node as visited
        int currentNode = visitedQueue.front();
        
        for (int i = currentNode*numberOfNodes; i <= ((currentNode+1)*numberOfNodes)-1; i++){				 // traversing adj matrix, which is a 1D array
            if (adjacencyMatrix[i]=1 && !visitedArray[i%numberOfNodes] && !exploredArray[i%numberOfNodes]){  // node is adjacent and un-visited
                    BFSNumbers.push( make_pair(i%numberOfNodes, BFS_Number_Current) );
                    BFS_Number_Current++;
                    visitedQueue.push(i%numberOfNodes);
                    visitedArray[i%numberOfNodes]=1;
            }
        }
        // all adjacent nodes of current node have been visited. So pop current node from visitedQueue and add to exploredQueue
        visitedQueue.pop();
        exploredQueue.push(currentNode);
        exploredArray[currentNode]=1;
    }
}

int main(int argc, char **argv)
{
    ifstream inFile;
    int adjacencyMatrixSize = 0;
    vector<int> adjacencyMatrix;
    vector<char> ReadFileVector; 

    std::fstream myFile; //change to outputfile
    string inputFilePath;
    
    cout <<"\n\n>>>>>>>>>>>-    WELCOME TO GRAPH BFS SEQUENCE GENERATOR    -<<<<"<<"\n\nEnter full input DAT file path+name (example- C:\\Users\\User1\\Desktop\\input.dat):  ";
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
    
    // Now that adjacency matrix has been read, invoke the BFS function to generate BFN numbers
    cout<<"\nGenerating BFS numbers ...";
    GenerateBFSNumbers(adjacencyMatrix, adjacencyMatrixSize);
    Sleep(2000);
    
    cout<<"\n\nNodes and their BFS Numbers:  ";
    while(!BFSNumbers.empty()){
        pair<int, int> outputNode;
        outputNode = BFSNumbers.front();
        cout<<outputNode.first<<"   "<<outputNode.second<<"\n";
        BFSNumbers.pop();
    }
    Sleep(5000);

	return 0;
}
