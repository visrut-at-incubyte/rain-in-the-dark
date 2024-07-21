cc main.c -I./raylib-5.0_linux_amd64/include -L./raylib-5.0_linux_amd64/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
LD_LIBRARY_PATH=./raylib-5.0_linux_amd64/lib:$LD_LIBRARY_PATH ./a.out