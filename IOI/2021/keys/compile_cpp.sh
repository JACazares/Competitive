if [ "$#" -eq 0 ]; then
	g++-14 main.cpp -o main -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -Wconversion
elif [ "$#" -eq 1 ]; then
	g++-14 $1.cpp -o $1 -std=c++20 -Wall -Wextra -Wshadow -DLOCAL -O2 -Wconversion
else
	echo "invalid num of parameters"
fi

