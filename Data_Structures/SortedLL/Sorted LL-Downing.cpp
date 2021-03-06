#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct node			//A structure, which contains all the data (int + pointer) for each element (node) in the linked list
{
	int data;		//This will contain the number which the user wishes to add  to the list.
	node *next;		//This will point to the next node.
};

void Enter(void);				//Each function handles a different part of the program.
void Manual(void);				//They are named logically and should explain themselves
void File(void);

int Add(int a, node **head);
int Remove(int a, node **head);
void Destroy(node **head);
void Print(node **head);

int main()
{
	int opt = 0, end = 0;
	
	do{
		cout<<"LINKED LISTS \n";		//Intro/Options you can enter.
		cout<<"\nHow would you like to run this program? \n";
		cout<<"1 => Manual Entry \n";
		cout<<"2 => File Entry \n";
		cout<<"3 => Quit \n";
		
		do{
			cout<<"\nEnter an option. => ";	//type a number in and press enter.
			cin>>opt;
		}while(opt != 1 && opt != 2 && opt != 3);	//Can only enter options 1, 2 or 3
		
		switch(opt)
		{
			case 1:	//Manual Entry
					system("cls");		//clear the screen
					Manual();			//call up Manual function - handles user entry
					break;
			case 2:	//File Entry
					system("cls");		//clear the screen
					File();				//call up File function - handles file entry
					break;
			case 3: 
					cout<<"\nQuitting... \n=>";
					Sleep(5000);    //pause for 5 seconds
					end = 1;		//Ends the program as the main do/while loop ends.
					break;
		}
   		system("cls");	//clear the screen
	}while(end != 1);	//Only ends when 1 is entered.
}

void Enter(void)	//This function is just to stop the screen from ending quickly - makes the user hit enter before the program continues.
{
	char c;
	
	do{
		cout<<"\nPress ENTER to continue. => ";	//PRESS ENTER!!
        c = getch();
   	}while(c != 13);	//Only ends when the user presses ENTER
}

void Manual(void)	//This function does the manual entry portion of the program.
{
	int a = 0, end = 0, x = 0, ret = 0;	//a is for user inputs, end for ending this function, x for function selection and ret for values returned by functions.
	node *head = NULL; 		//head of the linked list - points to the start of the list. Set to NULL as there aren't any elements in the list (yet).
	
	do{
		cout<<"Manual Entry. \n\n";				//Intro/Options you can enter
		cout<<"What do you want to do? \n";		
		cout<<"1 => Add \n";						//Each number is used in a switch
		cout<<"2 => Remove \n";					//to call up the function requested.
		cout<<"3 => Print \n";
		cout<<"4 => Quit \n";
		
		do{
			cout<<"\nEnter an option => ";		//type a number in and press enter
			cin>>x;
		}while(x != 1 && x != 2 && x != 3 && x != 4 && x != 5);	//can only enter 1-5 otherwise the above message repeats endlessly
		
		switch(x)
		{
			/*
			NOTE FOR FUTURE:
			The "&" is a REFERENCE to the pointer head. This means changing head in the given function will change the 'head' refered to in THIS function. 
			This must be done or else the list will seem to be empty to the print function (as the above 'head' will still be NULL) and adding will not work as
			head will still be NULL and it won't point to any nodes!
			*/
			case 1:
					cout<<"\nHow much do you want to add? \n";	//Ask user for input.
					cout<<"Enter it here. => ";	
					cin>>a;										//Take an input from the user.
					ret = Add(a, &head);								//Sends the input to the add function	
					
					if(ret == 0)							//everything went fine
						cout<<'\n'<<a<<" was added. \n";
					if(ret == -1)							//There was an error when adding a to the list.
						cout<<"ERROR! Memory allocation failed! \n";					
					break;									
			case 2:												
					cout<<"\nWhat number would you like to remove? \n";	//Ask user for input
					cout<<"Enter it here. => ";
					cin>>a;
					ret = Remove(a, &head);		//make ret equal to what the Remove function outputs
					
					if(ret == a)							//if ret = a, then the number was removed successfully
						cout<<'\n'<<a<<" was removed. \n";
					if(ret == -1)							//-1 means the number wasn't found in the list
						cout<<"\nThe number entered was not found in the list! \n";	
					if(ret == -2)							//-2 means the list is empty!
						cout<<"\nERROR! The list is empty! \n";				
					break;												
			case 3:
					Print(&head);	//Print Function
					break;
			case 4:
					cout<<"\nGood bye! :( \n";
					end = 1;	//breaks the do/while loop so the program returns to the main.
					break;
		}
		Enter();		//Calls up the press enter to continue function
   		system("cls");	//Clears the screen
	}while(end != 1);
	
	Destroy(&head);		//This deletes all the elements in the linked list (frees up the memory taken by the nodes)
}

