#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
    
using namespace std;

class TicTacToe{
    //making things public as of now. have to make variables as private later with getter setter methods
public:
    
    char Player_Sign[26] = {'X','O','A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','Y','Z'};
    int Number_Of_Players = 0;
    int Size_of_Board = 0;
    int Win_Sequence = 0;
    int Row = 0;
    int Column = 0;
    int Turn = 0;
    int size = 0;
    int flag = 0;
    int index = 0;
    int Player;
    int Winner = 0;
    int Game_Array_Size = 0;
    char Player_Character;
    char Board_Sign = '  ';
    char Choice = ' ';
    string User_Input;
    int index_check = 0;
    char Default_Char = 'AA';
    string Save_FileName;
    string token[3];
    string sep;
    string Q = "Q";
    string q = "q";
    string S = "S";    
    string s = "s";
    
    TictacToe();
    
    int Validate_Number_Of_Players(int Number_Of_Players){
        if(Number_Of_Players < 2 || Number_Of_Players > 26){ 
            cout << "Number of Users should be between 2 and 26 \n";
            return 0;
        }        
        return 1;
    }

    int Validate_Board_Size(int Size_of_Board){
        if(Size_of_Board < 2 || Size_of_Board > 999){
            cout << "Size of Board should between 2 and 999 \n";
            return 0;
        }    
        return 1;
    }

    char Validate_Game_Possible(int Size,int Number_Of_Players,int Win_Sequence){
        int Total_Blocks = Size * Size;
        Win_Sequence = Win_Sequence-1;
        if(Total_Blocks < (Win_Sequence*Number_Of_Players + 1)){
            return 'Q';
        }        
        return 'PO';
    }

    void Initialize_Game_Array(char *Game_Array,int size){    
    // Mark all indices of Game_Array as blank for a new game
        int index;
        for(index = 0; index <= size-1; index++){
            Game_Array[index] = ' ';        
        }        
    }

