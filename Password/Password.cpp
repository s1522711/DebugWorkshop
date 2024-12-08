#include <iostream>

struct Password
{
	char value[16];
	bool incorrect;
	Password() : value(""), incorrect(true)
	{
	}
};

int main()
{
	std::cout << "Enter your password to continue:" << std::endl;
	Password pwd;
	std::cin >> pwd.value;

	if (!strcmp(pwd.value, "********"))
		pwd.incorrect = false;

	if(!pwd.incorrect)
		std::cout << "Congratulations\n";

	return 0;
}

/*
* the bug here is a buffer overflow in the Password struct, the value array is only 16 bytes long, but the input is not limited to 16 bytes, so the user can input more than 16 bytes and overwrite the incorrect flag.
* also the password is compared using strcmp, which is not safe, it's better to use strncmp with a length limit. otherwise, the user can input a string that is not null-terminated and the program will keep reading from memory until it finds a null byte.
*/
