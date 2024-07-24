TARGET=add-nbo

all: $(TARGET)

$(TARGET): main.c
	gcc -o $(TARGET) main.c

clean:
	rm -f $(TARGET)

