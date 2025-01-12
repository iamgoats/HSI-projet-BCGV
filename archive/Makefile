LIB_DIR = .
APP_DIR = .

.PHONY: lib
lib:
	$(MAKE) -C $(LIB_DIR) -f Makefile.lib

.PHONY: app
app:
	$(MAKE) -C $(APP_DIR) -f Makefile.app

.PHONY: all
all: lib app

.PHONY: clean
clean:
	$(MAKE) -C $(LIB_DIR) -f Makefile.lib clean
	$(MAKE) -C $(APP_DIR) -f Makefile.app clean
