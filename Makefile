# Makefile для проекта обработки данных о странах

country_filter: obj/main.o obj/country.o obj/file_handler.o
	gcc -o bin/country_filter obj/main.o obj/country.o obj/file_handler.o

obj/main.o: src/main.c include/country.h include/file_handler.h
	gcc -c src/main.c -o obj/main.o

obj/country.o: src/country.c include/country.h
	gcc -c src/country.c -o obj/country.o

obj/file_handler.o: src/file_handler.c include/file_handler.h
	gcc -c src/file_handler.c -o obj/file_handler.o

clean:
	rm -f obj/*.o bin/country_filter

.PHONY: clean

