all:
	clang++ -std=c++26 -o promsg promsg.cpp

run:
	-listargs $$(pgrep PROClient) 0x$$(grep 'GameAssembly' /proc/$$(pgrep PROClient)/maps | grep ' 00000000 ' | cut -d'-' -f1)
	./promsg $$(pgrep PROClient) 0x$$(grep 'GameAssembly' /proc/$$(pgrep PROClient)/maps | grep ' 00000000 ' | cut -d'-' -f1)

t:
	clang++ -std=c++26 -o promsg promsg.cpp
	-listargs $$(pgrep PROClient) 0x$$(grep 'GameAssembly' /proc/$$(pgrep PROClient)/maps | grep ' 00000000 ' | cut -d'-' -f1)
	./promsg $$(pgrep PROClient) 0x$$(grep 'GameAssembly' /proc/$$(pgrep PROClient)/maps | grep ' 00000000 ' | cut -d'-' -f1)

clean:
	-rm -r ./.cache
	-rm ./compile_commands.json
	-rm ./promsg
