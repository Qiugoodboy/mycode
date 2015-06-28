flight:flight.o main.o  
	gcc  flight.o main.o -o flight
flight.o:flight.c
	gcc  -c flight.c -o flight.o
main.o:main.c
	gcc  -c  main.c -o main.o
clean:
	rm *.o flight
