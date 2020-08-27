// Lesson8OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Header.h"
#include <string>
#include <array>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdint>//for std::uint_fast8
#include <string>
#include <cstddef>
#include <iostream>
#include "Vector3d.h" // for creating Vector3d object
#include "Point3d.h" // for creating Point3d object
#include <chrono> // for std::chrono functions
#include <algorithm> // for std::sort
#include <cmath>
#include <string_view>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <random>


class Card
{
private:
    std::vector m_rank;
    m_suit;
};

void chapter_8_comprehensive_quiz3()
{
/*
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

enum class CardSuit
{
  SUIT_CLUB,
  SUIT_DIAMOND,
  SUIT_HEART,
  SUIT_SPADE,

  MAX_SUITS
};

enum class CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,

  MAX_RANKS
};

struct Card
{
  CardRank rank{};
  CardSuit suit{};
};

struct Player
{
  int score{};
};

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

// Maximum score before losing.
constexpr int maximumScore{ 21 };

// Minium score that the dealer has to have.
constexpr int minimumDealerScore{ 17 };

void printCard(const Card& card)
{
  switch (card.rank)
  {
  case CardRank::RANK_2:
    std::cout << '2';
    break;
  case CardRank::RANK_3:
    std::cout << '3';
    break;
  case CardRank::RANK_4:
    std::cout << '4';
    break;
  case CardRank::RANK_5:
    std::cout << '5';
    break;
  case CardRank::RANK_6:
    std::cout << '6';
    break;
  case CardRank::RANK_7:
    std::cout << '7';
    break;
  case CardRank::RANK_8:
    std::cout << '8';
    break;
  case CardRank::RANK_9:
    std::cout << '9';
    break;
  case CardRank::RANK_10:
    std::cout << 'T';
    break;
  case CardRank::RANK_JACK:
    std::cout << 'J';
    break;
  case CardRank::RANK_QUEEN:
    std::cout << 'Q';
    break;
  case CardRank::RANK_KING:
    std::cout << 'K';
    break;
  case CardRank::RANK_ACE:
    std::cout << 'A';
    break;
  default:
    std::cout << '?';
    break;
  }

  switch (card.suit)
  {
  case CardSuit::SUIT_CLUB:
    std::cout << 'C';
    break;
  case CardSuit::SUIT_DIAMOND:
    std::cout << 'D';
    break;
  case CardSuit::SUIT_HEART:
    std::cout << 'H';
    break;
  case CardSuit::SUIT_SPADE:
    std::cout << 'S';
    break;
  default:
    std::cout << '?';
    break;
  }
}

int getCardValue(const Card& card)
{
  if (card.rank <= CardRank::RANK_10)
  {
    return (static_cast<int>(card.rank) + 2);
  }

  switch (card.rank)
  {
  case CardRank::RANK_JACK:
  case CardRank::RANK_QUEEN:
  case CardRank::RANK_KING:
    return 10;
  case CardRank::RANK_ACE:
    return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}

void printDeck(const deck_type& deck)
{
  for (const auto& card : deck)
  {
    printCard(card);
    std::cout << ' ';
  }

  std::cout << '\n';
}

deck_type createDeck()
{
  deck_type deck{};

  index_type card{ 0 };

  auto suits{ static_cast<index_type>(CardSuit::MAX_SUITS) };
  auto ranks{ static_cast<index_type>(CardRank::MAX_RANKS) };

  for (index_type suit{ 0 }; suit < suits; ++suit)
  {
    for (index_type rank{ 0 }; rank < ranks; ++rank)
    {
      deck[card].suit = static_cast<CardSuit>(suit);
      deck[card].rank = static_cast<CardRank>(rank);
      ++card;
    }
  }

  return deck;
}

void shuffleDeck(deck_type& deck)
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  std::shuffle(deck.begin(), deck.end(), mt);
}

bool playerWantsHit()
{
  while (true)
  {
    std::cout << "(h) to hit, or (s) to stand: ";

    char ch{};
    std::cin >> ch;

    switch (ch)
    {
    case 'h':
      return true;
    case 's':
      return false;
    }
  }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
{
  while (true)
  {
    std::cout << "You have: " << player.score << '\n';

    if (player.score > maximumScore)
    {
      return true;
    }
    else
    {
      if (playerWantsHit())
      {
        player.score += getCardValue(deck[nextCardIndex++]);
      }
      else
      {
        // The player didn't go bust.
        return false;
      }
    }
  }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
{
  while (dealer.score < minimumDealerScore)
  {
    dealer.score += getCardValue(deck[nextCardIndex++]);
  }

  return (dealer.score > maximumScore);
}

bool playBlackjack(const deck_type& deck)
{
  index_type nextCardIndex{ 0 };

  Player dealer{ getCardValue(deck[nextCardIndex++]) };

  std::cout << "The dealer is showing: " << dealer.score << '\n';

  Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
  nextCardIndex += 2;

  if (playerTurn(deck, nextCardIndex, player))
  {
    return false;
  }

  if (dealerTurn(deck, nextCardIndex, dealer))
  {
    return true;
  }

  return (player.score > dealer.score);
}

int main()
{
  auto deck{ createDeck() };

  shuffleDeck(deck);

  if (playBlackjack(deck))
  {
    std::cout << "You win!\n";
  }
  else
  {
    std::cout << "You lose!\n";
  }

  return 0;
}

This Blackjack program is really composed of four parts: 
the logic that deals with cards, 
the logic that deals with the deck of cards, 
the logic that deals with dealing cards from the deck, 
and the game logic. 
Our strategy will be to work on each of these pieces individually, 
testing each part with a small test program as we go. 
That way, instead of trying to convert the entire program in one go,
we can do it in 4 testable parts.

a) Let’s start by making Card a class instead of a struct. 
The good news is that the Card class is pretty similar to the 
Monster class from the previous quiz question. 

First, create private members to hold the rank and suit
(name them m_rank and m_suit accordingly). 

Second, create a public constructor for the Card class so we can initialize Cards.
Third, make the class default constructible,
either by adding a default constructor or by adding default arguments 
to the current constructor. 

Finally, move the printCard() and getCardValue() 
functions inside the class as public members (remember to make them const!)

A reminder

When using a std::array (or std::vector) where the elements are a class type, 
your element’s class must have a default constructor so the elements
can be initialized to a reasonable default state. 
If you do not provide one, you’ll get a cryptic error about attempting to reference 
a deleted function.

*/
}

int main()
{
    //timing_your_code();
	chapter_8_comprehensive_quiz3();
	

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project 
// > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > 
// Project and select the .sln file
