#include <iostream>
#include <string>
#include <vector>
#include"polynoms.h"
#include"func_for_main.h"
using namespace std;


//основная программа
int main(){

   //строка сообщает о синтаксической ошибке
string serror="Syntax error. Data entered incorrectly.\n";
int Nom;//номер полинома в векторе
//строка для ввода команды
string s;

string res_of_op="";//имя результата
string opr_lef="";//имя левого операнда
string opr_rig="";//имя правого операнда
//вектор, хранящий полиномы для работы
vector <polynom> store;
store.clear();

//начало работы программы
while (true){

getline(cin,s);//ввод команды

vector <string> words=split_list(s);//вектор из слов

int n_o_w=words.size();//количество слов в команде
 //(number of words)- расшифровка

if ((n_o_w==0) || (n_o_w>4)){//проверка на количество слов
    cout<<serror;//от 1 до 4
    }

 //======если введена команда exit
if (n_o_w==1){
    if (words[0]=="exit"){
        //очистка вектора полиномов
        //перед выходом из программы
         store.clear();
         break;
        }
    else {
      cout<<serror;
    }
}

//=====проверка на печать полинома
if (n_o_w==2){
    if (words[0]=="print"){
        if (name_cont(words[1])){
            Nom=search_poly(words[1],store);
            if (Nom!=-1){ cout<<store[Nom];}
          //если полином есть в векторе то печать иначе сообщение
          //что его нет в векторе
            else{ cout<<"Polynom "<<words[1]<<" is not declared.\n";}
            }//сообщение о неправильном вводе имени
         else{ cout<<"Name of the polylom entered incorrectly.\n";}
        }
    //проверка на ввод нового полинома
    if (words[0]=="init"){
        if (name_cont(words[1])){
             Nom=search_poly(words[1],store);
             getline(cin,s);
             vector <long long int> st_coeff=make_coeff(s);
             if ( st_coeff.empty() ){
                cout<<"Coefficents entered incorrectly.\n";
             }
             else{
             if (Nom == -1){ store.push_back(make_poly(words[1],st_coeff));}
             else { store[Nom]=make_poly(words[1],st_coeff);}
             }
        }
         else{ cout<<"Name of the polylom entered incorrectly.\n";}
    }
    if ((words[0]!="init") && (words[0]!="print")){
      cout<<serror;
    }

}

//=====проверка на взятие первой производной
if (n_o_w==3){


    if (words[0]=="differ"){
       if (name_cont(words[1]) && name_cont(words[2])){
            int Nom2;
             Nom2=search_poly(words[2],store);
            if (Nom2!=-1){
                Nom=search_poly(words[1],store);
                if (Nom!=-1){
                    store[Nom]=derivat(store[Nom2],1);
                }
                else{ store.push_back(derivat(store[Nom2],1)); store[store.size()-1].set(words[1]);}
            }
           else{ cout<<"Polynom "<<words[2]<<" is not declared.\n";}
       }
        else{ cout<<"Name of the polylom entered incorrectly.\n";}
    }
    else{
      cout<<serror;
    }
}
}
return 0;}



