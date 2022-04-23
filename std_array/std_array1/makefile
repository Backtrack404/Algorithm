CORSS =
CC=$(CORSS)g++

EXE=std_array1

DEFINES=
LDFLAGS = -lpthread -L/usr/local/lib -lssl -lcrypto
CXXFLAGS=-g -I./include $(DEFINES)

C_SRC=$(wildcard *.c)
CPP_SRC = $(wildcard *.cpp)
CC_SRC = $(wildcard *.cc)
SRC = $(C_SRC) $(CPP_SRC) $(CC_SRC)
OBJ = $(C_SRC:.c=.o) $(CC_SRC:.cc=.o) $(CPP_SRC:.cpp=.o)

defualt : $(EXE) clean

all : $(EXE)
	echo complete!!

$(EXE) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	strip $@
	

clean:
	rm $(EXE).o


