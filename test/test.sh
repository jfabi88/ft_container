FILE="exec.o"

if [ $# == 1 ]; then
	if [ $1 == "capacity" ]; then
		echo "[TEST CAPACITY]"
		clang++ -g capacity_test.cpp -o $FILE
	elif [ $1 == "enable" ]; then
		echo "[TEST ENABLE]"
		clang++ enable_if_test.cpp -o $FILE
	elif [ $1 == "ft_vector" ]; then
		echo "[TEST FT_VECTOR]"
		clang++ -std=c++98 ft_vector_test.cpp -o $FILE
	elif [ $1 == "vector" ]; then
		echo "[TEST VECTOR]"
		clang++ vector_test.cpp -o $FILE
	elif [ $1 == "is_iterator" ]; then
		echo "[TEST IS_ITERATOR]"
		clang++ -g is_iterator_test.cpp -o $FILE
	elif [ $1 == "access" ]; then
		echo "[TEST ACCESS]"
		clang++ element_access_test.cpp -o $FILE
	elif [ $1 == "assign" ]; then
		echo "[TEST ASSIGN]"
		clang++ assign_test.cpp -o $FILE
	elif [ $1 == "iterator" ]; then
		echo "[TEST ITERATOR]"
		clang++ iterator_test.cpp -o $FILE
	elif [ $1 == "operator" ]; then
		echo "[TEST OPERATOR]"
		clang++ operator_test.cpp -o $FILE
	elif [ $1 == "reverse" ]; then
		echo "[TEST REVERSE]"
		clang++ reverse_test.cpp -o $FILE
	elif [ $1 == "insert" ]; then
		echo "[TEST INSERT]"
		clang++ insert_test.cpp -o $FILE
	elif [ $1 == "erase" ]; then
		echo "[TEST INSERT]"
		clang++ erase_test.cpp -o $FILE
	fi
	if [ -e $FILE ]
	then
		./exec.o
		rm exec.o
		echo "[END TEST]"
	fi
fi
