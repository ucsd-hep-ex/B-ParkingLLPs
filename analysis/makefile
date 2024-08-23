ROOTFLAGS=`root-config --cflags --libs` 
CXXDEPFLAGS = -MMD -MP -I$(shell pwd)/include

APPDIR = $(shell pwd)/app

all: main

main:  ${APPDIR}/cJSON.o\
       ${APPDIR}/analyzer_base.o\
       ${APPDIR}/analyzer_config.o\
       ${APPDIR}/analyzer_objects.o\
       ${APPDIR}/analyzer_tree.o\
       ${APPDIR}/analyzer_histograms.o\
       ${APPDIR}/analyzer.o \
       ${APPDIR}/CommandLineInput.o\
       main.C 
	g++ --std=c++11 $^ -o RunAnalyzer.exe ${ROOTFLAGS} ${CXXDEPFLAGS}

# Compile rule for .c files
${APPDIR}/%.o: ${APPDIR}/%.c
	gcc -c $< -o $@ -I$(shell pwd)/include


# Compile rule for .C files
${APPDIR}/%.o: ${APPDIR}/%.C
	g++ --std=c++11 -c $< -o $@ ${ROOTFLAGS} ${CXXDEPFLAGS}

clean:
	rm -f  *.{o,d,exe}
	rm -f  ${APPDIR}/*.{o,d,exe}
