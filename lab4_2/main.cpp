#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

void threadFunc1(string str, ofstream *logOdd){
    *logOdd << str <<endl;
    //печатаем строку
    cout<<str<<endl;
}

void threadFunc2(string str, ofstream *logEven){
    *logEven << str <<endl;
    cout<<str<<endl;
}

int main(){
    string str;
    ifstream poem, printLogOdd, printLogEven;
    ofstream logOdd, logEven;

    cout << "Управление потоками 2" << endl;
    cout << "Подлесных Т.П" << endl;
    
    //открываем файлы
    poem.open("file.txt");
    logOdd.open("logOdd");
    logEven.open("logEven");

    // end-of-file eof() возвращает 1, если был достигнут конец файла
    while(!poem.eof()){
        //получаем строку
        getline(poem, str);
        // Создаем поток по идентификатору thread и функции потока threadFunc1 
	    // и передаем потоку указатель на файл
        std::thread t1(threadFunc1, str, &logOdd);
        getline(poem, str);
        std::thread t2(threadFunc2, str, &logEven);

        // Ждем завершения потока
        t1.join();
        t2.join();
    }

    poem.close();
    logOdd.close();
    logEven.close();

    cout << "\nВ файле logOdd: " <<endl;
    printLogOdd.open ("logOdd");
	while (getline(printLogOdd, str))
	{
		cout << str << endl;
	}
    printLogOdd.close();

    cout << "\nВ файле logEven: " <<endl;
    printLogEven.open ("logEven");
	while (getline(printLogEven, str))
	{
		cout << str << endl;
	}
    printLogEven.close();

}