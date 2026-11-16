CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -g -pthread
SOURCES = main.c dectobin.c function_pointers.c interprocess_comm.c main_ipc.c mutex.c signal_function.c signal_handler.c signals.c threadargs.c threadfunc.c threads.c

flecode: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@