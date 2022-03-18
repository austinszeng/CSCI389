centralized: centralized.o
	gcc -Wall -Werror -Wextra -pedantic -O0 -g centralized.o -o centralized

centralized.o: centralized.c
	gcc -c centralized.c

dissemination: dissemination.o
	gcc -Wall -Werror -Wextra -pedantic -O0 -g dissemination.o -o dissemination

dissemination.o: dissemination.c
	gcc -c dissemination.c

mcs: mcs.o
	gcc -Wall -Werror -Wextra -pedantic -O0 -g mcs.o -o mcs

mcs.o: mcs.c
	gcc -c mcs.c

clean:
	rm *.o centralized dissemination mcs