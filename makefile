CXX := g++
CPP_FLAGS := -Werror -W -Wall -Wextra -pedantic -std=c++20

# Lib Naming
TARGET_NAME := libUtils
TARGET_LIB := $(TARGET_NAME).a
LIB_INC := $(TARGET_NAME).h

# Lib Project Files
LIB_DIR := lib
SRC_DIR := src

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:.cpp=.o)
INC_FLAGS := $(addprefix -I,$(sort $(dir $(SRCS))))

# Debug Settings
DBGLIB = $(LIB_DIR)/$(TARGET_NAME)_debug.a
DBGOBJS = $(addprefix $(LIB_DIR)/dbg/,$(OBJS))
DBGCXXFLAGS = $(INC_FLAGS) -g -O0 -DDEBUG

# Release Settings
RELLIB = $(LIB_DIR)/$(TARGET_LIB)
RELOBJS = $(addprefix $(LIB_DIR)/,$(OBJS))
RELCXXFLAGS = $(INC_FLAGS) -O3 -DNDEBUG

# Debug Lib Build
dbg: $(DBGLIB)

$(DBGLIB): $(DBGOBJS)
	$(info Building debug library...)
	ar rcs $@ $^

$(LIB_DIR)/dbg/%.o: %.cpp
	$(info Building debug objects...)
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(DBGCXXFLAGS) $(INCFLAGS) $< -o $@

# Release Lib Build
rel: $(RELLIB)

$(RELLIB): $(RELOBJS)
	$(info Building release library...)
	ar rcs $@ $^

$(LIB_DIR)/%.o: %.cpp
	$(info Building release objects...)
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(RELCXXFLAGS) $(INCFLAGS) $< -o $@

# Test Naming
TST_NAME := UtilsLibTest

# Test Project Files
TST_DIR := build
TSRC_DIR := test

LIB_DIRS := lib/
LIBS = -lUtils
LDFLAGS = $(addprefix -L,$(LIB_DIRS)) $(LIBS)

TSRCS := $(shell find $(TSRC_DIR) -name '*.cpp')
TOBJS := $(TSRCS:.cpp=.o)
TINC_FLAGS := $(addprefix -I,$(sort $(dir $(TSRCS)))) -I$(SRC_DIR)/

# Debug Settings
TDBGEXE = $(TST_DIR)/$(TST_NAME)_debug
TDBGOBJS = $(addprefix $(TST_DIR)/dbg/,$(TOBJS))
TDBGCXXFLAGS = $(TINC_FLAGS) -g -O0 -DDEBUG

# Release Settings
TRELEXE = $(TST_DIR)/$(TST_NAME)
TRELOBJS = $(addprefix $(TST_DIR)/,$(TOBJS))
TRELCXXFLAGS = $(TINC_FLAGS) -O3 -DNDEBUG

# Debug Test Build
tstdbg: $(TDBGEXE)

$(TDBGEXE): $(TDBGOBJS)
	$(info Building debug tests...)
	$(CXX) $(CXXFLAGS) $(TDBGCXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TST_DIR)/%.o: %.cpp
	$(info Building debug test objects...)
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(TDBGCXXFLAGS) -o $@ $<

# Release Test Build
tst: $(TRELEXE)

$(TRELEXE): $(TRELOBJS)
	$(info Building tests...)
	$(CXX) $(CXXFLAGS) $(TRELCXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TST_DIR)/%.o: %.cpp
	$(info Building test objects...)
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(TRELCXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -r $(LIB_DIR)
	rm -r $(TST_DIR)
