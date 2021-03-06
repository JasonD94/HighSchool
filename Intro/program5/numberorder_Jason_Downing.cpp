#include <iostream.h>

int main()
{
	int a,b,c;		//three numbers entered so 3 variables needed.
	cout<<"Welcome to the 3-NUMBER-SORT PROGRAM. \n";
	cout<<"This program will arrange three numbers \n";			//prompt for program.
	cout<<"in ascending order. (least to greatest) \n";			//explains the program to the user
	cout<<endl;
	cout<<"Please enter the first number.   ";	    //asks for the first number
	cin>>a;
	cout<<endl;
	cout<<"Please enter the second number.  ";     	//asks for the second number
	cin>>b;
	cout<<endl;
	cout<<"Please enter the third number.   ";     	//asks for the third and final number
	cin>>c;
	cout<<endl;                                    	//the 'cin' commands accept a/b/c and store it in a variable.
													//I used a/b/c as it was shorter and easier to use than num1/num2/etc.
													//made it easier to plan out the program as well (see next comments)
	/*there seems to be three possible outcomes:
	~NONE are equal
	~SOME are equal
	~ ALL are equal
	thus three 'levels'.
	mathematically there is 27 possible outcomes.
	as in 123, 111, 222, 333, etc.
	but the code should take all of that into account */

	/*  ALL POSSIBLE NUMBERS
	LEVEL 1
	6 possible

	123
	132
	213
	231
	312
	321

	LEVEL 2
	18 possible

	121
	131
	212
	232
	313
	323

	112
	113
	221
	223
	331
	332

	122
	133
	211
	233
	311
	322

	LEVEL 3
	3 possible

	111
	222
	333

	3 + 6 + 18 = 27
	*/

	//LEVEL  1
	//are none of the numbers equal?
	//if so, figure out which one is less than, which one is greater
	//and which one fits in the middle.
	/* the possible outcomes are
	abc
	acb
	bac
	bca
	cab
	cba */

	if(a<b)
	{
		if(a<c)
		{
			if(b<c)
			{
           cout<<"The order is: \n";
				cout<<a<<" , "<<b<<" , "<<c;
			}
		}
	}

	if(a<c)
	{
		if(a<b)
		{
			if(c<b)
			{
				cout<<"The order is: \n";
				cout<<a<<" , "<<c<<" , "<<b;
			}
		}
	}

	if(b<a)
	{
		if(b<c)
		{
			if(a<c)
			{
				cout<<"The order is: \n";
				cout<<b<<" , "<<a<<" , "<<c;
			}
		}
	}

	if(b<c)
	{
		if(b<a)
		{
			if(c<a)
			{
				cout<<"The order is: \n";
				cout<<b<<" , "<<c<<" , "<<a;
			}
		}
	}

	if(c<a)
	{
		if(c<b)
		{
			if(a<b)
			{
				cout<<"The order is: \n";
				cout<<c<<" , "<<a<<" , "<<b;
			}
		}
	}

	if(c<b)
	{
		if(c<a)
		{
			if(b<a)
			{
				cout<<"The order is: \n";
				cout<<c<<" , "<<b<<" , "<<a;
			}
		}
	}

	//LEVEL 2
	//are some of the numbers equal?
	//if so figure out which ones are equal and where they fit
	//ie if a=b, is it greater than c or less than c?
	//also theres something like 18 possiblities...
	//BUT i don't need to repeat a=b to b=a, since thats the same.
	//so these 6 should take all 18 into account...

	/* same as LEVEL 1, there should be only 6 possible outcomes.
	abc
	acb
	bac
	bca
	cab
	cba
	*/

	if(a==b)
	{
		if(b<c)
		{
			cout<<"The order is: \n";
			cout<<a<<" , "<<b<<" , "<<c;
		}
	}

	if(a==b)
	{
		if(b>c)
		{
			cout<<"The order is: \n";
			cout<<c<<" , "<<b<<" , "<<a;
		}
	}

	if(b==c)
	{
		if(c<a)
		{
			cout<<"The order is: \n";
			cout<<b<<" , "<<c<<" , "<<a;
		}
	}

	if(b==c)
	{
		if(c>a)
		{
			cout<<"The order is: \n";
			cout<<a<<" , "<<c<<" , "<<b;
		}
	}

	if(c==a)
	{
		if(a<b)
		{
			cout<<"The order is: \n";
			cout<<a<<" , "<<c<<" , "<<b;
		}
	}

	if(c==a)
	{
		if(a>b)
		{
			cout<<"The order is: \n";
			cout<<b<<" , "<<c<<" , "<<a;
		}
	}

	//LEVEL 3
	//are all numbers equal?
	//easiest one - just order them since it doesn't matter as they are ALL EQUAL.

	if(a==b)
	{
		if(b==c)
		{
			cout<<"The order is: \n";
			cout<<a<<" , "<<b<<" , "<<c;
		}
	}

	cout<<endl;     //ends line to make everything look evenly spaced.
  	cout<<endl;
	cout<<"Thank You for using the 3-NUMBER PROGRAM. \n";    //thanks user for using program.

      return 0;
}
