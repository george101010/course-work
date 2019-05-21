#ifndef POLYNOMS_H
#define POLYNOMS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class polynom {
    public:
         friend ostream& operator<< (ostream &out, const polynom &polynom);// перегрузка cout
         friend  polynom operator+(polynom& ,polynom& );//перегрузка сложения
         friend  polynom operator-(polynom& ,polynom& );//перегрузка вычетания
         friend  polynom operator*(polynom& ,polynom& );//перегрузка умножения
         friend  polynom derivat(polynom& ,int n);//производная порядка n
         friend  polynom pow(polynom& ,int n);// перегрузка возведения в степень
         friend  polynom inser(polynom&   A,polynom&   B);//вставка полинома В в полином А
         friend int get_degree(polynom& A);
         friend  string getname(polynom&  );//возвращает имя полинома
         void mp(string st,vector <long long int> &cf);
         void setname(string st);//присвоение имени из основной программы

    private:
        string name;//имя полинома
        int degree;//степень полинома
        vector<long long int>coeffs;//вектор коэффициентов полинома

    public://методы


        polynom& operator=(const polynom& right){//перегрузка присваивания
            this->degree=right.degree;
            this->coeffs.clear();
            for (int i=0;i<=right.degree;i++){
                this->coeffs.push_back(right.coeffs[i]);
            }
            return *this;}
        };


#endif
