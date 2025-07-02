#include <stdio.h>
#include <string.h>

#define max_alunos 5

float calcularMedia(float n1, float n2, float n3);

int main() {
    char nomes[max_alunos][50]; 
    float notas[max_alunos][3]; 
    float medias[max_alunos];  

    float maiorMedia;
    char nomeMaiorMedia[50];
    int i, j;

    printf("--- Cadastro de Notas da Turma ---\n\n");

    for (i = 0; i < max_alunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(nomes[i], 50, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = 0;

        printf("Digite as 3 notas do(a) %s (separadas por espaco): ", nomes[i]);
        scanf("%f %f %f", &notas[i][0], &notas[i][1], &notas[i][2]);

        while (getchar() != '\n');

        medias[i] = calcularMedia(notas[i][0], notas[i][1], notas[i][2]);
    }

    printf("\n\n--- Tabela de Resultados ---\n");
    printf("------------------------------------------------------------------\n");
    printf("%-20s %-7s %-7s %-7s %-7s %s\n", "Nome", "Nota 1", "Nota 2", "Nota 3", "Media", "Situacao");
    printf("------------------------------------------------------------------\n");

    for (i = 0; i < max_alunos; i++) {
        printf("%-20s %-7.1f %-7.1f %-7.1f %-7.1f ",
               nomes[i],
               notas[i][0],
               notas[i][1],
               notas[i][2],
               medias[i]);

        if (medias[i] >= 7.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
            strcpy(nomeMaiorMedia, nomes[i]);
        }
    }
    printf("------------------------------------------------------------------\n\n");

    printf("Aluno com a maior media da turma: %s (Media: %.1f)\n", nomeMaiorMedia, maiorMedia);

    return 0;
}

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}