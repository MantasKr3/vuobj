#include "my_f.h"
int n; // namu darbu skaicius
int m=0; //studentu skaicius
string klaida = "Iveskite ne skaicius";
string klaida2 = "Iveskite  (neneigiama)skaiciu";
string klaida3 = "Iveskite  skaiciu tarp 1 ir 10";
string klaida4 = "Iveskite reikiama skaiciu";
struct stud {
  string vardas;
  string pavarde;
  int selection;
  vector <int> nd;
  int kiekis;
  double egz;
  double vid;
  double median;

};

void print(vector <stud> &studentai) {
  for (int i = 0; i < m; i++) {
    cout << studentai[i].vardas<<std::setw(5);//setw neveikia?
    cout << studentai[i].pavarde <<std::setw(5);//setw neveikia?
    if(studentai[i].selection==1){
          cout <<std::setprecision(3)<<studentai[i].vid;
          cout <<std::setw(5)<<"-"<<endl;
    }
    else{
          cout <<std::setw(5)<<"-";
          cout <<std::setprecision(3)<<studentai[i].median<<endl;;
    }
  }
}

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector <stud> &studentai) {
  double sum = 0, intr = 0;
  for (int i = 0; i <studentai[m].kiekis;i++) {
    sum += studentai[m].nd[i];
      intr = (sum / studentai[m].kiekis) * 0.4 + studentai[m].egz * 0.6;
      studentai[m].vid=intr;
  }

}
void count2(vector <stud> &studentai)
{
std::sort(studentai[m].nd.begin(),studentai[m].nd.end());
if ( studentai[m].kiekis % 2 == 0)
    {
      studentai[m].median=(studentai[m].nd[studentai[m].kiekis / 2 - 1] + studentai[m].nd[studentai[m].kiekis / 2]) / 2;
    }
    else 
    {
       studentai[m].median=(studentai[m].nd[studentai[m].kiekis / 2]);
    }
  }
  




  void inputas(vector <stud> &studentai)
{
  string salyga = "y";
  string v,p;
  //////////////////////////////////////////////////////////////////////////////////////////////
  while (salyga == "y") {
    cout << "Ar norite ivesti studento duomenis? Jei norite: irasykite - y, jei ne irasykite betkuria raide-zodi" << endl;
    cin >> salyga;
    cout << endl;
  //////////////////////////////////////////////////////////////////////////////////////////////
    if (salyga == "y") {
      studentai.push_back(stud());
      checkpoint: //pridetas check point jei varde ar pavardeje yra skaiciu
        cout << endl;
      cout << "Iveskite varda" << endl;
      cin >> v;
      try {
        if (is_number(v)==true)
          throw klaida;

      } catch (string klaida) {
        cout << klaida << endl;
        goto checkpoint;
      }
      studentai[m].vardas=v;
      checkpoint4: //pridetas check point jei varde ar pavardeje yra skaiciu
      cout << "Iveskite pavarde" << endl;
      cin >> p;
      try {
        if (is_number(p)==true)
          throw klaida;

      } catch (string klaida) {
        cout << klaida << endl;
        goto checkpoint4;
      }
       studentai[m].pavarde=p;
  cout << "Iveskite studento atliktu namu darbu skaiciu" << endl;
  checkpoint5:
  string ndsk;
  cin >> ndsk;
 try {
        if (is_number(ndsk) == false)
          throw klaida2;

      } catch (string klaida2) {
        cout << klaida2 << endl;
        goto checkpoint5;
      }
        int testsk=std::stoi(ndsk);

       try {
        if (testsk<=0)
          throw klaida4;

      } catch (string klaida4) {
        cout << klaida2 << endl;
        goto checkpoint5;
      }
      studentai[m].kiekis=testsk;
  cout << endl;
    int pasirinkimas=0;
  checkpoint6: //pridetas check point jei varde ar pavardeje yra skaiciu
        cout << endl;
      cout << "Iveskite jei norite vid- 1, jei medianos- 2" << endl;
      cin>>pasirinkimas;
 
      //  try {
      //   if ((pasirinkimas!=1)||(pasirinkimas!=2))
      //     throw klaida4;

      // } catch (string klaida4) {
      //   cout << klaida4 << endl;
      //   goto checkpoint6;
      // }
     studentai[m].selection=pasirinkimas;
    
   //////////////////////////////////////////////////////////////////////////////////////////////
      int sk;
      for (int i = 0; i<studentai[m].kiekis; i++) {
    srand(time(NULL));
    sk=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
    studentai[m].nd.push_back(sk);
    
      }
    //////////////////////////////////////////////////////////////////////////////////////////////
    int sk2;
    srand(time(NULL));
    sk2=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
      studentai[m].egz=sk2;
    count(studentai);
    count2(studentai);
      m++;
     }
   //////////////////////////////////////////////////////////////////////////////////////////////
    else {
    print(studentai);
    break;
    }
}
  }





int main(int argc, char * argv[]) {
  vector <stud> studentai;
  inputas(studentai);
  
  return 0;
}