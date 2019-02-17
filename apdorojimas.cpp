#include <iostream> 
#include <string> 
#include <cassert> 
#include <iomanip> 
#include <vector> 
#include "my_f.h"
int n; // namu darbu skaicius
int m=0; //studentu skaicius
string klaida = "Iveskite ne skaicius";
string klaida2 = "Iveskite  (neneigiama)skaiciu";
string klaida3 = "Iveskite  skaiciu tarp 1 ir 10";
string klaida4 = "Iveskite neneigiama ir nelygu 0 skaiciu";


void print(vector < string > vardas, vector < string > pavarde,vector < double > galutinis) {
  for (int i = 0; i < m; i++) {
    cout << vardas[i]<<"  ";//setw neveikia?
    cout << pavarde[i] <<"  ";//setw neveikia?
    cout <<galutinis[i]<<endl;
  }
}

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector < int > &nd, vector < int > &egz, vector < double > &galutinis) {
  double check = 0, stdsk = 0, sum = 0, intr = 0;
  for (int i = 0; i < nd.size();i++) {
    check++;
    sum += nd[i];
    if (check == n) {
      check = 0;
      intr = (sum / n) * 0.4 + egz[stdsk] * 0.6;
      sum = 0;
      stdsk++;
      galutinis.push_back(intr);
      intr = 0;
    }

  }

}
void input(vector <string> &vardas, vector <string> &pavarde,vector < int > &nd,vector < int > &egz,vector < double > &galutinis)
{

  cout << "Iveskite studentu atliktu namu darbu skaiciu - n" << endl;
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
  string salyga = "y";
  string v;
  string p;
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
      m++;
   //////////////////////////////////////////////////////////////////////////////////////////////
       cout << "Iveskite " << n << " namu darbu rezultatus" << endl;
      string skaicius;
      int test;
      int sk;
      for (int i = 0; i < n; i++) {
        checkpoint2: cout << " >> ";
        cin >> skaicius;
        try {
          if (is_number(skaicius) == false){
                throw klaida2;
          }
        } catch (string klaida2) {
          cout << klaida2 << endl;
          goto checkpoint2;
        }
              test=std::stoi(skaicius);

        try{
             if((test>10)||(test<=0)){
                throw klaida3;
            }
        }
        catch(string klaida3) {
           cout << klaida3 << endl;
          goto checkpoint2;
        }
        sk = std::stoi(skaicius);
        nd.push_back(sk);
      }
    //////////////////////////////////////////////////////////////////////////////////////////////
      string egzas;
      int test2;
      int sk2;   
      cout << "Iveskite " << v << " " << p << " egzamino rezultata " << endl;
       checkpoint3: 
      cin >> egzas;
      try {
        if (is_number(egzas) == false)
          throw klaida2;
        
      }
      catch (string klaida2) {
        cout << klaida2 << endl;
        goto checkpoint3;
      }
            test2=std::stoi(egzas);

      try {
         if((test2>10)||(test2<=0)){
                throw klaida3;
            }
      }
       catch (string klaida3) {
        cout << klaida3<< endl;
        goto checkpoint3;
      }
      sk2=std::stoi(egzas);
      egz.push_back(sk2);

     }
   //////////////////////////////////////////////////////////////////////////////////////////////
    else {
    count(nd,egz,galutinis);
    print(vardas, pavarde,galutinis);
    break;
    }
}
  }



int main(int argc, char * argv[]) {
  vector < double > galutinis;
  vector < int > nd;
  vector < int > egz;
  vector <string> vardas;
  vector <string> pavarde;
  input(vardas,pavarde,nd,egz,galutinis);
  return 0;
}