FILE=`find . -name $1.cpp`
g++ -g -c $FILE -I ./include/ -o $1.o
g++ -g -c ./src/common.cpp -I ./include/ -o common.o
g++ -lstdc++ $1.o common.o -o ./bin/$1
rm -rf *.o
