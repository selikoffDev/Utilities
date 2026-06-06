CXX := g++
CXXFLAGS := -Werror -W -Wall -Wextra -pedantic -std=c++20

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

# Release Settings
RELLIB = $(LIB_DIR)/$(TARGET_LIB)
RELOBJS = $(addprefix $(LIB_DIR)/,$(OBJS))
RELCXXFLAGS = $(INC_FLAGS) -O3 -DNDEBUG

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

# Release Settings
TRELEXE = $(TST_DIR)/$(TST_NAME)
TRELOBJS = $(addprefix $(TST_DIR)/,$(TOBJS))
TRELCXXFLAGS = $(TINC_FLAGS) -O3 -DNDEBUG
$(info $(TSRCS))

# Release Test Build
tst: $(TRELEXE)

$(TRELEXE): $(TRELOBJS)
	$(info Building tests...)
	$(CXX) $(TRELCXXFLAGS) $(TRELCXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TST_DIR)/%.o: %.cpp
	$(info Building test objects...)
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(TRELCXXFLAGS) -o $@ $<

.PHONY: clean, all, remake
clean:
	rm -r $(LIB_DIR)
	rm -r $(TST_DIR)

all: rel tst
remake: clean rel tst
