# Alterações da revisão 2

Versão: 13 de outubro de 2026. Originais preservados no PDF da primeira entrega e em `historico/Entrega2_original.zip`.

| Alteração | Justificativa |
|---|---|
| Fluxograma geral: menu, leitura, validação e retornos | Diferenciar repetir a entrada inválida de executar novamente o menu, conforme o código. |
| Cadastro detalhado em duas partes, ligado pelo conector A | Tornar legíveis as repetições de código, campos, previsão, situação e efetivos, preservando a sequência original. |
| Cadastro já realizado solicita efetivos | Refinar o planejamento para registrar os dados necessários ao resumo. |
| Capacidade, datas e EOF explícitos | Documentar tratamentos existentes no código; capacidade de 100 é decisão de implementação. |
| UC01: capacidade como verificação inicial | Evitar uma pré-condição que ocultava o tratamento de base cheia. |
| Percentual sobre previsões das realizadas | Fixar uma regra aberta no planejamento; não é fórmula imposta pelo enunciado. Previsão zero: N/A; mais efetivos que previstos: acima de 100%. |
| Efetivos zerados fora de realizada | Alinhar requisitos, atualização e cálculo. Não há histórico nem contagem de estudantes únicos. |
| Testes: 30 casos com entradas e saídas integrais | Melhorar rastreabilidade e conferir repetição de mensagens de erro, ponderação do percentual e mudança realizada→planejada. |
| Dev-C++ como ambiente principal | Respeitar o ambiente da equipe; GCC no terminal é alternativa e ambiente desta verificação. |
| Sumário, legendas e README | Facilitar leitura, navegação e identificação de pendências reais. |

## Verificação do código

Não houve alteração em `src/main.c`. SHA-256: `8c1d267b726897218db5d11f947a134a012d9302f22c0bd45125ce88d35486fe`.

O teste opcional recompila o código com `gcc -std=c11 -Wall -Wextra -Wpedantic` e executa 30 cenários. O resultado registrado nesta revisão é 30/30 aprovados. Isso comprova esses cenários no ambiente registrado, não ausência de todos os defeitos nem execução no Dev-C++.

Os registros anteriores de terminal foram mantidos porque o código C permanece idêntico. As imagens são renderizações da transcrição, não capturas diretas. Os novos testes têm entradas e saídas próprias em `evidencias/`.

## Limites

Não foram verificados publicação no GitHub, atividades ou experiências da equipe, nem execução no computador da disciplina. O vídeo e seu roteiro anterior não foram revisados. A equipe deve validar as decisões e completar as evidências indicadas em `PENDENCIAS_EQUIPE.md`.
