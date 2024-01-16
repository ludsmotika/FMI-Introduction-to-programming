#include <iostream>
#include <fstream>
#include <istream>
#include <string>

const int MaxAccountNameLength = 50;
const int MaxAccountPasswordLength = 50;
const int MaxRowInFileLength = 50;

void printNonogramTitle() {
	std::cout << " _   _   ___   _   _   ___    ____  ____      _     __  __ \n";
	std::cout << "| \\ | | / _ \\ | \\ | | / _ \\  / ___||  _ \\    / \\   |  \\/  |\n";
	std::cout << "|  \\| || | | ||  \\| || | | || |  _ | |_) |  / _ \\  | |\\/| |\n";
	std::cout << "| |\\  || |_| || |\\  || |_| || |_| ||  _ <  / ___ \\ | |  | |\n";
	std::cout << "|_| \\_| \\___/ |_| \\_| \\___/  \\____||_| \\_\\/_/   \\_\\|_|  |_|\n";
}

void printCharMatrix(char** matrix, int boardSize) {
	if (!matrix)
	{
		return;
	}

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!matrix[i])
		{
			return;
		}
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			std::cout << matrix[i][j] << '|';
		}
		std::cout << std::endl;
	}
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

void deleteMatrix(char** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int convertCharToDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';

	return -1;
}

unsigned convertStrToUnsigned(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;

	while (*str)
	{
		int digit = convertCharToDigit(*str);
		if (digit == -1)
			return 0;
		(result *= 10) += digit;
		str++;
	}

	return result;
}

int generateRandomNumberBetweenOneAndTwo()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	return (std::rand() % 2) + 1;
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

int boardSizeForLevel(int level)
{
	switch (level)
	{
	case 1:
		return 5;
		break;
	case 2:
	case 3:
		return 10;
		break;
	case 4:
	case 5:
		return 15;
		break;

	default:
		return 0;
		break;
	}
}

void fillRowsFromFileToCharArray(char* filename, char** accounts, int rowsCount)
{
	std::ifstream filein(filename);

	if (!filein.is_open())
	{
		return;
	}


	for (size_t i = 0; i < rowsCount; i++)
	{
		char currentRow[MaxRowInFileLength];
		filein.getline(currentRow, MaxRowInFileLength, '\n');
		int currentRowLength = mystrlen(currentRow);

		accounts[i] = new char[currentRowLength + 1];
		mystrcpy(currentRow, accounts[i]);
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

	ofs << username << std::endl;
	ofs << password << std::endl;

	ofs.clear();
	ofs.close();
}

bool isValidInputForLogin(int indexOfUsername, char* password, char* passwordToCompareWith)
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
		return isValidInputForLogin(indexOfUsername, password, accounts[indexOfUsername + 1]);
	}
	else
	{
		return isValidInputForRegister(indexOfUsername, username, password);
	}
}

void userInput(char** accounts, int accountsFileRows, char* loggedInUsername, bool doesUserHaveAnAccount)
{
	std::cout << (doesUserHaveAnAccount ? "Login" : "Register") << std::endl;

	//get the input of the user
	std::cout << "Username: ";
	char username[MaxAccountNameLength];

	std::cin.ignore();
	std::cin.getline(username, MaxAccountNameLength);

	std::cout << "Password: ";
	char password[MaxAccountPasswordLength];
	std::cin.getline(password, MaxAccountPasswordLength);

	//check if the input contains in the accounts

	while (!isInputValid(accounts, accountsFileRows, username, password, doesUserHaveAnAccount))
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
		saveUsernameAndPasswordInFile(filename, username, password);
	}

	mystrcpy(username, loggedInUsername);
}

char** initBoard(int level)
{
	int size = boardSizeForLevel(level);

	char** board = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		board[i] = new char[size + 1];

		for (size_t j = 0; j < size; j++)
		{
			board[i][j] = '0';
		}

		board[i][size] = '\0';
	}

	return board;
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

	deleteMatrix(accounts, accountsFileRows);

	return doesUserHaveAnAccount;
}

