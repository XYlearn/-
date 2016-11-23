dest : grade_manage.o main.o
	gcc -O2 -o dest grade_manage.o main.o

grade_manage.o : grade_manage.c grade_manage.h
	gcc -O2 -c grade_manage.c
main.o : main.c grade_manage.h
	gcc -O2 -c main.c
clean : 
	rm main.o grade_manage.o
