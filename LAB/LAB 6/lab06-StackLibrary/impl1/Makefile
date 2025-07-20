stack-int:
	cp -R item-int.h ./item.h
	cp -R item-int.c ./item.c
	gcc -Wall -g -o impl1 \
	    client.c stack.c util.c item.c -lm

stack-string:
	cp -R item-string.h ./item.h
	cp -R item-string.c ./item.c
	gcc -Wall -g -o impl1 \
	    client.c stack.c util.c item.c -lm

stack-struct:
	cp -R item-struct.h ./item.h
	cp -R item-struct.c ./item.c
	gcc -Wall -g -o impl1 \
	    client.c stack.c util.c item.c -lm

clean:
	rm -rf impl1
	rm -rf item.h
	rm -rf item.c
	rm -rf util.c
	rm -rf util.h
	rm -rf *~
	rm -rf #*
	rm -rf *.bak
