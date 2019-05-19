#ifndef FUNC_FOR_MAIN_H
#define FUNC_FOR_MAIN_H
#include <iostream>
#include"polynoms.h"

using namespace std;

//функция возвращает массив строк,
//содержащий слова команды
vector <string>  split_list( string st );
//функция проверки правильности названия полинома
bool name_cont(string st);

 //функция поиска полинома в списке по имени
int search_poly (string nm,vector <polynom> &vp);
//функция создания вектора коэффициентов для полинома
vector <long long int> make_coeff(string st);
//функция конвертирует вводимую строку в число от 0 до n
//если строка не число, функция возвращает -1
int ent_num(string str, int n);
#endif
