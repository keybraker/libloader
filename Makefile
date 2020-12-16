DESTDIR = /tmp/stage
PREFIX = /usr/local

CPP = g++
CCFLAGS = -O3 -pedantic -Wall -Wextra -std=c++1z -c
CCLINK = -I/usr/local/include -L/usr/local/lib -libloader

cnm_lib = -o libloader.so
cnm_loading = -o exp_loading_bar
cnm_progress = -o exp_progress_bar
cnm_pingpong = -o exp_pingpong_bar

obj_loading = src/exp_loading_bar.o
obj_progress = src/exp_progress_bar.o
obj_pingpong = src/exp_pingpong_bar.o

obs_lib = libloader.so
obj_lib = lib/libloader.o
hdr_lib = lib/libloader.h

all: lib

lib: lib/libloader.o
	g++ -Wall -Werror -fPIC -c lib/libloader.cpp
	g++ -shared -o libloader.so lib/libloader.o

lib-root: lib/libloader.o
	g++ -Wall -Werror -fPIC -c lib/libloader.cpp
	g++ -shared -o libloader.so lib/libloader.o
	mkdir -p /usr/local/lib
	mkdir -p /usr/local/include
	cp lib/libloader.so /usr/local/lib/libloader.so
	cp lib/libloader.h /usr/local/include/libloader.h

loading:
	clear
	g++ -Wall -o loading src/exp_loading_bar.cpp lib/libloader.cpp
	./loading

progress:
	clear
	g++ -Wall -o progress src/exp_progress_bar.cpp lib/libloader.cpp
	./progress

pingpong:
	clear
	g++ -Wall -o pingpong src/exp_pingpong_bar.cpp lib/libloader.cpp
	./pingpong
	
clean:
	rm -rf *.o *.so src/*.o src/*.so lib/*.o lib/*.so
	rm loading progress pingpong

# lib:
# 	g++ -c -Wall -Werror -fpic lib/libloader.cpp
# 	g++ -shared -o $(LIBa) $(LIBO)
# 	mkdir -p $(DESTDIR)$(PREFIX)/lib
# 	mkdir -p $(DESTDIR)$(PREFIX)/include
# 	cp $(LIBa) $(DESTDIR)$(PREFIX)/lib/$(LIBa)
# 	cp $(LIBH) $(DESTDIR)$(PREFIX)/include/

# %.o: %.cpp $(hdr_lib)
# 	$(CPP) $(CCFLAGS) -o $@ -c $<