    char Print_Game_Board(char *Game_Array, int Size_of_Board){        
        int index =0;    
        int row=0, col=0;                                                
                        
        for(row=0; row<Size_of_Board; row++){
            if(row == 0){
                //cout<<"    ";
                for(index=0; index<Size_of_Board; index++){                    
                    if(index <= 9){
                        cout<<"    "<<index+1<<"  ";
                    }
                    else if(index == 10){
                        cout<<"  "<<index+1<<"  ";
                    }
                    else if(index > 10 && index < 100){
                        cout<<"   "<<index+1<<"  ";
                    }
                    else if(index == 100){
                        cout<<" "<<index+1<<" ";
                    }
                    else if(index > 100 && index < 1000){
                        cout<<"  "<<index+1<<"  ";
                    }
                }
                cout<<"\n\n";
            }
        
            for (col=0;col<Size_of_Board;col++){
                if (col==0){                
                    cout<<row+1;
                }
                
                index = row*Size_of_Board+col;
                cout<<"  "<<Game_Array[index]<<" ";
                
                if (col<Size_of_Board-1){
                    if(row < 9)
                        cout<<"  |";
                    else if(row>=9 && row<100 && col==0)
                        cout<<" |";
                    else if(row>=9 && row<100 && col>0)
                        cout<<"  |";
                }
            }
			cout<<"\n";
											
			if (row < Size_of_Board-1){
                for(index=0;index<Size_of_Board-1;index++){
                    if(index==0){
                        cout<<"-------+";
                    }
                    else if(index > 9){
                        cout<<"------+";
                    }
                    else{
                        cout<<"------+";
                    }
				}	
                cout<<"------\n";
			}											
		}                                                        
        return Default_Char;
    }
                    
                    
    int CheckWinner(char *Game_Array,int Player,int Size_of_Board, int Win_Sequence){                 
        int row=0, col=0, count=0, index=0;
        char currentChar;
        currentChar = Player_Sign[Player-1];
                 
        //Checking for every row
        for(row = 0; row < Size_of_Board; row++){
            for (col = 0; col < ( Size_of_Board-(Win_Sequence-1) ); col++){
                //calculating index
                index = (row)*Size_of_Board+(col);
                    
                while (Game_Array[index] == currentChar){
                    col++;
                    index = (row)*Size_of_Board+(col);
                    
                    count++;
                    if (count == Win_Sequence){
                        return Player;
                    }
                }
                count = 0;
            }
        }
                    
        // Checking for every column
        for ( col = 0; col < Size_of_Board; col++){
            for ( row = 0; row < (Size_of_Board-(Win_Sequence-1)); row++){                        
                //calculating index
        
                index = (row)*Size_of_Board+(col);
        
                while (Game_Array[index] == currentChar){
                    row++;
                    index = (row)*Size_of_Board+(col);
                            
                    count++;
                    if(count == Win_Sequence){
                        return Player;
                    }
                }
                count = 0;
            }
        }
                                                         
        // Checking for forwards diagonal 
        for ( col = 0; col < (Size_of_Board - (Win_Sequence-1)); col++){
            for ( row = 0; row < (Size_of_Board - (Win_Sequence-1)); row++){
                //calculating index
                index = (row)*Size_of_Board+(col);
            
                while (Game_Array[index] == currentChar){
                    row++;
                    col++;
                    index = (row)*Size_of_Board+(col);
        
                    count++;
                    if (count == Win_Sequence){
                        return Player;
                    }
                }
                count = 0;
             }
        }
        
        // Check for backwards diagonal 
        for ( col = Size_of_Board-1; col > (Win_Sequence-2); col--){
            for ( row = 0; row < (Size_of_Board-(Win_Sequence-1)); row++){
                //calculating index
                index = (col)*Size_of_Board+(row);
                while (Game_Array[index] == currentChar){
                    row++;                                 
                    col--;  
                    index = (col)*Size_of_Board+(row);
                                            
                    count++;                                   
                    if (count == Win_Sequence){
                        return Player;                      
                    }                                       
                }                                           
                count = 0;                                      
            }                                               
        }
        //Return 0 if no winner calculated
        return 0;           
    }
                    
                    
    char Player_Move(char *Game_Array, int Size_of_Board, int Player){
        do{
            cout<<"\nPlayer "<< Player_Sign[Player-1]<<" :Enter Row and Column(r c): ";
            //flushing cin
            cin.clear();
            fflush(stdin);
            getline (cin, User_Input);
            
            stringstream myinput(User_Input);
            myinput >> token[0] >>  token[1] ;
                                                 
            istringstream(token[0]) >> Row;
            istringstream(token[1]) >> Column;   
            
            if(Row != NULL){
                index_check = (Row - 1) * Size_of_Board + (Column-1);
            }
          
            if(Row == NULL){			
                if(token[0] == q || token[0] == Q){
                    Choice = 'q';
                    break;
                }
                if(token[0] == s || token[0] == S){
                    Choice = 's';
                    break;
                }
                else if(Row>Size_of_Board || Column>Size_of_Board || Row<1 || Column <1){        // Invalid row or column input by user
                    cout<<"\n\nInvalid row/column combination entered. Must be between 1 and "<<Size_of_Board<<". Try Again!";
                    // Choice = 'Q';
                }
            }
        } while(Game_Array[index_check] != ' ' || Row > Size_of_Board ||  Column > Size_of_Board);
        
        if(Choice != 'Q' && Choice != 'q' && Choice != 'S' && Choice != 's'){
            // calculate index from row and column entered
            index = (Row - 1) * Size_of_Board + (Column-1);
            Player_Character = Player_Sign[Player-1];
            Game_Array[index] = Player_Character;
            Choice = Print_Game_Board(Game_Array, Size_of_Board);
        }                                        
        return  Choice;
    }
    
    
    int Play(char* Game_Array, int Number_Of_Players, int Size_of_Board, int Win_Sequence, int Turn_S ){
        int Player = 0;
        int Winner = 0;
        Turn = Turn_S;
        Choice = Print_Game_Board(Game_Array, Size_of_Board);
          
        do{
            Player = (Turn)%Number_Of_Players+1;  
            Choice = Player_Move(Game_Array,Size_of_Board,Player);
          
            if(Choice == 'Q' || Choice == 'q'){
               cout<<"\n\nDo you want to save the game? (Y/N)";
               char doYouWantToSaveGame;
               cin>>doYouWantToSaveGame;
               if(doYouWantToSaveGame == 'Y' || doYouWantToSaveGame == 'y'){
                   Choice = 'S';                   
               }
               else{
                   cout << "Thank you for playing! Quitting game... \n";
                   Sleep(2000);
                   return 1001;
               }
            }
            
            if(Choice == 'S' || Choice == 's'){               
                bool fileOpenStatus = true;
                
                do{
                    fileOpenStatus = true;
                    cout << "\nEnter a .txt file name to save the game with complete path (eg : C:/Users/Savefile.txt): ";
                    cin.clear();
                    fflush(stdin);
                
                    getline(cin, Save_FileName);
                    ofstream outfile;
                    outfile.open(Save_FileName.c_str());
                    
                    if(!outfile){
                        cout<<"\n\nFailed to access file. Try Again ___";
                        Sleep(2000);
                        fileOpenStatus = false;
                        continue;
                    }
                    
                    outfile <<Number_Of_Players << "\n";
                    outfile <<Size_of_Board << "\n";
                    outfile <<Win_Sequence << "\n";
                    outfile <<Turn <<"\n";
                    
                    for(int j=0;j<Size_of_Board*Size_of_Board;j++){    
                        outfile << Game_Array[j];
                    }
                                                
                    outfile.close();
                    
                    cout<<"\n\nGame saved successfully! Location: "<<Save_FileName<<"\nExiting now ...";
                    Sleep(4000);
                                            
                    return 1002;
                } while(!fileOpenStatus);            
            }    
                else{
                    Winner = CheckWinner(Game_Array,Player,Size_of_Board,Win_Sequence);
                    if (Winner != 0){
                        return Winner;
                    }                 
                }   
            
                Turn = Turn+1;              
             
        }while(Turn < Size_of_Board*Size_of_Board);               
        Winner = 1003; // setting Winner as arbitary value to depict draw(Winner should ideally never be greater than 1000)
        
        return  Winner;
    }
};              // end of class TicTacToe