char** checkForSavedGameOfUser(char* username, int& level, int& boardForLevel, bool& doesUserHaveASavedGame)
{
	char filename[] = "savedGames.txt";
	int savedGamesFileRows = fileRowsCount(filename);
	char** savedGames = new char* [savedGamesFileRows];

	fillRowsFromFileToCharArray(filename, savedGames, savedGamesFileRows);

	for (size_t i = 0; i < savedGamesFileRows; i++)
	{
		if (!mystrcmp(savedGames[i], "save") && savedGames[i + 1] && !mystrcmp(savedGames[i + 1], username))
		{
			level = convertStrToUnsigned(savedGames[i + 2]);
			boardForLevel = convertStrToUnsigned(savedGames[i + 3]);
			int boardSize = boardSizeForLevel(level);

			char** board = new char* [boardSize];

			for (size_t j = 0; j < boardSize; j++)
			{
				board[j] = new char[boardSize + 1];
				mystrcpy(savedGames[j + i + 4], board[j]);
			}

			deleteMatrix(savedGames, savedGamesFileRows);
			return board;
		}
	}

	deleteMatrix(savedGames, savedGamesFileRows);
	return nullptr;
}


char** loadLevel(int levelToLoad, int boardForLevel)
{
	char filename[] = "gameLevels.txt";
	int gameLevelsFileRows = fileRowsCount(filename);
	char** gameLevels = new char* [gameLevelsFileRows];

	fillRowsFromFileToCharArray(filename, gameLevels, gameLevelsFileRows);

	int counter = 1;
	int rowToStartReadingFrom = -1;

	for (size_t i = 0; i < gameLevelsFileRows; i++)
	{
		if (!mystrcmp(gameLevels[i], "level") && (counter++ == ((levelToLoad - 1) * 2) + boardForLevel))
		{
			rowToStartReadingFrom = i + 1;
			break;
		}
	}

	int boardSize = boardSizeForLevel(levelToLoad);

	char** board = new char* [boardSize];
	for (size_t i = 0; i < boardSize; i++)
	{
		board[i] = new char[boardSize];
		mystrcpy(gameLevels[rowToStartReadingFrom + i], board[i]);
	}

	return board;
	//todo: delete the gameLevels matrix when needed
}

int findBiggestCountOfSequencesForRowsOrCols(char** answerBoard, int size, bool isForRows)
{
	if (!answerBoard)
	{
		return -1;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (!answerBoard[i])
		{
			return -1;
		}
	}

	int biggestCountOfSequences = 0;

	bool isInSequence = false;
	int currentCountOfSequences = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (isForRows ? answerBoard[i][j] == '1' : answerBoard[j][i] == '1')
			{
				isInSequence = true;
			}
			else
			{
				if (isInSequence == true)
				{
					currentCountOfSequences++;
					isInSequence = false;
				}
			}
		}
		if (isInSequence == true)
		{
			currentCountOfSequences++;
			isInSequence = false;
		}

		if (currentCountOfSequences > biggestCountOfSequences)
		{
			biggestCountOfSequences = currentCountOfSequences;
		}

		currentCountOfSequences = 0;
	}

	return biggestCountOfSequences;
}

