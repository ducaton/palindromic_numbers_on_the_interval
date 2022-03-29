#include <iostream>

using namespace std;

int main() {
	int start, //Начало интервала
	end, //Конец интервала
	ln, //Длина числа
	lntmp, //Временные переменные
	tmp, 
	tmp2,
	tmp3,
	deln=1, //Деление
	odeln=1; //Остаток от деления
	//Ввод интервала
	cout<<"Enter the beginning the of interval"<<endl;
	cin>>start;
	cout<<"Enter the end the of interval"<<endl;
	cin>>end;
	//Числа меньше 10 не могут быть палиндромом
	if (start<10) start=10;
	if (start>end) {
	    cout<<"Диапазон должен быть от меньшего к большему"<<endl;
	    return 1;
	}
	//Основной цикл
	while (start!=end){
		//Вычисление длины числа
		ln=0;
		tmp=start;
		while (tmp!=0) {
			tmp/=10;
			ln++;
		}
		//Вычисление чисел деления нацело и деления с остатком
		lntmp=ln;
		while (lntmp>0) {
			if (tmp==0) {
				deln*=10;
				tmp=1;
			}
			else {
				odeln*=10;
				tmp=0;
			}
			lntmp--;
		}
		//Вывод палиндрома (делит число пополам и сравнивает)
		if (start/deln==start%odeln){
			if (ln<4) cout<<start<<endl;
			else {
				//Разворот второй половины числа, которая равна первой половине
				tmp=start;
				tmp2=tmp%odeln;			
				tmp3=0;
				while(tmp2){
					tmp3=tmp3*10+tmp2%10;
					tmp2/=10;
				}
				tmp=tmp/odeln*odeln+tmp3;
				cout<<tmp<<endl;
				//cout<<'\t'<<deln<<'\t'<<odeln<<endl;
			}
		}
		deln=1;
		odeln=1;
		start++;
	}
}
