#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <time.h>

using namespace std;

int main() {
    ofstream logs;
    ifstream log;
    //int pid, rv;
    char fileName[32] = "log";
    string printFile;
    
    cout << "Создание и идентификация процессов\n";
    cout << "Подлесных Т.П\n";

    cout << "Введите имя файла в который будет производиться запись логов:\n";
    //cin >> fileName;
    

    //const auto p1 = std::chrono::system_clock::now();
    // logs << "seconds since epoch: " << std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count() << '\n';
    // logs << "Logs: \n";
    
    int pid;
    logs.open(fileName, ios_base::app);
    time_t curtime;

    time(&curtime);

    logs << "Время: " << ctime(&curtime) << endl;

    pid = fork();
    if (pid == 0) {
        //процесс потомка
        sleep(2);
        logs << "Потомок 1: ";
        logs << "Индификатор процесса= "<<getpid()<<endl;
        logs << "Индификатор предка= "<< getppid()<<endl;
        logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
        logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
        logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
        logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
        logs << "Реальный групповой индификатор= "<<getgid()<<endl;
        logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
        exit(1);

    } else if (pid > 0){

        pid = vfork();
    if (pid == 0) {
        sleep(4);
        pid_t pid = getpid();

    logs << "Потомок 2: ";
        logs << "Индификатор процесса= "<<getpid()<<endl;
        logs << "Индификатор предка= "<< getppid()<<endl;
        logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
        logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
        logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
        logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
        logs << "Реальный групповой индификатор= "<<getgid()<<endl;
        logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
        execl("main1","main1",fileName, NULL);
        exit(1);
    } else if (pid > 0){
        pid_t pid2 = getpid();
        // процессы предка
        // процессы предка
        // проверяем, что родительский процесс блокируется
        sleep(1);
        logs << "Предок: ";
        logs << "Индификатор процесса= "<<getpid()<<endl;
        logs << "Индификатор предка= "<< getppid()<<endl;
        logs << "Индификатор сессии процесса= "<<getsid(pid2)<<endl;
        logs << "Индификатор группы процессов= "<<getpgid(pid2)<<endl;
        logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
        logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
        logs << "Реальный групповой индификатор= "<<getgid()<<endl;
        logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
    } else {
        // ошибка fork
        // выход из родительского процесса
        printf("Ошибка vfork()");
        exit(1);
    }
        
    } else {
        // ошибка fork
        // выход из родительского процесса
        printf("Ошибка fork()");
        exit(1);
    }

    cout << "В файле: " <<endl;
    log.open ("log");
	while (getline(log, printFile))
	{
		cout << printFile << endl;
	}
    return 0;
}
