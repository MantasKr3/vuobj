#ifndef GUARD_DFUNCTIONS_H
#define GUARD_DFUNCTIONS_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <cmath>
#include <utility>
#include <random>
#include <list>
#include <deque>
#include <numeric>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::deque;

struct stud {
  string vardas;
  string pavarde;
  int selection;
  deque <int> nd;
  int kiekis;
  int egz;
  double vid;
  double median;
};

bool compare_m (stud &a, stud &b);
void generate(int change);
void print(deque < stud > & g, deque < stud > & n);
void input(deque <stud> &studentai,int change);
void inputas(deque <stud> &studentai);
bool is_number(const std::string  &s);
void count(deque <stud> &studentai);
void count2(deque <stud> &studentai);
bool gavoSkola(const stud& s);
deque<stud> rastin(std::deque<stud>& studentai);
void skirstymas(std::deque<stud>& studentai, std::deque<stud>& n,std::deque<stud>& g);
void skirstymas2(std::deque<stud>& studentai, std::deque<stud>& n, std::deque<stud>& g);


#endif
