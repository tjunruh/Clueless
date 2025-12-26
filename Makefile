
CXX := g++

EXECUTABLE ?= clueless

SRC_DIR ?= Code
BLD_DIR ?= build
ASCII_ENGINE_DIR ?= ASCII_Board_Game_Engine_v3.4.0-alpha
INC_DIR := $(shell find $(SRC_DIR) -type d)

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:%=$(BLD_DIR)/%.o)
DEPS := $(OCJS:.o=.d)

LDFLAGS := -lncurses -L external_libraries/$(ASCII_ENGINE_DIR)/Linux/ -lascii_engine
INC_FLAGS := $(addprefix -I,$(INC_DIR))
CXXFLAGS := -std=c++17 -O2 $(INC_FLAGS) -Wall -MMD -MP -I external_libraries/$(ASCII_ENGINE_DIR)/Linux/headers

.PHONY: all clean

OUT := clueless

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	mkdir -p $(BLD_DIR)/bin
	mv $(EXECUTABLE) $(BLD_DIR)/bin
	cp external_libraries/$(ASCII_ENGINE_DIR)/Linux/libascii_engine.so $(BLD_DIR)/bin
	cp -r board_configs $(BLD_DIR)/bin
	rm -rf $(BLD_DIR)/Code
	cp Clueless.sh $(BLD_DIR)

$(BLD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -r $(BLD_DIR)

-include $(DEPS)