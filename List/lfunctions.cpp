#include "lfunctions.h"

bool compare_m(stud & a, stud & b) {
   return a.vid < b.vid;

};

bool gavoSkola(const stud & s) {
   return s.vid < 5.0;
}

bool is_number(const std::string & s) {
   std::string::const_iterator it = s.begin();
   while (it != s.end() && std::isdigit( * it)) ++it;
   return !s.empty() && it == s.end();
}

int m = 0; //studentu skaicius
int
const ndskaicius = 5; // default nd darbu skaiciaus 
int ilgv = 0;
int ilgp = 0;

void generate(int change) {
   auto name = std::to_string(change);
   string fn = "kursiokai" + name + ".txt";
   ofstream off(fn);
   //off << "ivedimas" << endl;
   string vardas = "vardas";
   string pavarde = "pavarde";
   int sk[ndskaicius];
   int egz;
   std::random_device rd;
   std::mt19937 generuoti(rd());
   std::uniform_int_distribution < int > random(1, 10);
   for (int i = 0; i < change; i++) {
      off << vardas << i << "  " << pavarde << i << "  "; // Issue #2 Vardai ir pavardes kartais kartojasi. -- SOLVED
      for (int j = 0; j < ndskaicius; j++) {

         sk[j] = random(generuoti);
         off << sk[j] << "  ";
      } // Issue #3 Retai generuoja reiksmes daugiau nei 9 ir maziau nei 3
      egz = random(generuoti);
      off << egz << endl;
   }
   off.close();
}

void skirstymas(std::list < stud > & studentai, std::list < stud > & n, std::list < stud > & g) {
    vector<stud> studn(studentai.begin(),studentai.end());

   sort(studn.begin(), studn.end(), compare_m);

   vector < stud > ::iterator ptr = studn.begin();
   for (vector < stud > ::iterator it = studn.begin(); it != studn.end(); it++) {
      if (( * it).vid >= 5) {
         ptr = it;

         break;
      }

   }
   n.resize(ptr - studn.begin());
   n.assign(studn.begin(), ptr);
   g.resize(studn.end() - ptr);
   g.assign(ptr, studn.end());
   studentai.assign(studn.begin(),studn.end());


}
// void skirstymas2(std::list < stud > & studentai, std::list < stud > & n, std::list < stud > & g) {
//    sort(studentai.begin(), studentai.end(), compare_m);
//    vector<stud> studn(studentai.begin(),studentai.end());


//    vector < stud > ::iterator ptr = studn.begin();
//    for (vector < stud > ::iterator it = studn.begin(); it != studn.end(); it++) {
//       if (( * it).vid >= 5) {
//          ptr = it;

//          break;
//       }

//    }
//    n.resize(ptr - studn.begin());
//    n.assign(studn.begin(), ptr);
//    studentai.resize(studn.end() - ptr);
//    studentai.assign(ptr, studn.end());

// }

void print(list < stud > & g, list < stud > & n) {
   ofstream Aout("geriukai.txt");
   ofstream Bout("nenaudeliai.txt");
   for (auto & i: g) {
      Aout << i.vardas << std::left << std::setw(ilgv + 4) << "  "; // setw neveikia?
      Aout << i.pavarde << std::left << std::setw(ilgp + 4) << "  "; // setw neveikia?
      Aout << std::fixed << std::setprecision(2) << i.vid << std::setw(ndskaicius - 1) << "  ";

      Aout << std::fixed << std::setprecision(2) << i.median << endl;

   }
   Aout.close();
   for (auto & i: n) {
      Bout << i.vardas << std::left << std::setw(ilgv + 4) << "  "; // setw neveikia?
      Bout << i.pavarde << std::left << std::setw(ilgp + 4) << "  "; // setw neveikia?
      Bout << std::fixed << std::setprecision(2) << i.vid << std::setw(ndskaicius - 1) << "  ";

      Bout << std::fixed << std::setprecision(2) << i.median << endl;

   }
   Bout.close();

}

void count(vector < stud > & studn) {
   double sum = 0, k = 0, vid = 0;;

   for (int i = 0; i < studn[m].kiekis; i++) {
      sum += studn[m].nd[i];
   }
   studn[m].vid = (sum / studn[m].kiekis) * 0.4 + studn[m].egz * 0.6;
}
void count2(vector < stud > & studn) {

   std::sort(studn[m].nd.begin(), studn[m].nd.end());

   if (studn[m].kiekis % 2 == 0) {
      studn[m].median = (studn[m].nd[studn[m].kiekis / 2 - 1] + studn[m].nd[studn[m].kiekis / 2]) / 2;
   } else {
      studn[m].median = (studn[m].nd[studn[m].kiekis / 2]);
   }
}
void input(list < stud > & studentai, int change) {
   auto name = std::to_string(change);
    vector<stud> studn(studentai.begin(),studentai.end());
   ifstream in ("kursiokai" + name + ".txt"); in .ignore(256, '\n');
   int p;
   while (! in .eof()) {
      studn.push_back(stud()); in >> studn[m].vardas >> std::ws >> studn[m].pavarde;
      if (studn[m].vardas.length() > ilgv) ilgv = studn[m].vardas.length();
      if (studn[m].pavarde.length() > ilgp) ilgp = studn[m].pavarde.length();
      for (int i = 0; i < ndskaicius; i++) {
         in >> p;
         studn[m].nd.push_back(p);
      }
       in >> studn[m].egz;
      studn[m].kiekis = ndskaicius;
      in .ignore(0, '\n');
      count(studn);
      count2(studn);
      m++;
   }
   m = 0;
   studentai.assign(studn.begin(),studn.end());

}

