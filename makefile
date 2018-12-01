#
# MAKEFILE
#

PROGNAME = test
CPPFLAGS = -std=c++14 -Wall
OBJS  = main.o
OBJS += app.o
OBJS += window.o
OBJS += r_path.o
OBJS += input.o
OBJS += bitmask.o
OBJS += gamestate.o
OBJS += fsm.o
OBJS += splashscreen.o
OBJS += playercontrol.o
OBJS += sprite.o
OBJS += entity.o
OBJS += transform.o
OBJS += collection.o
OBJS += frames.o
OBJS += animation.cpp
OBJS += -lsfml-graphics
OBJS += -lsfml-window
OBJS += -lsfml-system


all: $(OBJS)
	g++ $(CPPFLAGS) -o $(PROGNAME) $(OBJS)

app: app.cpp app.hpp
	g++ $(CPPFLAGS) -c app.cpp

window: window.cpp window.hpp
	g++ $(CPPFLAGS) -c window.cpp

r_path: r_path.cpp r_path.hpp
	g++ $(CPPFLAGS) -c r_path.cpp

input: input.cpp input.hpp
	g++ $(CPPFLAGS) -c input.cpp

bitmask: bitmask.cpp bitmask.hpp
	g++ $(CPPFLAGS) -c bitmask.cpp

gamestate: gamestate.cpp gamestate.hpp state.hpp
	g++ $(CPPFLAGS) -c gamestate.cpp

splashscreen: splashscreen.cpp splashscreen.hpp state.hpp
	g++ $(CPPFLAGS) -c splashscreen.cpp

playercontrol: playercontrol.cpp playercontrol.hpp component.hpp
	g++ $(CPPFLAGS) -c playercontrol.cpp

sprite: sprite.cpp sprite.hpp component.hpp
	g++ $(CPPFLAGS) -c sprite.cpp

transform: transform.cpp transform.hpp state.hpp
	g++ $(CPPFLAGS) -c transform.cpp

main: main.cpp
	g++ $(CPPFLAGS) -c main.cpp

fsm: fsm.cpp fsm.hpp
	g++ $(CPPFLAGS) -c fsm.cpp

entity: entity.cpp entity.hpp
	g++ $(CPPFLAGS) -c entity.cpp

collection: collection.cpp collection.hpp
	g++ $(CPPFLAGS) -c collection.cpp

frame: frames.cpp frames.hpp
	g++ $(CPPFLAGS) -c frames.cpp

animation: animation.cpp animation.hpp component.hpp
	g++ $(CPPFLAGS) -c animation.cpp

clean:
	-rm *.o
