#include "functions.h"

bool compare_m (stud &a, stud &b){
  return a.vid<b.vid;
 
};
bool compare_v (stud &a, stud &b){
  return a.vardas<b.vardas;
 
};
int m = 0; //studentu skaicius
int const ndskaicius = 5; // default nd darbu skaiciaus 
void generate(int change) {
  auto name = std::to_string(change);
  string fn="kursiokai" + name + ".txt";
  ofstream off(fn);
  off << "ivedimas" << endl;
  string vardas = "vardas";
  string pavarde = "pavarde";
  int sk[ndskaicius];
  int egz;
  srand(time(NULL));
  for (int i = 0; i < change; i++) {
    off << vardas << i << "  " << pavarde << i << "  "; // Issue #2 Vardai ir pavardes kartais kartojasi. -- SOLVED
    for (int j = 0; j < ndskaicius; j++) {

      sk[j] = std::round(1 + (double) rand() / RAND_MAX * (10 - 1));
      off << sk[j] << "  ";
    } // Issue #3 Retai generuoja reiksmes daugiau nei 9 ir maziau nei 3
    egz = std::round(1 + (double) rand() / RAND_MAX * (10 - 1));
    off << egz << endl;
  }
  off.close();
  
}
// void swap(struct stud * i, struct stud * j) {
//   stud t;
//   t = * i;
//   * i = * j;
//   * j = t;

// }
// void sort(vector < stud > & studentai, int m) {
//   int i = 0;
//   bool swapped = true;
//   while (swapped) {
//     i++;
//     swapped = false;
//     for (int j = 0; j < m - i; j++) {
//       if (studentai[j].vid < studentai[j + 1].vid) {
//         swap( & studentai[j], & studentai[j + 1]);
//         swapped = true;
//       }
//       if (studentai[j].vid == studentai[j + 1].vid) {
//         if (studentai[j].median < studentai[j + 1].median) {
//           swap( & studentai[j], & studentai[j + 1]);
//           swapped = true;
//         }
//       }

//     }

//   }
// }

void sortinti(vector < stud > & studentai,vector < stud > & g, vector < stud > & n)
{
 std::sort(studentai.begin(),studentai.end(),compare_m);
 int it;
 for(int i = 0; i <studentai.size(); i++)
  {
    if(studentai[i].vid>=5)
    {
      it=i;
      break;
    }
   
  }
g.resize(it);
g.assign();
 }
 
void print(vector < stud > & studentai,vector < stud > & g, vector < stud > & n) {
  // auto name = std::to_string(change);
  ofstream Aout("geriukai.txt",std::ios::app);
  ofstream Bout("nenaudeliai.txt",std::ios::app);

  for (int i = 0; i < m; i++) { // Issue #4 Nesilygiuoja tekstas, neveikia std::setw

      
      Aout << studentai[i].vardas <<std::left<<std::setw(ndskaicius-1)<<"  "; // setw neveikia?
      Aout << studentai[i].pavarde <<std::left<<std::setw(ndskaicius-1)<<"  "; // setw neveikia?
      Aout << std::fixed << std::setprecision(2) << studentai[i].vid <<std::setw(ndskaicius-1)<<"  ";

       Aout << std::fixed << std::setprecision(2) << studentai[i].median << endl;
    } 
    // for (int i = 0; i < m; i++) {
    //   Bout << studentai[i].vardas <<std::setw(ndskaicius-1); // setw neveikia?
    //   Bout << studentai[i].pavarde <<std::setw(ndskaicius-1); // setw neveikia?

    //   Bout << std::fixed << std::setprecision(2) << studentai[i].vid <<std::setw(ndskaicius-1)<<"  ";

    //   Bout << std::fixed << std::setprecision(2) << studentai[i].median << endl;
    // }
    studentai.clear();
    m=0;

  }

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector < stud > & studentai) {
  double sum = 0, k = 0, vid = 0;;
  for (int i = 0; i < studentai[m].kiekis; i++) {
    sum += studentai[m].nd[i];
  }
  studentai[m].vid = (sum / studentai[m].kiekis) * 0.4 + studentai[m].egz * 0.6;
}
void count2(vector < stud > & studentai) {
  std::sort(studentai[m].nd.begin(), studentai[m].nd.end());
  if (studentai[m].kiekis % 2 == 0) {
    studentai[m].median = (studentai[m].nd[studentai[m].kiekis / 2 - 1] + studentai[m].nd[studentai[m].kiekis / 2]) / 2;
  } else {
    studentai[m].median = (studentai[m].nd[studentai[m].kiekis / 2]);
  }
}
void input(vector < stud > & studentai, int change) {
  auto name = std::to_string(change);
  ifstream in ("kursiokai" + name + ".txt"); in .ignore(256, '\n');
  int p;
  while (! in .eof()) {
    studentai.push_back(stud()); in >> studentai[m].vardas >> std::ws >> studentai[m].pavarde;
    for (int i = 0; i < ndskaicius; i++) { in >> p;
      studentai[m].nd.push_back(p);
    } in >> studentai[m].egz;
    studentai[m].kiekis = ndskaicius; in .ignore(0, '\n');
    count(studentai);
    count2(studentai);
    m++;
  }
  m=m-1;// Issue #1 - blogai ivedant duomenis is failo nuskaitomas eiluciu/teksto skaicius, pridedamos 1-2 neegzituojancios eilutes, klaida naudojant eof()?
}
void inputas(vector < stud > & studentai) {
  string klaida = "Iveskite ne skaicius";
  string klaida2 = "Iveskite  (neneigiama)skaiciu";
  string klaida3 = "Iveskite  skaiciu tarp 1 ir 10";
  string klaida4 = "Iveskite reikiama skaiciu";
  int
  const N = 5;
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
      studentai[m].vardas = v;
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
      studentai[m].pavarde = p;
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
        studentai[m].kiekis = testsk;

      } else {
        studentai[m].kiekis = ndskaicius;
      }
      cout << endl;
      int pasirinkimas = 0;
      checkpoint4: //pridetas check point jei varde ar pavardeje yra skaiciu
        cout << endl;
      cout << "Įveskite jei norite vid - 1, jei medianos - 2" << endl;
      cin >> pasirinkimas;

      //  try {
      //   if ((pasirinkimas!=1)||(pasirinkimas!=2))
      //     throw klaida4;

      // } catch (string klaida4) {
      //   cout << klaida4 << endl;
      //   goto checkpoint4;
      // }
      studentai[m].selection = pasirinkimas;
      //////////////////////////////////////////////////////////////////////////////////////////////
      int sk;
      for (int i = 0; i < studentai[m].kiekis; i++) {
        srand(time(NULL));
        sk = std::round(1 + (double) rand() / RAND_MAX * (10 - 1));
        studentai[m].nd.push_back(sk);
      }
      //////////////////////////////////////////////////////////////////////////////////////////////
      int sk2;
      srand(time(NULL));
      sk2 = std::round(1 + (double) rand() / RAND_MAX * (10 - 1));
      studentai[m].egz = sk2;
      count(studentai);
      count2(studentai);
      m++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    else {
      break;
    }
  }
}