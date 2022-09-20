LCPP=clang++
ICPP=icpc
GCPP=g++

WFLAGS=-Wall -Wextra -pedantic

CFLAGS=-g3 -std=c++11

OFLAGS=-march=native -mavx2 -Ofast -ffast-math

INCLUDES=-I/usr/include/opencv4

LIBS=-lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_imgproc

all: gcc icc lcc

gcc:
	$(GCPP) $(CFLAGS) $(OFLAGS) $(INCLUDES) filter_cv.cpp $(LIBS) -o filter_cv_$@

s:
	$(GCPP) -S $(CFLAGS) $(OFLAGS) $(INCLUDES) filter_cv.cpp $(LIBS)

icc:
	$(ICPP) $(CFLAGS) $(OFLAGS) $(INCLUDES) filter_cv.cpp $(LIBS) -o filter_cv_$@

lcc:
	$(LCPP) $(CFLAGS) $(OFLAGS) $(INCLUDES) filter_cv.cpp $(LIBS) -o filter_cv_$@

clean: 
	rm -f *~ *.s filter_cv_*
