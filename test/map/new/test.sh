FILE="a.out"

clang++ main_map.cpp -o $FILE
./$FILE $@
rm $FILE
rm exec