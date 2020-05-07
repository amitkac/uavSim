TARGET_EXEC = uavSim

CC=gcc
CXX = g++
RM=rm -f

CPPFLAGS = -g
LDLIBS= -lSDL2 -lSDL2_image
SRCS= main.cpp Sim.cpp TextManager.cpp uavObject.cpp Map.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(TARGET_EXEC)


$(TARGET_EXEC):$(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(TARGET_EXEC) $(OBJS) $(LDLIBS)
	$(info successfully compiled)$

clean:
	$(RM) $(OBJS)

cleanall: clean
	$(RM) $(TARGET_EXEC)

