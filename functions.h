#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <cmath>

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
bool compare_v (stud &a, stud &b);
void generate(int change);
void sortinti(vector < stud > & studentai,vector < stud > & g, vector < stud > & n);
void print(vector < stud > & studentai,vector < stud > & g, vector < stud > & n);
void input(vector <stud> &studentai,int change);
void swap(struct stud* i, struct stud* j);
void sort(vector <stud> &studentai);
bool is_number(const std::string  &s);
void count(vector <stud> &studentai);
void count2(vector <stud> &studentai);

#endif