void loadDataForRowsOrCols(char** answerBoard, int** data, int longestPossibleRowInData, int size, bool isForRows)
{
	if (!answerBoard || !data)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!answerBoard[i])
		{
			return;
		}
	}

	for (size_t i = 0; i < longestPossibleRowInData; i++)
	{
		if (!data[i])
		{
			return;
		}
	}

	int indexToSaveOn = longestPossibleRowInData - 1;
	int currentCountOfSequences = 0;
	bool wasPreviousAValidPosition = false;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (isForRows ? answerBoard[i][j] == '1' : answerBoard[j][i] == '1')
			{
				currentCountOfSequences++;
				wasPreviousAValidPosition = true;
			}
			else
			{
				if (wasPreviousAValidPosition)
				{
					data[i][indexToSaveOn] = currentCountOfSequences;
					indexToSaveOn--;
					currentCountOfSequences = 0;
					wasPreviousAValidPosition = false;
				}
			}
		}
		if (currentCountOfSequences)
		{
			data[i][indexToSaveOn] = currentCountOfSequences;
		}
		currentCountOfSequences = 0;
		indexToSaveOn = longestPossibleRowInData - 1;
		wasPreviousAValidPosition = false;
	}
}

int** getRowsOrColsInfo(char** answerBoard, int size, bool isForRows, int& longestRowLength)
{
	if (!answerBoard)
	{
		return nullptr;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (!answerBoard[i])
		{
			return nullptr;
		}
	}

	longestRowLength = findBiggestCountOfSequencesForRowsOrCols(answerBoard, size, isForRows);

	int** data = new int* [size];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = new int[longestRowLength];
		for (size_t j = 0; j < longestRowLength; j++)
		{
			data[i][j] = 0;
		}
	}

	loadDataForRowsOrCols(answerBoard, data, longestRowLength, size, isForRows);

	return data;
}

int getCountOfSymbolsToIndent(int** rowsInfo, int longestRowLength, int boardSize)
{
	int longestRowSymbols = 0;
	int currentRowSymbols = 0;

	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < longestRowLength; j++)
		{
			if (rowsInfo[i][j] >= 10 && rowsInfo[i][j] <= 99)
			{
				currentRowSymbols += 3;
			}
			else if (rowsInfo[i][j] >= 1 && rowsInfo[i][j] <= 9)
			{
				currentRowSymbols += 2;
			}
			else if (rowsInfo[i][j] == 0)
			{
				currentRowSymbols += 2;
			}
		}

		if (currentRowSymbols > longestRowSymbols)
		{
			longestRowSymbols = currentRowSymbols;
		}
		currentRowSymbols = 0;
	}

	return longestRowSymbols;
}

void printWholeBoard(int** rowsInfo, int longestRowLength, int** colsInfo, int longestColLength, char** currentBoard, int boardSize)
{
	if (!rowsInfo || !colsInfo || !currentBoard)
		return;

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!currentBoard[i])
			return;
	}
	for (size_t i = 0; i < longestRowLength; i++)
	{
		if (!rowsInfo[i])
			return;
	}
	for (size_t i = 0; i < longestColLength; i++)
	{
		if (!colsInfo[i])
			return;
	}

	int longestRowSymbols = getCountOfSymbolsToIndent(rowsInfo, longestRowLength, boardSize);

	for (int i = longestColLength - 1; i >= 0; i--)
	{
		for (size_t i = 0; i < longestRowSymbols; i++)
		{
			std::cout << " ";
		}
		std::cout << "|";
		for (size_t j = 0; j < boardSize; j++)
		{
			if (colsInfo[j][i] >= 1 && colsInfo[j][i] <= 9)
			{
				std::cout << " " << colsInfo[j][i] << "|";
			}
			else if (!colsInfo[j][i])
			{
				std::cout << "  " << "|";
			}
			else
			{
				std::cout << colsInfo[j][i] << "|";
			}
		}
		std::cout << std::endl;
	}

	int wholeBoardLength = (boardSize * 3) + longestRowSymbols + 1;

	for (size_t i = 0; i < wholeBoardLength; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;


	for (size_t i = 0; i < boardSize; i++)
	{

		int indent = 0;
		for (int j = longestRowLength - 1; j >= 0; j--)
		{
			if (rowsInfo[i][j])
			{
				(rowsInfo[i][j] >= 10 && rowsInfo[i][j] <= 99 ? indent += 3 : indent += 2);
				std::cout << rowsInfo[i][j] << " ";
			}
			else
			{
				indent += 2;
				std::cout << "  ";
			}
		}

		for (size_t i = indent; i < longestRowSymbols; i++)
		{
			std::cout << " ";
		}

		std::cout << "|";

		for (size_t j = 0; j < boardSize; j++)
		{
			const char* symbolsToPrint = (currentBoard[i][j] == '0' ? "  " : (currentBoard[i][j] == '1' ? "XX" : "--"));
			std::cout << symbolsToPrint << "|";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < wholeBoardLength; i++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
	}
}

bool areValidIndexes(int x, int y, char** currentBoard, int boardSize)
{
	if (!currentBoard)
		return false;

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!currentBoard[i])
			return false;
	}

	if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
	{
		std::cout << "You have entered an invalid indexes! Please try again." << std::endl;
		return false;
	}

	if (currentBoard[x][y] != '0')
	{
		std::cout << "You have already filled this position! Enter new coordinates." << std::endl;
		return false;
	}

	return true;
}