void File(void)
{
	ifstream entry;		//ifstream for opening the file
    string filename;    //string to hold the filename
    string command;     //string to hold each line in the file
    string hold;		//string that holds the first part of command
    string input;		//string to hold the input (ie '3') that will then be converted to an int
	int num = 0;		//final num to sent to the functions
	int code = 0;		//code that holds the return value of the functions
	char c;             //press enter variable
    int a, x = 1;		//x is for the do/while loop
    
    node *head = NULL; 		//head of the linked list - points to the start of the list. Set to NULL as there aren't any elements in the list (yet).
    
    cout<<"FILE ENTRY \n\n";
    cout<<"What is the name of the file you would like to open? \n";
    cout<<"Enter it here: -> ";
    cin>>filename;		//make sure to enter the full name ie data1.txt
    cout<<'\n';
    entry.open(filename.c_str());	//opens the file, using the name the user entered in
    
    if(!entry)     //if the file does not open, this is true.
    {              //the below errror will then print out.
        cout<<"Unable to open the selected file! \n";
        Sleep(5000);    //pause for 5 seconds
        exit(0);        //exit the program
    }
    
    do{
		num = 0;
		getline(entry, command, '\n');
		
		//ADD Command
        if(strncmp(command.c_str(), "ADD", 3) == 0)	//this detects the ADD command by comparing the line in the file to the string 'ADD' (up to 3 chars)
        {									//the first issue to get the number to be sent to the ADD function:
			cout<<"\n*** ADD Function. *** \n";
			//split the string into two - hold string (add) and input string (#s)
			istringstream str(command);		//stream to take command, so that it can be split into two different strings
			while(!str.eof())
			{
				getline(str, hold, ' ');	//take the command part of the command string and put into the hold string.
				getline(str, input, '\n');	//take the number to be ADDED into the input string.
			}
			//now convert the input string that contains #s to an int
			num = atoi(input.c_str());	//convert the input string to an int.
			
			//now pass the num int to the push function
			code = Add(num, &head);	//the following works just like the manual part of the program
            if(code == 0)				//if ADD returns zero, everything worked fine so print the num with a message to the user.
                cout<<num<<" was added to the list. \n";	//message says everything is working.
            if(code == -1)				//if ADD returns -1 bad things happened and therefore something went wrong
				cout<<"ERROR! Memory allocation failed! \n";	//aka memory allocation failed
		}
        
        //REMOVE Command
		if(strncmp(command.c_str(), "REMOVE", 6) == 0)	//this detects the REMOVE command by comparing the line in the file to the string 'REMOVE' (up to 6 chars)
        {									//the first issue to get the number to be sent to the REMOVE function:
			cout<<"\n*** REMOVE Function. *** \n";
			//split the string into two - hold string (remove) and input string (#s)
			istringstream str(command);		//stream to take command, so that it can be split into two different strings
			while(!str.eof())
			{
				getline(str, hold, ' ');	//take the command part of the command string and put into the hold string.
				getline(str, input, '\n');	//take the number to be ADDED into the input string.
			}
			//now convert the input string that contains #s to an int
			num = atoi(input.c_str());	//convert the input string to an int.
			
			//now pass the num int to the push function
			code = Remove(num, &head);	//the following works just like the manual part of the program
            if(code == num)				//if REMOVE returns the number, everything worked fine so print the num with a message to the user.
                cout<<num<<" was removed from the list. \n";	//message says everything is working.
            if(code == -1)				//if REMOVE returns -1 the number was not found!
				cout<<num<<" was not found in the list! \n";
			if(code == -2)				//if REMOVE returns -2 the list is empty!!
				cout<<"ERROR! The list is empty! \n";
		}
		
		//PRINT Command
		if(command.compare("PRINT") == 0)
    	{
            cout<<"\n*** PRINT Function. ****\n";
            Print(&head);	//call the print function!
		}

		//EXIT command
		//Confusingly the paper says 'END' but the data text files have 'EXIT'... so I went with EXIT!
        if(command.compare("EXIT") == 0)
        {
			entry.close();	//closes the file
            cout<<"\nThis is the end of the file! \n";
            cout<<"Quitting to the main menu. \n=>";
			Destroy(&head);	//destroy all the nodes! :#
			Sleep(5000);    //pause for 5 seconds
            break;
        }
        
        Enter();
        cout<<'\n';
        
    }while(x == 1);	//loop until the end of the file, which is until x == 0;	
}

