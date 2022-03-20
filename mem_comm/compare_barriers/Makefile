test_barriers: test_barriers.o
	g++ -Wall -Werror -Wextra -pedantic -O0 -g centralized.o dissemination.o mcs.o test_barriers.o -o test_barriers

test_barriers.o: test_barriers.cc
	g++ -c test_barriers.cc

centralized: centralized.o
	g++ -Wall -Werror -Wextra -pedantic -O0 -g centralized.o -o centralized

centralized.o: centralized.cc
	g++ -c centralized.cc

dissemination: dissemination.o
	g++ -Wall -Werror -Wextra -pedantic -O0 -g dissemination.o -o dissemination

dissemination.o: dissemination.cc
	g++ -c dissemination.cc

mcs: mcs.o
	g++ -Wall -Werror -Wextra -pedantic -O0 -g mcs.o -o mcs

mcs.o: mcs.cc
	g++ -c mcs.cc

clean:
	rm *.o centralized dissemination mcs test_barriers