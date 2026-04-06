CXX = g++
CXXFLAGS = -g -Wall -std=c++17
BIN_DIR = bin

OBJS = $(BIN_DIR)/driver.o $(BIN_DIR)/book.o $(BIN_DIR)/txt_parser.o
TARGET = driver

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/driver.o: driver.cpp book.h txt_parser.h parser.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c driver.cpp -o $@

$(BIN_DIR)/book.o: book.cpp book.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c book.cpp -o $@

$(BIN_DIR)/txt_parser.o: txt_parser.cpp txt_parser.h parser.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c txt_parser.cpp -o $@