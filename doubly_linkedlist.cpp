#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node *next;
    node *prev;
    node(int value){
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class doubly_ll{
    private:
    node *head;
    node *tail;
    int length;
    public:
    doubly_ll(int value){
        node *newNode = new node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void print_list(){
        node *temp = head;
        while(temp){
            cout<<"following value of the list is "<<temp->value;
        }
        return;
    }
/* one heck of a way to do it.
    void append(int value){
        node *newNode1 = new node(value);
        if(length == 0){
            head = tail = newNode1;
        }
        else{
            node *temp = head;
            node *pre = head;
            while(temp!=nullptr){
                pre = temp;
                temp=temp->next;
            }
            temp->next = newNode1;
            newNode1->prev = pre;
        }
    }
*/
    void append(int value){
        node *newNode1 = new node(value);
        if(length == 0){
            head = tail = newNode1;
        }
        else{
            tail->next = newNode1;
            newNode1->prev = tail;
        }
        length++;
    }

    void delete_last(){
        if(length==0) return;
        else if(length == 0){
            head = tail = nullptr;
        }
        else{
            // node *temp = head;
            // while(temp->next){
                // temp = temp->next;
            // }
            // temp->next = nullptr;
            // tail = temp;
            tail = tail->prev;
            tail->next =  nullptr;
        }
        length --;
    }

    void prepend(int value){
        node *newNode = new node(value);
        if(length==0){
            head = tail = newNode;
        }
        else{
        head->prev = newNode;
        head = newNode;}
        length++;
    }

    void delete_first(){
        if(length == 0){
            nullptr;
        }
        else if(length == 1){
            head = tail = nullptr;
        }
        else{
            head = head ->next;
            head-> prev = nullptr;
        }
        length --;
    }

    node *get(int index){
        if(index<0 || index>=length) return nullptr;
        node *temp = head;
        //while(temp != index){   // biggest error - node address cannot be compared to an integer.
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp;
    }

    node *set(int index, int value){
        if(index<0 || index>=length) return nullptr;
        node *temp = head;
        for(int i=0; i< index; i++){
            temp = temp->next;
        }
        temp->value = value;
        return temp;
    }

    node *insert_node(int index, int value){
        if(index<0 || index> length) return nullptr;
        node *newNode = new node(value);
        if(length == 0){
            append(value);
        }
        if(index == length ){
            append(value);
        }
        node *temp = head;
        for(int i=0; i<index-1; i++){
            temp = temp->next;
        }
        temp->next = newNode;
        length ++;
        return temp->next;
    }

    node *deleteNode(int index){
        if(index<0, index>length){return nullptr;}
        node *temp = head;
        node *pre = head;
        if(length==0){
            return nullptr;
        }
        for(int i=0; i<length; i++){
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        delete temp;
        length--;
    }
    node *
};

