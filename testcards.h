// testcards.h
//Authors: Nick Ong
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>
#include "cards.h"

using namespace std;
void runAll();
void test_constructors();
void test_equal();

void test_append();
void test_remove();
void test_contains();

//test cases
void test_append_empty_list();
void test_append_normal();

void test_equal_empty_list();
void test_equal_normal();

void test_contains_empty_list();
void test_contains_normal();

void test_remove_last_element();
void test_remove_first_element();
void test_remove_normal();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: STRING TEST" << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: INT TEST" << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}


void assertEquals(Card &expected, Card &actual){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: CARD TEST" << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(bool expected, bool actual) {
  if (expected == actual) {
    cout<<"PASSED "<< endl;
  } else {
    cout<<"  FAILED: BOOL TEST" << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}






#endif
