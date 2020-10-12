// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_constructors();
  test_equal();

  test_append();
  test_remove();
  test_contains();
  cout<<"All TESTS PASSED"<<endl;
}

void test_constructors(){
  START_TEST("test_constructors");
  Card newCard, newCard2("h 3");
  CardList deck;

  if(!(newCard.next))
    {
      cout<<"PASSED"<<endl;
    }
  assertEquals(newCard2.value, "h 3");
  if (!(deck.getFirst()))
    {
      cout<<"PASSED"<<endl;
    }
}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  test_equal_normal();
  END_TEST("test_equal");

}

void test_equal_empty_list(){
  string testname = "case 0: [], []";
  CardList l1, l2;

  l1.append("h 3");
  l2.append("h 3");//this appends a new value to be the head and tail for each list
  
  assertEquals(*(l1.getFirst()),*(l2.getFirst()));
  assertEquals(*(l1.getLast()), *(l2.getLast()));
}

void test_equal_normal(){
  string testname = "case 1: [h 3, c 10, d j],  [h 3, c 10, d j]";
  CardList l1, l2;
  l1.append("h 3");
  l1.append("c 10");
  l1.append("d j");

  l2.append("h 3");
  l2.append("c 10");
  l2.append("d j");
	    
  assertEquals(*(l1.getFirst()),*(l2.getFirst()));
  assertEquals(*(l1.getLast()), *(l2.getLast()));
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_normal();
  END_TEST("test_append");
}

void test_append_empty_list(){ 
  CardList deck;
  deck.append("h 4");
  assertEquals(deck.getFirst(), deck.getLast()); //tests if the head and tail are equal
}

void test_append_normal(){
  CardList deck;
  Card newCard("h 10");
  
  deck.append("h 4");
  deck.append("h 10");
  assertEquals(*(deck.getLast()), newCard); //tests if the last card is the same as the card created (in terms of value)
}

void test_remove(){
  START_TEST("test_remove");
  test_remove_last_element();
  test_remove_first_element();
  test_remove_normal();
  END_TEST("test_remove");
}

void test_remove_last_element(){
  CardList deck;
  Card newCard("h 2");
  deck.append("h 3");
  deck.append("h 2");
  deck.append("h 1");
  deck.remove(*(deck.getLast()));

  assertEquals(*(deck.getLast()), newCard); //tests if the last card after removal is the middle card
}

void test_remove_first_element(){
  CardList deck;
  Card newCard("h 2");
  deck.append("h 3");
  deck.append("h 2");
  deck.append("h 1");
  deck.remove(*(deck.getFirst()));

  assertEquals(*(deck.getFirst()), newCard); //tests if the first card after removal is the middle card
}

void test_remove_normal(){
  CardList deck;
  Card newCard("h 1"), delCard("h 2");
  deck.append("h 3");
  deck.append("h 2");
  deck.append("h 1");
  deck.remove(delCard);

  assertEquals(*(deck.getFirst()->next), newCard); //tests if the first card's "next" value is the last card
}

void test_contains(){
  START_TEST("test_contains");
  test_contains_empty_list();
  test_contains_normal();
  END_TEST("test_contains");
  
}
void test_contains_empty_list(){
  CardList deck;
  Card newCard("h 3");
  assertEquals(deck.contains(newCard), false);
}

void test_contains_normal(){
  CardList deck;
  Card newCard("h 1");
  deck.append("h 3");
  deck.append("h 2");
  deck.append("h 1");

  assertEquals(deck.contains(newCard), true);
}






