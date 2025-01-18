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

class Linked_list{
    private:
    node *head;
    node *tail;
    int length;
    public:
    Linked_list(int value){
        node *Node1 = new node(value);
        head = Node1;
        tail = Node1;
        length = 1;
    }
    ~Linked_list(){
        node *temp = head;
        while(temp){
            head = head->next;
            delete temp;
            temp = head;
        }    //we dont add destructor for head, tail, length or temp here because following is in linked list and when we call linked list,
            //   default destructor clears out the data for the it... whereas the Node is different class and does not clear out hence we define a destructor for the   Node class.
    }

    void printList(){
        node *temp = head;
        while(temp != nullptr){
            cout << temp->value;
            temp = temp->next;
        }
        
    }

    void getHead(){
        cout<< head->value;
    }

    void getTail(){
        cout<< tail ->value;
    }

    void getLength(){
        cout<< length;
    }

    void append(int value){
        node *newNode = new node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void delete_last()
    {
        if(length == 0){
            return;
        }
        else if(length==1){
            delete tail;
            head = tail = nullptr;
        }
        else{
            node *temp = head;
            node *pre = head;
            while(temp)
            {
                pre = temp;
                temp = temp->next;
            }
            delete temp;
            tail = pre;
            }
            length --;
    }

    void deletefirst(){
        if(length == 0)
        {
        return;
        }
        else if(length==1)
        {
        delete tail;
        head = tail = nullptr;
        }

        else{
            node *temp = head;
            head = head -> next;
            delete temp;
        }
        length --;
    }
    
    void prepend(int value){
       node *newNode = new node(value);
       if(length==0){
        head = tail = newNode;
       } 
       else{
        newNode->next = head;
        head = newNode;
       }
       length++;
    }

    void deletefirst(){
        if(length==0) return;
        else if(length == 1){
            delete head;
        }
        else{
            node *temp = head;
            head = head ->next;
            delete temp;
        }
        length --;
    }

    node *get(int index){
        if(index<0 || index>=length) return nullptr;
        node *temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp;
    }

    node *set(int index, int value){
        if(index<0 || index>= length){ return nullptr;}
        node *temp = head;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        temp->value = value;
        return temp;
        }

    /*node *insert(int index, int value){      //something that will cause lota of problem
        if(index<0 || index>length){
            return nullptr;
        }
        node *newNode = new node(value);
        if(index==0){
            prepend(value);
        }
        else if(index==length-1){
            append(value);
        }
        else{
            node *newNode = new node(value);
            node *temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        length++;
        return newNode;
    }
    */      //instead write the whole code to insert.... //use the whole logic in simple one code.

    node *insert(int index,int value)
    {
        if(index<0 || index >length) {return nullptr;}
        node *newNode = new node(value); 
        if(index == 0){
            head = tail = newNode;
        }
        else if(index == length){
            tail->next = newNode;
        }
        else{
            node *temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        length++;
        return newNode;
    }


    node *deleteindex(int index){
        if(index<0 || index >length) {return nullptr;}
        node *temp = get(index-1);
        if(index==0){
            temp = temp->next;
            head = head->next;
            delete temp;
        }
        else if(index==length){
            delete tail;
            tail = temp;
        }
        else{
            node *tempp = get(index);
            temp->next = tempp->next;
            delete tempp;
        }
        length--;
        return nullptr;
    }

    void reverse(){
        node*temp = head;
        head=tail;
        tail=temp;
        node *before;
        node *after = temp->next;
        while(temp!=head){
            temp->next=before;
            before = temp;
            temp = after;
            after = after->next;
        }
    }

    //find middle node -- using the logic of fast and slow node... fastest node skips 2 place whereas slowest node skips 1 place

    /*node *middleNode(){
        node *fast=head;
        node *slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    */

   node *middleNode(){
    node *temp = head;
    int countnode =0;
    while(temp){
        countnode++;
        temp=temp->next;
    }
    int middlenode = countnode/2;
    node *pp = head;
    for(int i=0;i<middlenode;i++){
        pp=pp->next;
    }
    return temp;
   }

   bool hasloop(){
    node *slow =head;
    node *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {return true;}
        return false;
    }
   }

   node *findKthFromEnd(int k){
    node *slow = head;
    node *fast = head;
    for(int i=0; i<k;i++){
        fast=fast->next;
        if(fast != nullptr){return nullptr;} //if fast reaches nullptr first then the kth spot was too big to fill in.    
    }
    while(fast!=nullptr){
        slow=slow->next;
        fast = fast->next;
    }
    return slow;
   }

   
};

int main() {
    Linked_list *LL1 = new Linked_list(20);
    LL1->getHead();
    LL1->getLength();
    LL1->getLength();
    LL1->append(22);

}