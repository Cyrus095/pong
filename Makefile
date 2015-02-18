CC:= g++
CFLAGS:= -Wall -O3 -std=c++11 -pedantic -Wno-unused-result
LIBS:= -lm -lGL -L./lib -lsfml-system -lsfml-window -lGLEW
MKDIR:= mkdir -p
CPDIR:= cp -rf
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

.PHONY: all run install dump tar count clean distclean libclean tarclean

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

install:
	@echo "Downloading SFML..."
	@wget 'www.sfml-dev.org/files/SFML-2.2-linux-gcc-64-bit.tar.gz'
	@tar -zxvf SFML-2.2-linux-gcc-64-bit.tar.gz > /dev/null
	@$(CPDIR) SFML-2.2/include/SFML $(INCDIR)
	@$(CPDIR) SFML-2.2/lib $(LIBDIR)
	@$(RMDIR) SFML-2.2* > /dev/null
	@echo "Downloading GLEW..."
	@wget 'http://sourceforge.net/projects/glew/files/glew/1.12.0/glew-1.12.0.zip'
	@unzip glew-1.12.0.zip > /dev/null
	@echo "Building GLEW..."
	@cd glew-1.12.0 && make
	@$(CPDIR) glew-1.12.0/include/GL $(INCDIR)
	@$(CPDIR) glew-1.12.0/lib/* $(LIBDIR)
	@$(RMDIR) glew-1.12.0* > /dev/null
	@echo "Done!"

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

libclean:
	$(RMDIR) $(INCDIR)/GL $(INCDIR)/SFML $(LIBDIR)

tarclean:
	$(RM) $(TAR)
