loading:
	clear
	g++ -o loading loadingBar.cpp
	./loading

progress:
	clear
	g++ -o progress progressBar.cpp
	./progress
	
clean:
	rm  loading progress 

