#include "my_f.h"
int n; // namu darbu skaicius
int m=0; //studentu skaicius
string klaida = "Iveskite ne skaicius";
string klaida2 = "Iveskite  (neneigiama)skaiciu";
string klaida3 = "Iveskite  skaiciu tarp 1 ir 10";
string klaida4 = "Iveskite reikiama skaiciu";


void print(vector < string > vardas, vector < string > pavarde,vector < double > galutinis,vector <int> zmogus,vector <double> median) {
  for (int i = 0; i < m; i++) {
    cout << vardas[i]<<"  ";//setw neveikia?
    cout << pavarde[i] <<"  ";//setw neveikia?
    if(zmogus[i]==1){
          cout <<std::setprecision(3)<<galutinis[i];
          cout << "  "<<"-"<<endl;
    }
    else{
          cout << "  "<<"-";
          cout <<std::setprecision(3)<<median[i]<<endl;;
    }
  }
}

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector < int > &nd, vector < int > &egz, vector < double > &galutinis,vector <int> &zmogus) {
  double check = 0, sum = 0, intr = 0;
  for (int i = 0; i <n;i++) {
    sum += nd[i];
      intr = (sum / n) * 0.4 + egz[m] * 0.6;
      galutinis.push_back(intr);
  }

}
void count2(vector < int > &nd, vector < int > &egz,vector <int> &zmogus,  vector <double> &median)
{
std::sort(nd.begin(),nd.end());
if ( n % 2 == 0)
    {
      median.push_back((nd[n / 2 - 1] + nd[n / 2]) / 2);
    }
    else 
    {
      return median.push_back(nd[n / 2]);
    }
  }
  

void input(vector <string> &vardas, vector <string> &pavarde,vector < int > &nd,vector < int > &egz,vector < double > &galutinis, vector <int> &zmogus,vector <double> &median )
{
  string salyga = "y";
  string v;
  string p;
  int pasirinkimas;
  //////////////////////////////////////////////////////////////////////////////////////////////
  while (salyga == "y") {
    cout << "Ar norite ivesti studento duomenis? Jei norite: irasykite - y, jei ne irasykite betkuria raide-zodi" << endl;
    cin >> salyga;
    cout << endl;
  //////////////////////////////////////////////////////////////////////////////////////////////
    if (salyga == "y") {
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
      vardas.push_back(v);
      pavarde.push_back(p);
        cout << "Iveskite studento atliktu namu darbu skaiciu - n" << endl;
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
      n=std::stoi(ndsk);
  cout << endl;
  string pas;
  checkpoint6: //pridetas check point jei varde ar pavardeje yra skaiciu
        cout << endl;
      cout << "Iveskite jei norite vid- 1, jei medianos- 2" << endl;
      cin >> pas;
//        try {
//         if (is_number(pas) == true)
//           throw klaida2;

//       } catch (string klaida2) {
//         cout << klaida2 << endl;
//         goto checkpoint6;
//       }
pasirinkimas=std::stoi(pas);

//        try {
//         if ((pasirinkimas!=1)||(pasirinkimas!=2))
//           throw klaida4;

//       } 
//       catch (string klaida4) {
//         cout << klaida4 << endl;
//         goto checkpoint6;
//       }
      zmogus.push_back(pasirinkimas);
      m++;
   //////////////////////////////////////////////////////////////////////////////////////////////
 
      int test;
      int sk;
      for (int i = 0; i < n; i++) {
    srand(time(NULL));
    sk=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
    nd.push_back(sk);
      }
    //////////////////////////////////////////////////////////////////////////////////////////////
    int sk2;
    srand(time(NULL));
    sk2=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
      egz.push_back(sk2);
    count(nd,egz,galutinis,zmogus);
    count2(nd,egz,zmogus,median);
    nd.clear();
    egz.clear();

     }
   //////////////////////////////////////////////////////////////////////////////////////////////
    else {
    print(vardas, pavarde,galutinis,zmogus,median);
    break;
    }
}
  }



int main(int argc, char * argv[]) {
  vector < double > galutinis;
  vector <double> median;
  vector < int > nd;
  vector < int > egz;
  vector <int> zmogus;
  vector <string> vardas;
  vector <string> pavarde;
  input(vardas,pavarde,nd,egz,galutinis,zmogus,median);
  return 0;
}