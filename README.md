 # CC_Lab2

Распараллеливание вычислений средствами OpenMP.

Лабораторная работа выполняется на языке C++ в среде Visual Studio. Во всех заданиях следует обеспечить контроль вводимой информации. При некорректном вводе – повторно запрашивать информацию у пользователя. Выполнить вычисления в однопоточном и многопоточном режиме и сравнить времена выполнения. Количество потоков задаётся пользователем. Количество исходных данных не кратно в общем случае количеству потоков. Исходные данные для задания генерируются с помощью генератора псевдослучайных чисел, где 100000<n<1000000, 100<An<10000000. Результаты сравниваются по времени выполнения при разном числе процессов и объёме данных и оформляются в виде таблицы. В отчёте приводятся снимки экрана, программный код, таблицы тестов и замеров времени выполнения, формулируется вывод. Количество потоков по-умолчанию при необходимости получать средствами OpenMP.

Задание 10

Дана последовательность натуральных чисел {a0…an–1}. \nСоздать многопоточное приложение для поиска суммы ai, где ai – четные числа

![image](https://user-images.githubusercontent.com/70890402/212094960-74970b3e-54b0-480c-b7c0-97cb9e3f7e51.png)
