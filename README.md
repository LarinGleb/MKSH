# MKSH
Questions for International computer school. There are four methonds of sort:
1) Bubble sort
2) Gnome sort
3) Cocktail sort
4) Insertion sort

Count elements in array are 2^11, 2^13 and 2^15. It is consecutive numbers from 1 to count elements.

To compile to windows in the source folder, run:
g++ main.cpp -o main.exe -lstdc++ -L "include/" -larr -lbubble -lcocktail -lstdnew -lgnome -linsertion

If it is necessary to compile on Linux, then with CMake files are present:
mkdir build
cd build
cmake ../
do
./Sort

If you want to add your own sorting method, then you will need to:
    For Windows:    
        compile the .a library and add it to include, as well as to gcc
    For Linux: 
        you need to add it to the cmake file.