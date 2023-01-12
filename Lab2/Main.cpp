#include <iostream>
#include <time.h>
#include <cmath>
#include <omp.h>
#include <math.h>
#include <string>
#include <random>
#include <ctime>

using namespace std;
bool isNumber(const string& s)
{
	if (s.find_first_not_of("0123456789") == -1)
	{
		if (s != "")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main() {
		setlocale(LC_ALL,"Rus");


		mt19937 rng( std::time(0) ) ;
		uniform_int_distribution<long long> distr( 101, 9999999 ) ;
		
	
		const int countUnit = 100000;
		const int countCoup = 100;
		long countThreads;
		long b = 55434;
        

		static long long A[countUnit];
		static long long C1[countUnit];
		static long long C2[countUnit];
		long long N111[2][countCoup];

		bool flag = false;
		string numberStr;
		long i, j;
		double timer;
		

		
		cout << "Введите количество потоков (от 1 до " << countUnit << "): ";
		do
		{
				getline(cin, numberStr);
				
				flag = isNumber(numberStr);
				if (!flag)
				{
					cout << "Количество потоков указано некорректно. Попробуйте еще раз.";
				}
				else
				{
					countThreads = stoi(numberStr);
					if (countUnit > countThreads)
					{
							break;
					}
					else
					{
							cout << "Количество потоков должно быть меньше количества элементов массива. Попробуйте еще раз." << endl;
					}
				}
		} while (5 == 5);
		cout << "Количество потоков = " << countThreads << endl;
		
		omp_set_num_threads(countThreads);
		srand((unsigned) time(NULL));

		//заполняем последовательности чисел
		for (i = 0; i < countUnit; i++)
		{
			A[i] = distr(rng);
			C1[i] = distr(rng);
			C2[i] = 1 + (rand() % 3);
			//cout << C1[i] << endl;
		}
		for (j = 0; j < countCoup; j++)
		{
			N111[0][j] = j;
			N111[1][j] = 2*j;
		}

		
		cout << "Задание № 10. Поиск суммы всех четных чисел массива" << endl;
		cout << "Дана последовательность натуральных чисел {a0…an–1}. \nСоздать многопоточное приложение для поиска суммы ai, где ai – четные числа" << endl;
		timer = omp_get_wtime();
		long long sum = 0;
		for (i = 0; i < countUnit; i++)
		{
			sum += (C1[i] % 2 == 0 ? C1[i] : 0);
		}
		timer = omp_get_wtime() - timer;
		cout << "Без потоков. Сумма = " << sum << " (Время: " << timer << " с). " << endl;



		timer = omp_get_wtime();
		sum = 0;
		#pragma omp parallel for reduction (+:sum)
		for (i = 0; i < countUnit; i++)
		{
			sum += (C1[i] % 2 == 0 ? C1[i] : 0);
		}
		timer = omp_get_wtime() - timer;
		cout << "С потоками. Результат = " << sum << " (Время: " << timer << " с). " << endl << endl;
		/**/




		system("pause");	
}
