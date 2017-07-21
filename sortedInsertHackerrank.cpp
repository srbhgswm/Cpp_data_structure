#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

Node* SortedInsert(Node *head,int data);
void print(Node* head);

int main(){
	int N, data; Node* head = NULL;
	cout<<"Enter the number of data you want to input: ";
	cin>>N;cout<<endl;
	for(int i=0;i<N;i++){
		cout<<"Enter a number: ";
		cin>>data;
		cout<<endl;
		head = SortedInsert(head,data);
		print(head);
		cout<<endl;
			}
	return 0;
}

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
    if (head == NULL){
        head = new Node; head->data = data; head->prev = NULL; head->next = NULL; 
    }
    else {
	Node* i = head; Node *temp1, *temp2;
        while (i != NULL){
            if (data > i->data){
                temp1 = i;
                temp2 = i->next;
                i = i->next;
            }
            else if (head->data > data) { temp1 = NULL; temp2= head; break; }
            else break;
        }
        Node* insNode = new Node;
        insNode->prev = temp1; insNode->next = temp2; insNode->data = data;
        if (temp2 != NULL) temp2->prev = insNode;
        if (temp1 != NULL) temp1->next = insNode;
        else head = insNode;
    }
    return head;
}

void print(Node* head){
	Node* i = head;
	while(i != NULL){
		cout <<"It is " << i->data << " " << i << endl;
		i = i->next;
			}
}
