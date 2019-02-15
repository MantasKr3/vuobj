#include < iostream > 
#include < string > 
#include < cassert > 
#include < iomanip > 
#include < vector > 
#include "my_f.h"
int n; // namu darbu skaicius
int m; //studentu skaicius
string klaida = "Iveskite ne skaicius";
string klaida2 = "Iveskite  skaiciu";
void print(vector < string > vardas, vector < string > pavarde, vector < int > galutinis) {
  for (int i = 0; i < m; i++) {
    cout << vardas[i] << std::setw(4) << pavarde[i] << std::setw(4) << galutinis[i] << endl;
  }
}

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector < int > nd, vector < int > egz, vector < int > galutinis) {
  int check = 0, stdsk = 0, sum = 0, intr = 0;
  for (int i = 0; i < nd.size(); ++i) {
    check++;
    sum += nd[i];
    if (check == n) {
      check = 0;
      intr = (sum / n) * 0.4 + egz[stdsk] * 0.6;
      m++;
      sum = 0;
      stdsk++;
      galutinis.push_back(intr);
      intr = 0;
    }

  }

}
void input(vector < string > vardas, vector < string > pavarde, vector < int > nd, vector < int > egz, vector < int > galutinis) {

  cout << "Iveskite studentu atliktu namu darbu skaiciu - n" << endl;
  cin >> n;
  cout << endl;
  string salyga = "taip";
  string v;
  string p;
  while (salyga == "taip") {
    cout << "Ar norite ivesti studento duomenis? Jei norite: irasykite - y, jei ne irasykite betkuria raide-zodi" << endl;
    cin >> salyga;
    cout << endl;
    if (salyga == "y") {
      checkpoint: //pridetas check point jei varde ar pavardeje yra skaiciu
        cout << endl;
      cout << "Iveskite varda" << endl;
      cin >> v;
      try {
        if (is_number(v) == true)
          throw klaida;

      } catch (string klaida) {
        cout << klaida << endl;
        goto checkpoint;
      }
      cout << "Iveskite pavarde" << endl;
      cin >> p;
      try {
        if (is_number(p) == true)
          throw klaida;

      } catch (string klaida) {
        cout << klaida << endl;
        goto checkpoint;
      }
      vardas.push_back(v);
      pavarde.push_back(p);
      m++;
      cout << "Iveskite " << n << " namu darbu rezultatus" << endl;
      string skaicius;
      int sk;
      for (int i = 0; i < n; i++) {
        checkpoint2: cout << " >> ";
        cin >> skaicius;
        try {
          if (is_number(skaicius) == false)
            throw klaida2;

        } catch (string klaida2) {
          cout << klaida2 << endl;
          goto checkpoint2;
        }
        sk = std::stoi(skaicius);
        nd.push_back(sk);
      }
      int egzas;
      cout << "Iveskite " << v << " " << p << " egzamino rezultata " << endl;
      cin >> egzas;
      checkpoint3: 
      try {
        if (is_number(skaicius) == false)
          throw klaida2;

      }
      catch (string klaida2) {
        cout << klaida2 << endl;
        goto checkpoint3;
        egz.push_back(egzas);
      }
    }

    else {}
    count(nd, egz, galutinis);
    print(vardas, pavarde, galutinis);
    break;
  }

}

int main(int argc, char * argv[]) {
  vector < int > galutinis;
  vector < int > nd(n);
  vector < int > egz;
  vector < string > vardas;
  vector < string > pavarde;
  input(vardas, pavarde, nd, egz, galutinis);
  return 0;
}