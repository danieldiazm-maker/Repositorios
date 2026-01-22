# Compilador
CXX := g++
# Quitamos las banderas de ASAN porque tu MinGW no las tiene
# Dejamos -g para que puedas usar un debugger si quieres luego
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g

# Detección de extensión
ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT :=
endif

# Archivos
SRCS := $(wildcard *.cpp)
TARGETS := $(SRCS:%.cpp=%$(EXEEXT))

all: $(TARGETS)

%$(EXEEXT): %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Limpieza compatible con Git Bash (rm)
clean:
	rm -f *$(EXEEXT) *.o