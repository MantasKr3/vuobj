#ifndef GUARD_lFUNCTIONS_H
#define GUARD_lFUNCTIONS_H
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
#include <vector>
#include <numeric>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::list;
using std::vector;
using std::ifstream;
using std::ofstream;

struct stud {
  string vardas;
  string pavarde;
  int selection;
  vector <int> nd;
  int kiekis;
  int egz;
  double vid;
  double median;
};

bool compare_m (stud &a, stud &b);
void generate(int change);
void print(list < stud > & g, list < stud > & n);
void input(list <stud> &studentai,int change);
void inputas(list <stud> &studentai);
bool is_number(const std::string  &s);
void count(list <stud> &studentai);
void count2(list <stud> &studentai);
bool gavoSkola(const stud& s);
list<stud> rastin(std::list<stud>& studentai);
void skirstymas(std::list<stud>& studentai, std::list<stud>& n,std::list<stud>& g);
void skirstymas2(std::list<stud>& studentai, std::list<stud>& n, std::list<stud>& g);


#endif
