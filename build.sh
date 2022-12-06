FILE=`find . -name $1.cpp`
g++ -g -c $FILE -I ./include/ -o $1.o
g++ -lstdc++ $1.o -o ./bin/$1
rm -rf *.o
