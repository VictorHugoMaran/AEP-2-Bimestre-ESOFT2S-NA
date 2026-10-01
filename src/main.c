/* PSE em Acao - AEP 2026/2. Dados ficticios e coletivos; memoria volatil. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

#define MAX_ACOES 100
#define TEXTO 101
#define PLANEJADA 1
#define REALIZADA 2
#define CANCELADA 3

typedef struct {
    int codigo;
    char escola[TEXTO];
    char tema[TEXTO];
    char data[11];
    char publico[TEXTO];
    char responsavel[TEXTO];
    int prevista;
    int situacao;
    int efetiva;
} Acao;

/* Retorna 0 no fim da entrada, -1 se a linha nao couber e 1 no sucesso. */
int lerLinha(char texto[], size_t tamanho) {
    size_t n;
    int c;
    if (fgets(texto, (int)tamanho, stdin) == NULL) return 0;
    n = strlen(texto);
    if (n > 0 && texto[n - 1] == '\n') texto[--n] = '\0';
    else if (!feof(stdin)) {
        c = getchar();
        if (c != '\n' && c != EOF) {
            while ((c = getchar()) != '\n' && c != EOF) { }
            return -1;
        }
    }
    if (n > 0 && texto[n - 1] == '\r') texto[n - 1] = '\0';
    return 1;
}

void aparar(char texto[]) {
    size_t inicio = 0, fim = strlen(texto);
    while (texto[inicio] && isspace((unsigned char)texto[inicio])) inicio++;
    while (fim > inicio && isspace((unsigned char)texto[fim - 1])) fim--;
    memmove(texto, texto + inicio, fim - inicio);
    texto[fim - inicio] = '\0';
}

int lerTexto(const char *mensagem, char destino[], size_t tamanho) {
    int resultado;
    for (;;) {
        printf("%s", mensagem);
        fflush(stdout);
        resultado = lerLinha(destino, tamanho);
        if (resultado == 0) return 0;
        if (resultado == -1) {
            printf("Erro: texto muito longo. Limite: %zu bytes.\n", tamanho - 1);
            continue;
        }
        aparar(destino);
        if (destino[0] == '\0') puts("Erro: campo obrigatorio vazio.");
        else return 1;
    }
}

int lerInteiro(const char *mensagem, int minimo, int maximo, int *valor) {
    char linha[80], *fim;
    long numero;
    for (;;) {
        if (!lerTexto(mensagem, linha, sizeof linha)) return 0;
        errno = 0;
        numero = strtol(linha, &fim, 10);
        if (errno == ERANGE || *fim != '\0' || numero < minimo || numero > maximo) {
            printf("Erro: informe um inteiro entre %d e %d.\n", minimo, maximo);
        } else {
            *valor = (int)numero;
            return 1;
        }
    }
}

int dataValida(const char *data) {
    int dia, mes, ano, diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    size_t i;
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') return 0;
    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i])) return 0;
    }
    dia = (data[0] - '0') * 10 + data[1] - '0';
    mes = (data[3] - '0') * 10 + data[4] - '0';
    ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 +
          (data[8] - '0') * 10 + data[9] - '0';
    if (ano < 1 || mes < 1 || mes > 12) return 0;
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) diasMes[1] = 29;
    return dia >= 1 && dia <= diasMes[mes - 1];
}

int buscarCodigo(const Acao acoes[], int quantidade, int codigo) {
    int i;
    for (i = 0; i < quantidade; i++) if (acoes[i].codigo == codigo) return i;
    return -1;
}

const char *nomeSituacao(int situacao) {
    switch (situacao) {
        case PLANEJADA: return "Planejada";
        case REALIZADA: return "Realizada";
        case CANCELADA: return "Cancelada";
        default: return "Desconhecida";
    }
}

void armazenarAcao(Acao acoes[], int *quantidade, Acao nova) {
    acoes[*quantidade] = nova;
    (*quantidade)++;
}

