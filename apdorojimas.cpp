#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <vector>
#include "my_f.h"
int n;
string klaida ="Iveskite ne skaicius";
bool is_number(const std::string& s){
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}
void input(vector<string> vardas,vector<string> pavarde,vector<int> nd,int N[]){

cout<<"Iveskite studentu atliktu namu darbu skaiciu - n"<<endl;
cin>>n;
cout<<endl;
string salyga="taip";
string v;
string p;
while(salyga=="taip"){
 cout<<"Ar norite ivesti studento duomenis? Jei norite: rasykite - taip, jei ne - ne "<< endl;
 cin>>salyga;
 cout<<endl;
    if(salyga=="taip") {
chechpoint:
cout<<endl;
cout<<"Iveskite varda"<<endl;
cin>>v;
try{
    if(is_number(v)==true)
    throw klaida;

}
catch(string klaida){
cout<<klaida<<endl;
goto chechpoint;
}
cout<<"Iveskite pavarde"<<endl;
cin>>p;
try{
    if(is_number(v)==true)
    throw klaida;

}
catch(string klaida){
cout<<klaida<<endl;
goto chechpoint;
}
vardas.push_back(v);
pavarde.push_back(p);
}
else{

}
}

}

int main()
{
int ND[n];
vector<int> nd (n);
vector<string> vardas;
vector<string> pavarde;
input(vardas,pavarde,nd,ND);
return 0;
}