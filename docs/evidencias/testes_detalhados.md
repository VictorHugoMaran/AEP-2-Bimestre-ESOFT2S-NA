# Registro detalhado dos testes - revisão 2

Execução UTC: 2026-10-13T17:17:50.289057+00:00

SHA-256 de src/main.c: `8c1d267b726897218db5d11f947a134a012d9302f22c0bd45125ce88d35486fe`

Ambiente: Linux-6.18.44-x86_64-with-glibc2.39

Compilador: gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0

Testes automáticos opcionais; esta execução não comprova uso do Dev-C++.

## T01 - Base vazia: listar, pesquisar, atualizar e resumir

Entrada integral: [T01_entrada.txt](T01_entrada.txt)

Saída integral observada: [T01_saida.txt](T01_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Nenhuma acao cadastrada.
Acoes cadastradas: 0
N/A
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {'Nenhuma acao cadastrada.': 3}; observadas: {'Nenhuma acao cadastrada.': 3}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T02 - Cadastro planejado e listagem completa

Entrada integral: [T02_entrada.txt](T02_entrada.txt)

Saída integral observada: [T02_saida.txt](T02_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Codigo: 101 | Situacao: Planejada
Publico-alvo: Turmas do 6 ano
Previstos: 40 | Efetivos: 0
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T03 - Cadastro realizado solicita efetivos

Entrada integral: [T03_entrada.txt](T03_entrada.txt)

Saída integral observada: [T03_saida.txt](T03_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Realizadas: 1
Total de participacoes efetivas: 32
80.00%
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T04 - Cadastro cancelado zera efetivos

Entrada integral: [T04_entrada.txt](T04_entrada.txt)

Saída integral observada: [T04_saida.txt](T04_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Situacao: Cancelada
Efetivos: 0
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T05 - Codigo duplicado exige outro identificador

Entrada integral: [T05_entrada.txt](T05_entrada.txt)

Saída integral observada: [T05_saida.txt](T05_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
codigo ja cadastrado
Acoes cadastradas: 2
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T06 - Pesquisa exata por codigo e registro ausente

Entrada integral: [T06_entrada.txt](T06_entrada.txt)

Saída integral observada: [T06_saida.txt](T06_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Encontradas: 1
Nenhuma acao encontrada.
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T07 - Pesquisa parcial por escola retorna todos os resultados

Entrada integral: [T07_entrada.txt](T07_entrada.txt)

Saída integral observada: [T07_saida.txt](T07_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Encontradas: 2
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T08 - Pesquisa parcial por tema

Entrada integral: [T08_entrada.txt](T08_entrada.txt)

Saída integral observada: [T08_saida.txt](T08_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Encontradas: 1
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T09 - Atualiza para realizada e corrige efetivos

Entrada integral: [T09_entrada.txt](T09_entrada.txt)

Saída integral observada: [T09_saida.txt](T09_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Total de participacoes efetivas: 36
90.00%
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T10 - Atualizacao de codigo inexistente

Entrada integral: [T10_entrada.txt](T10_entrada.txt)

Saída integral observada: [T10_saida.txt](T10_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Registro inexistente.
Planejadas: 1
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T11 - Realizada para cancelada e planejada elimina efetivos

Entrada integral: [T11_entrada.txt](T11_entrada.txt)

Saída integral observada: [T11_saida.txt](T11_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Canceladas: 1
Planejadas: 1
Total de participacoes efetivas: 0
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T12 - Resumo misto: percentual so das realizadas

Entrada integral: [T12_entrada.txt](T12_entrada.txt)

Saída integral observada: [T12_saida.txt](T12_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Planejadas: 1 | Realizadas: 1 | Canceladas: 1
Previstos em todas as acoes: 70
Previstos nas realizadas: 40
80.00%
```

Resultado observado: retorno 0; 4/4 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T13 - Previsao zero evita divisao por zero

Entrada integral: [T13_entrada.txt](T13_entrada.txt)

Saída integral observada: [T13_saida.txt](T13_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Total de participacoes efetivas: 5
N/A
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T14 - Participacao superior ao previsto permitida

Entrada integral: [T14_entrada.txt](T14_entrada.txt)

Saída integral observada: [T14_saida.txt](T14_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
120.00%
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T15 - Menu rejeita texto, decimal, lixo e inteiro excessivo

Entrada integral: [T15_entrada.txt](T15_entrada.txt)

Saída integral observada: [T15_saida.txt](T15_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Erro: informe um inteiro
Encerrando o sistema.
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {'Erro: informe um inteiro': 6}; observadas: {'Erro: informe um inteiro': 6}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T16 - Campos vazios, quantidade negativa e situacao invalida

Entrada integral: [T16_entrada.txt](T16_entrada.txt)

Saída integral observada: [T16_saida.txt](T16_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
campo obrigatorio vazio
Erro: informe um inteiro
Previstos: 40 | Efetivos: 0
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {'campo obrigatorio vazio': 2, 'Erro: informe um inteiro': 3}; observadas: {'campo obrigatorio vazio': 2, 'Erro: informe um inteiro': 3}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T17 - Datas impossiveis e ano nao bissexto

Entrada integral: [T17_entrada.txt](T17_entrada.txt)

Saída integral observada: [T17_saida.txt](T17_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
data invalida
Data prevista: 29/02/2028
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {'data invalida': 2}; observadas: {'data invalida': 2}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T18 - Campo longo recusado sem contaminar a proxima entrada

Entrada integral: [T18_entrada.txt](T18_entrada.txt)

Saída integral observada: [T18_saida.txt](T18_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
texto muito longo
Escola: Escola Horizonte
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T19 - 100 registros aceitos; tentativa 101 bloqueada

Entrada integral: [T19_entrada.txt](T19_entrada.txt)

Saída integral observada: [T19_saida.txt](T19_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Limite de armazenamento atingido
Acoes cadastradas: 100
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T20 - EOF no cadastro encerra sem confirmar

Entrada integral: [T20_entrada.txt](T20_entrada.txt)

Saída integral observada: [T20_saida.txt](T20_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Operacao incompleta nao confirmada
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: ['Sucesso: acao cadastrada']

**Situação: PASSOU**

## T21 - Somas de grandes quantidades sem overflow de int

Entrada integral: [T21_entrada.txt](T21_entrada.txt)

Saída integral observada: [T21_saida.txt](T21_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Total de participacoes efetivas: 4294967294
100.00%
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T22 - Limite exato de texto (100 bytes) aceito

Entrada integral: [T22_entrada.txt](T22_entrada.txt)

Saída integral observada: [T22_saida.txt](T22_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Escola: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: ['texto muito longo']

**Situação: PASSOU**

## T23 - Quantidade efetiva negativa exige correcao

Entrada integral: [T23_entrada.txt](T23_entrada.txt)

Saída integral observada: [T23_saida.txt](T23_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Erro: informe um inteiro
Total de participacoes efetivas: 32
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T24 - Codigo zero ou negativo e submenu invalido

Entrada integral: [T24_entrada.txt](T24_entrada.txt)

Saída integral observada: [T24_saida.txt](T24_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Erro: informe um inteiro
Encontradas: 1
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {'Erro: informe um inteiro': 3}; observadas: {'Erro: informe um inteiro': 3}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T25 - Pesquisa vazia e sem correspondencia

Entrada integral: [T25_entrada.txt](T25_entrada.txt)

Saída integral observada: [T25_saida.txt](T25_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
campo obrigatorio vazio
Nenhuma acao encontrada.
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {'campo obrigatorio vazio': 2}; observadas: {'campo obrigatorio vazio': 2}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T26 - Nova execucao inicia sem os dados da anterior

Entrada integral: [T26_entrada.txt](T26_entrada.txt)

Saída integral observada: [T26_saida.txt](T26_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Nenhuma acao cadastrada.
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T27 - Datas de seculos e formato estrito

Entrada integral: [T27_entrada.txt](T27_entrada.txt)

Saída integral observada: [T27_saida.txt](T27_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
data invalida
Data prevista: 29/02/2000
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {'data invalida': 3}; observadas: {'data invalida': 3}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T28 - EOF em atualizacao incompleta encerra

Entrada integral: [T28_entrada.txt](T28_entrada.txt)

Saída integral observada: [T28_saida.txt](T28_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Operacao incompleta nao confirmada
```

Resultado observado: retorno 0; 1/1 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: ['Sucesso: situacao atualizada']

**Situação: PASSOU**

## T29 - Percentual agregado ponderado entre realizadas

Entrada integral: [T29_entrada.txt](T29_entrada.txt)

Saída integral observada: [T29_saida.txt](T29_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Total de participacoes efetivas: 55
55.00%
```

Resultado observado: retorno 0; 2/2 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**

## T30 - Realizada retorna diretamente para planejada

Entrada integral: [T30_entrada.txt](T30_entrada.txt)

Saída integral observada: [T30_saida.txt](T30_saida.txt)

Resultado esperado: retorno 0 e presença dos seguintes trechos:

```text
Planejadas: 1 | Realizadas: 0
Total de participacoes efetivas: 0
N/A
```

Resultado observado: retorno 0; 3/3 trechos esperados encontrados.

Contagens esperadas: {}; observadas: {}

Trechos que não devem aparecer: []

**Situação: PASSOU**
