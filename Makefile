CFLAGS = -Wall -Wextra -pedantic -Iclass -Iheader
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
EXECUTABLE = bin/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp
	g++ $(CFLAGS) -c $< -o $@

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
