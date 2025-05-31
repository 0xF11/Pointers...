#include <iostream>
#include <windows.h>


#define text(x) std::cout << x << std::endl;

int main()
{

	// POINTERS - 
	// Pointers can be ANY  thing however a pointer is just an address making it mainly exclusively an integer
	// If i assign this pointer to say int* or char*, etc The data inside of the pointer is presumed to be using those rules 
	// and/or be that variable type
	// void* ptrnull = 0; 
	// PTR being 0 makes it invalid and a NULLPTR
	// Reading to or writing from a ptr of 0 (NULLPTR) will crash the program.
	int checker = 0; // just using this to update to the if statements, going to memory edit the program

	int localplayer = 503918;
	int hacker = 9999;
	int* ptr = &localplayer; 
	// Okay so, A pointer is nothing really, It holds the address in memory to our value
	// ptrs are used to store the location of our data and nothing more.

	std::cout << *ptr << std::endl;

	double helper = 5.5;
	double* ptrr = &helper;
	// Correction. Pointers do not MAKE what we are pointing to an integer, That was dumb to say.
	// The addresses our pointers host our value at are usually integers however, like in the example i wrote about
	// Typing double* ptrr Lets our compiler know that Yes i want a pointer to this, and that stored memory address will be an integer
	// Our value within that stored memory address is going to be a double.
		text("Your pointer points to the memory address of: ");
		std::cout << ptrr << std::endl;
		text("And the value of what you are pointing at is: ");
		std::cout << *ptrr << std::endl;


	text("Hello! Please input what you would like to change the value to.");
	text("If your value is NOT equal to 503918, I REPEAT NOT EQUAL TO THIS you will be banned for cheating.");

	std::cin >> checker;
	if (checker != 503918)
	{
		ptr = &checker;
	}
		
	if (ptr != &localplayer)
	{
		text("You think you can hack the game dont you?");
	}
	

	if (ptr == &localplayer)
	{
		text("Thank you for being a normal player!! Bye bye!");
	}
	Sleep(1000);


	float  Morestuff = 9.9f;
	float* floatpoint;

	floatpoint = &Morestuff;

	std::cout << floatpoint << '\n'; // All im doing is printing my pointer here.
	std::cout << *floatpoint << '\n'; // By adding a * to the beginning of floatpoint (*floatpoint) we have DEREFERENCED the pointer
	*floatpoint = 55.5f ; // We can also change the value of dereferenced pointers (userful in the future for memhacks? probably...)
	std::cout << *floatpoint << std::endl;// Prints our newely dereferenced float, which is 55.5 instead of 9.9


	text("\nHi!");


	// Okay! Final thing. Allocating memory for ourselves.
	// This was kinda confusing when i just glanced at it on thechernos video however i think i am understand it.


	// This is working by
	char* alloc // We are making a char* to our variable named alloc
		= // Alloc is going to just be our frequency in a way to host
	new char[8]; // 8 bytes of stored memory

	memset(alloc, 0, 8); // Now the way this is working is as follows, memset well kinda self explanitory
	// memset = set memory (size?)
	// (alloc) is our buffer 
	// 0 is what is being stored in these bytes while we are allocating it memory
	// 8 is how many bytes we want.

	// For example, if i wanted 4 bytes worth of allocated memory it would be written like so

	char* buffer = new char[4]; // I can make an educated guess saying that the 
								//"new" infront of char is making our char variable "new" by making it 4 bytes
	memset(buffer, 0, 4);		// Allocate memory, To variable buffer, With the value of 0, For 4 bytes of memory.

	// One more thing, Since now i know this is actually allocating 1 byte 4 times using a char, 
	// This is how i can make a bool allocated into multiple bytes.
	bool* switchy = new bool[4];
	memset(switchy, 0, 4);


	bool** nestedbool = &switchy; // Our ** Indicates it is a pointer pointing to a pointer.
	// This is how multilevel pointers are made
	// When reverse engineering games (I.E. Assault cube)
	// Finding our weapon class as a 3 level pointer
	// I can assume that it is using something along the lines of V
	bool*** boolptr2 = &nestedbool;
	// ^-^
	// To make it 3 levels, Now obviously not this simple however multiple bits of code within them. This can also make reverse
	// engineering certain things harder due to the fact that it is nested in multiple pointers.

	std::string poop;
	

	text("test your nested bool");
	std::cin >> poop;
	
	
	if (poop == "true")
	{
		*switchy = true;
	}
	else if(poop == "false")
	{
		
		*switchy = false;
	}

	std::cout << *switchy;

	// ONE LAST THING FOR REALS

	delete[] boolptr2;
	delete[] nestedbool;
	delete[] switchy;
	delete[] buffer;
	delete[] alloc;

	// YOU ONLY!! Delete things you use new with, For example. 
	// I will not be deleting floatpoint just because it is a pointer
	// I will be deleting alloc, buffer, boolptr2, nestedbool, and switchy because they are allocating memory.
	// This can cause a memoryleak if it is not deleted when it is no longer being used.
	// Delete them in reverse order of allocation 
	std::cin.get(); // just stablize program running.

}
