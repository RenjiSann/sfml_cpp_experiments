CC = g++
CFLAGS = -g -Wall
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -lm
TARGET = main

DEPS = simple_pendulum.cpp double_pendulum.cpp utils.cpp pendulum_drawing.cpp
OBJS = $(subst .cpp,.o, $(DEPS))
HEADS = $(subst .cpp,.hpp, $(DEPS))

#$(info $$OBJS is [${OBJS}])
all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS) $(HEADS)
	$(CC) $(CFLAGS) $(TARGET).cpp $(OBJS) $(LDFLAGS) -o $(TARGET) 

clean:
	$(RM) $(TARGET) *.o
