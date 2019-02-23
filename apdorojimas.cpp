#include "functions.h"
#include <chrono>

int main(int argc, char * argv[]) {
  auto start = std::chrono::high_resolution_clock::now();  

  vector <stud> studentai;
  int sk=10;
  for(int i=0;i<5;i++){
  generate(sk);
  input(studentai,sk);
  //sort(studentai);
  print(studentai,sk);
  sk=sk*10;
  }

  //Išjungta galimybė įvesti duomenis iš failo,kad nesimaišytų generavimui

  // string salyga;
  // cout<<"Ar norite įvesti duomenis iš failo? Jei norite: įrašykite - y, jei ne įrašykite betkurią raidę-žodį"<<endl;
  // cin>>salyga;
  // if(salyga=="y"){
  // input(studentai);
  // }
  cout<<endl;
//Išjungta galimybė įvesti,kad nesimaišytų generavimui

//inputas(studentai);
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout << "Generavimo ir skaičiavimo įvykdimas užtruko: "<< diff.count() << " s\n";
  return 0;
}