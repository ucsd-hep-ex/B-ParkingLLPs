ROOTFLAGS=`root-config --cflags --libs` 
CXXDEPFLAGS = -MMD -MP 

all: main

main:  fakeRate.o\
       CommandLineInput.o\
       main.C 
	g++ --std=c++11 $^ -o RunfakeRate.exe ${ROOTFLAGS} ${CXXDEPFLAGS}

%.o: %.C  
	g++ --std=c++11 -c $^ -o $@ ${ROOTFLAGS} ${CXXDEPFLAGS} 

clean:
	rm -f  *.{o,d,exe,pdf,png}
