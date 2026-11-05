# Roteiro de vídeo — PSE em Ação

Duração planejada: **6min40s**, com 20 segundos de margem até o limite de sete minutos. Divisão sugerida; a equipe pode trocar os responsáveis. Ensaiem com cronômetro: a digitação e a troca de telas também contam. Todos devem participar. As falas abaixo são propostas para adaptação à experiência real da equipe.

Antes de gravar, compile e abra o programa. Deixe código, fluxogramas e testes preparados em outras janelas. Use somente dados fictícios. Para economizar tempo, cole os campos de exemplo durante os cadastros, mantendo a execução visível. Não corte o vídeo de modo a simular uma funcionalidade que não existe.

## 0:00–0:45 — Daniel: apresentação e problema

**Tela:** título e integrantes por poucos segundos; em seguida, menu real do programa.

**Fala sugerida:**

“Olá! Somos Daniel, Murilo e Victor, e este é o PSE em Ação. A proposta atende uma equipe fictícia que acompanha ações de saúde nas escolas. O problema é que os registros ficam dispersos, dificultando saber o que foi planejado, realizado ou cancelado. Nossa aplicação em C centraliza essas informações no terminal. Ela utiliza apenas dados fictícios e coletivos, sem cadastro individual de estudantes ou informações clínicas. Vamos mostrar como o planejamento da primeira entrega foi transformado nesta versão funcional.”

## 0:45–2:15 — Daniel: cadastro, listagem e pesquisa

**Ação na tela:** escolha 1. Cadastre 101; Escola Horizonte; Saude bucal; 10/10/2026; Turmas do 6 ano; Equipe IntegraPSE; digite -1 na previsão e depois 40; situação 1. Escolha 2 para listar. Escolha 3, critério 2, termo `horizonte`.

**Fala sugerida, acompanhando a digitação:**

“O menu mantém as seis opções previstas no nosso fluxograma. No cadastro, informamos o código, a escola, o tema, a data, o público, o responsável e a quantidade prevista. Aqui, uma quantidade negativa é recusada, e o programa solicita a correção. A situação inicial será planejada. Depois da confirmação, o sistema volta ao menu. A listagem apresenta os dados da ação, e a pesquisa permite procurar por código, escola ou tema. Neste exemplo, usamos apenas um trecho do nome da escola. Se houver várias correspondências, todas aparecem. Isso implementa os requisitos de cadastro, listagem e pesquisa.”

## 2:15–3:50 — Murilo: atualização e resumo

**Ação na tela:** opção 4, código 101, situação 2, efetivos 32. Cadastre 102/Escola Aurora/Atividade fisica/15/10/2026/Turmas do 7 ano/Equipe Aurora/20/situação 1. Cadastre 103/Escola Jardim/Alimentacao saudavel/20/10/2026/Turmas do 8 ano/Equipe Jardim/10/situação 3. Escolha 5.

**Fala sugerida:**

“Agora atualizamos a ação para realizada. Nesse momento, o sistema pede a quantidade de participantes que compareceram: trinta e dois. Vamos incluir também uma ação planejada e uma cancelada para demonstrar o resumo. Temos uma ação em cada situação e setenta participações previstas no conjunto. Para calcular o percentual, comparamos apenas as ações realizadas: trinta e dois efetivos divididos por quarenta previstos resultam em oitenta por cento. Planejadas e canceladas ficam fora dessa divisão. Se a previsão das realizadas for zero, o programa mostra N/A. Esses números representam participações acumuladas, e não estudantes únicos.”

## 3:50–5:15 — Murilo: explicação do código

**Tela:** mostre `Acao`, `main`, `cadastrarAcao`, `lerInteiro` e `gerarResumo` em trechos legíveis. Evite rolar rapidamente pelo arquivo inteiro.

**Fala sugerida:**

“No código, a struct Acao reúne os campos de cada registro. Um vetor comporta até cem ações, e a variável quantidade indica quantas posições estão ocupadas. A main controla o menu com repetição e switch, chamando uma função para cada operação. Os laços for percorrem os registros para listar, pesquisar e resumir. O cadastro primeiro valida uma variável local e só depois a copia para o vetor. Assim, um cadastro incompleto não é armazenado. Para ler números, usamos fgets e strtol, verificando se toda a entrada corresponde a um inteiro válido. Também conferimos códigos repetidos, campos vazios e datas inexistentes. Os dados ficam apenas em memória, como foi definido na primeira entrega.”

## 5:15–6:05 — Victor: coerência e testes

**Tela:** fluxograma de cadastro e tabela de rastreabilidade; em seguida resultado real de `python3 tests/testar.py` (ou `python` no ambiente configurado).

**Fala sugerida:**

“O requisito RF01 aparece no caso de uso de cadastro, no fluxograma e na função cadastrarAcao. Atualização e resumo também estão relacionados aos requisitos RF04 e RF05. O fluxo original foi complementado com o limite de armazenamento e com a solicitação de efetivos quando a ação já é cadastrada como realizada. O pacote possui vinte e oito testes reproduzíveis, cobrindo operações, dados inválidos, limites e situações como divisão por zero. Nesta execução, todos passaram.”

**Cuidado:** diga “nesta execução, todos passaram” apenas se o resultado mostrado na gravação confirmar isso. Se houver falha, corrija e execute novamente antes de gravar.

## 6:05–6:40 — Victor: resultados e encerramento

**Tela:** volte ao programa; mostre a opção 6 e a mensagem de encerramento.

**Fala sugerida:**

“A versão permite registrar e acompanhar ações coletivas com informações organizadas. Ainda existem limitações: os dados são perdidos ao sair, há um máximo de cem ações e não existe histórico de alterações. Como evolução, podemos estudar gravação em arquivo e novos filtros. O projeto relaciona requisitos, algoritmos e programação em uma solução simples de apoio ao planejamento. O código, o manual e os testes ficam no repositório para avaliação. Obrigado!”

## Conferência antes de enviar

- Participação dos três integrantes e áudio compreensível.
- Vídeo final com no máximo sete minutos.
- Programa em execução, cadastro, consulta, atualização, resumo e ao menos uma validação visíveis.
- Explicação de struct, vetor, funções, condicionais e laço do menu.
- Relação entre requisitos, fluxogramas, pseudocódigos e funções.
- Dados exclusivamente fictícios e coletivos.
- Link do vídeo com acesso liberado para avaliação, inserido no README e no documento.
- Se mencionar que os arquivos estão no GitHub, confirmar que foram publicados.
