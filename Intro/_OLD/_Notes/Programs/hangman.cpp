#include <iostream.h>
#include <iomanip.h>

main()
{
	int a,c;
   char b;

	cout<<"Welcome to the Hangman Program \n";

	do{
	a = 0;

	cout<<endl;
	cout<<"     |------"<<endl;
	cout<<"    o_o    |  "<<endl;
	cout<<"     |     |  "<<endl;
	cout<<"    \\ /    |  "<<endl;
	cout<<"     |     |  "<<endl;
	cout<<"    / \\  ====="<<endl;

	cout<<"\nTHE RULES: \n";
	cout<<"1. You have 15 guesses - right or wrong.      \n";
	cout<<"2. Guess only the 26 letters in the alphabet. \n";
	cout<<"3. HAVE FUN.                                  \n";

	do{
	c = 15;
	c--;

	cout<<"\nPlease guess a letter.";
	cout<<"\nEnter it here. -> ";
	cin>>b;

	switch (b)
	{
		case 'a':
					cout<<"You guessed a correct letter!";
					break;
		case 'b':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'c':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'd':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'e':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'f':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'g':
					cout<<"You guessed a correct letter!";
					break;
		case 'h':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'i':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'j':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'k':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'l':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'm':
					cout<<"You guessed a correct letter!";
					break;
		case 'n':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'o':
					cout<<"You guessed a correct letter!";
					break;
		case 'p':
					cout<<"You guessed a correct letter!";
					break;
		case 'q':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'r':
					cout<<"You guessed a correct letter!";
					break;
		case 's':
					cout<<"You guessed an incorrect letter!";
					break;
		case 't':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'u':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'v':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'w':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'x':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'y':
					cout<<"You guessed an incorrect letter!";
					break;
		case 'z':
					cout<<"You guessed an incorrect letter!";
					break;
		 default:
					cout<<"You didn't enter a letter!";
					cout<<"Enter a letter and try again.";
					break;
	}

	}while(c < 15);

	cout<<"The word is:                    \n";
	cout<<"P R O G R A M                   \n";
	cout<<"I bet you never thought of that!\n";

	cout<<"\nYou can rerun the program if you want. ";
	cout<<"\nEnter 1 to continue, 2 to quit. ->";
	cin>>a;
	}while(a==1);

	return 0;
}