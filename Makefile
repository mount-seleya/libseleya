LDFLAGS_libseleya = $(shell pkg-config --static --libs glfw3) -lvulkan ${LDFLAGS}

all: libseleya.so seleya

libseleya.so:
	${CC} -c -fPIC ./src/libseleya.c -I./src/include ${LDFLAGS_libseleya}
	${CC} -shared -fPIC -Wl,-soname,libseleya.so \
		-o libseleya.so ./libseleya.o -lc \
		${LDFLAGS_libseleya}

seleya: libseleya.so
	${CC} -c ./demo/seleya.c -I./demo/include -I./src/include -L./ -lseleya
	${CC} -o ./seleya ./seleya.o -L./ -lseleya

clean:
	rm -rf ./seleya ./*.o ./*.so
