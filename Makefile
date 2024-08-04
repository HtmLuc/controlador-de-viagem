CFLAGS = -Wall -Wextra -pedantic -Iclass -Iheader
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
EXECUTABLE = bin/main

ifeq ($(OS), Windows_NT)
CLEAR_TERMINAL = cls
else
CLEAR_TERMINAL = clear
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ $(CFLAGS) $^ -o $@

obj/%.o: src/%.cpp
	g++ $(CFLAGS) -c $< -o $@

.PHONY: run
run:
	@$(CLEAR_TERMINAL)
	./$(EXECUTABLE)

.PHONY: c-run
c-run: $(EXECUTABLE)
	@$(CLEAR_TERMINAL)
	./$(EXECUTABLE)

.PHONY: clear
clear:
	rm -f $(OBJECTS) $(EXECUTABLE)
