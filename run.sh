file_name=$1

cc $file_name -I./raylib-5.0_linux_amd64/include -L./raylib-5.0_linux_amd64/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Werror

if [ $? -eq 0 ]; then
    echo "Compilation successful"
else
    echo "Compilation failed"
    exit 1
fi

LD_LIBRARY_PATH=./raylib-5.0_linux_amd64/lib:$LD_LIBRARY_PATH ./a.out