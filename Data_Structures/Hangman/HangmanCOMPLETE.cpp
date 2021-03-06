#include <conio.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;
using std::string;

struct node			//A structure, which contains all the data (int + pointer) for each element (node) in the linked list
{
	string word;	//This will contain the number which the user wishes to add  to the list.
	node *next;		//This will point to the next node.
};
			
//REQUIRED FUNCTIONS:
void Intro(void);						//"HANGMAN" ASCII Art
int  Populate(node **head);				//Makes the circle list of words
string ChooseWord(node **head);			//Randomly chooses a word between 0 and 1000.
int PlayRound(node **head);				//Plays a round of hangman
void Destroy(node **head); 				//DESTROYS THE BASE WHEN DA PROGRAM IS DONE!
void Report(double win, double lose);			//Reports the number of wins/loses and the win percent

//Not required but I found it easier to set it up with multiple functions for playing a round.
void printman(int tries);																//Prints Hangman as he appears thus far
void Enter(void);																		//For the "Press Enter To Continue..." Prompt

int main()
{
	node *head = NULL; 		//head of the linked list - points to the start of the list. Set to NULL as there aren't any elements in the list (yet).
	srand(time(0));			//Seeds the random
	int c = 1, ret = 0, result = 0;
	double win = 0, lose = 0;
	
	ret = Populate(&head);	//Calls the Populate function - fills the list with 1000 words!
	
	if(ret == -1)
		cout<<"ERROR! Populate function failed! \n";
	
	do{	
		//Introduction!
		Intro();
		Enter();
		system("cls");	//clear the screen
		
		//Play da round of da hangman!
		result = PlayRound(&head);
		
		if(result == 0)
			cout<<"ERROR!";
		if(result == 1)
			win++;
		if(result == 2)
			lose++;
		
		//Ask if they are done!
		do{
			cout<<"\n\nWould you like to play again?";
			cout<<"\nPress 1 to continue and 2 to quit. -> ";
			cin>>c;
		}while(c != 1 && c != 2);	//User may ONLY enter 1 or 2!
		
		system("cls");	//clear the screen
		
	}while(c == 1);		//run til the user wants to quit.
	
	Report(win, lose);
	Enter();
	Destroy(&head);	//destroy all the nodes! :#
	
	return 0;
}

void Intro(void)	//ASCII ART 'HANGMAN'
{
	cout<<" ------------------------------------------------------------------------   \n";
    cout<<" |  *    *     ***     *   *   *******   *       *     ***     *   *    |   \n";
    cout<<" |  *    *    *   *    **  *   #         **     **    *   *    **  *    O   \n";
  	cout<<" |  ******   *******   * * *   #  ****   * *   * *   *******   * * *   \\|/ \n";
	cout<<" |  *    *   *     *   *  **   #     *   *  * *  *   *     *   *  **   / \\ \n";
	cout<<" |  *    *   *     *   *   *   *******   *   *   *   *     *   *   *        \n";
	cout<<" |                               V1.5                                       \n";
    cout<<" ======================================================================     \n";
}

int  Populate(node **head)	//REQUIRED FUNCTION 'POPULATE' - generates a linked list with 1,000 words!
{
	ifstream entry;		                 //ifstream for opening the file
	string filename = "Wordlist.txt";    //string to hold the filename
	string line;						 //string to temp. hold each line's word
	node *temp, *temp2;		             //Temporary pointers
    int x = 0;
    
	entry.open(filename.c_str());	//opens the file, using the name the user entered in
	
	if(!entry)     //if the file does not open, this is true.
    {              //the below errror will then print out.
        cout<<"Unable to open the selected file! \n";
        Sleep(5000);    //pause for 5 seconds
        return -1;
    }
	
	do{
		getline(entry, line, '\n');		//Goes through one line of the file and stores the given word in a string
		
		if(strncmp(line.c_str(), ";", 1) == 0)
		{
			entry.close();	//closes the file
			x = 1;
			break;
		}
		
		temp = new(nothrow) node;		//Make a new node and fill it with the data from the user. (NOTHROW returns NULL on failure)
		
		if(!temp)			//If temp threw a NULL, then it seems memory allocation failed!
			return -1;		//Therefore return -1 to show memory allocation failed error to the user.
		
		//Transfer word to the node
		temp -> word = line;		//'word' contains the data - transfer it to 'words' var. in the node	
		temp -> next = NULL;	    //next is equal to head as it is a circularly linked list!
		
		//Add the node to the list
		if(*head == NULL)		//IF head is NULL, then the list is empty!
			*head = temp;		//So make head point to temp! Now the list has one element! Woo Hoo!
		else
		{
			temp2 = *head;					//The list isn't empty - I will have to search for the last node.
			while(temp2 -> next != NULL)	//FIND the last node - the one just before NULL!
				temp2 = temp2 -> next;		//Temp2 now contains the address of the last node
			temp2 -> next = temp;			//Make temp the last node in the linked list.
		}
		
	}while(x == 0);
	
	return 0;
}

