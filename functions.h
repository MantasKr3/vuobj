#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H
#include <iostream>
#include <vector>
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
void print(vector < stud > & g, vector < stud > & n);
void input(vector <stud> &studentai,int change);
void inputas(vector <stud> &studentai);
bool is_number(const std::string  &s);
void count(vector <stud> &studentai);
void count2(vector <stud> &studentai);
bool gavoSkola(const stud& s);
vector<stud> rastin(std::vector<stud>& studentai);
void skirstymas(std::vector<stud>& studentai, std::vector<stud>& n,std::vector<stud>& g);
void skirstymas2(std::vector<stud>& studentai, std::vector<stud>& n, std::vector<stud>& g);


#endif
