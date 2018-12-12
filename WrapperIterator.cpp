/*@desc: Implementation of vector class that serves std vector functions: get, set, insert, push, pop, iterate
  @remark: Class supports vectors of all data types: int, string, char...
  @authors: Rahul Sharma, Vishwajeet Kakde
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> class FakeVectorClass{
    public:

    T get(int index);
    void set(int index, T value);
    void insert(int index , T value);
    void push(T value);
    void pop();
};


template<class T> class FakeVectorClassImplementation : public FakeVectorClass<T>{
	
    private:
        vector<T> myvector;
        int sizeofvector;
        int calcindex;
        int displayindex=0;
    
    public:
        bool isempty(){
            return myvector.empty();
        }
        
        get(int position){
            sizeofvector = myvector.size();
            if(position < 1 || position > sizeofvector){
                cout<<"\nERROR: Index out of bound!";
            }
            
            else{
                return myvector[position-1];
            }
        }
        
        set(int position, T value){
            sizeofvector = myvector.size();
            if(position < 1 || position > sizeofvector+1){
                cout<<"\nERROR: Index out of bound!";
            }
            
            else{
                myvector[position-1] = value;
            }
        }
        
        push(T value){
            myvector.push_back(value);
        }
        
        pop(){
            if(!myvector.empty()){
                myvector.pop_back();
            }
            else{
                cout << "\nERROR: Cannot pop from an empty stack!"	;
            }		
        }
        
        insert(int position, T value){
            int sizeofvector = myvector.size();
            if(position > sizeofvector+1){
                cout<<"\nERROR: You cannot set value at an index disjoint to vector!";
            }
            else{
                myvector.insert(myvector.begin()+position,value);
            }
        }
        
        /*void display(){
            for(displayindex=myvector.size()-1; displayindex>=0; --displayindex){
                cout<<"\n\n"<<myvector[displayindex]<<" ";    
            }
        }*/
        
        void iterator_function(){	
            cout<<"\nVector contents: ";
            for (typename vector<T>::reverse_iterator myiterator = myvector.rbegin();  myiterator!= myvector.rend(); myiterator++){
                cout << *myiterator << " ";
            }
            cout<<"\n";
        }	
};


int main(){
    int IntAtIndex;         // Int Variable to hold return of get() element
    string StringAtIndex;   // String Variable to hold return of get() element
    
    FakeVectorClassImplementation<int> FakeVectorClassImplementationIntObj;             // int vector object
    FakeVectorClassImplementation<string> FakeVectorClassImplementationStringObj;       // string vector object

    /**** Testing vector functionality for INT vector - ****/
    
    // TEST: PUSH
    cout<<"\nPushing values ...";
    FakeVectorClassImplementationIntObj.push(10);       
    FakeVectorClassImplementationIntObj.push(20);
    FakeVectorClassImplementationIntObj.push(30);
    FakeVectorClassImplementationIntObj.push(40);
    FakeVectorClassImplementationIntObj.push(50);
    FakeVectorClassImplementationIntObj.iterator_function();
    
    // TEST: GET
    cout<<"\nGetting value ...";
    IntAtIndex = FakeVectorClassImplementationIntObj.get(2);
    cout << "\nValue at input position is : "<< IntAtIndex;
    FakeVectorClassImplementationIntObj.iterator_function();
    
    // TEST: SET
    cout<<"\nSetting value ...";
    FakeVectorClassImplementationIntObj.set(3,90);
    FakeVectorClassImplementationIntObj.iterator_function();
    
    // TEST: POP
    cout<<"\nPopping value ...";
    FakeVectorClassImplementationIntObj.pop();
    FakeVectorClassImplementationIntObj.iterator_function();
    
    // TEST: INSERT
    cout<<"\nInserting value ...";
    FakeVectorClassImplementationIntObj.insert(3,70);
    FakeVectorClassImplementationIntObj.iterator_function();
    
 return 0;

}