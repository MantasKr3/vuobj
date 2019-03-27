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
  string optionas;

  for(int i=0;i<5;i++){

  cout<<"Vykdyti skiaciavima su "<<sk<< " studentu ? y/n"<<endl;
  cin>>optionas;
  cout<<endl;
  if(optionas=="y"){

  auto start = std::chrono::high_resolution_clock::now();

  generate(sk);
  input(studentai,sk);
skirstymas(studentai,n,g,sk);
  print(g,n);

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout << "Generavimo ir skaičiavimo įvykdimas su "<<sk<<" studentų užtruko: "<< diff.count() << " s\n";

  sk=sk*10;

  studentai.clear();
  g.clear();
  n.clear();

  }
  else {
    break;
  }
 
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
    //cout << "Programos įvykdimas užtruko: "<< diffas.count() << " s\n";
    cout<<endl;
    return 0;
}