int main(int argc, char **argv){
    int flag = 0; 
    int Game_Array_Size = 0;
    int Turn = 0;
    int index = 0;
    int row, col = 0; 
    char choice;
    int Game_Winner = 0;
    
    // Variables for Resume Game    
    string Resume_Game_String;
    string Temp_String;
    int Resume_Number_of_Players;
    int Resume_Size_of_Board;
    int Resume_Win_Sequence = 0;
    int Resume_Turn = 0;
    string Resume_Game_File;

    //declaring object of class (game instance)
    TicTacToe TictacToe_Game;
    
    cout<<"\n|| ********* Welcome to TIC TAC TOE ********* ||";
    do{
        cout<<"\n\n1. New Game (N)"<<"  2. Resume Saved Game (R)"<<"  3. Quit Game (Q)"<<"\n\n<<Press Q or S anytime to Quit or Save game>>" ;
        
        cout<<"\n\n\nEnter Choice (N/R/Q/S): ";
        cin>>choice;
        
        if(choice == 'Q' || choice == 'q'){
            cout<<"\nQuitting game...";
            Sleep(1200);
            break;
        }
        
        if(choice == 'N' || choice == 'n'){
            cout <<"\nStarting New Game ....";
            do{
                cout << "\nEnter number of players: ";
                cin >> TictacToe_Game.Number_Of_Players;
                flag = TictacToe_Game.Validate_Number_Of_Players(TictacToe_Game.Number_Of_Players); 
            } while(flag!=1);
            
            do{
                cout << "\nEnter Size of Board: ";
                cin >> TictacToe_Game.Size_of_Board;
                flag = TictacToe_Game.Validate_Board_Size(TictacToe_Game.Size_of_Board);
            } while(flag!=1);
            
            cout << "\nEnter the Win Sequence for the game: ";
            cin >> TictacToe_Game.Win_Sequence;
            
            if(TictacToe_Game.Size_of_Board >= TictacToe_Game.Win_Sequence){
                choice = TictacToe_Game.Validate_Game_Possible(TictacToe_Game.Size_of_Board , TictacToe_Game.Number_Of_Players , TictacToe_Game.Win_Sequence);
            }
            
            else{                                                           // terminate game if invalid game configuration entered by user
                choice = 'Q';
            }
                
            if(choice == 'Q' || choice == 'q'){
                cout << "\n!! Invalid game configuration. Quitting game__ !!\n";
                Sleep(2000);
                break;
            }
                       
            Game_Array_Size =TictacToe_Game.Size_of_Board * TictacToe_Game.Size_of_Board  ;
            char  *Game_Array = new char[Game_Array_Size];
        
            //Initialize Game Board to Empty for new game
            TictacToe_Game.Initialize_Game_Array(Game_Array,TictacToe_Game.Size_of_Board*TictacToe_Game.Size_of_Board);
            
            //Starting the game
            Game_Winner = TictacToe_Game.Play(Game_Array, TictacToe_Game.Number_Of_Players, TictacToe_Game.Size_of_Board, TictacToe_Game.Win_Sequence, Turn);
            
            if(Game_Winner < 1000){
                cout << "\n\nCongratulations! Player " << Game_Winner << " Wins !!! ";
                cout << "\n\nThank you for playing! Quitting ___";
                Sleep(5000);
            }
            
            else if(Game_Winner == 1003){
                cout << "\n\n The Game is a draw";
                cout << "\n\nThank you for playing! Quitting ___";
                Sleep(5000);
                choice = 'Q';
            }
            
            else{ // Either user has pressed Q to quit or S to save, in either case, the game quits after approrpiate message
                choice = 'Q';
            }                   
            
            break;
        }
             
        if(choice == 'R' || choice == 'r'){                                  // restore a saved game
            cout<<"\nResuming Game ... \n";
            
            bool fileOpenStatus;
            do{
                fileOpenStatus = true;
                cout << "\n Enter a .txt file name to resume the game with complete path (eg : C:/Users/Savefile.txt): ";
                cin.ignore(INT_MAX, '\n');
                getline( cin, Resume_Game_File);
                
                ifstream thefile;
                
                thefile.open(Resume_Game_File.c_str());
                
                if(!thefile){
                    cout<<"\n\nFailed to access file. Try Again ___";
                    Sleep(2000);
                    fileOpenStatus = false;
                    continue;
                }
                
                thefile >> Resume_Number_of_Players;
                thefile >> Resume_Size_of_Board;
                thefile >> Resume_Win_Sequence;
                thefile >> Resume_Turn;
                
                thefile.close();
                
                //Read last line
                ifstream readlastline;
                readlastline.open(Resume_Game_File.c_str());
                
                if(readlastline.is_open()) {
                    readlastline.seekg(-1,ios_base::end);                
                
                    bool keepLooping = true;
                    while(keepLooping){
                        char readch;
                        readlastline.get(readch);                            
    
                        if((int)readlastline.tellg() <= 1) {             
                            readlastline.seekg(0);                      
                            keepLooping = false;                
                        }
                        
                        else if(readch == '\n') {                  
                            keepLooping = false;                
                        }
                        
                        else {                                  
                            readlastline.seekg(-2,ios_base::cur);      
                        }
                    }
        
                                getline(readlastline,Resume_Game_String);    
                }
                
                readlastline.close();
                        
                char *Resume_Game_Array = new char[Resume_Size_of_Board*Resume_Size_of_Board];
                
                for(index = 0; index <Resume_Size_of_Board*Resume_Size_of_Board  ; index++){
                    Resume_Game_Array[index] = ' ';
                }
                        
                for(int i = 0; i<Resume_Game_String.length(); i++){
                    if(Resume_Game_String.at(i)!=' '){
                        Resume_Game_Array[i] = Resume_Game_String.at(i);
                    }
                }
                                    
                Game_Winner = TictacToe_Game.Play(Resume_Game_Array, Resume_Number_of_Players, Resume_Size_of_Board, Resume_Win_Sequence,Resume_Turn );
                    
                if(Game_Winner < 1000){
                    cout << "\n\nCongratulations! Player " << TictacToe_Game.Player_Sign[Game_Winner-1] << " Wins!!\n";
                }
                
                else if(Game_Winner == 1003){
                    cout << "\n\n The Game is a draw\n";
                    choice = 'Q';
                }
                
                else{ // Either user has pressed Q to quit or S to save, in either case, the game quits after approrpiate message
                    Sleep(1500);
                    choice = 'Q';
                }                
                break;
            } while (!fileOpenStatus);
        } // End of resume routine
        
        else {                  // Invalid input entered, inform user and prompt for new input
            cout<<"\n\nInvalid input entered! Quitting game ...";
            Sleep(3000);
            break;
        }
    } while(choice!='Q');
        
	return 0;
}

