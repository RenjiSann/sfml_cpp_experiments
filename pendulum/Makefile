CC = g++
CFLAGS = -g -Wall
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lm
TARGET = main
OBJS = pendulum.o utils.o

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS)
	$(CC) $(CFLAGS) $(TARGET).cpp $(OBJS) $(LDFLAGS) -o $(TARGET) 

clean:
	$(RM) $(TARGET) *.o
