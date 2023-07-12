CC = gcc
FLAGS = -Wall -Werror -Wextra

all: format txt cipher copy1 copy2 m1

format:
		cp ../materials/linters/.clang-format .
		clang-format -i --style=file *.c

copy1:
		cp ai_modules/m1.c .

copy2:
		cp ai_modules/m2.c .

cipher:
		$(CC) $(FLAGS) cipher.c -o ../build/cipher

m1:
		touch m1.h 
		touch m2.h
		rm -rf ai_modules/m1.h ai_modules/m2.h
		cp m1.h ai_modules/
		cp m2.h ai_modules/
		rm -rf m1.h m2.h
		# cp ../build/m1.c ai_modules/
		# cp ../build/m2.c ai_modules/

txt:
		cp *.txt ../build/

clean:
		rm -rf *.out ../build/cipher ../build/*.txt .clang-format m1.c m2.c 