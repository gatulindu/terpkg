all:
	gcc src/main.c src/terpkg.c -o terpkg
install:
	mv terpkg /usr/local/bin
