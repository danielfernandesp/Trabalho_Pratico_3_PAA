all: src/main.c src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c
	gcc src/main.c -o EXEC src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c
run: EXEC
	./EXEC