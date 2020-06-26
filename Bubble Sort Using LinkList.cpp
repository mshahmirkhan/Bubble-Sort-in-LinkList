#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
double data; // data
Node* next; // pointer to next
};
class List
{
public:
List(void) { head = NULL; } // constructor
~List(void); // destructor
Node* InsertNode( double x);
int DeleteNode(double x);
void DisplayList(int size,bool boo);
void bubbleSort(int arr[], int n);
private:
Node* head;
};



Node* List::InsertNode( double x)
{
	Node* newNode = new Node;
	newNode->data = x; 
	newNode->next = head;
	head= newNode;

return newNode;
}




int List::DeleteNode(double x)
{
	Node* currNode = head;
	head=head->next;
	free(currNode);

return 0;
}



void List::DisplayList(int size,bool boo)
{
	if(size==0)
	{
		cout<<"\n\nList is empty";
		return;
	}
int data[size]={0},i=0;
Node* currNode = head;
while (currNode != NULL)
{
	data[i]=currNode->data;
	currNode = currNode->next;
	i++;
 }
 if(boo){
 	
 	bubbleSort(data, size); 
    cout<<"\nElement of the link list after Sort:\n";
 }else{
 	
    cout<<"\nElement of the link list without Sort:\n";
 }
      for(int i=0;i<size;i++)
      {
    	 cout<<data[i]<<" ";
    	 cout<<endl;
      }
}

  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void List::bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
} 
List::~List(void)
{
}




int main(void)
{
List list;

	int data,Stime=1,SNentries=0,tempArrSize=0 ;
	char choice2,sel;
do{
	int choice,Nentries;
	cout<<"BUBBLE SORT WITH LINK LIST \n\n";
	cout<<"Choose any of the follwing option \n\n";

	cout<<"1_  INSERTION \n";
	cout<<"2_  DELETION \n";
	cout<<"3_  SORT\n";
	cout<<"4_  EXIT\n";
	
	cout<<"\nENTER YOUR CHOICE: \n";
	cin>>choice;
	
	switch(choice){
		case 1:
			if(Stime==1){
			cout<<"how many Entries you want to insert: ";
			cin>>Nentries;
			cout<<"\nENTER "<<Nentries<<" elements in Link List:\n";
			
				
					for(int i=1;i<=Nentries;i++)
					{
					cin>>data;
					list.InsertNode(data);
					}	
					cout<<"\n";
					list.DisplayList(Nentries,1);
					tempArrSize=Nentries;
				}
				else{
					
			cout<<"\nHow many Entries you want to insert: ";
			cin>>SNentries;
			cout<<"\nENTER "<<SNentries<<" elements in Link List:\n";
			
				
					
					for(int i=1;i<=SNentries;i++)
					{
					cin>>data;
					list.InsertNode(data);
					}
					cout<<"\n\nDo you  want to sort the elements? Enter Y/N:";
					cin>>sel;	
					if(sel == 'y' || sel == 'Y'){
						list.DisplayList(SNentries+Nentries,1);
					}else{
						list.DisplayList(SNentries+Nentries,0);
					}
					tempArrSize=SNentries+Nentries;
				}
				Stime++;
			break;
		
		case 2:{
			cout<<"\n\n\nHow many recent elements you want to remove ? : ";
			cin>>Nentries;
			if(tempArrSize<Nentries){
				cout<<"\nI'm sorry but List Size is "<<tempArrSize;
				break;
			}
				
			for(int i=1;i<=Nentries;i++)
				{
					list.DeleteNode(i);
				}
				tempArrSize=tempArrSize-Nentries;
			cout<<"\n "<<Nentries<<" elements is DELETED ";
			
			
					cout<<"\nDo you  want to sort the elements? Enter Y/N:";
					cin>>sel;	
					if(sel == 'y' || sel == 'Y'){
						list.DisplayList(SNentries+Nentries,1);
					}else{
						list.DisplayList(SNentries+Nentries,0);
					}
				
			break;
		}
		case 3:{
				list.DisplayList(tempArrSize,1);
			break;
		}
		case 4:{
			
				cout<<"\n GOOD BYE :-\n\n ";
			break;
		}
		default:cout<<"\n\nThis is not an option (TRY AGAIN)";
	}

 
	cout << "\n\nDoyou want to repeat the program? Enter Y/N:  ";
    cin >> choice2;
    system("CLS"); 
} while (choice2 == 'y' || choice2 == 'Y');


}