string ChooseWord(node **head)	//REQUIRED FUNCTION 'CHOOSEWORD' - randomly returns one of the 1,000 words in the linked list.
{
	int random, x;			//Various variables needed
	string thew;
	node *temp = *head;		//Node temp is used for traversing the list - its equal to head so it can move through the list
	random = 0, x = 0;
	
	random = rand()%1001;	//Generates a random number between 0 and 1000
	
	do{
		temp = temp -> next;		//temp will at some point contain the address of the node that has the word needed.
		x++;						//It just keeps moving forward until x, or # of the node, equals random, 
	}while(x != random);			//the node # containing the word to be used in the program.
	
	thew = temp -> word;			//thew is just a string that contains the word, gotten from temp which is the node that was randomly selected.
	
	return thew;					//Return the string with the word needed!
}

int PlayRound(node **head)		//REQUIRED FUNCTION 'PLAYROUND' - allows a user to play a game of hangman by comparing each letter entered!
{
	char input[30] = {0};							//Array for the letters that have been guessed   (A,E,P,L, etc)
	char guess[30] = {0};							//Array for the 'guessed' word, as it is so far. (ie "Gue--" for the word "Guess")
	string real;									//String to hold the real word
	int a, g, corlet, tries, wordlen, result;		//Ints needed for the function
	
	real = ChooseWord(head);						//Generates a random word from the ChooseWord function
	wordlen = strlen(real.c_str());					//Find the length of the word
	
	g = 0, tries = 0, result = 0;		//Make sure everything is zero!!!
	
	do{
		corlet = 0;
		cout<<"HANGMAN V1.5 \n";
		printman(tries);				//Print out the hangman
		
		//Displays the word as it has been guess thus far, and also displays the letters that the user has guessed.
		cout<<"\nThe word 'is': ";
		
    	for(a = 0; a < wordlen; a++)	//a will go 0 to how long the word is
    	{   
       		if(guess[a] == real[a])		//If guess contains a letter in real,
				cout<<guess[a];			//it displays that letter
			if(guess[a] == 0)			//If guess equals 0, aka doesn't have a letter,
				cout<<"*";				//then it displays a censor symbol or a star "*"
    	}
    	
    	//Prints out all the letters that have been guessed so far.
    	cout<<"\n\nLETTERS GUESSED: ";
    	for(a = 0; a < 28; a++)			//Simple for loop that displays all the ltters guessed so far.
        	cout<<input[a]<<" ";
    	
    	//User can guess a letter and see if it is in the word
		cout<<"\n\nGuess a letter. -> ";	//Input works by storing each letter in the input array
		cin>>input[g];
		
    	//Compare the guessed letter to the real word and see if it is a letter in the real word or not
    	for(a = 0; a < wordlen; a++)		//Run through the word
    	{
            if(input[g] == real[a])			//And if a guessed letter is in the real word
            {
                	guess[a] = real[a];		//Guess array contains the word as it has been guessed so far
               	 	corlet++;				//Increase correct letter counter so as not to flag this letter as incorrect
            }
    	}
    	
    	if(corlet == 0 && tries < 6)			//The guessed letter was NOT in the word - increase tries.
    	{										//The reason is the correct letter counter didn't increase, so it wasn't correct
			tries++;							//Tries is how many tries you have to guess the word - in my program that is 6
		}
    
    	if(corlet == 0 && tries == 6)			//You lost if this happened. Aka letter was not in the word and you maxxed out your tries.
    	{
			result = 2;    		//You lost! :(
			break;				//Break the program - we're done with this function for now
		}

    	if(strncmp(guess, real.c_str(), wordlen) == 0)	 //You won if this happened. Aka the guessed word equaled the real word.
		{											     //The reason is the guessed word equaled the real word, which is what the strncmp
			result = 1;    		//You won! :)			   command does - compares words and if they are equal they equal 0.
			break;				//Break the program - we're done with this function for now
		}
    	
    	//IF NONE OF THESE IFS WERE TRIGGERED THEN: well, the letter was in the word and it hasn't been correctly guessed yet! Carry on guessing!
    	
    	system("cls");			//Clear the screen!
		g++;					//G stands for Guess # - so it starts at 0 and continues. if g = 2 then 2+1 = 3 so guess # = 3
	}while(result == 0);
	
	system("cls");				//Clear the screen!
	memset(input, '\0', 30);	//reset these arrays incase the program is rerun.
	memset(guess, '\0', 30);
	
	if(result == 1)
	{
		cout<<"HANGMAN V1.5 \n\n";
		cout<<"   O Hey!     O    O     O    O           \n";		//Some more ASCII art!
		cout<<"  \\|/        \\|/  \\|/   \\|/  \\|/     \n";		
		cout<<"  / \\        / \\  / \\   / \\  / \\     \n";
		cout<<"========================================= \n\n"; 
		
		cout<<"The word was: "<<real;
		cout<<"\nWoo hoo! You WON! You saved Hangman! :D \n";			//YAY! WE SAVED YOU, HANGMAN!
		cout<<"You don't win any prizes though. ;( \n";
		Enter();
		return 1;	//1 = WINNER!
	}

    if(result == 2)
    {
		cout<<"HANGMAN V1.5 \n";
		cout<<"____   \n";
    	cout<<"|  |   \n";
    	cout<<"|  O   \n";		//ASCII ART!
    	cout<<"| /|\\ \n";
    	cout<<"| / \\  \n";
    	cout<<"|________ \n\n";
    	
    	cout<<"Sorry, you LOST. You killed Hangman! :# \n";		//You... killed him... HOW COULD!
    	cout<<"By the way - the real word was: "<<real<<'\n';
    	Enter();
    	return 2;	//2 = LOSER!
	}

}