int cadastrarAcao(Acao acoes[], int *quantidade) {
    Acao nova = {0};
    if (*quantidade >= MAX_ACOES) {
        puts("Limite de armazenamento atingido (100 acoes). Cadastro nao iniciado.");
        return 1;
    }
    puts("\n--- CADASTRAR ACAO ---");
    do {
        if (!lerInteiro("Codigo (positivo): ", 1, INT_MAX, &nova.codigo)) return 0;
        if (buscarCodigo(acoes, *quantidade, nova.codigo) == -1) break;
        puts("Erro: codigo ja cadastrado. Informe outro codigo.");
    } while (1);
    if (!lerTexto("Escola: ", nova.escola, sizeof nova.escola)) return 0;
    if (!lerTexto("Tema: ", nova.tema, sizeof nova.tema)) return 0;
    do {
        if (!lerTexto("Data prevista (DD/MM/AAAA): ", nova.data, sizeof nova.data)) return 0;
        if (dataValida(nova.data)) break;
        puts("Erro: data invalida. Use DD/MM/AAAA e uma data existente.");
    } while (1);
    if (!lerTexto("Publico-alvo (coletivo): ", nova.publico, sizeof nova.publico)) return 0;
    if (!lerTexto("Responsavel (ficticio): ", nova.responsavel, sizeof nova.responsavel)) return 0;
    if (!lerInteiro("Participantes previstos: ", 0, INT_MAX, &nova.prevista)) return 0;
    if (!lerInteiro("Situacao [1 Planejada / 2 Realizada / 3 Cancelada]: ", 1, 3, &nova.situacao)) return 0;
    if (nova.situacao == REALIZADA) {
        if (!lerInteiro("Participantes efetivos: ", 0, INT_MAX, &nova.efetiva)) return 0;
    }
    armazenarAcao(acoes, quantidade, nova);
    puts("Sucesso: acao cadastrada. Retornando ao menu.");
    return 1;
}

void exibirAcao(const Acao *acao) {
    puts("------------------------------------------------------------");
    printf("Codigo: %d | Situacao: %s\n", acao->codigo, nomeSituacao(acao->situacao));
    printf("Escola: %s\nTema: %s\nData prevista: %s\n", acao->escola, acao->tema, acao->data);
    printf("Publico-alvo: %s\nResponsavel: %s\n", acao->publico, acao->responsavel);
    printf("Previstos: %d | Efetivos: %d\n", acao->prevista, acao->efetiva);
}

void listarAcoes(const Acao acoes[], int quantidade) {
    int i;
    if (quantidade == 0) { puts("Nenhuma acao cadastrada."); return; }
    printf("\n--- LISTAGEM: %d ACAO(OES) ---\n", quantidade);
    for (i = 0; i < quantidade; i++) exibirAcao(&acoes[i]);
}

/* Busca parcial; ignora caixa nas letras ASCII. Acentos devem coincidir. */
int contemTexto(const char texto[], const char termo[]) {
    size_t i, j;
    for (i = 0; texto[i]; i++) {
        for (j = 0; termo[j] && texto[i + j]; j++) {
            if (tolower((unsigned char)texto[i + j]) != tolower((unsigned char)termo[j])) break;
        }
        if (termo[j] == '\0') return 1;
    }
    return 0;
}

int pesquisarAcoes(const Acao acoes[], int quantidade) {
    int tipo, codigo, i, encontrados = 0;
    char termo[TEXTO];
    if (quantidade == 0) { puts("Nenhuma acao cadastrada."); return 1; }
    if (!lerInteiro("Pesquisar [1 Codigo / 2 Escola / 3 Tema]: ", 1, 3, &tipo)) return 0;
    if (tipo == 1) {
        if (!lerInteiro("Codigo: ", 1, INT_MAX, &codigo)) return 0;
        i = buscarCodigo(acoes, quantidade, codigo);
        if (i >= 0) { exibirAcao(&acoes[i]); encontrados = 1; }
    } else {
        if (!lerTexto("Termo da pesquisa: ", termo, sizeof termo)) return 0;
        for (i = 0; i < quantidade; i++) {
            if (contemTexto(tipo == 2 ? acoes[i].escola : acoes[i].tema, termo)) {
                exibirAcao(&acoes[i]); encontrados++;
            }
        }
    }
    if (!encontrados) puts("Nenhuma acao encontrada.");
    else printf("Encontradas: %d acao(oes).\n", encontrados);
    return 1;
}

