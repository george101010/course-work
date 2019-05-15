#include"polynoms.h"
#include <iostream>

using namespace std;

//=====перегрузка сложения=====
polynom operator + (polynom&   A,polynom&   B) {
   polynom Res;
   if (A.degree>=B.degree){
       Res=A;//приравнивание res
        for (int i=0;i<=B.degree;i++){
            Res.coeffs[i]+=B.coeffs[i];
        }
    }
    else{
        Res=B;//приравнивание res
        for (int i=0;i<=A.degree;i++){
            Res.coeffs[i]+=A.coeffs[i];
        }
  }
    return Res;
}
//=====перегрузка вычетания=====
polynom operator - (polynom&   A,polynom&   B) {
   polynom Res;
   if (A.degree>=B.degree){
       Res=A;//приравнивание res
        for (int i=0;i<=B.degree;i++){
            Res.coeffs[i]-=B.coeffs[i];
        }
    }
    else{
        Res=B;//приравнивание res
        for (int i=0;i<=A.degree;i++){
            Res.coeffs[i]=A.coeffs[i]-Res.coeffs[i];
        }
        for (int i=A.degree+1;i<=B.degree;i++){
            Res.coeffs[i]= -Res.coeffs[i];
        }
  }
    return Res;
}
//=====перегрузка умножения=====
polynom operator * (polynom&   A,polynom&   B) {
   polynom Res;
   Res.coeffs.clear();
   Res.degree=A.degree+B.degree;
   for (int i=0;i<=Res.degree;i++){
       Res.coeffs.push_back(0);
   };

   if (A.degree>=B.degree){
            for (int i=0;i<=B.degree;i++){
                 for (int k=0;k<=A.degree;k++){
                    Res.coeffs[k+i]=Res.coeffs[k+i]+B.coeffs[i]*A.coeffs[k];
                 }
            }
    }
    else{
            for (int i=0;i<=A.degree;i++){
                 for (int k=0;k<=B.degree;k++){
                    Res.coeffs[k+i]=Res.coeffs[k+i]+A.coeffs[i]*B.coeffs[k];
                 }
            }
}
    return Res;
}
//=====перегрузка возведения в степень=====
polynom pow(polynom& A,int n){
    polynom Res;
    if (n==0){//обработка случаев если n=1 или 0
        Res.degree=0;
        Res.coeffs.push_back(1);
        return Res;
        }
    if (n==1){
        Res=A;
        return Res;
    }
    else{
        Res.degree=0;
        Res.coeffs.push_back(1);
        for (int i=1;i<=n;i++){
                Res=Res*A;
    }}
    return Res;
    }

//=====вставка полинома В в полином А=====
polynom inser(polynom&   A,polynom&   B){
    polynom Res;//вставка по схеме Горнера
    Res.degree=0;
    Res.coeffs.push_back(A.coeffs[A.degree]);
    for (int i=A.degree-1;i>=0;i--){
        Res=Res*B;
        Res.coeffs[0]+=A.coeffs[i];
    }


    return Res;
}
//=====производная порядка n=====
polynom derivat(polynom& A,int n){
    polynom Res;
    if (n>A.degree){// обработка случаев когда n больше или
        Res.degree=0;//равна степени полинома

        Res.coeffs.push_back(0);
        return Res;
         }
    if (n==A.degree){
        Res.degree=0;
        int fact=1;
        for (int i=1;i<=A.degree;i++){
                fact=fact*i;
        }

        Res.coeffs.push_back(fact*A.coeffs[A.degree]);
    }
    else{//обработка общего случая
        Res.degree=A.degree-n;
        for (int i=n;i<=A.degree;i++){
            int fact=1;
            for (int k=i;k>i-n;k--){
                fact=fact*k;
            }
            Res.coeffs.push_back(A.coeffs[i]*fact);
        }
}
return Res;
    }
//=========перегрузка cout====
ostream& operator<< (ostream &out, const polynom &A){ // перегрузка cout
    //печать названия полинома
    out<<A.name<<"(x)=";
    //печать коэффициента при х^n
    out<<A.coeffs[A.degree]<<"*x^"<<A.degree;
    //печать коэффициентов при х^i
    for (int i=A.degree-1;i>1;i--){
        if (A.coeffs[i]>0 ){
                out<<"+";}
        if (A.coeffs[i]!=0){
                out<<A.coeffs[i]<<"*x^"<<i;
        }
        }
    //печать коэффициента при х
    if (A.coeffs[1]!=0){
        if (A.coeffs[1]>0){
                out<<"+";}
        out<<A.coeffs[1]<<"*x";
    }
    //печать свободного члена
    if (A.coeffs[0]!=0){
        if (A.coeffs[0]>0){
                out<<"+";}
        out<<A.coeffs[0];
    }


    return out;}
    //=======возвращает имя полинома======
    string getname(polynom&  A){
            return A.name;}
    //=========конструктор полинома=======
    polynom make_poly(string st,vector <long long int> cf){
        polynom A;
        A.name=st;
        A.degree=cf.size()-1;
        A.coeffs=cf;
        return A;
    }
//===присвоение имени полиному из основной программы
    polynom :: void setname(string st){
        name=st;}





