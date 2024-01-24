CXX = g++
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,obj/%.o,$(SRCS))

alpha_blender : obj $(OBJS) main.cpp 
	@echo "\n****** Building alpha_blender ******\n"
	@$(CXX) $(CXXFLAGS) $(OBJS)  main.cpp -o $@ `pkg-config --cflags --libs opencv4`

obj : 
	@echo "\n****** Creating obj directory ******\n"
	@mkdir  obj
	@mkdir result

obj/%.o : src/%.cpp
	@echo "\n****** Creating $@ file from $< ******\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ `pkg-config --cflags --libs opencv4`

clean :
	@echo "\n****** Cleaning up ******\n"
	@rm -rf alpha_blender obj result