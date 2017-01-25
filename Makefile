# build an executable
all: hill8queen.cpp 
	clang++ -o hill8queen -stdlib=libstdc++ hill8queen.cpp -std=c++0x
clean: 
	$(RM) hill8queen
