# Linux Processes

Add multi threading support by including -pthread (posix threads), because C++ is expected to use the underlying system thread library.
Also, pthread is an industry standard over the OS specific threads, using the OS specific calls when std::thread is an abstraction 
in C++ that could be implemented using pthread or the OS's native threads.

Read more:
https://stackoverflow.com/questions/46994982/g-why-do-i-have-to-pass-pthread-option-while-using-stdthread
https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux