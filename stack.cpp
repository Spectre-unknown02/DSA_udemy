#include <iostream>
using namespace std;

class node
{
    public:
    int value;
    node *next;
    node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
class stack
{
    private:
    node *top;
    node *bottom;
    int height;
    public:
    stack(int value)
    {
    node *newNode = new node(value);
    top = bottom = newNode;
    height = 1;
    }

    void printstack(){
        node *temp = top;
        while(temp){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

    void gettop(){
        cout<<top->value<<endl;
    }
    void getbottom(){
        cout<<bottom->value<<endl;
    }

    void push(int value){
        node *newnode = new node(value);
        bottom ->next = newnode;
        bottom = newnode;
        height++;
    }

    void pop(){
        if(height == 0){return;}
        node *temp = top;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = nullptr;
        bottom = temp;
        return;
    }
};

void main(){
    stack *stack1 = new stack(5);
}
   