void getInput(int& x, int& y, bool& toFill, char** currentBoard, int boardSize)
{
	std::cout << "Enter x:";
	std::cin >> x;
	x--;
	std::cout << "Enter y:";
	std::cin >> y;
	y--;
	int numToCast;
	std::cout << "Mark as (fill = '1') or (empty = '0'):";
	std::cin >> numToCast;

	while (!areValidIndexes(x, y, currentBoard, boardSize))
	{
		std::cout << "Enter x:";
		std::cin >> x;
		x--;
		std::cout << "Enter y:";
		std::cin >> y;
		y--;
		std::cout << "Mark as (fill = '1') or (empty = '0'):";
		std::cin >> numToCast;
	}

	toFill = numToCast;
}

void autofillLineIfCurrentMoveFilledIt(int x, int y, char** currentBoard, char** answerBoard, int boardSize)
{
	if (!currentBoard)
		return;

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!currentBoard[i])
			return;
	}

	bool isColFinished = true;
	bool isRowFinished = true;
	for (size_t i = 0; i < boardSize; i++)
	{
		if (answerBoard[i][y] == '1' && currentBoard[i][y] != '1')
			isColFinished = false;

		if (answerBoard[x][i] == '1' && currentBoard[x][i] != '1')
			isRowFinished = false;
	}

	if (isRowFinished)
	{
		for (size_t i = 0; i < boardSize; i++)
		{
			if (answerBoard[x][i] == '0')
				currentBoard[x][i] = '2';
		}
	}
	if (isColFinished)
	{
		for (size_t i = 0; i < boardSize; i++)
		{
			if (answerBoard[i][y] == '0')
				currentBoard[i][y] = '2';
		}
	}

}

bool doesUserWonTheGame(char** answerBoard, char** currentBoard, int boardSize)
{
	if (!answerBoard || !currentBoard)
		return false;

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!answerBoard[i] || !currentBoard[i])
			return false;
	}

	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			if (answerBoard[i][j] == '1' && currentBoard[i][j] != '1')
				return false;
		}
	}

	return true;
}

char playNonogram(char** answerBoard, char** currentBoard, int boardSize, int level)
{
	if (!answerBoard || !currentBoard)
		return 'e';

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!answerBoard[i] || !currentBoard[i])
			return 'e';
	}

	int longestRowLength = 0;
	int** rowsInfo = getRowsOrColsInfo(answerBoard, boardSize, true, longestRowLength);
	int longestColLength = 0;
	int** colsInfo = getRowsOrColsInfo(answerBoard, boardSize, false, longestColLength);

	int wrongAnswers = 0;

	while (true)
	{
		printWholeBoard(rowsInfo, longestRowLength, colsInfo, longestColLength, currentBoard, boardSize);
		std::cout << "You have only " << level - wrongAnswers << " lives left!" << std::endl;

		int x = 0;
		int y = 0;
		bool toFill = false;
		getInput(x, y, toFill, currentBoard, boardSize);

		if ((answerBoard[x][y] == '1' && toFill) || (answerBoard[x][y] == '0' && !toFill))
		{
			currentBoard[x][y] = (toFill ? '1' : '2');

			autofillLineIfCurrentMoveFilledIt(x, y, currentBoard, answerBoard, boardSize);

			if (doesUserWonTheGame(answerBoard, currentBoard, boardSize))
			{
				printWholeBoard(rowsInfo, longestRowLength, colsInfo, longestColLength, currentBoard, boardSize);
				std::cout << "You have successfully passed the level!";
				return 'w';
			}
		}
		else
		{
			std::cout << "You made a mistake. This position should not be " << (toFill ? "checked" : "empty") << "." << std::endl;
			if (++wrongAnswers == level)
			{
				std::cout << "you lost the game";
				return 'l';
			}
		}
	}
}

