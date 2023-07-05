miniclang: main.cpp source_location.pcm token.pcm lexer.pcm
	clang++ -std=c++20 main.cpp -fprebuilt-module-path=. -o miniclang.out

source_location.pcm: source_location.cpp
	clang++ -std=c++20 -x c++-module source_location.cpp --precompile -fprebuilt-module-path=. -o source_location.pcm

token.pcm: token.cpp source_location.pcm
	clang++ -std=c++20 -x c++-module token.cpp --precompile -fprebuilt-module-path=. -o token.pcm

lexer.pcm: lexer.cpp token.pcm source_location.pcm
	clang++ -std=c++20 -x c++-module lexer.cpp --precompile -fprebuilt-module-path=. -o lexer.pcm

.PHONY: clean
clean:
	rm -rf *.pcm *.out
