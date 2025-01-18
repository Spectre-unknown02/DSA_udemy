#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;
    node(int value){
        this->value = value;
        this->next = nullptr;
    }
};

class queue{
    private:
    node *first;
    node *last;
    int length;
    public:
    queue(int value){
        node *newnode = new node(value);
        first = last = newnode;
        length = 1;
    }

    void printq(){
        node *temp = first;
        while(temp){
            cout<<temp->value;
            temp = temp->next;
        }
    }

    void gettop(){
        cout<<first->value<<endl;
    }
    void getlast(){
        cout<<last->value<<endl;
    }
    void enqueue(int value){
        node *newNode = new node(value);
        if(length ==0){
        first = last = newNode;
        }
        else{
            last->next = newNode;
        }
        length++;
    }

    void dequeue(){
        if(length==0){
            return;
        }
        else if(length==1){
            delete last;           
            first = last = nullptr;
        }
        else{
            node *temp = first;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = nullptr;
            last = temp;
        }
        length --;
    }
};