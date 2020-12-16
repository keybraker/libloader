DESTDIR = /tmp/stage
PREFIX = /usr/local

CPP = g++
CCFLAGS = -O3 -pedantic -Wall -Wextra -std=c++1z -c
CCLINK = -I/usr/local/include -L/usr/local/lib -libloader

cnm_lib = -o libloader.so
cnm_loading = -o loading
cnm_progress = -o progress
cnm_pingpong = -o pingpong

obj_loading = src/loading.o
obj_progress = src/progress.o
obj_pingpong = src/pingpong.o

obs_lib = libloader.so
obj_lib = lib/libloader.o
hdr_lib = lib/libloader.h

all: lib

lib: $(obj_lib)
	g++ -shared $(obj_lib) $(cnm_lib)
	mkdir -p /usr/local/lib
	mkdir -p /usr/local/include
	cp $(obs_lib) /usr/local/lib/$(obs_lib)
	cp $(hdr_lib) /usr/local/include/

loading:
# 	# clear
	$(CPP) $(cnm_loading) $(CCLINK)
	./loading

# progress:
# 	# clear
# 	$(CPP) $(CCFLAGS) $(cnm_lib) $(obj_lib)
# 	$(LIBO) $(OBJ_MDRZ)
# 	g++ -o progress src/exp_progress_bar.cpp
# 	./progress

# pingpong:
# 	# clear
# 	$(CPP) $(CCFLAGS) $(cnm_lib) $(obj_lib)
# 	$(LIBO) $(OBJ_MDRZ)
# 	g++ -o pingpong src/exp_pingpong_bar.cpp
# 	./pingpong
	
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

%.o: %.cpp $(hdr_lib)
	$(CPP) $(CCFLAGS) -o $@ -c $<