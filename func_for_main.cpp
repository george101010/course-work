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
    vector <string> ws=split_list(st);

    int lenst=ws.size();

    //если в строке больше 20 слов или ноль
    if ((lenst>20) || (lenst==0)){
        cout<<"Polynom's degree must not be more than 20. Or entered string is empty.\n";
        numbs.clear();
        return numbs;
    }
    int lenw=0;//длина одного слова
    for (int i=lenst-1;i>=0;i-- ){
        int number=0;
        lenw=ws[i].length();
        //если в слове больше 4 символов
        if (lenw>4){
            cout<<"Word must have no more 4 symbols.\n";
            numbs.clear();
            return numbs;
       }
       //если спереди минус удалить его
       //и длину слова уменьшить
       //флаг отрицательности true
       bool neg=0;
       if (ws[i][0]=='-'){
            neg=1;
            ws[i].erase(0,1);
            lenw=lenw-1;
       }//если в слове был только минус это ошибка
       if (lenw==0){
            cout<<"Number must not be contain only minus.\n";
            numbs.clear();
            return numbs;
       }
       //формирование числа
        for (int k=0;k<lenw;k++ ){
            //если цифра, то формирование
            //числа иначе ошибка
            if (isdigit(ws[i][k])){
                number=number*10+(int)ws[i][k]-48;
            }
            else{
                numbs.clear();
                cout<<"Coefficents entered incorrectly.\n";
                return numbs;
            }//если число по модулю больше 100 - ошибка
            if   (number>100){
                numbs.clear();
                cout<<"Some coefficents more than 100.\n";
                return numbs;
            }
            }
            if (neg){ number=-number; }//добавить минус если он есть
            numbs.push_back(number); }
            if (numbs[lenst-1]==0){
                cout<<"The first coefficient must not be equal zero\n";
               numbs.clear();
            }

    return numbs;
}
//===функция конвертирует вводимую строку в число от 0 до n
//===если строка не число, функция возвращает -1
int ent_num(string str, int n){
  int len=str.length();
  if (len>3){//если строка больше 3 символов то
    cout<<"Word must have no more 3 symbols.";//выход из функции
    return -1;
  }
  int number=0;
  for (int i=0;i<len;i++){
    if (isdigit(str[i])){
      number=10*number+(int)str[i]-48;
    }
    else {//если в строке другие символы
      cout<<"Number entered incorrectly.\n";
      return -1;
    }
    }
  if (number>n){//если число больше заданного  n
    cout<<"The entered number is greater than "<<n<<".\n";
    return -1;
  }
return number;
}
