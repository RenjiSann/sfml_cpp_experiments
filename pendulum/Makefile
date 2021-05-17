CC = g++
CFLAGS = -g -Wall
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lm

TARGET = main
DEPS = pendulum

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(DEPS)
	$(CC) $(CFLAGS) $(TARGET).cpp $(DEPS).o $(LDFLAGS) -o $(TARGET) 

$(DEPS): $(DEPS)
	$(CC) -c $(DEPS).cpp $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(TARGET) *.o
