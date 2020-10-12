//cards.cpp
//Nick Ong
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
#include <fstream>

using namespace std;

//Card Class implementation
Card::Card() : next(0) {};
Card::Card(string cardValue) : next(0)
{
  value = cardValue;
}

bool Card::operator==(const Card& c)
{
  return value == c.value;
}

ostream& operator<<(ostream& ofs, const Card& c)
{
  ofs << c.value << endl;
  return ofs;
}


//CardList Class Implementaion
CardList::CardList()
{
  first = NULL;
  last = NULL;
}

CardList::~CardList()
{
  Card* iter = first;
  Card* iterNext;
  while (iter)
    {
      iterNext = iter->next;
      delete iter;
      iter = iterNext;
    }
}

void CardList::append(string cardValue)
{
  Card* newCard = new Card(cardValue);
  
  if (!first)
    {
      first = newCard;
      last = newCard;
    }
  else
    {
      last->next = newCard;
      last = newCard;
    }
}

bool CardList::contains(Card& c)
{
  Card* iter = first;
  while (iter)
    {
      if ((*iter) == c)
	{
	  return true;
	}
      iter = iter->next;
    }
  return false;
}

void CardList::remove(Card& c)
{
  if (first == NULL && last == NULL) //empty list
    {
      cout<<"Empty list"<<endl;
      exit(1);
    }
  Card *iter = first;
  Card* iterNext;
  if (*iter == c)//if the removed card is the first card
   {
    if (first == last)//if there is only one card in the deck
      {
         last = last->next;
      }
    iterNext = iter->next;
    first = iterNext;
    delete iter;
    iter = iterNext;
    
   }
  
  else
    {
      while (iter->next)
      {
	if (*(iter->next) == c)
	  {
	    if (last == iter->next)//if the removed card is the last card
	      {
		      last = iter;
	      }
	    iterNext = iter->next;
	    iter->next = iter->next->next;
	    delete iterNext;
	    break;
	  }
	iter = iter->next;
      }
    }
}

Card* CardList::getFirst() const
{
  return first;
}

Card* CardList::getLast() const
{
  return last;
}
