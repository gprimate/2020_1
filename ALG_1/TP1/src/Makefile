CC=g++ 
CFLAGS=-Wall -Wextra 
EXEC=./tp1 
TMPOUT=tp1.testresult


$(EXEC): main.cpp functions.o
	$(CC) $(CFLAGS) main.cpp functions.o -o $(EXEC)

functions.o: functions.cpp 
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

test: $(EXEC)
	@bash ../run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf mergeSort.o months.o planet.o radixSort.o

