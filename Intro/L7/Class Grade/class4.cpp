#include <iostream.h>

main()
{
	int a = 1;       //sets a=1 so the while loops will work until 0/other numbers are entered.
	int counter=0;   //finds the total numbers entered.
	int b;
	char c;

	cout<<"Welcome to the CLASS GRADE Program. \n";
	cout<<"This program will calculate the class \n";         //intro prompt
	cout<<"grade average, invidivual grades and more! \n";
	cout<<endl;

	cout<<"Which calculation do you need to do? \n";
	cout<<endl;
	cout<<"Numerical Grade to Letter Grade \n";
	cout<<"If so, press 1. \n";                        //these ask user for either 1 or 2, corresponding to the selection
	cout<<endl;                                         //of the program that they want to use.
	cout<<"Letter Grade to Numerical Range \n";
	cout<<"If so, press 2. \n";
	cin>>a;
	cout<<endl;

	while(a==1)  //if a==1, then the number grade part start.
	{
		cout<<"Please input a Numerical Grade. ";    //this code asks for a number grade
		cin>>b;                                      //then displays the letter grade.
		cout<<endl;


		if((b<=100)&&(b>=97))
		{
        cout<<"Letter Grade: A+ \n";
		cout<<"97-100 is the range for an A+. \n";
        }
        
		if((b<=96)&&(b>=93))
		{
        cout<<"Letter Grade: A \n";
        cout<<"93-96 is the range for an A. \n";
        }
        
		if((b<=92)&&(b>=90))
		{
		cout<<"Letter Grade: A- \n";
        cout<<"90-92 is the range for an A-. \n";
        }

		if((b<=89)&&(b>=87))
		{
		cout<<"Letter Grade: B+ \n";
        cout<<"87-89 is the range for a B+. \n";
        }

		if((b<=86)&&(b>=83))
		{
		cout<<"Letter Grade: B \n";
        cout<<"83-86 is the range for a B. \n";
        }

		if((b<=82)&&(b>=80))
		{
		cout<<"Letter Grade: B- \n";
        cout<<"80-82 is the range for a B-. \n";
        }
        
		if((b<=79)&&(b>=77))
		{
		cout<<"Letter Grade: C+ \n";
        cout<<"77-79 is the range for a C+. \n";
        }

		if((b<=76)&&(b>=73))
		{
		cout<<"Letter Grade: C \n";
		cout<<"73-76 is the range for a C. \n";
        }

		if((b<=72)&&(b>=70))
		{
		cout<<"Letter Grade: C- \n";
		cout<<"70-72 is the range for a C-. \n";
        }

		if((b<=69)&&(b>=65))
		{
        cout<<"Letter Grade: D \n";
        cout<<"65-69 is the range for a D. \n";
        }

		if((b<=64)&&(b>=0))
		{
		cout<<"Letter Grade: F \n";
		cout<<"0-64 is the range for a F. \n";
        }

		if(b>=65)
			cout<<"You Passed! \n";       //simple if/else to find out if the user passed or failed.
		else
			cout<<"You Failed! \n";

		cout<<endl;
		cout<<"Press 1 to continue or 0 to exit. ";    //lets the user continue the program by pressing 1.
		cin>>a;                                        //or exit the program by pressing 0 (or any other number).
		counter=counter+=1;
		cout<<endl;

	}

	while(a==2)   //if a==2, then the letter grade part starts.
	{
		cout<<"Please input a Letter Grade. ";   //this code asks the user for a letter grade, then displays the numerical range.
		cin>>c;
		cout<<endl;
		
		if(c=='a')
		cout<<"90-100 is an A \n";
		
		if(c=='b')
		cout<<"80-89 is a B \n";
		
		if(c=='c')
		cout<<"70-79 is a C \n";
		
		if(c=='d')
		cout<<"65-69 is a D \n";
        
        if(c=='f') 
        cout<<"0-64 is a F \n";
		
		if((c=='a')||(c=='b')||(c=='c')||(c=='d'))
			cout<<"You Passed! \n";
		else
			cout<<"You Failed! \n";
		
		cout<<endl;
		cout<<"Press 2 to continue or 0 to exit. ";    //lets the user cont. by pressing 2 or exit by pressing 0.
		cin>>a;
		cout<<endl;
	}
  	cout<<endl;
	cout<<"Thank You for using the CLASS GRADE Program. \n";    //lets the user know the program is done.
	cout<<"\n The loop ran " <<counter<<" times";  //number of times the program ran.


	return 0;
}