int atualizarSituacao(Acao acoes[], int quantidade) {
    int codigo, indice, situacao, efetiva = 0;
    if (quantidade == 0) { puts("Nenhuma acao cadastrada."); return 1; }
    if (!lerInteiro("Codigo para atualizar: ", 1, INT_MAX, &codigo)) return 0;
    indice = buscarCodigo(acoes, quantidade, codigo);
    if (indice == -1) { puts("Registro inexistente."); return 1; }
    exibirAcao(&acoes[indice]);
    if (!lerInteiro("Nova situacao [1 Planejada / 2 Realizada / 3 Cancelada]: ", 1, 3, &situacao)) return 0;
    if (situacao == REALIZADA) {
        if (!lerInteiro("Participantes efetivos: ", 0, INT_MAX, &efetiva)) return 0;
    }
    /* Confirma os dois valores juntos; falha na entrada nao altera o registro. */
    acoes[indice].situacao = situacao;
    acoes[indice].efetiva = efetiva;
    puts("Sucesso: situacao atualizada. Fora de Realizada, efetivos ficam em zero.");
    return 1;
}

void gerarResumo(const Acao acoes[], int quantidade) {
    int i, planejadas = 0, realizadas = 0, canceladas = 0;
    long long previstosGeral = 0, previstosRealizadas = 0, efetivos = 0;
    for (i = 0; i < quantidade; i++) {
        previstosGeral += acoes[i].prevista;
        switch (acoes[i].situacao) {
            case PLANEJADA: planejadas++; break;
            case REALIZADA:
                realizadas++;
                previstosRealizadas += acoes[i].prevista;
                efetivos += acoes[i].efetiva;
                break;
            case CANCELADA: canceladas++; break;
        }
    }
    puts("\n--- RESUMO GERAL ---");
    printf("Acoes cadastradas: %d\n", quantidade);
    printf("Planejadas: %d | Realizadas: %d | Canceladas: %d\n", planejadas, realizadas, canceladas);
    printf("Previstos em todas as acoes: %lld\n", previstosGeral);
    printf("Previstos nas realizadas: %lld\n", previstosRealizadas);
    printf("Total de participacoes efetivas: %lld\n", efetivos);
    if (previstosRealizadas == 0) puts("Participacao nas realizadas: N/A (previsao igual a zero).");
    else printf("Participacao nas realizadas: %.2f%%\n", 100.0 * (double)efetivos / (double)previstosRealizadas);
    puts("Participacoes acumuladas; nao representam estudantes unicos.");
}

void exibirMenu(void) {
    puts("\n========== PSE EM ACAO ==========\n"
         "1 - Cadastrar acao\n2 - Listar acoes\n3 - Pesquisar acao\n"
         "4 - Atualizar situacao\n5 - Gerar resumo geral\n6 - Sair");
}

int main(void) {
    Acao acoes[MAX_ACOES];
    int quantidade = 0, opcao = 0, entradaAberta = 1;
    puts("PSE em Acao | IntegraPSE | Versao academica 2026/2\n"
         "Use somente dados ficticios e coletivos.\n"
         "Os dados ficam em memoria e serao perdidos ao encerrar.");
    do {
        exibirMenu();
        if (!lerInteiro("Opcao: ", 1, 6, &opcao)) { entradaAberta = 0; break; }
        switch (opcao) {
            case 1: entradaAberta = cadastrarAcao(acoes, &quantidade); break;
            case 2: listarAcoes(acoes, quantidade); break;
            case 3: entradaAberta = pesquisarAcoes(acoes, quantidade); break;
            case 4: entradaAberta = atualizarSituacao(acoes, quantidade); break;
            case 5: gerarResumo(acoes, quantidade); break;
            case 6: puts("Encerrando o sistema. Dados em memoria descartados."); break;
        }
    } while (opcao != 6 && entradaAberta);
    if (!entradaAberta) puts("\nEntrada encerrada (EOF). Operacao incompleta nao confirmada; sistema encerrado.");
    return 0;
}
