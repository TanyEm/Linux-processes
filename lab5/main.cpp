#include <iostream>
#include <csignal>

using namespace std;

void getSignal (int error)
{
    printf("Тип ошибки: \n");
	switch(error) {
	case SIGSEGV:
	    printf ("Нарушение защиты памяти\n");
        raise(1); // завершить программу со значением 1
    break;
	case SIGFPE:
	    printf ("Неверная операция\n");
        raise(2); // завершить программу со значением 2
    break;
	}

}

int main () {
    int delimoe;
    int choice;

    cout << "Обработка сигналов\n";
    cout << "Подлесных Т.П\n";

    cout << "Введите код операции:\n0 - деление\n1 - память\n2 - корректная работа\n";
    cin >> choice;

    // перехват сигнала
    signal (SIGSEGV,getSignal);
    signal (SIGFPE,getSignal);

    if (choice == 0){
        printf("Деление на ноль запрещено, операция неверна\n");
        delimoe = delimoe/0;
    } else if (choice == 1){
        printf("Запрещены преобразования строковой константы в char *, нарушает защиту памяти\n");
        char * S = "Hello";
        cin.getline( S, 255 );

        // Правильно делать константный указатель на изменяемую строку, указав размер сразу
        //char S[255] = "Hello"; // Указатель S менять нельзя, строку "Hello" можно
        //cin.getline( S, 255 ); // Не больше чем выделено на массив, на начало которого указывает S
    }

    printf ("Корректное окончание работы \n");
    return 0;
}