// vector<stud> rastin(std::vector<stud>& studentai) {
//         std::vector<stud>::iterator it =
//                 stable_partition(studentai.begin(), studentai.end(), gavoSkola);
//         std::vector<stud> minksti(it, studentai.end());
//         studentai.erase(it, studentai.end());
//         return minksti;
//     }

void inputas(list < stud > & studentai) {
   m = 0;
   studentai.clear();
   studentai.resize(0);
   ilgv = 0;
   ilgp = 0;
   string klaida = "Iveskite ne skaicius";
   string klaida2 = "Iveskite  (neneigiama)skaiciu";
   string klaida3 = "Iveskite  skaiciu tarp 1 ir 10";
   string klaida4 = "Iveskite reikiama skaiciu";
   int
   const N = 5;
   vector<stud> studn(studentai.begin(),studentai.end());
   string salyga = "y";
   string v, p;
   cout << endl;
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
            if (is_number(v) == true)
               throw klaida;

         } catch (string klaida) {
            cout << klaida << endl;
            goto checkpoint;
         }
         studn[m].vardas = v;
         if (studn[m].vardas.length() > ilgv) ilgv = studn[m].vardas.length();
         checkpoint2: //pridetas check point jei varde ar pavardeje yra skaiciu
            cout << "Iveskite pavarde" << endl;
         cin >> p;
         try {
            if (is_number(p) == true)
               throw klaida;

         } catch (string klaida) {
            cout << klaida << endl;
            goto checkpoint2;
         }
         studn[m].pavarde = p;
         if (studn[m].pavarde.length() > ilgp) ilgp = studn[m].pavarde.length();
         string sal;
         cout << "Ar norite ivesti atliktu namu darbu skaiciu,ar norit naudoti default reiksme? y - ivesti" << endl;
         cin >> sal;
         cout << endl;
         if (sal == "y") {
            cout << "Iveskite studento atliktu namu darbu skaiciu" << endl;
            checkpoint3:
               string ndsk;
            cin >> ndsk;
            try {
               if (is_number(ndsk) == false)
                  throw klaida2;

            } catch (string klaida2) {
               cout << klaida2 << endl;

               goto checkpoint3;
            }
            int testsk = std::stoi(ndsk);

            try {
               if (testsk <= 0)
                  throw klaida4;

            } catch (string klaida4) {
               cout << klaida2 << endl;
               goto checkpoint3;
            }
            studn[m].kiekis = testsk;

         } else {
            studn[m].kiekis = ndskaicius;
         }
         cout << endl;
         int pasirinkimas = 0;
         checkpoint4: //pridetas check point jei varde ar pavardeje yra skaiciu
            cout << endl;
         cout << "Įveskite jei norite vid - 1, jei medianos - 2" << endl;
         cin >> pasirinkimas;

         try {
            if (pasirinkimas != 1 || pasirinkimas != 2)
               throw klaida4;

         } catch (string klaida4) {
            cout << klaida4 << endl;
            goto checkpoint4;
         }
         studn[m].selection = pasirinkimas;
         //////////////////////////////////////////////////////////////////////////////////////////////
         int sk;
         std::random_device rd;
         std::mt19937 generuoti(rd());
         std::uniform_int_distribution < int > random(1, 10);
         for (int i = 0; i < studn[m].kiekis; i++) {
            sk = random(generuoti);
            studn[m].nd.push_back(sk);
         }
         //////////////////////////////////////////////////////////////////////////////////////////////
         int sk2;
         sk2 = random(generuoti);
         studn[m].egz = sk2;
         count(studn);
         count2(studn);
         m++;
      }
      //////////////////////////////////////////////////////////////////////////////////////////////
      else {
         for (int i = 0; i < m; i++) {
            cout << "Vardas" << std::setw(ilgv) << "Pavarde" << std::setw(ilgp) << "Rezultatai";
            cout << studn[i].vardas << std::setw(ilgv+5);
            cout << studn[i].pavarde << std::setw(ilgp+5);
            if (studn[i].selection == 1) {
               cout << studn[i].vid << endl;
            }
            if (studn[i].selection == 2) {
               cout << studn[i].median << endl;
            }

         }
         break;
      }
   }
}