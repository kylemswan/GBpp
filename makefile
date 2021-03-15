# environment configuration
EXE := gbpp
SRCDIR := source
INCDIR := include
BLDDIR := build

# compiler configuration
CXX := g++
CXXFLAGS := -g -Wall -MMD -I$(INCDIR)

# link required SFML libraries
LDLIBS := -lsfml-system -lsfml-window -lsfml-graphics

# all directories / modules containing source files
DIRS := source source/cpu

# find source files and generate the corresponding object and dependency names
SRCS := $(foreach DIR, $(DIRS), $(notdir $(wildcard $(DIR)/*.cpp)))
OBJS := $(patsubst %.cpp, build/%.o, $(SRCS))
DEPS := $(wildcard build/*.d)

# set VPATH so that source files are found in their (sub) directories
VPATH := $(DIRS)

# compilation and linking targets
$(EXE): $(OBJS)
	$(CXX) $^ -o $@ $(LDLIBS)

$(BLDDIR)/%.o: %.cpp | $(BLDDIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) 

$(BLDDIR):
	mkdir $@

include $(DEPS)

# utility targets
clean:
	rm -rf $(BLDDIR)

remove:
	rm -f $(EXE)