void deleteRows(const char* filename, int startRow, int endRow) {

	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		std::cout << "Error opening file: " << filename << std::endl;
		return;
	}

	if (startRow < 0 || endRow < startRow) {
		std::cout << "Invalid startRow or endRow values." << std::endl;
		inputFile.close();
		return;
	}

	std::ofstream outputFile("temp.txt");

	int currentRow = 0;
	char line[MaxRowInFileLength];

	while (inputFile.getline(line, sizeof(line)))
	{
		if (currentRow < startRow || currentRow > endRow)
		{
			outputFile << line << std::endl;
		}
		++currentRow;
	}

	inputFile.close();
	outputFile.close();

	if (std::remove(filename) != 0)
	{
		std::cout << "Error removing file: " << filename << std::endl;
		return;
	}

	if (std::rename("temp.txt", filename) != 0)
	{
		std::cout << "Error renaming file." << std::endl;
		return;
	}

}



void saveGame(int level, int boardForLevel, char* username, char** board, int boardSize)
{
	if (!board)
		return;

	for (size_t i = 0; i < boardSize; i++)
	{
		if (!board[i])
			return;
	}

	char filename[] = "savedGames.txt";
	int savedGamesFileRows = fileRowsCount(filename);
	char** savedGames = new char* [savedGamesFileRows];

	fillRowsFromFileToCharArray(filename, savedGames, savedGamesFileRows);

	bool doesUserHaveASavedGame = false;
	int rowToStartDeleting = -1;
	int rowToStopDeleting = -1;

	for (size_t i = 0; i < savedGamesFileRows; i++)
	{
		if (!mystrcmp(savedGames[i], "save") && !mystrcmp(savedGames[i + 1], username))
		{
			rowToStartDeleting = i;
			int levelForSavedGameToDelete = convertStrToUnsigned(savedGames[i + 2]);
			int rowsOfSavedGame = boardSizeForLevel(levelForSavedGameToDelete);

			rowToStopDeleting = rowToStartDeleting + 3 + rowsOfSavedGame;
			break;
		}
	}

	if (rowToStartDeleting != -1)
	{
		deleteRows(filename, rowToStartDeleting, rowToStopDeleting);
	}


	std::ofstream ofs(filename, std::ofstream::app);
	if (!ofs.is_open())
	{
		return;
	}

	ofs << "save" << std::endl;
	ofs << username << std::endl;
	ofs << level << std::endl;
	ofs << boardForLevel << std::endl;
	for (size_t i = 0; i < boardSize; i++)
	{
		ofs << board[i] << std::endl;
	}

	ofs.clear();
	ofs.close();

	deleteMatrix(savedGames, savedGamesFileRows);
}

char getInputAfterGameEnded(char* message)
{
	char answer;
	std::cout << message << " Yes='y' No='n': ";
	std::cin >> answer;

	while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
	{
		std::cout << "Invalid answer! Try again: ";
		std::cin >> answer;
	}

	return answer;
}

