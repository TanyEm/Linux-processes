#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main1(int arg, char *argv[]){

    ofstream logs;
    ifstream log;
    char fileName[32] = "";
    string printFile;
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

    return 0;
}