CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17

GCOVFLAGS = --coverage
SRC = $(wildcard model/*.cc controller/*.cc)
OBJS = $(SRC:.cc=.o)

LIBS= -lgtest -lm

all: 
	make uninstall
	make clean 
	make install 
	make dist
	make gcov_report
	make run

install: app_folder
	cd view && qmake6 && make && make clean && rm -f Makefile && rm -f .qmake.stash && mv 3DViewer ../../app/

run:
	../app/3DViewer

uninstall:
	rm -rf ../app
	rm -f ../dist.tar


dvi:
	open dvi.html

dist:
	mkdir -p ../dist
	cp ../app/3DViewer ../dist/3DViewer
	cp dvi.html ../dist/dvi.html
	cd .. && tar -cf dist.tar dist && rm -rf dist



tests: $(OBJS)
	$(CXX) $(CXXFLAGS) tests/test.cc $^ -o viewer_test $(LIBS)
	./viewer_test

gcov_report: clean
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $(SRC) tests/test.cc -o viewer_test $(LIBS)
	./viewer_test
	lcov -t "Report" -o report.info --no-external -c -d .
	genhtml -o report/ report.info
	rm -rf *.gcno *.gcov *.gcda *.info *.a tests/*.o
	open ./report/index.html

clean:
	rm -rf viewer_test *.gcno *.gcda **/*.o report

app_folder:
	mkdir -p ../app

clang:
	clang-format -style=Google -n ./**/*.cc
