#include <iostream.h>

int main()
{
	int length,width,area;
	cout<<"This program will calculate the area of a room in square feet. \n"; //this will print to the screen.
	cout<<"Enter the length of the room. \t";  // Prompt to enter the length
	cin>>length;                               // This retrieves the length and stores it.
	cout<<"Enter the width of the room. \t";   // Prompt to enter the width
	cin>>width;                                // This retrieves the width and stores it.
	area=length*width;                         // This calculates the area by multiplying width times height.
	cout<<"The area of the room is:\t" <<area;    //This prints the area to the screen.

	return 0;
}