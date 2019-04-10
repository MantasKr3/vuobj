#include "lfunctions.h"
#include "lapdorojimas.h"

int main() {

  auto startas = std::chrono::high_resolution_clock::now(); 
  list <stud> studentai;
  list <stud> g;
  list <stud> n;
  int sk=10; // Pradinė reikšmė
  int sksum=0;
  string optionas;


  for(int i=0;i<5;i++){
  cout<<endl;
  cout<<"Vykdyti skiaciavima su "<<sk<< " studentu ? y - taip, bet kuris kitas mygtukas,zodis - ne"<<endl;
  cin>>optionas;
  cout<<endl;
  if(optionas=="y"){

  auto start = std::chrono::high_resolution_clock::now();

  generate(sk);
  input(studentai,sk);
skirstymas2(studentai,n,g);
  print(studentai,n);

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end-start; 
std::cout << "[STRATEGIJA 2] LIST Generavimo ir skaičiavimo įvykdimas su "<<sk<<" studentų užtruko: "<<endl;
cout<< diff.count() << " s\n";

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
  string salyga;
  cout<<"Ar norite įvesti duomenis > Jei norite: įrašykite - y, jei ne įrašykite betkurią raidę-žodį"<<endl;
  cin>>salyga;
  if(salyga=="y"){
  inputas(studentai);
  }

    auto endas = std::chrono::high_resolution_clock::now();
    cout<<endl;
    return 0;
}