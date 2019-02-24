#include "functions.h"
#include <chrono>

int main(int argc, char * argv[]) {
  

  vector <stud> studentai;
  int sk=10; // Pradinė reikšmė
  for(int i=0;i<5;i++){
  auto start = std::chrono::high_resolution_clock::now(); 
  generate(sk);
  input(studentai,sk);
  print(studentai,sk);
  auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout << "Generavimo ir skaičiavimo įvykdimas su "<<sk<<" studentų užtruko: "<< diff.count() << " s\n";
  sk=sk*10;
  }
    cout<<endl;
  //sort(studentai);
  //Išjungta galimybė įvesti duomenis iš failo,kad nesimaišytų generavimui
  // string salyga;
  // cout<<"Ar norite įvesti duomenis iš failo? Jei norite: įrašykite - y, jei ne įrašykite betkurią raidę-žodį"<<endl;
  // cin>>salyga;
  // if(salyga=="y"){
  // input(studentai);
  // }
  //Išjungta galimybė įvesti,kad nesimaišytų generavimui
  //inputas(studentai);
  return 0;
}