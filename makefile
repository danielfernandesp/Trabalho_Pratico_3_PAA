all: src/main.c src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c src/sources/frequencia.c
	gcc src/main.c -o EXEC src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c src/sources/frequencia.c
run: EXEC
	./EXEC