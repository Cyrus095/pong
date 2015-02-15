CC:= g++
CFLAGS:= -Wall -O3 -std=c++11 -pedantic -Wno-unused-result
LIBS:= -lm -lGL -L./lib -lsfml-system -lsfml-window -lGLEW
MKDIR:= mkdir -p
RMDIR:= rm -rf
RM:= rm -f
BINDIR:= bin
SRCDIR:= src
INCDIR:= include
LIBDIR:= lib
OBJDIR:= obj
DOCDIR:= doc
BIN:= Pong
SRC:= $(wildcard $(SRCDIR)/*.cpp)
OBJ:= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
INC:= -I$(INCDIR)
TAR:= $(BIN).tar.gz

.PHONY: all dump tar count clean distclean tarclean run

all: $(BINDIR)/$(BIN)

$(BINDIR)/$(BIN): $(OBJ) | $(BINDIR)
	$(CC) $^ $(LIBS) -o $@
	@echo "Generating C++ binary \033[1;32m"$@"\033[0m"

$(OBJ): | $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR) $(BINDIR):
	$(MKDIR) $@

run: all
	export LD_LIBRARY_PATH=./$(LIBDIR) && ./$(BINDIR)/$(BIN)

dump:
	@echo "src:" $(SRC)
	@echo "obj:" $(OBJ)

tar:
	$(MKDIR) $(BIN)
	cp -r $(INCDIR) $(SRCDIR) $(DOCDIR) $(LIBDIR) Makefile *.md $(BIN)
	tar -czf $(TAR) $(BIN)
	$(RMDIR) $(BIN)
	@echo "\033[1;32m" $(TAR) "\033[0mcreated successfully!"

count:
	wc -l $(SRCDIR)/* $(INCDIR)/*

clean:
	$(RMDIR) $(OBJDIR)

distclean: clean
	$(RMDIR) $(BINDIR)

tarclean:
	$(RM) $(TAR)
