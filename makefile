all: src/main.c src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c src/sources/frequencia.c src/sources/shiftAnd.c
	gcc src/main.c -o EXEC src/sources/shiftAndAproximado.c src/sources/leituraArquivo.c src/sources/frequencia.c src/sources/shiftAnd.c
run: EXEC
	./EXEC