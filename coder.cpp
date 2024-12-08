#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string> 
using namespace std; 

struct Node; 
struct charFrequency;

vector<Node> allNodes;

int change_node_number; 

charFrequency* head_charFrequency = NULL;

struct Node{
    int weigth; 
    Node* left;
    Node* right;
    Node* parent;
    Node(int w=1, Node* l=NULL, Node* r=NULL){
        weigth = w;
        left = l;
        right = r;
    }
    ~Node(){

    }
}

struct charFrequency{
    unsigned char ch;
    Node* p_Node;
    charFrequency* next_char;
}

void charFrequencyLinkedList (charFrequency** head, unsigned char* read_value){
    while(*head != NULL){
        if(head -> next_char == read_value){
            head -> weigth++;
            change_node_number = *head;
            return;
        }
        head = head -> next_char;
    }
    charFrequency* temp = (charFrequency*)malloc(sizeof(struct charFrequency));
    temp -> ch = read_value;
    temp -> next_char = NULL;
    temp -> p_Node = Node;
    if (*head != NULL)  {temp -> next_char = *head;}
    *head = temp;
    allNodes.push(Node);
}

void sortNodes(unsigned char** ch){

    
}

void loadDatafromFile(string* path){

    int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0, greyscale = 0;

    ifstream FILE;
    FILE.open(path, ios::binary);

    if (FILE.good()==false)
    {
        cout<<"Error"<<endl;
        exit(0);
    }

    string line = "";
    char first_char = '';

    getline(FILE, line); // get P number
  
    do
    {
        FILE.get(first_char);   // get any comments 

        if (first_char == "#")  {getline(FILE, line);}
        else {FILE.unget();}

    }while(first_char == "#");

    FILE >> num_of_rows >> num_of_cols >> greyscale; // picture size - X, Y, Greymap

    unsigned char pixel;
    for (int row=0; row<num_of_rows; row++)
    {
        for (int col=0; col<num_of_cols; col++)
        {
            FILE >> pixel;
            charFrequencyLinkedList(&head_frequency, &pixel);
            sortNodes(&change_node_number);  
        }
    }

    FILE.close();
}


void makeCodes(){

}

void showCodes(){

}

void freeMemory(){

}

int main() 
{
    string path = "barbara.pgm";

    loadDatafromFile(&path); 

    makeCodes();

    showCodes();

    freeMemory();

	return 0; 
} 



