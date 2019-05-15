#include <iostream>
#include <string>
#include <vector>
#include  <locale>
#include"func_for_main.h"
using namespace std;

//функция возвращает массив строк,
//содержащий слова команды
vector <string>  split_list( string st ){
    vector <string> ws;
    ws.clear();
    string w="";
    st=st+" ";
    int lenst=st.length();
     for (int i=0;i<lenst;i++){
        if (st[i]!=' '){
            w=w+st[i];
    }
        else {
          if (w!=""){ ws.push_back(w);}
             w="";
     }
    }
    return ws;
    }

//функция проверки парвильности названия полинома
bool name_cont(string st){
  //проверка первого символа
    if ( ((int)st[0]<65) || ((int)st[0]>90)){ return false; }
   //проверка числового индекса
    int lenst=st.length();
    if (lenst==1) {return true;}
    else {
        if (((int)st[1]<49) || ((int)st[1]>57)) { return false; }
        for (int i=2;i<lenst;i++){
            if ( ((int)st[i]<48) || ((int)st[i]>57)){return false;}
    }
    }
    return true;
    }

 //функция поиска полинома в списке по имени
 int search_poly (string nm,vector <polynom> &vp){
    int N=-1;
    int Np=vp.size();
    for (int i=0;i<Np;i++){

        if (getname(vp[i])==nm){
           N=i;
           break;
        }
    }
    return N;
    }
//===функция создания вектора коэффициентов для полинома
vector <long long int> make_coeff(string st){
    vector <long long int> numbs;
    numbs.clear();
    vector <string> ws=split_list(st);
    int lenst=ws.size();
    int number;
    for (int i=0;i<lenst;i++){
        number=0;


        bool neg;
        if (ws[i][0]=='-'){  neg=1; ws[i].erase (0,1); }
        else {  neg=0; }

        int dlnum=ws[i].length();

        if ( (dlnum==0) || (dlnum>3)){
                numbs.clear();
                cout<<"+++Coefficents entered incorrectly.\n";
                return numbs;
        }

        for (int k=0;k<dlnum;k++){
            if (isdigit(ws[i][k])==0) {
                numbs.clear();
                cout<<"Coefficents entered incorrectly.\n";
                return numbs;
            }
            else {
                number=number*10+(int)ws[i][k]-48;
            }
            }
        if   (number>100){
                numbs.clear();
                cout<<"Some coefficents more than 100.\n";
                return numbs;
        }
        if (neg){ number=-number; }
        numbs.push_back(number);


    }
    return numbs;
}

