.PHONY: clean
.SUFFIXES: .cpp .o
CXX := g++
CXXFLAGS :=
LINKFLAGS := -lSDL2 -lSDL2_image
EXEC := main
OBJS := main.o Sprite.o AnimatedSprite.o ExampleAnim.o
Sprite := Sprite.cpp Sprite.h
AnimatedSprite := AnimatedSprite.cpp AnimatedSprite.h
ExampleAnim := ExampleAnim.cpp ExampleAnim.h
ALL := $(Sprite) $(AnimatedSprite) $(ExampleAnim)

ifeq ($(OS),Windows_NT)
	CXXFLAGS += -Iinclude -Llib
	LINKFLAGS := -lmingw32 -lSDL2main $(LINKFLAGS)
else
	#NOTHING
endif

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LINKFLAGS) -o $(EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

#Files to be compiled
main.o: main.cpp $(ALL)
Sprite.o: $(Sprite)
AnimatedSprite.o: $(AnimatedSprite) $(Sprite)
ExampleAnim.o: $(ExampleAnim) $(AnimatedSprite) $(Sprite)

clean:
	rm *.o 
