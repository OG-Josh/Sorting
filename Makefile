CXX = g++

CXXFLAGS = -g --std=c++11

BINARY = hwec

TARFILE = hwec.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hwec.cpp -o $(BINARY)
clean:
	rm -rf $(BINARY) $(TARFILE)
tar:
	tar cf $(TARFILE) Makefile hwec.scr hwec.cpp