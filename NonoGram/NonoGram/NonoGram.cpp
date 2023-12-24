#include <iostream>
#include <fstream>
#include <istream>
#include <string>

const int MaxAccountNameLength = 50;
const int MaxAccountPasswordLength = 50;

void printNonogramTitle() {
	std::cout << " _   _   ___   _   _   ___    ____  ____      _     __  __ \n";
	std::cout << "| \\ | | / _ \\ | \\ | | / _ \\  / ___||  _ \\    / \\   |  \\/  |\n";
	std::cout << "|  \\| || | | ||  \\| || | | || |  _ | |_) |  / _ \\  | |\\/| |\n";
	std::cout << "| |\\  || |_| || |\\  || |_| || |_| ||  _ <  / ___ \\ | |  | |\n";
	std::cout << "|_| \\_| \\___/ |_| \\_| \\___/  \\____||_| \\_\\/_/   \\_\\|_|  |_|\n";
}

int mystrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return 0; //some error value
	}

	while ((*first) && (*second) && ((*first) == (*second)))
	{
		first++;
		second++;
	}

	return (*first - *second);

}

void mystrcpy(const char* source, char* dest)
{
	if (!source || !dest)
		return;
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

int mystrlen(char* ptr)
{
	if (!ptr)
	{
		return 0;
	}

	int count = 0;

	while (*ptr)
	{
		count++;
		ptr++;
	}

	return count;
}

void clearString(char* ptr, int size)
{
	if (!ptr)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		ptr[i] = '\0';
	}
}

int fileRowsCount(char* filename)
{
	std::ifstream filein(filename);

	if (!filein.is_open())
	{
		return -1;
	}

	int counter = 0;

	char currentRow[50];

	while (filein.getline(currentRow, 50, '\n'))
	{
		counter++;
	}


	filein.clear();
	filein.close();

	return counter;
}

void fillRowsFromFileToCharArray(char* filename, char** accounts, int rowsCount)
{
	std::ifstream filein(filename);

	if (!filein.is_open())
	{
		return;
	}

	char currentRow[MaxAccountNameLength];

	for (size_t i = 0; i < rowsCount; i++)
	{
		filein.getline(currentRow, MaxAccountNameLength, '\n');

		int currentRowLength = mystrlen(currentRow);

		accounts[i] = new char[currentRowLength];
		mystrcpy(currentRow, accounts[i]);
		clearString(currentRow, MaxAccountNameLength);
	}

	filein.clear();
	filein.close();
}

bool isRegisterInputValid(char** accounts, int rows, char* username, char* password)
{
	
	//check if there is a user with the same username

	int indexOfUsername = -1;
	for (size_t i = 0; i < rows; i += 2)
	{
		if (!mystrcmp(username, accounts[i]))
		{
			indexOfUsername = i;
			break;
		}
	}

	if (indexOfUsername != -1)
	{
		std::cout << "This username is already in use!" << std::endl;
		return false;
	}
	
	//check how strong the password is

}

bool isLoginInputValid(char** accounts, int rows, char* username, char* password)
{
	//in order for the input to be valid the username must be in the accounts and the next element by index next to the username must be the password 

	int indexOfUsername = -1;
	for (size_t i = 0; i < rows; i += 2)
	{
		if (!mystrcmp(username,accounts[i]))
		{
			indexOfUsername = i;
			break;
		}
	}

	if (indexOfUsername == -1)
	{
		std::cout << "Invalid username!"<< std::endl;
		return false;
	}

	if (mystrcmp(password,accounts[indexOfUsername+1]))
	{
		std::cout << "Invalid password!" << std::endl;
		return false;
	}

	return true;
}

void userLogin(char** accounts, int accountsFileRows, char* loggedInUsername)
{
	//get the input of the user
	std::cout << "Username: ";
	char username[MaxAccountNameLength];

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cin.getline(username, MaxAccountNameLength);

	std::cout << "Password: ";
	char password[MaxAccountPasswordLength];
	std::cin.getline(password, MaxAccountPasswordLength);

	//check if the input contains in the accounts

	while (!isLoginInputValid(accounts, accountsFileRows, username, password))
	{
		std::cout << "Username: ";
		std::cin.getline(username, MaxAccountNameLength);

		std::cout << "Password: ";
		std::cin.getline(password, MaxAccountPasswordLength);
	}

	mystrcpy(username, loggedInUsername);
}


void userRegister(char** accounts,int accountsFileRows, char* loggedInUsername)
{
	//get the input
	std::cout << "Username: ";
	char username[MaxAccountNameLength];

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cin.getline(username, MaxAccountNameLength);

	std::cout << "Password: ";
	char password[MaxAccountPasswordLength];
	std::cin.getline(password, MaxAccountPasswordLength);

	while (!isRegisterInputValid(accounts, accountsFileRows, username, password))
	{
		std::cout << "Username: ";
		std::cin.getline(username, MaxAccountNameLength);

		std::cout << "Password: ";
		std::cin.getline(password, MaxAccountPasswordLength);
	}

//add a row to the file with accounts


}


void setup(char* username)
{
	printNonogramTitle();

	//login register
	char answer;
	std::cout << std::endl << "Do you have an account \"Y/N\": ";
	std::cin >> answer;

	while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
	{
		std::cout << "Invalid answer! Try again: ";
		std::cin >> answer;
	}

	char doesUserHaveAnAccount = (answer == 'Y' || answer == 'y') ? true : false;

	//load all accounts from the file
	std::ifstream ifs("accounts.txt");

	if (!ifs.is_open())
	{
		return;
	}

	char filename[] = "accounts.txt";
	int accountsFileRows = fileRowsCount(filename);
	char** accounts = new char* [accountsFileRows];

	fillRowsFromFileToCharArray(filename, accounts, accountsFileRows);

	if (doesUserHaveAnAccount)
	{
		userLogin(accounts, accountsFileRows, username);
	}
	else
	{
		userRegister(accounts, accountsFileRows,username);
	}
}

int main()
{

	char currentuser[50];
	setup(currentuser);

	//methods for reading from the files 
	//methods for writing in the files
	//MethodsFor Writing on the console
	//printing the currentState of the game

}


