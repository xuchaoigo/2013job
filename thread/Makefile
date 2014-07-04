TARGET = test 

OBJS = pthread.o 

all:$(TARGET)

CC = gcc -lpthread

CFLAGS = -Wall -MD

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o *.d $(TARGET)
	