//Below is all the linked list related functions
int Add(int a, node **head)
{	
	node *curr, *prev;				//Temporary pointers. Curr = Current Node, Prev = the previous node
	
	curr = new(nothrow) node;		//Make a new node and fill it with the data from the user. (NOTHROW returns NULL on failure)
	if(!curr)						//If temp threw a NULL, then it seems memory allocation failed!
		return -1;					//Therefore return -1 to show memory allocation failed error to the user.
	curr -> data = a;				//'a' contains the data - transfer it to 'data' var. in the node	
	curr -> next = NULL;			//next is NULL for now.
							
	if(*head == NULL)				//IF head is NULL, then the list is empty!
		*head = curr;				//So make head point to temp! Now the list has one element! YAY!

	else							//The list isn't empty - I will have to search for the last node.	
	{
		prev = *head;				//make prev = to head for the searching part.
		
		if(curr -> data <= prev -> data)		//if the current int is less then the head's int, just make it the head!
		{										//no need to search for nothing!
			*head = curr;						//head becomes curr,
			curr -> next = prev;				//and curr points to the previous head, containing the rest of the list!
		}
		//other wise search until you find where curr is less then the next node or prev -> next == null
		else			
		{
			while(prev -> next != NULL)				//it's somewhere in the middle and prev -> next isn't NULL yet
			{
				if(curr -> data >= prev -> data && curr -> data <= prev -> next -> data)	
				{									//if current is great then the last node, and less then the next node, proceed.									
					curr -> next = prev -> next;	//current should point to what previous was pointing to
					prev -> next = curr;			//previous should then point to current
					break;							//break to exit this while loop
				}
				prev = prev -> next;				//move forward one node
			}
		
			if(prev -> next == NULL)	//it made it to the end of the list, so it must be the last link in the linked list!
				prev -> next = curr;	//so just make previous equal to current. No need to make curr -> next = null since this was already done above!
		}	
	}
	
	return 0;
}

int Remove(int a, node **head)
{
	int found = 0;
	node *curr, *prev;		//Temporary pointers
	curr = *head;			//Temp now equals head
	
	if(*head == NULL)	//If the list is empty, don't even bother searching - the number isn't there! :P
		return -2;		//(thus return an error)
	else
	{
		do{								//Search through the list for the number by using temp. Check the first node's data value. 
			if(curr -> data == a)		//Then move forward one and check again. If it is found, remove it and return the given number (in this case var. a)
			{							//to indicate success!
				found = 1;
				
				if(curr == *head)		//If the value is found in the start of the list,
				{
					*head = curr -> next;	//head must be reassigned - in this case just by moving it forward one. (by setting it equal to curr's next, or the next node)
					delete curr;			//Remove the node containing 'a' (the current node)
				}
				
				else if(curr -> next == NULL)	//If the value is the last node of the list, make sure the last node's pointer is NULL! or you'll have a bad pointer!
				{
					prev -> next = NULL;	//make prev's next NULL because it doesn't point to anything! its the end of the list now!
					delete curr;			//Remove the node containing 'a' (the current node)
				}
				
				else					//If the value is somewhere in the middle, then just rearrange a few things
				{
					prev -> next = curr -> next;	//Reroute the nodes - the previous node's (temp2) next should point to the next node (stored in the next of temp)
					delete curr;					//Remove the node containing 'a' (the current node)
				}
				
				return a;				
			}
			prev = curr;		 //stores the (soon to be previous) node
			curr = curr -> next; //move forward one node
		}while(curr != NULL);	
	}
	
	if(found == 0)
		return -1;
}

void Print(node **head)
{
	cout<<"\nThis is what is in teh list! \n\n";
	node *temp;		//Temporary pointer
	temp = *head;	//Makes temp equal to head
	
	if(temp == NULL)	//head is also NULL, aka empty list.
	{
		cout<<"ERROR! The list is empty! \n";	//eek! the list is empty!
	}
	else	//Well, the list has something stored! Print the nodes out!
	{
		do{
			cout<<temp -> data<<'\t';	//couts the current node
			temp = temp -> next; 		//basically moves it forward one node
		}while(temp != NULL);	//run until the end of the linked list
		cout<<'\n';
	}
	//DOES NOT NEED TO RETURN VALUE!
}

void Destroy(node **head)
{
	node *curr, *root;	//Temporary pointers
	root = *head;		//root is now equal to the first node
	if(*head == NULL)	
		return;			//if the list is empty no need to do the following else!
	else
	{					//if the list has nodes - run the following
		do{				
			curr = root;			//curr equals the first node.
			root = root -> next;	//root is now equal to the next node
			delete curr;			//curr is deleted - this means root is actually equal to the first node now (since the current one was deleted!)
			if(root -> next == NULL)//if root's next is NULL, then the last node was deleted with the 'delete curr' line. 
				*head = NULL;		//so this means *head can be set equal to NULL (an empty list)
		}while(*head != NULL);		//and the do/while stops running as the list is empty and all nodes were deleted from memory.
	}
}
