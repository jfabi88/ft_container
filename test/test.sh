FILE="exec.o"

if [ $# == 1 ]; then
	if [ $1 == "enable" ]; then
		echo "[TEST ENABLE]"
		clang++ enable_if_test.cpp -o $FILE
	elif [ $1 == "ft_vector" ]; then
		echo "[TEST FT_VECTOR]"
		clang++ ft_vector_test.cpp -o $FILE
	elif [ $1 == "vector" ]; then
		echo "[TEST VECTOR]"
		clang++ vector_test.cpp -o $FILE
	elif [ $1 == "iterator" ]; then
		echo "[TEST IS_ITERATOR]"
		clang++ is_iterator_test.cpp -o $FILE
	fi
	if [ -e $FILE ]
	then
		./exec.o
		rm exec.o
		echo "[END TEST]"
	fi
fi
