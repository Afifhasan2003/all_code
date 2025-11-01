//https://www.youtube.com/watch?v=Nq7ok-OyEpg
//from striver's linkedlist playlist

#include <bits/stdc++.h>
using namespace std;

// struct Node  both will work..but class is better
class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int> arr){  //we always return the head
    Node* head = new Node(arr[0]);
    Node* mover = head;                 //cant change head, we will return it

    for (int i = 1; i < arr.size(); i++)  //start from 1, coz arr[0] is already on first element
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;     //here mover is previous node, so we can change its next pointer
        mover=temp;             //now mover is the current node
    }

    return head;


}
int traversal(Node* head){
    Node* temp= head; // dont wanna mess with head
    int lenght=1;

    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        lenght++;
    }
    cout<<endl;

    return lenght;
}
bool checkElement(Node* head, int target){
    Node* temp= head; 
    

    while (temp)
    {
        if(temp->data ==target)
            return true;

        temp=temp->next; 
    }
    return false;
}
Node* deleteHead(Node* head){
    if(head==NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;  
    return head;

}
Node* deleteTail(Node* head){

    if(head==NULL || head->next==NULL ) 
        return NULL;


    Node* temp = head;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
     
    return head;
}
Node* deleteOnPosition(Node* head,int k){
    if(!head){
        return head; 
    }
    else if (k==1)
    {
        // return head->next;  just this much would be fine.. but for clearing the memory space

        Node* temp = head;
        head=head->next;
        free(temp);
        return head; 
    }
    
    Node* temp = head;
    for (int i = 1; i < k-1 && temp->next != NULL ; i++)
    {
        temp= temp->next;
    }

    temp->next = temp->next->next;

    

    return head;
}
Node* deleteOnPosition2(Node* head,int k){
    //using previous pointer
    if(!head) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* current = head;
    Node* previous = nullptr;   //to keep track of previous node
    int count = 1;
    while (current && count < k) {
        previous = current;  //move previous to current
        current = current->next;  //move current to next
        count++;
    }
    if (current) {  //if current is not null, we found the position
        previous->next = current->next;  //link previous to next of current
        delete current;  //delete current node
    }
    return head;
}
//using only current pointer

Node* deleteTarget(Node* head,int target){
    if(!head) return head;

    if(head->data == target){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next && current->next->data != target)
    {
        current = current->next;
    }

    if(current->next){ //if we found the target
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}
Node* deleteALLTarget(Node* head, int target) {
    if (!head) return head;

    // Remove leading nodes with the target value
    while (head && head->data == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == target) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

Node* insertAtFirst(Node* head,int k){

    // Node* temp = new Node(k);
    // temp->next = head;
    // return temp;

    return new Node(k,head);    //it will do the same
                                //returning a node whose next is head
}
Node* insertAtLast(Node* head, int k){

    if (!head) return new Node(k);

    Node* temp = head;
    Node* temp2 = new Node(k);
    while (temp->next)
    {
        temp=temp->next;
    }
    temp->next = temp2;

    return head;
    
}
Node* insertAtPosition(Node* head, int p, int k){
    if( p == 1) return new Node(k,head);    // now doesnt matter if head is null or first

    Node* temp = head;
    Node* prev = nullptr;

    int count=1; 
    while (temp && count<p)
    {
        prev = temp;
        temp= temp->next;
        count++;
    }
    Node* temp2 = new Node(k,temp);
    prev->next = temp2;
    
    return head;
    
}
Node* insertBefoValue(Node* head, int v,int k){
    if(!head) return head;    // now doesnt matter if head is null or first
    
    if(head->data ==v ){
        Node* temp = new Node(k,head);
        return temp;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp && temp->data !=v)
    {
        prev = temp;
        temp= temp->next;
        
    }
    Node* temp2 = new Node(k,temp);
    prev->next = temp2;
    
    return head;
}

int main() {
    
    vector<int> arr={2,5,1,3,4,7,5,11,5,8,1,6,5,9};


    // Node* y = new Node(arr[0],nullptr);
    // cout<<y<<endl;
    // cout<<y->data <<endl;


    Node* head = convertArrayToLL(arr);
    // cout<<head->data<<endl;

    cout<<"Full linkedList is: ";
    traversal(head);


    if(checkElement(head, 8)){
        cout<<"8 is present in the linkedlist"<<endl;
    } else cout<<"8 is not present in the linkedList"<<endl;



    // head= new Node(69,head);     this will do too ,returning a node whose next is head
    head = insertAtFirst(head,69);
    cout<<"After adding 69 at first: ";
    traversal(head);

    head = insertAtLast(head, 100);
    cout<<"After adding 100 at last: ";
    traversal(head);

    head = insertAtPosition(head,3,200);
    cout<<"after adding 200 at third: ";
    traversal(head);

    head = insertBefoValue(head, 3, 999);
    cout<<"after adding 999 before 3: ";
    traversal(head);










    // head=deleteHead(head);
    // cout<<"after removing head: ";
    // traversal(head);

    // head=deleteTail(head);
    // cout<<"after removing last: ";
    // traversal(head);

    // int k=1;
    // head = deleteOnPosition(head,k);
    // cout<<"after deleting on position "<< k <<": ";
    // traversal(head);

    // head = deleteTarget(head, 1);
    // cout<<"after deleting target 1: ";
    // traversal(head);
    // head = deleteALLTarget(head, 5);
    // cout<<"after deleting all target 5: ";
    // traversal(head);

    return 0;
}