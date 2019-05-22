#include <iostream>
#include <string>
#include <vector>
#include"polynoms.h"
#include"func_for_main.h"
using namespace std;


//основная программа
int main(){

   //строка сообщает о синтаксической ошибке
string serror="Syntax error. Command entered incorrectly.\n";
int Nom;//номер полинома в векторе
int Nom2,Nom3;//номера полиномов - операндов в векторе
//строка для ввода команды
string s;


//вектор, хранящий полиномы для работы
vector <polynom> store;
store.clear();
vector <string> words;//вектор из слов
cout<<"Polynom calculator is ready for work. Enter necessary command.\n";
//начало работы программы
while (true){

getline(cin,s);//ввод команды

words=split_list(s);//формирование вектора из слов

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
         words.clear();
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
            else{
                if (words[1]=="all"){
                    Nom=store.size();
                    if (Nom!=0){
                        for (int i=0;i<Nom;i++){
                        cout<<store[i];
                        }}
                        else {cout<<"No polynoms were created.\n";}
                }
                else {cout<<"Name of the polylom entered incorrectly.\n";}
                }
            }

    //проверка на ввод нового полинома
    if (words[0]=="init"){
        if (name_cont(words[1])){
             Nom=search_poly(words[1],store);
             cout<<"Enter the coefficients separated by a space:\n";
             getline(cin,s);
             vector <long long int> st_coeff=make_coeff(s);

             if ( st_coeff.empty() ==0){


             if (Nom == -1){

                    polynom D;
                    D.mp(words[1], st_coeff);
                    store.push_back( D );

             }
             else {
                    polynom D;
                    D.mp(words[1], st_coeff);
                     store[Nom]=D;
             }
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

             Nom2=search_poly(words[2],store);
            if (Nom2!=-1){
                Nom=search_poly(words[1],store);
                if (Nom!=-1){
                    store[Nom]=derivat(store[Nom2],1);
                }
                else{ store.push_back(derivat(store[Nom2],1)); store[store.size()-1].setname(words[1]);}
            }
           else{ cout<<"Polynom "<<words[2]<<" is not declared.\n";}
       }
        else{ cout<<"Name of the polylom entered incorrectly.\n";}
    }
    else{
      cout<<serror;
    }
}

if (n_o_w==4){
    if (words[0]=="summ"){ //обработка суммы
        if (name_cont(words[1]) && name_cont(words[2]) && name_cont(words[3])){

                 Nom2=search_poly(words[2],store);
                 Nom3=search_poly(words[3],store);
                 if ( (Nom2!=-1) && (Nom3!=-1)){
                     Nom=search_poly(words[1],store);
                     if (Nom!=-1){
                        store[Nom]=store[Nom2]+store[Nom3];
                     }
                     else{ store.push_back(store[Nom2]+store[Nom3]); store[store.size()-1].setname(words[1]);}
                     }
                      else{ cout<<"Polynom "<<words[2]<<" or polynom "<<words[3] <<" is not declared.\n"; }
        }
        else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }

    if (words[0]=="substr"){ //обработка вычитания
        if (name_cont(words[1]) && name_cont(words[2]) && name_cont(words[3])){

                 Nom2=search_poly(words[2],store);
                 Nom3=search_poly(words[3],store);
                 if ( (Nom2!=-1) && (Nom3!=-1)){
                     Nom=search_poly(words[1],store);
                     if (Nom!=-1){
                        store[Nom]=store[Nom2]-store[Nom3];
                     }
                     else{ store.push_back(store[Nom2]-store[Nom3]); store[store.size()-1].setname(words[1]);}
                     }
                      else{ cout<<"Polynom "<<words[2]<<" or polynom "<<words[3] <<" is not declared.\n"; }
        }
        else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }

    if (words[0]=="mult"){ //обработка умножения
        if (name_cont(words[1]) && name_cont(words[2]) && name_cont(words[3])){

                 Nom2=search_poly(words[2],store);
                 Nom3=search_poly(words[3],store);
                 if ( (Nom2!=-1) && (Nom3!=-1)){
                    if ((get_degree(store[Nom2])<=100) && (get_degree(store[Nom3])<=100)){//если степени операндов не превышают 100
                        Nom=search_poly(words[1],store);
                        if (Nom!=-1){
                            store[Nom]=store[Nom2]*store[Nom3];
                        }
                        else{ store.push_back(store[Nom2]*store[Nom3]); store[store.size()-1].setname(words[1]);} }
                 else {cout<<"One of the polynoms have degree more than 100.\n";}
                     }
                      else{ cout<<"Polynom "<<words[2]<<" or polynom "<<words[3] <<" is not declared.\n"; }
        }
        else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }

    if (words[0]=="insert"){ //обработка вставки
        if (name_cont(words[1]) && name_cont(words[2]) && name_cont(words[3])){

                 Nom2=search_poly(words[2],store);
                 Nom3=search_poly(words[3],store);
                 if ( (Nom2!=-1) && (Nom3!=-1)){
                     if ((get_degree(store[Nom2])<=50) && (get_degree(store[Nom3])<=50)){//если степени операндов не превышают 50
                        Nom=search_poly(words[1],store);
                        if (Nom!=-1){
                            store[Nom]=inser(store[Nom2], store[Nom3]);
                        }
                        else{ store.push_back(inser(store[Nom2], store[Nom3])); store[store.size()-1].setname(words[1]);}}
                        else {cout<<"One of the polynoms have degree more than 50.\n";}
                        }
                        else{ cout<<"Polynom "<<words[2]<<" or polynom "<<words[3] <<" is not declared.\n"; }
        }
        else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }
//обработка производной n порядка
    if (words[0]=="differ"){
         if (name_cont(words[1]) && name_cont(words[2]) ){
            Nom3=ent_num(words[3] , 500);
            if (Nom3!=-1){
                 Nom2=search_poly(words[2],store);
                 if (Nom2!=-1){
                    Nom=search_poly(words[1],store);
                    if (Nom!=-1){
                        store[Nom]=derivat(store[Nom2], Nom3);
                     }
                     else{ store.push_back(derivat(store[Nom2], Nom3)); store[store.size()-1].setname(words[1]);}

                 }
                 else {cout<<"Polynom "<<words[2]<<" is not declared.\n";}

            }
         }
         else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }
//обработка  возведения в степень n
    if (words[0]=="pow"){
         if (name_cont(words[1]) && name_cont(words[2]) ){
            Nom3=ent_num(words[3] , 50);
            if (Nom3!=-1) {
                 Nom2=search_poly(words[2],store);
                 if (Nom2!=-1){
                    Nom=search_poly(words[1],store);
                    if (Nom!=-1){
                        if (get_degree(store[Nom2])<=50) {store[Nom]=pow(store[Nom2], Nom3);}//если степень не превышает 50
                        else {cout <<"Degree of polynom is more than 50.\n";}
                     }
                     else{
                            if (get_degree(store[Nom2])<=50) {store.push_back(pow(store[Nom2], Nom3)); store[store.size()-1].setname(words[1]);}
                             else {cout <<"Degree of polynom is more than 50.\n";}}

                 }
                 else {cout<<"Polynom "<<words[2]<<" is not declared.\n";}

            }

         }
         else {cout<<"Name of the polylom entered incorrectly.\n"; }
    }
//конец if
 if ((words[0]!="pow") && (words[0]!="differ") && (words[0]!="insert") && (words[0]!="mult") && (words[0]!="summ") && (words[0]!="substr") ){
    cout<<serror;
 }
}

}
return 0;
}





