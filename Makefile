CFLAGS = -Wall -Wextra -pedantic -Iclass -Iheader
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
EXECUTABLE = bin/main
FILES = data/*.txt

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

.PHONY: s-run
s-run:
	./$(EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	@$(CLEAR_TERMINAL)
	./$(EXECUTABLE)

.PHONY: clear
clear:
	rm -f $(OBJECTS) $(EXECUTABLE) $(FILES)
