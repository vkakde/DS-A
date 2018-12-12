#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <string>

using namespace std;

int main(){
	map<string, string> sortedDictionary;
    map<string,string> ::iterator it;
    
    // insert keyvalue pairs as given in question
    sortedDictionary.insert(pair<string, string>("hello", "world"));
    sortedDictionary.insert(pair<string, string>("goodbye", "everyone"));
    sortedDictionary.insert(pair<string, string>("name", "student"));
    sortedDictionary.insert(pair<string, string>("occupation", "student"));
    sortedDictionary.insert(pair<string, string>("year", "2016"));
    sortedDictionary.insert(pair<string, string>("gpa", "4.0"));
    sortedDictionary.insert(pair<string, string>("lab", "yes"));
    sortedDictionary.insert(pair<string, string>("assignment", "no"));
    sortedDictionary.insert(pair<string, string>("department", "cs"));
    
    cout<<"\nInsertion Successful. Displaying key-value pairs:  \n\n";
    
    for (it=sortedDictionary.begin(); it!=sortedDictionary.end(); ++it){
        cout << it->first << "  =>  " << it->second << '\n';
    }
    
    Sleep(3000);
    
    cout<<"\n\n\nRetrieving the value for key 'gpa' : "<<sortedDictionary["gpa"];
    Sleep(2500);
    
    cout<<"\n\n\nRetrieving the value for key 'department' : "<<sortedDictionary["department"];
    Sleep(2500);
    
    char choice='a';
    
    while(choice!='q' || choice!='Q' || choice!='6') {
        cout<<"\n\n\n>>>> SORTED DICTIONARY MENU <<<<\n";
        cout<<"\n1. Insert key-value pair\t2. Retrieve value associated with key\n3. Delete key\t4. Search key\n5. Display dictionary\t6. Quit program (Q)\n\nEnter choice:  ";
        
        cin>>choice;
        
        if(choice=='1'){
            string key, value;
            cout<<"\n\n [INSERT] Enter key:  ";
            cin>>key;
            cout<<"\nEnter value:  ";
            cin>>value;
            sortedDictionary.insert(pair<string, string>(key, value));
            cout<<"\nSuccessfully Inserted!";
            Sleep(3000);
        }

        else if(choice=='2'){
            string key, value;
            cout<<"\n\n [RETRIEVE] Enter key:  ";
            cin>>key;
            try{
                value=sortedDictionary.at(key);
                cout<<"\nValue at key "<<key<<" is:  "<<value;
            }
            catch(exception &e){
                cout<<"\nKey not found.";
            }
            Sleep(2000);
        }

        else if(choice=='3'){
            string key, value;
            cout<<"\n\n [DELETE] Enter key:  ";
            cin>>key;
            try{
                value=sortedDictionary.at(key);
                sortedDictionary.erase(key);
                cout<<"\nKey-value pair at key "<<key<<" has been erased. ";
            }
            catch(exception &e){
                cout<<"\nKey not found.";
            }
            Sleep(2000);
        }
           
        else if(choice=='4'){
            string key, value;
            cout<<"\n\n [SEARCH] Enter key:  ";
            cin>>key;
            try{
                value = sortedDictionary.at(key);
                cout<<"\nKey "<<key<<" has been found. Corresponding value:  "<<value;
            }
            catch(exception &e){
                cout<<"\nKey not found.";
            }
            Sleep(2000);
        }

        else if(choice=='5'){
            for (it=sortedDictionary.begin(); it!=sortedDictionary.end(); ++it){
                cout << it->first << "  =>  " << it->second << '\n';
            }
            Sleep(2000);
        }
            
        else{
            cout<<"\nExiting program ... ";
            Sleep(3000);
            exit(0);
        }            
    }
    return 0;
}
