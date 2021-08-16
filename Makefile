game:main.o game.o ProBar.o
		gcc $^ -o $@
%.o:%.s
		gcc -c $<
%.s:%.i
		gcc -S $<
%.i:%.c
		gcc -E $<

.PHONY:
clean:
		rm -f *.o game

