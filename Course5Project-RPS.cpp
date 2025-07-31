#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRPSGame { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1Wins = 1, ComputerWins = 2, Draw = 3 };

int ReadPositiveNumber(string message)
{
	int positiveNumber = 0;
	do
	{
		cout << endl << message;
		cin >> positiveNumber;
	} while (positiveNumber <= 0 || positiveNumber > 10);

	return positiveNumber;
}

enRPSGame ReadPlayerChoice(string message)
{
	int positiveNumber1To3 = 0;
	do
	{
		cout << endl << message;
		cin >> positiveNumber1To3;
	} while (positiveNumber1To3 < 1 || positiveNumber1To3 > 3);

	return (enRPSGame)positiveNumber1To3;
}

int GenerateRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enRPSGame ComputerRPSChoice()
{
	return (enRPSGame)GenerateRandomNumber(1, 3);
}

enWinner Winner(enRPSGame PlayerChoice, enRPSGame ComputerChoice)
{
	if (PlayerChoice == enRPSGame::Rock)
	{
		if (ComputerChoice == enRPSGame::Rock)
			return enWinner::Draw;

		else if (ComputerChoice == enRPSGame::Paper)
			return enWinner::ComputerWins;

		else
			return enWinner::Player1Wins;
	}

	else if (PlayerChoice == enRPSGame::Paper)
	{
		if (ComputerChoice == enRPSGame::Rock)
			return enWinner::Player1Wins;

		else if (ComputerChoice == enRPSGame::Paper)
			return enWinner::Draw;

		else
			return enWinner::ComputerWins;
	}

	else
	{
		if (ComputerChoice == enRPSGame::Rock)
			return enWinner::ComputerWins;

		else if (ComputerChoice == enRPSGame::Paper)
			return enWinner::Player1Wins;

		else
			return enWinner::Draw;
	}
}

string WinnerToString(enWinner winner)
{
	switch (winner)
	{
	case Player1Wins:
		return "Player1";

	case ComputerWins:
		return "Computer";

	case Draw:
		return "No Winner";

	default:
		return "Unknown";
	}
}

string RPSToString(enRPSGame RPS)
{
	switch (RPS)
	{
	case Rock:
		return "Rock";

	case Paper:
		return "Paper";

	case Scissors:
		return "Scissors";

	default:
		return "Unknown";
	}
}

void PrintGameOver(int Player1Wins, int ComputerWins, int DrawTimes, int GameRounds, string FinalWinner)
{
	cout << "\t\t\t__________________________________________________________________________\n";
	cout << "\t\t\t\t\t\t+++ G a m e  O v e r +++\n";
	cout << "\t\t\t__________________________________________________________________________\n";
	cout << "\t\t\t_____________________________[Game Results]_______________________________\n";
	cout << "\t\t\tGame Rounds\t\t: " << GameRounds;
	cout << "\n\t\t\tPlayer1 Won Times\t: " << Player1Wins;
	cout << "\n\t\t\tComputer Won Times\t: " << ComputerWins;
	cout << "\n\t\t\tDraw Times\t\t: " << DrawTimes;
	cout << "\n\t\t\tFinal Winner\t\t: " << FinalWinner;
	cout << "\n\t\t\t__________________________________________________________________________\n";
}

char PlayAgain(string message)
{
	char answer;

	do
	{
		cout << message;
		cin >> answer;
	} while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

	if (answer == 'y' || answer == 'Y')
	{
		system("cls");
		system("color 0F");
	}

	return answer;
}

void NumberOfRounds(int number, int& Player1Wins, int& ComputerWins, int& DrawTimes, int& GameRounds, string& FinalWinner)
{
	enRPSGame PlayerChoice, computerChoice;

	for (int i = 1; i <= number; i++)
	{
		cout << "\n\nRound [" << i << "] begins: \n\n";

		PlayerChoice = ReadPlayerChoice("Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ");
		computerChoice = ComputerRPSChoice();

		enWinner winnerValue = Winner(PlayerChoice, computerChoice);
		string WinnerResult = WinnerToString(winnerValue);

		cout << "\n___________________Round [" << i << "]___________________\n";
		cout << "\nPlayer1  Choice: " << RPSToString(PlayerChoice);
		cout << "\nComputer Choice: " << RPSToString(computerChoice);

		if (winnerValue == enWinner::Player1Wins)
		{
			system("Color 2F");
			++Player1Wins;
			++GameRounds;
			cout << "\nRound Winner   : [" << WinnerResult << "]";

		}
		else if (winnerValue == enWinner::ComputerWins)
		{
			system("Color 4F");
			++ComputerWins;
			++GameRounds;
			cout << "\a";
			cout << "\nRound Winner   : [" << WinnerResult << "]";
		}
		else
		{
			system("Color E0");
			++DrawTimes;
			++GameRounds;
			cout << "\nRound Winner   : [" << WinnerResult << "]";
		}

		if (Player1Wins > ComputerWins)
			FinalWinner = "Player1";

		else if (ComputerWins > Player1Wins)
			FinalWinner = "Computer";

		else
			FinalWinner = "No Winner";


		cout << "\n_______________________________________________\n";
	}

	PrintGameOver(Player1Wins, ComputerWins, DrawTimes, GameRounds, FinalWinner);


}

void StartGame()
{
	char PlayMore;

	do
	{


		int Player1Wins = 0, ComputerWins = 0, DrawTimes = 0, GameRounds = 0;
		string FinalWinner = "";

		int ReadNumberOfRounds = ReadPositiveNumber("\nHow Many Rounds 1 to 10 ? ");

		NumberOfRounds(ReadNumberOfRounds, Player1Wins, ComputerWins, DrawTimes, GameRounds, FinalWinner);

		PlayMore = PlayAgain("\n\t\t\tDo You Want to Play More ? [y]:yes, [n]:no ? ");
	} while (PlayMore == 'y' || PlayMore == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}