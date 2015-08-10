target:reverse_list.o
	gcc -o target reverse_list.o
#	gcc reverse_list.c -o target
reverse_list.o:reverse_list.c
	gcc -c reverse_list.c 
.PHONY:clean
clean:
	rm -rf *.o target
