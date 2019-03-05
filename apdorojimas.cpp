#include "functions.h"
#include "apdorojimas.h"

int main() {
  auto startas = std::chrono::high_resolution_clock::now(); 
  vector <stud> studentai;
  vector <stud> g;
  vector <stud> n;


  cout<<endl;
  int sk=10; // Pradinė reikšmė
  int sksum=0;
  for(int i=0;i<5;i++){
  auto start = std::chrono::high_resolution_clock::now(); 
  generate(sk);
  input(studentai,sk);
  auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout << "Generavimo ir skaičiavimo įvykdimas su "<<sk<<" studentų užtruko: "<< diff.count() << " s\n";
  sortinti(studentai,g,n);
  print(studentai,g,n);
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
    auto endas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffas = endas-startas; 
    cout << "Programos įvykdimas užtruko: "<< diffas.count() << " s\n";
    cout<<endl;
    return 0;
}