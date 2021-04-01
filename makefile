all:
		gcc 3-sat.c main.c -o main
run:
		./main
clean:
		rm main
random:
		gcc gerarId.c -o id