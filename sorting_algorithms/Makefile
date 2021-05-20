CC = g++
CFLAGS = -g -Wall -Wextra
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lm

DEPS = sorting_strategy.cpp sortable.cpp sorting_view.cpp insertion_sort_strategy.cpp
OBJS = $(subst .cpp,.o,$(DEPS))
HEADS = $(subst .cpp,.hpp,$(DEPS))

TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(OBJS) $(HEADS)
	$(CC) $(CFLAGS) $(OBJS) $(TARGET).cpp -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) *.o $(TARGET)