void printman(int tries)					//Prints the Hangman as he appears.
{											//Basically a switch and some ASCII art.
    switch(tries)
    {
        case 0:
                cout<<"____  \n";
                cout<<"|  |  \n";
                cout<<"|     \n";
                cout<<"|     \n";
                cout<<"|     \n";
                cout<<"|________ \n\n";
                break;   
            
        case 1:
                cout<<"____  \n";
                cout<<"|  |  \n";
                cout<<"|  O   \n";
                cout<<"|     \n";
                cout<<"|     \n";
                cout<<"|________ \n\n";
                break;
            
        case 2:
                cout<<"____  \n";
                cout<<"|  |  \n";
                cout<<"|  O  \n";
                cout<<"|  |  \n";
                cout<<"|     \n";
                cout<<"|________ \n\n";
                break;
                
        case 3:
                cout<<"____  \n";
                cout<<"|  |  \n";
                cout<<"|  O  \n";
                cout<<"| /|  \n";
                cout<<"|     \n";
                cout<<"|________ \n\n";
                break;
            
        case 4:
                cout<<"____   \n";
                cout<<"|  |   \n";
                cout<<"|  O   \n";
                cout<<"| /|\\ \n";
                cout<<"|      \n";
                cout<<"|________ \n\n";
                break;
            
        case 5:
                cout<<"____   \n";
                cout<<"|  |   \n";
                cout<<"|  O   \n";
                cout<<"| /|\\ \n";
                cout<<"| /    \n";
                cout<<"|________ \n\n";
                break;
                
        default:
                cout<<"ERROR! \n";		//If it somehow glitches/bugs past 6 tries, well this flags it as an error!
                break;
    }   
}

void Destroy(node **head)	//REQUIRED FUNCTION - destroys all the nodes in the linked list!
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

void Report(double win, double lose)	//REQUIRED FUNCTION - displays the results of the hangman program!
{
	double winp = 0;					//Win percentage var (has to be float for teh percent - forgot that the first time! D:
	double total;
	total = win + lose;
	winp = win / total;	 			//Calculates win %
	winp = winp * 100;
		
	cout<<"THE RESULTS OF MANY HANGMAN GAMES... \n";	//TEH RESULTS
	cout<<" Wins: "<<win<<'\n';							//WINS
	cout<<"Loses: "<<lose<<'\n';						//LOSES
	cout<<"Win Percent: "<<winp<<"% \n";				//WIN %
}

void Enter(void)	//This function is just to stop the screen from ending quickly - makes the user hit enter before the program continues.
{
	char c;	//char to accept
	
	do{
		cout<<"\nPress ENTER to continue. => ";	//PRESS ENTER!!
        c = getch();
   	}while(c != 13);	//Only ends when the user presses ENTER - ASCII value of 13!
}
