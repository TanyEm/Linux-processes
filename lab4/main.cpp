#include <iostream>
#include <fstream>
#include <unistd.h>
#include <thread>

using namespace std;

// / Создаем поток для работы с файлом как объект ifstream для ввода (чтения) данных из файла
	ifstream logs;

void threadFunc(ifstream *logs) {
	string printFile;

	if (logs->is_open()){
		cout << "Файл открыт" << endl;
	} else {
		cout << "Файл не открыт" << endl;
	}
	
	//Печатаем все из файла
    std::cout << "В файле: " <<endl;
	while (getline(*logs, printFile))
	{
		cout << printFile << endl;
	}

	int sched_setscheduler();
	cout << "Класс планирования: " << sched_setscheduler << endl;

	logs->close();
}


int main() {
	ofstream myfile;
	myfile.open ("logs.txt");
    myfile << "В этом файле привет миру :)\n";
	myfile << "Пишу сюда что-нибудь чтобы проверить работу программы\n";
	myfile << "Еще что-то\n";
	myfile << "И еще\n";
	myfile << "И еще\n";
	myfile << "Наверное хватит\n";
    myfile.close();

	cout << "Управление потоками" << endl;
    cout << "Подлесных Т.П" << endl;
	// Открывам файл
  	logs.open("logs.txt");
	// Создаем поток по идентификатору thread и функции потока threadFunc 
	// и передаем потоку указатель на файл
  	
	  
	  std::thread t1(threadFunc, &logs);
	int pthread_getschedparam(pthread_t thread, int *policy, struct sched_param *param);

	
	// Ждем завершения потока
  	t1.join();
	// Устанавливаем планировщик. получает алгоритм диспетчеризации процесса с номером pid. 
	// Если pid равен нулю, то возвращается алгоритм планирования вызывающего процесса (код планирования).
	int sched_setscheduler();
	cout << "Класс планирования: " << sched_setscheduler <<  endl;

	// принудительное закрытие, если файл все еще открыт
	if (logs.is_open()){
		cout << "Файл все еще открыт" << endl;
		cout << "теперь закрыть" << endl;
		logs.close();
	}

    return 0;
}