TARGET := Utilities

CXX := g++

BUILD_DIR := lib

SRC_DIRS := src
INCL_DIRS := include

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%)
OBJS := $(OBJS:.cpp=.o)

INC_FLAGS := $(addprefix -I,$(INCL_DIRS))
CPP_FLAGS := $(INC_FLAGS) -Werror

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LD_FLAGS)

$(BUILD_DIR)/%.o: %.cpp 
	mkdir -p $(dir $@)
	$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
