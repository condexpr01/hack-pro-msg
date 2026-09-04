
all: compile

t: compile run

compile:
	clang++ -std=c++26 -o promsg promsg.cpp

run:
	pid=$$(pgrep PROClient);\
	base=0x$$(grep 'GameAssembly' /proc/$$(pgrep PROClient)/maps | grep ' 00000000 ' | cut -d'-' -f1);\
	fallbackfile='/tmp/dump_addr';\
	listargs $${pid} $${base} $${fallbackfile};\
	./promsg $${pid} $${base} $${fallbackfile};


clean:
	-rm -r ./.cache
	-rm ./compile_commands.json
	-rm ./promsg
