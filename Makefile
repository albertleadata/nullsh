LPX = 64
PGM = nullsh
UTP = testunit
C_SRC = nullsh.c

INC = -I$(HOME)/include -I/usr/include/mysql
LDP = -L$(HOME)/lib -L/usr/lib$(LPX)

CFLG = -g -c -fPIC $(INC)
LFLG = -fPIC -shared $(LDP)

all: $(PGM)

clean:
	rm -f $(C_SRC:.c=.o) $(PGM)

$(PGM): $(C_SRC:.c=.o)
	gcc -g -o $@ $(C_SRC:.c=.o)

%.o : %.cc
	g++ -o $*.o -g -Wno-write-strings -c -fPIC $(INC) $(DEFS) $<

%.o: %.c
	gcc $(CFLG) -o $*.o $<
