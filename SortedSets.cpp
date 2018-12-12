/*@desc 
 * Write a sorted set data structure using binary search trees. 
 * Then, read in numbers from a file named infile.dat, inserting them into an instance of your sorted set. 
 * You will then prompt the user for a value, and search the tree to determine if the value is found in the tree. 
 * If the value is present, output "Yes" and no other text. 
 * If the value is missing, output "No" and no other text.
 * 
 * Example:
 * infile.dat
 * 1, 2, 3, 4, 5, 6, 7
 * Program
 * Sorted Set A Contains 1, 2, 3, 4, 5, 6, 7
 * User Input = 9
 * Output
 * No
 *
 *@author Rahul_Sharma, Vishwajeet_Kakde
 */

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
#include <fstream>

using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

class BST{
private:
    // A utility function to create a new BST node
    struct node *newNode(int item){
        struct node *temp =  (struct node *)malloc(sizeof(struct node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }
    
    /* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. */
    struct node * minValueNode(struct node* node){
        struct node* current = node;
    
        /* loop down to find the leftmost leaf */
        while (current->left != NULL){
            current = current->left;            
        }
    
        return current;
    }
  
    void inorder(struct node *root){
        if (root != NULL){
            inorder(root->left);
            printf("%d \n", root->key);
            inorder(root->right);
        }
    }

public:
/* A utility function to insert a new node with given key in BST */
    node* insert(node* node, int key){
        /* If the tree is empty, return a new node */
        if (node == NULL) return newNode(key);
    
        /* Otherwise, recur down the tree */
        if (key < node->key)
            node->left  = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);   

	/* return the (unchanged) node pointer */
	return node;
    }
    

    /* Given a binary search tree and a key, this function deletes the key
    and returns the new root */
    struct node* deleteNode(node* root, int key){
        // base case
        if (root == NULL){
            return root;
        }
    
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        if (key < root->key){
            root->left = deleteNode(root->left, key);
        }
    
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (key > root->key){
            root->right = deleteNode(root->right, key);
        }
    
        // if key is same as root's key, then This is the node
        // to be deleted
        else{
            // node with only one child or no child
            if (root->left == NULL){
                node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                node *temp = root->left;
                free(root);
                return temp;
            }
    
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node* temp = minValueNode(root->right);
    
            // Copy the inorder successor's content to this node
            root->key = temp->key;
    
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
    
    
    /* function to search an element in a binary search tree */
    node* search(node* root, int key){
        // Base Cases: root is null or key is present at root
        if (root == NULL || root->key == key){
            return root;
        }
        
        // Key is greater than root's key
        if (root->key < key){
            return search(root->right, key);
        }
    
        // Key is smaller than root's key
        return search(root->left, key);
    }  
  
public:    
    /* function to test if binary search tree is empty */
    bool isEmpty(node* root){
        if(root == NULL){
            return true;
        }
        false;
    }
};

class SortedSets : public BST{
public:
    node *add (node *node, int key){
        struct node *root = insert(node, key);
        return root;
    } 
    node *remove(node *node, int value){
        struct node *root = deleteNode(node, value);
        return root;
    }
    node *contains(node *node, int value){
        struct node *root = search(node, value);
        return root;
    }
};
 
int main(){
    node *root = NULL;
    SortedSets X;
    vector<int> numbers;
    int value;
    char filename[500];
    
    char choice;
    while(choice!='q'){
        cout<<"\n\nSortedSet Menu\n1.Read insertion input from file\t2.Search\t\n\nEnter Choice:  ";
        cin>> choice;
        
        if(choice == 'q'){
            exit(0);
        }
        
        else if(choice == '1'){
            cout<<"\n\nEnter complete file path and name: ";
            cin>>filename;
            // cin.getline(filename, 500);  // <- to allow whitespaces
            std::fstream filestream(filename, ios::in);
                
            if (filestream) {        
            // read the elements in the file into a vector  
            while ( filestream >> value){
                numbers.push_back(value);
                }            
            }
            
            for(std::vector<int>::iterator it = numbers.begin() ; it != numbers.end(); ++it){
                root = X.add(root, *it);	
                cout<<*it<<"  ";
            }
        }
        
        else if(choice == '2'){
            cout<<"\n\nEnter element to search: ";
            int element;
            cin>>element;
            
            node *res = X.contains(root, element);
            
            if(res==NULL){
                cout<<"\nNo";
            }
            else{
                cout<<"\nYes";
            }
        }

        else{
            cout<<"\nInvalid choice entered!!";
            Sleep(3000);
        }
    }
    return 0;
}

