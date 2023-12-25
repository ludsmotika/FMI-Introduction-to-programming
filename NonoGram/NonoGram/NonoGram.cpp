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

void saveUsernameAndPasswordInFile(char* filename, char* username, char* password) 
{
	std::ofstream ofs(filename, std::ofstream::app);

	if (!ofs.is_open())
	{
		return;
	}

	ofs << username<< std::endl;
	ofs << password<< std::endl;

	ofs.clear();
	ofs.close();
}

bool isValidInputForLogin(int indexOfUsername,char* password, char* passwordToCompareWith) 
{
	if (indexOfUsername == -1)
	{
		std::cout << "Invalid username!" << std::endl;
		return false;
	}
	
	if (mystrcmp(password, passwordToCompareWith))
	{
		std::cout << "Invalid password!" << std::endl;
		return false;
	}

	return true;
}

bool isValidInputForRegister(int indexOfUsername, char* username, char* password) 
{
	if (indexOfUsername != -1)
	{
		std::cout << "This username is already in use!" << std::endl;
		return false;
	}

	if (mystrlen(username) < 5)
	{
		std::cout << "Please enter a username which is at least 5 characters long!" << std::endl;
		return false;
	}

	if (mystrlen(password) < 8)
	{
		std::cout << "Please enter a password which is at least 8 characters long!" << std::endl;
		return false;
	}

	return true;
}


bool isInputValid(char** accounts, int rows, char* username, char* password, bool doesUserHaveAnAccount)
{
	//in order for the input to be valid the username must be in the accounts and the next element by index next to the username must be the password 

	int indexOfUsername = -1;
	for (size_t i = 0; i < rows; i += 2)
	{
		if (!mystrcmp(username, accounts[i]))
		{
			indexOfUsername = i;
			break;
		}
	}

	if (doesUserHaveAnAccount)
	{
		return isValidInputForLogin(indexOfUsername,password, accounts[indexOfUsername + 1]);
	}
	else 
	{
		return isValidInputForRegister(indexOfUsername,username,password);
	}
}

void userInput(char** accounts, int accountsFileRows, char* loggedInUsername, bool doesUserHaveAnAccount)
{
	std::cout << (doesUserHaveAnAccount ? "Login" :"Register") << std::endl;

	//get the input of the user
	std::cout << "Username: ";
	char username[MaxAccountNameLength];

	std::cin.ignore();
	std::cin.getline(username, MaxAccountNameLength);

	std::cout << "Password: ";
	char password[MaxAccountPasswordLength];
	std::cin.getline(password, MaxAccountPasswordLength);

	//check if the input contains in the accounts

	while (!isInputValid(accounts, accountsFileRows, username, password,doesUserHaveAnAccount))
	{
		std::cout << "Username: ";
		std::cin.getline(username, MaxAccountNameLength);

		std::cout << "Password: ";
		std::cin.getline(password, MaxAccountPasswordLength);
	}

	if (!doesUserHaveAnAccount)
	{
	  //save the new account username and password
		char filename[] = "accounts.txt";
		saveUsernameAndPasswordInFile(filename, username,password);
	}

	mystrcpy(username, loggedInUsername);
}



bool setup(char* username)
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
	char filename[] = "accounts.txt";
	int accountsFileRows = fileRowsCount(filename);
	char** accounts = new char* [accountsFileRows];

	fillRowsFromFileToCharArray(filename, accounts, accountsFileRows);

	userInput(accounts, accountsFileRows, username, doesUserHaveAnAccount);

	return doesUserHaveAnAccount;
}

void checkForSavedGameOfUser(char* username, int& level, int& boardForLevel) 
{
	//open the file
	//search for the name
	//if the name exists find the level and the board 
	//load the last played game data
}

int main()
{
	//setting up the game
	char username[MaxAccountNameLength];
	bool doesCurrentUserAlreadyHaveAnAccount = setup(username);

	//see if the user have a saved game in the file with saved games
	int level = -1;
	int boardForLevel = -1;

	if (doesCurrentUserAlreadyHaveAnAccount)
	{
		checkForSavedGameOfUser(username, level, boardForLevel);
	}

    //the file must contain
	//username
	//level 
	//currentState

	//printing the currentState of the game

}


