#include <iostream>
#include <fstream>
#include <unistd.h>
#include <thread>
// #include <paths.h>

using namespace std;

ifstream logs;

void task1(ifstream *logs) {
	string line;
	if (logs->is_open()) cout << "файл открыт" << endl;
	char str[80];
	cout << str << endl;
	getline(*logs, line);
    std::cout << "Файл содержит " << line <<endl;
	int sched_setscheduler();
	cout << "Класс планирования" << sched_setscheduler << endl;
	logs->close();
}


int main() {
	//std::thread* thr;
	
  	logs.open("log.txt");
  	std::thread t1(task1, &logs);
    cout << "Управление потоками" << endl;
    cout << "Подлесных Т.П" << endl;

	
	
  	t1.join();
	int sched_setscheduler();
	cout << "Класс планирования" << sched_setscheduler;

	// принудительное закрытие, если файл все еще открыт
	if (logs.is_open()){
		//logs << "Logs:";
		cout << "Файл открыт" << endl;
		logs.close();
	}

    return 0;
}