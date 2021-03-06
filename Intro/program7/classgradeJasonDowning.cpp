#include <iostream.h>

main()
{
    int a = 1;         //sets a=1 so the while loops will work until 0/other numbers are entered.
    int counter = 0;   //sum of the numbers entered.      (these are set equal to 0 so there is no starting values)
    int counter2 = 0;  //number of times the loop ran.    (if it was set equal to 1 it would change the resulting counter slightly)
    int average;       //used for the average calculation.
    int b;             //used for numerical grade to letter grade.
    char c;            //used for the second part, letter grade to numerical range.

    cout<<"Welcome to the Class Grade Program. \n";
    cout<<"This program will perform three calculations: \n";         //intro prompt
    cout<<"1. Numerical Grade to Letter Grade \n";
    cout<<"-- Running Class Average (for Numerical to Letter) \n";
    cout<<"2. Letter Grade to Numerical Range \n"<<endl;

    cout<<"Which calculation do you need to do? \n"<<endl;          //these ask user for either 1 or 2, corresponding to the selection
    cout<<"Numerical Grade to Letter Grade \n";                     //of the program that they want to use.
    cout<<"If so, press 1. \n"<<endl;
    cout<<"Letter Grade to Numerical Range \n";
    cout<<"If so, press 2. \n"<<endl;
    cout<<"Enter the number here -> ";
    cin>>a;
    cout<<endl;

    while(a==1)  //if a==1, then the number grade part start.
    {
        cout<<"Please input a Numerical Grade. ";    //this code asks for a number grade
        cin>>b;                                                //then displays the letter grade.
        counter += b;             // += b is basically "0 + 90 = counter". next one goes "90 + 90 = 180". and such.
        counter2 += 1;            // += 1 adds the total number of entries (0 + 1 + 1 + 1 etc), ie use it 5 times counter 2 will equal 5.
        cout<<endl;

        if((b<=100)&&(b>=97))
        {
            cout<<"Letter Grade: A+ \n";                        //the if's for all the possible grades.
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

        if( (b<=100) && (b>=65) )
            cout<<"You Passed! \n";       //simple if/else to find out if the user passed or failed.
        else
            cout<<"You Failed! \n";

        cout<<endl;                       //average is found by taking counter 1 and dividing it by counter2.
        average = counter / counter2;     //counter being 
        cout<<"The average of the set of grades is "<<average<<" \n";
        cout<<endl;
        cout<<"Press 1 to continue or 0 to exit. ";           //lets the user continue the program by pressing 1.
        cin>>a;                                              //or exit the program by pressing 0 (or any other number).
        cout<<endl;

    }

    while(a==2)   //if a==2, then the letter grade part starts.
    {
        cout<<"Please input a Letter Grade. ";   //this code asks the user for a letter grade, then displays the numerical range.
        cin>>c;
        cout<<endl;
        
        if( (c=='a') || (c=='A') )
                     cout<<"90-100 is an A \n";

        if( (c=='b') || (c=='B') )
                     cout<<"80-89 is a B \n";

        if( (c=='c') || (c=='C') )
                     cout<<"70-79 is a C \n";

        if( (c=='d') || (c=='D') )
                     cout<<"65-69 is a D \n";

        if( (c=='f') || (c=='F') )
                        cout<<"0-64 is a F \n";

        if( (c=='a') || (c=='A') || (c=='b') || (c=='B') || (c=='c') || (c=='C') || (c=='d') || (c=='D') )
            cout<<"You Passed! \n";
        else
            cout<<"You Failed! \n";
        
        cout<<endl;
        cout<<"Press 2 to continue or 0 to exit. ";    //lets the user cont. by pressing 2 or exit by pressing 0.
        cin>>a;
        cout<<endl;
    }

    cout<<"\nThank You for using the CLASS GRADE Program. \n";    //lets the user know the program is done.

    return 0;
}
