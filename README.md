# D. Бусинки
https://contest.yandex.ru/contest/29403/problems/D/

Ограничение времени

2 секунды

Ограничение памяти

256Mb

#### Ввод

стандартный ввод или input.txt

#### Вывод

стандартный вывод или output.txt

Маленький мальчик делает бусы. У него есть много пронумерованных бусинок. Каждая бусинка имеет уникальный номер – целое число в диапазоне от 1 до N. Он выкладывает все бусинки на полу и соединяет бусинки между собой произвольным образом так, что замкнутых фигур не образуется. Каждая из бусинок при этом оказывается соединенной с какой-либо другой бусинкой.

Требуется определить, какое максимальное количество последовательно соединенных бусинок присутствует в полученной фигуре.

## Формат ввода

В первой строке – количество бусинок 1 ≤ N ≤ 2500. В последующих N-1 строках по два целых числа – номера, соединенных бусинок.

## Формат вывода

Вывести одно число – искомое количество бусинок.

### Пример 1

#### Ввод
2\
1 2
#### Вывод
2

### Пример 2

#### Ввод
5\
2 1\
2 3\
2 4\
2 5
#### Вывод
3

### Пример 3

#### Ввод
10\
1 2\
2 3\
3 4\
4 5\
1 6\
6 10\
10 9\
9 8\
8 7
#### Вывод
10