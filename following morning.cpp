#include <iostream>


#define text(x) std::cout << x << std::endl;



int main()
{

	text("Pointers work like such: ");
	int x = 500;
	int* ptr;
	ptr = &x;

	
	text("I will output your memory address: ")
	std::cout << ptr;
	text("I will output your value (Dereferencing your pointer!)");
	std::cout << *ptr;


	text("\n\n We can also allocate memory to functions.");
	text("For example: ");


	char* buffer = new char[8]; // This allocates 8 bytes of memory to our "buffer char" However, This is just making 8 chars in an array.
	memset(buffer, 3, 8); // Prints a heart for some reason? Lol.

	std::cout << "poof!" << *buffer;

	delete[] buffer; // MAKE SURE! to delete things that you allocate memory with using new otherwise memory can leak.




}