bool handleAnswerAfterGameEnded(char answer, char**& currentBoard, int boardSize, int& level, int& boardForLevel, char* username, bool doesUserWon)
{
	if (answer == 'n' || answer == 'N')
	{
		currentBoard = initBoard(level);
		saveGame(level, boardForLevel, username, currentBoard, boardSize);

		return false;
	}
	else if (answer == 'y' || answer == 'Y')
	{
		if (doesUserWon)
		{
			level++;
			boardForLevel = generateRandomNumberBetweenOneAndTwo();
		}
		currentBoard = initBoard(level);
	}

	return true;
}

bool handleGameAnswer(char gameAnswer, char**& currentBoard, int boardSize, int& level, int& boardForLevel, char* username)
{

	if (gameAnswer == 'w')
	{
		char message[] = "Do you want to continue to the next level?";
		char answer = getInputAfterGameEnded(message);

		if (!handleAnswerAfterGameEnded(answer, currentBoard, boardSize, level, boardForLevel, username, true))
		{
			return false;
		}
	}
	else if (gameAnswer == 'l')
	{
		char message[] = "Try again?";
		char answer = getInputAfterGameEnded(message);

		if (!handleAnswerAfterGameEnded(answer, currentBoard, boardSize, level, boardForLevel, username, false))
		{
			return false;
		}
	}
	else if (gameAnswer == 's')
	{
		saveGame(level, boardForLevel, username, currentBoard, boardSize);
		return false;
	}
	else if (gameAnswer == 'e')
	{
		return false;
	}

	return true;
}

bool continueGameAnswerIsValid(char answer, int level)
{
	if (answer != 'c' && convertCharToDigit(answer) > level)
	{
		return false;
	}
	return true;
}

char savedGameOrContinueOnPreviousLevelsHandler(int& level)
{
	std::cout << "You have a saved game! You can continue the game or start on level which you have already played on." << std::endl;
	std::cout << "Your saved game is on level " << level << ". Choose 'c' for continue or enter the number of the level which you want to start play on. And remember you can play on levels before the one you reached:";

	char answer;
	std::cin >> answer;

	while (!continueGameAnswerIsValid(answer, level))
	{
		char answer;
		std::cin >> answer;
	}

	return answer;
}

int main()
{

	//setting up the game
	char username[MaxAccountNameLength];
	bool doesCurrentUserAlreadyHaveAnAccount = setup(username);

	//see if the user have a saved game in the file with saved games
	int level = 1;
	int boardForLevel = generateRandomNumberBetweenOneAndTwo();
	bool doesUserHaveASavedGame = false;
	char** currentBoard = initBoard(level);
	char** answerBoard;


	if (doesCurrentUserAlreadyHaveAnAccount)
	{
		currentBoard = checkForSavedGameOfUser(username, level, boardForLevel, doesUserHaveASavedGame);

		if (!currentBoard)
		{
			currentBoard = initBoard(level);
		}
		else
		{
			char answer = savedGameOrContinueOnPreviousLevelsHandler(level);

			if (answer != 'c')
			{
				level = convertCharToDigit(answer);
				currentBoard = initBoard(level);
			}
		}
	}

	while (true)
	{
		answerBoard = loadLevel(level, boardForLevel);
		int boardSize = boardSizeForLevel(level);

		//printCharMatrix(answerBoard, boardSize);
		//printCharMatrix(currentBoard, boardSize);

		char gameAnswer = playNonogram(answerBoard, currentBoard, boardSize, level);
		// w == won, l == lose, s == saveGame and exit

		if (!handleGameAnswer(gameAnswer, currentBoard, boardSize, level, boardForLevel, username))
			return 0;

		if (level == 6)
		{
			std::cout << "You passed all the levels. Congratulations!!!";
			return 0;
		}
	}
}

//todo: check for memory leaks
//todo: check for null ptr if's in the methods
//todo: check where does the methods should receive const pointer
//current board memory leak when checking for saved game
//handleAnswerAfterGameEnded current board initBoard pointer reallocation


