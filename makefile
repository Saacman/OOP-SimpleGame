#
# MAKEFILE
#

PROGNAME = test
CPPFLAGS = -std=c++14 -Wall
OBJS  = main.o
OBJS += app.o
OBJS += window.o
OBJS += r_path.o
OBJS += gamestate.o
OBJS += fsm.o
OBJS += splashscreen.o
OBJS += animation.o
OBJS += player.o
# OBJS += collider.o
# OBJS += platform.o
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

gamestate: gamestate.cpp gamestate.hpp state.hpp
	g++ $(CPPFLAGS) -c gamestate.cpp

splashscreen: splashscreen.cpp splashscreen.hpp state.hpp
	g++ $(CPPFLAGS) -c splashscreen.cpp

fsm: fsm.cpp fsm.hpp
	g++ $(CPPFLAGS) -c fsm.cpp

animation: animation.cpp animation.hpp
	g++ $(CPPFLAGS) -c animation.cpp

player: player.cpp player.hpp
	g++ $(CPPFLAGS) -c player.cpp

# collider: collider.cpp collider.hpp
# 	g++ $(CPPFLAGS) -c collider.cpp
#
# platform: platform.cpp platform.hpp
# 	g++ $(CPPFLAGS) -c collider.cpp

main: main.cpp
	g++ $(CPPFLAGS) -c main.cpp

clean:
	-rm *.o
