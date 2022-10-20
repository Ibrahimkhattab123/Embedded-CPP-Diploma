#Compiler
CXX = g++

#Source files liste
LINKED_LIST := LINKEDLISTNODE.cpp
LIST := LIST.cpp


APP_FILE := ./linkedlistapp.cpp

#Program excecutable file
LISTAPP_EXE = test



build_app: build_list build_linked_list build_main
	g++ build_main build_list build_linked_list -o $(LISTAPP_EXE)

build_main: $(APP_FILE)
	g++ -c $(APP_FILE)

build_list: $(LIST)
	g++ -c $(LIST) 

build_linked_list: $(LINKED_LIST)
	g++ -c $(LINKED_LIST) 

clean:
	rm *.exe 