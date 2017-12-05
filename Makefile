loading:
	clear
	g++ -o loading loadingBar.cpp
	./loading

progress:
	clear
	g++ -o progress progressBar.cpp
	./progress

pingpong:
	clear
	g++ -o pingpong pingpongBar.cpp
	./pingpong

libraryMaker:
	g++ -shared -fPIC -o libmultibar.so multibar.cpp
	
clean:
	rm loading progress pingpong

