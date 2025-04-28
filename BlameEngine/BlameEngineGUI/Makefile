#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# You will need SDL3 (http://www.libsdl.org) which is still unreleased/unpackaged.
<<<<<<< HEAD:BlameEngine/BlameEngineGUI/Makefile
=======
# Mac OS X:
#   brew install sdl3
>>>>>>> b3c96bde8c4e2ce0465d4c02d80f3d8173f2164c:examples/example_sdl3_vulkan/Makefile

#CXX = g++
#CXX = clang++

<<<<<<< HEAD:BlameEngine/BlameEngineGUI/Makefile
EXE = example_sdl3_sdlgpu3
IMGUI_DIR = ../..
SOURCES = main.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl3.cpp $(IMGUI_DIR)/backends/imgui_impl_sdlgpu3.cpp
=======
EXE = example_sdl3_vulkan
IMGUI_DIR = ../..
SOURCES = main.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl3.cpp $(IMGUI_DIR)/backends/imgui_impl_vulkan.cpp
>>>>>>> b3c96bde8c4e2ce0465d4c02d80f3d8173f2164c:examples/example_sdl3_vulkan/Makefile
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)

CXXFLAGS = -std=c++11 -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends
CXXFLAGS += -g -Wall -Wformat
LIBS =


##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
<<<<<<< HEAD:BlameEngine/BlameEngineGUI/Makefile
	LIBS += -ldl `pkg-config sdl3 --libs`

	CXXFLAGS += `pkg-config sdl3 --cflags`
=======
	LIBS += -ldl
	LIBS += `pkg-config --libs sdl3 vulkan`

	CXXFLAGS += `pkg-config --cflags sdl3 vulkan`
>>>>>>> b3c96bde8c4e2ce0465d4c02d80f3d8173f2164c:examples/example_sdl3_vulkan/Makefile
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
<<<<<<< HEAD:BlameEngine/BlameEngineGUI/Makefile
	LIBS += -framework Cocoa -framework IOKit -framework CoreVideo `pkg-config --libs sdl3`
	LIBS += -L/usr/local/lib -L/opt/local/lib

	CXXFLAGS += `pkg-config sdl3 --cflags`
=======
	LIBS += -framework Cocoa -framework IOKit -framework CoreVideo 
	LIBS += `pkg-config --libs sdl3 vulkan`
	LIBS += -L/usr/local/lib -L/opt/local/lib

	CXXFLAGS += `pkg-config --cflags sdl3 vulkan`
>>>>>>> b3c96bde8c4e2ce0465d4c02d80f3d8173f2164c:examples/example_sdl3_vulkan/Makefile
	CXXFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
<<<<<<< HEAD:BlameEngine/BlameEngineGUI/Makefile
	LIBS += -lgdi32 -limm32 `pkg-config --static --libs sdl3`

	CXXFLAGS += `pkg-config --cflags sdl3`
=======
	LIBS += -lgdi32 -limm32 `pkg-config --static --libs sdl3 vulkan`

	CXXFLAGS += `pkg-config --cflags sdl3 vulkan`
>>>>>>> b3c96bde8c4e2ce0465d4c02d80f3d8173f2164c:examples/example_sdl3_vulkan/Makefile
	CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o:$(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
