ROOTFLAGS=`root-config --cflags --libs` 
CXXDEPFLAGS = -MMD -MP

all: main

main:  analyzer_base.o\
       analyzer_config.o\
       analyzer_objects.o\
       analyzer_selections.o\
       analyzer_histograms.o\
       analyzer.o \
       main.C 
	g++ --std=c++11 $^ -o Run.exe ${ROOTFLAGS} ${CXXDEPFLAGS}

%.o: %.C  
	g++ --std=c++11 -c $^ -o $@ ${ROOTFLAGS} ${CXXDEPFLAGS} 

clean:
	rm -f  *.{o,d,exe}
