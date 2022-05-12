FILE="a.out"

clang++ main_vector.cpp -o $FILE
./$FILE $@
rm $FILE
rm exec