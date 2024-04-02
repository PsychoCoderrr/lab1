CFLAGS = -Wall -Wextra -Werror
SAN = -g -fsanitize=undefined
LIB_DIR = lib
OBJECT_DIR = object
EXECUTABLE = bin
OPTIM = -O0
LDFLAGS = -lreadline
CC = clang
all: SAN = 
all: EXECUTABLE := $(EXECUTABLE)_clean 
all: compile
debug: SAN = 
debug: EXECUTABLE := $(EXECUTABLE)_debug 
debug: CFLAGS = -g
debug: compile
asan: SAN := $(SAN),address
asan: EXECUTABLE := $(EXECUTABLE)_asan
asan: compile
msan: SAN := $(SAN),memory
msan: EXECUTABLE := $(EXECUTABLE)_msan
msan: compile

.PHONY: all compile preparation linker debug asan msan static clean formatting help 

$(OBJECT_DIR)/main.o: main.c $(LIB_DIR)/FieldInfo.h
	$(CC) -c $< -o $@ $(SAN) $(CFLAGS) $(OPTIM)

$(OBJECT_DIR)/vector.o: $(LIB_DIR)/vector.c $(LIB_DIR)/vector.h $(LIB_DIR)/FieldInfo.h
	$(CC) -c $< -o $@ $(SAN) $(CFLAGS) $(OPTIM)

$(OBJECT_DIR)/complex.o: $(LIB_DIR)/complex.c $(LIB_DIR)/complex.h $(LIB_DIR)/FieldInfo.h
	$(CC) -c $< -o $@ $(SAN) $(CFLAGS) $(OPTIM)

$(OBJECT_DIR)/number.o: $(LIB_DIR)/number.c $(LIB_DIR)/number.h $(LIB_DIR)/FieldInfo.h
	$(CC) -c $< -o $@ $(SAN) $(CFLAGS) $(OPTIM)

$(OBJECT_DIR)/tests.o: $(LIB_DIR)/tests.c $(LIB_DIR)/tests.h $(LIB_DIR)/FieldInfo.h
	$(CC) -c $< -o $@ $(SAN) $(CFLAGS) $(OPTIM)
	
compile: preparation linker
preparation:
	mkdir -p $(LIB_DIR)
	mkdir -p $(OBJECT_DIR)

linker: $(OBJECT_DIR)/main.o $(OBJECT_DIR)/vector.o $(OBJECT_DIR)/complex.o $(OBJECT_DIR)/number.o
	$(CC) $? -o $(EXECUTABLE) $(SAN) $(LDFLAGS) $(OPTIM)

static: 
	clang --analyze -Xanalyzer -analyzer-output=html *.c $(LIB_DIR)/*.c
formating:
	clang-format *.c -i -style=file
clean:
	rm -rf $(EXECUTABLE)* *plist $(OBJECT_DIR)/*.o
help:
	@echo "Available targets:"
	@echo "  all      : Build the executable with default settings"
	@echo "  linker  : Build the executable"
	@echo "  debug    : Build the executable with debugging information"
	@echo "  asan     : Build the executable with AddressSanitizer"
	@echo "  msan     : Build the executable with MemorySanitizer"
	@echo "  static   : Run static analysis and generate HTML reports"
	@echo "  clean    : Remove generated files"
	@echo "  formating: Format source code using clang-format"
	@echo "  help     : Display this help message"
	
