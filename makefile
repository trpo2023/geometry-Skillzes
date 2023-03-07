all: geometry

geometry: geometry.c
    gcc -Wall -Werror -o app geometry.c

clean:
    rm geometry

run:
    ./geometry
