#include "my_f.h"

int m=0; //studentu skaicius
int mokiniuskaicius;
int const ndskaicius=5;
string fn;
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
  int egz;
  double vid;
  double median;

};
void generate()
{ 
cout<<"iveskite failo pavadinima(.txt)"<<endl;
cin>>fn;
ofstream off (fn);
off<<"ivedimas"<<endl;
cout<<"Iveskite kiek norite sugeneruoti random studentu"<<endl;
int mokiniusk;
cin>>mokiniusk;
cout<<endl;
string vardas="vardas";
string pavarde="pavarde";
int sk[ndskaicius];
int egz;
 srand(time(NULL));
 for(int i=0;i<mokiniusk;i++){
   off<<vardas<<i<<"  "<<pavarde<<i<<"  ";
   for(int j=0;j<ndskaicius;j++)
   {
   
    sk[j]=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
    off<<sk[j]<<"  ";
   }
    egz=std::round(1 + ( double ) rand ()/ RAND_MAX * (10 - 1));
    off<<egz<<endl;
 }
 off.close();
 }
void swap(struct stud* i, struct stud* j)
{
    stud t;
     t = *i;
    *i = *j;
    *j = t;

}
void sort(vector <stud> &studentai)
{
		int i=0;
		bool swapped=true;
		while(swapped)
		{    
                        i++;
			swapped = false;
			for (int j = 0; j < m-i; j++) 
			{
				if(studentai[j].vardas > studentai[j+1].vardas)
				{
					swap(&studentai[j],&studentai[j+1]);
					swapped = true;
				}
				if(studentai[j].vardas == studentai[j+1].vardas)
				{
					if(studentai[j].pavarde > studentai[j+1].pavarde)
					{
						swap(&studentai[j],&studentai[j+1]);
						swapped = true;
					}
				}

			}

		}
}
void print(vector <stud> &studentai) {
  ofstream out ("rezultatai.txt");
  for (int i = 0; i < m; i++) {
    out << studentai[i].vardas<<"   ";//setw neveikia?
    out << studentai[i].pavarde <<"   ";//setw neveikia?
  
          out <<std::fixed<<std::setprecision(2)<<studentai[i].vid<<"   ";
      
          out <<std::fixed<<std::setprecision(2)<<studentai[i].median<<endl;
    }
    out.close();
  }

bool is_number(const std::string & s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit( * it)) ++it;
  return !s.empty() && it == s.end();
}
void count(vector <stud> &studentai) {
  double sum = 0, k=0,vid=0;;
  for (int i = 0; i <studentai[m].kiekis;i++) {
    sum += studentai[m].nd[i];
  }
    studentai[m].vid=(sum / studentai[m].kiekis)*0.4 + studentai[m].egz*0.6;

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
  



void input(vector <stud> &studentai){
ifstream in (fn);
in.ignore(256,'\n');
int p;

while(!in.eof()){
studentai.push_back(stud());
in>>studentai[m].vardas>>std::ws>>studentai[m].pavarde;
for(int i=0;i<ndskaicius;i++){
in>>p;
studentai[m].nd.push_back(p);
}
in>>studentai[m].egz;
studentai[m].kiekis=ndskaicius;
in.ignore(0,'\n');
count(studentai);
count2(studentai);
m++;
}
cout<<"***********************************"<<endl;
m=m-2;

}


  void inputas(vector <stud> &studentai)
{ 
  int const N=5;
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
       string sal;
       cout<<"Ar norite ivesti atliktu namu darbu skaiciu,ar norit naudoti default reiksme? y - ivesti"<<endl;
       cin>>sal;
       cout<<endl;
       if(sal=="y")
       {
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

       }
       else{
         studentai[m].kiekis=ndskaicius;
       }
 
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
    sort(studentai);
    print(studentai);
    break;
    }
}
  }





int main(int argc, char * argv[]) {
  vector <stud> studentai;
  generate();
  string salyga;
  cout<<"Ar norite ivesti duomenis is failo? Jei norite: irasykite - y, jei ne irasykite betkuria raide-zodi"<<endl;
  cin>>salyga;
  if(salyga=="y"){
  input(studentai);
  }
  cout<<endl;


inputas(studentai);
  
  return 0;
}