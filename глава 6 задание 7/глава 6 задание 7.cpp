#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


enum Dignity
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	LENGHT_DIGNITY
};

enum Suit
{
	SPADES,
	HEART,
	CLUBS,
	DIAMONDS,
	LENGHT_SUIT
};

struct Card
{
	Dignity dignity;
	Suit suit;
};

void printCard(const Card& card)
{
	switch (card.dignity)
	{
	case TWO:
		std::cout << 2;
		break;
	case THREE:
		std::cout << 3;
		break;
	case FOUR:
		std::cout << 4;
		break;
	case FIVE:
		std::cout << 5;
		break;
	case SIX:
		std::cout << 6;
		break;
	case SEVEN:
		std::cout << 7;
		break;
	case EIGHT:
		std::cout << 8;
		break;
	case NINE:
		std::cout << 9;
		break;
	case TEN:
		std::cout << 10;
		break;
	case JACK:
		std::cout << "J";
		break;
	case QUEEN:
		std::cout << "Q";
		break;
	case KING:
		std::cout << "K";
		break;
	case ACE:
		std::cout << "A";
		break;
	}
	switch (card.suit)
	{
	case SPADES:
		std::cout << "S";
		break;
	case HEART:
		std::cout << "H";
		break;
	case CLUBS:
		std::cout << "C";
		break;
	case DIAMONDS:
		std::cout << "D";
		break;
	}
}

void printDeck(const std::array<Card, 52>& deck)
{
	for (auto& element : deck)
	{
		printCard(element);
		std::cout << std::endl;
	}
}

void swapCard(Card& x, Card& y)
{
	Card temp = x;
	x = y;
	y = temp;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52>& deck)
{
	for (int i = 0; i < 52; ++i)
	{
		swapCard(deck[i], deck[getRandomNumber(0, 51)]);
	}
}

int getCardValue(Card card)
{
	switch (card.dignity)
	{
	case TWO:
		return 2;
		break;
	case THREE:
		return 3;
		break;
	case FOUR:
		return 4;
		break;
	case FIVE:
		return 5;
		break;
	case SIX:
		return 6;
		break;
	case SEVEN:
		return 7;
		break;
	case EIGHT:
		return 8;
		break;
	case NINE:
		return 9;
		break;
	case TEN:
		return 10;
		break;
	case JACK:
		return 10;
		break;
	case QUEEN:
		return 10;
		break;
	case KING:
		return 10;
		break;
	case ACE:
		return 11;
		break;
	}
	return 0;
}

bool playBlackjack(std::array<Card,52> &deck)
{
	Card* cardPtr = &deck[0];
	int playerPoint = 0;
	int dialerPoint = 0;

	std::cout << "DIALER HAVE CARD: ";
	printCard(*cardPtr);
	std::cout << "\n";

    dialerPoint += getCardValue(*cardPtr++);
	std::cout << "DIALER HAVE "<<dialerPoint<<" POINTS\n";
	std::cout << "\n";
;

    
    std::cout << "YOU HAVE CARD: ";
    printCard(*cardPtr);
    std::cout << " ";
    playerPoint += getCardValue(*cardPtr++);
	printCard(*cardPtr);
	std::cout << "\n";
	playerPoint += getCardValue(*cardPtr++);
	//playerPoint += getCardValue(*cardPtr) + getCardValue(*cardPtr++);
	std::cout << "YOU HAVE " << playerPoint << " POINTS\n";
	std::cout << "------------------\n";

	std::string choice;

	bool flag = true;
	while (flag) 
	{
		std::cout << "hit or stand?\n";
		std::cout << "your choice: ";
		std::cin >> choice;
		if (choice == "hit")
		{
			playerPoint += getCardValue(*cardPtr++);
			std::cout << playerPoint << '\n';
			if (playerPoint > 21)
			{
				std::cout << "HAHAHAHA YOU LOST\n\n\n\n\n";
				return false;
			}
		}
		if (choice == "stand")
			flag = false;
	}

	while (dialerPoint < 17) 
	{
		dialerPoint += getCardValue(*cardPtr++);
		if (dialerPoint > 21)
		{
			std::cout << "CONGRATULATIONS! YOU WIN!\n\n\n\n\n";
			return true;
		}
	}

	if (dialerPoint>playerPoint)
	{
		std::cout << "DIALER HAVE "<<dialerPoint<<" POINTS\n";
		std::cout << "YOU HAVE "<<playerPoint<<" POINTS\n";
		std::cout << "HAHAHAHA YOU LOST\n\n\n\n\n";
		return false;
	}

	if (dialerPoint < playerPoint)
	{
		std::cout << "DIALER HAVE " << dialerPoint << " POINTS\n";
		std::cout << "YOU HAVE " << playerPoint << " POINTS\n";
		std::cout << "CONGRATULATIONS! YOU WIN!\n\n\n\n\n";
		return true;
	}

	if (dialerPoint == playerPoint)
	{
		std::cout << "DIALER HAVE " << dialerPoint << " POINTS\n";
		std::cout << "YOU HAVE " << playerPoint << " POINTS\n";
		std::cout << "THIS IS A DRAW\n\n\n\n\n";
		return true;
	}
}
std::array<Card, 52> deck;

int main()
{

	srand(static_cast<unsigned int>(time(0)));
	rand();


	int card = 0;
	for (int i = 0; i < LENGHT_SUIT; ++i)
	{
		for (int j = 0; j < LENGHT_DIGNITY; ++j)
		{
			deck[card].dignity = static_cast<Dignity>(j);
			deck[card].suit = static_cast<Suit>(i);
			card++;
		}
	}
	std::string choice;
	/*std::cout << "playing?\n yes or no\n";
	std::cout << "your choice: ";*/
	
	//printDeck(deck);

	do
	{
		std::cout << "playing?\n yes or no\n";
		std::cout << "your choice:";
		std::cin >> choice;
		if (choice == "no")
			return 0;
		//system("cls");
		shuffleDeck(deck);
		printDeck(deck);
		playBlackjack(deck);

	} while (true);
	
	return 0;
}