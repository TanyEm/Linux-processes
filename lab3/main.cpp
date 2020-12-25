#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

ofstream logs;
int pid, rv;
char fileName[32] = "";

void checkFork(char *fileName) {
    pid_t pid = fork();
    if (pid == 0) {
        //процесс потомка
        sleep(5);
        logs << "Потомок 1: ";
	  	  logs << "Индификатор процесса= "<<getpid()<<endl;
	  	  logs << "Индификатор предка= "<< getppid()<<endl;
	  	  logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
	  	  logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
	  	  logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
	  	  logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
	  	  logs << "Реальный групповой индификатор= "<<getgid()<<endl;
	  	  logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
            execl("Done"," ",fileName, NULL);
            exit(rv);

    } else if (pid > 0){
        // процессы предка
        logs << "Предок: ";
	      logs << "Индификатор процесса= "<<getpid()<<endl;
	      logs << "Индификатор предка= "<< getppid()<<endl;
	      logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
	      logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
	      logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
	      logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
	      logs << "Реальный групповой индификатор= "<<getgid()<<endl;
	      logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
          execl("Done"," ",fileName, NULL);
    } else {
        // ошибка fork
        // выход из родительского процесса
        printf("Ошибка fork()");
        exit(1);
    }
}

void checkVfork(char *fileName) {
    pid_t pid = vfork();
    if (pid == 0) {
        sleep(10);
        logs << "Потомок 2: ";
	  	  logs << "Индификатор процесса= "<<getpid()<<endl;
	  	  logs << "Индификатор предка= "<< getppid()<<endl;
	  	  logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
	  	  logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
	  	  logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
	  	  logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
	  	  logs << "Реальный групповой индификатор= "<<getgid()<<endl;
	  	  logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
	  	  execl("Done"," ",fileName, NULL);
            exit(rv);
    } else if (pid > 0){

        // процессы предка
        logs << "Предок: ";
	      logs << "Индификатор процесса= "<<getpid()<<endl;
	      logs << "Индификатор предка= "<< getppid()<<endl;
	      logs << "Индификатор сессии процесса= "<<getsid(pid)<<endl;
	      logs << "Индификатор группы процессов= "<<getpgid(pid)<<endl;
	      logs << "Реальный индификатор пользователя= "<<getuid()<<endl;
	      logs << "Эффективный индификатор пользователя= "<<geteuid()<<endl;
	      logs << "Реальный групповой индификатор= "<<getgid()<<endl;
	      logs << "Эффективный групповой индификатор= "<<getegid()<<endl<<endl;
          execl("Done"," ",fileName, NULL);
        
    } else {
        // ошибка fork
        // выход из родительского процесса
        printf("Ошибка vfork()");
        exit(1);
    }
    
}


int main() {
    cout << "Создание и идентификация процессов\n";
    cout << "Подлесных Т.П\n";

    cout << "Введите имя файла в который будет производиться запись логов:\n";
    cin >> fileName;
    logs.open(fileName, ios_base::app);
    logs << "Logs: \n";

    checkFork(fileName);
    checkVfork(fileName);

    return 0;
}