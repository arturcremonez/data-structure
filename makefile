OBJECTS = src/main.o src/parameter_manager.o src/file_manager.o src/list.o

ted: $(OBJECTS)
	gcc $(OBJECTS) -std=c99 -fstack-protector-all -g -lm -o ted

clean:
	rm src/*.o

run:
	./ted -e bed/ -f casa-campo.geo -q 003-ups.qry -o bsd/ -fd 0.8

all:
	make ted
	make clean
	make run
