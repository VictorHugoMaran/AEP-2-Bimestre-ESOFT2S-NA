# PSE em Ação

### Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

Projeto acadêmico desenvolvido para a **Atividade de Estudo Programada (AEP)**, referente ao 2º semestre de 2026, no curso de **Engenharia de Software** da **UniCesumar**. A proposta interdisciplinar também contempla o curso de Análise e Desenvolvimento de Sistemas.

A solução atende à equipe intersetorial fictícia **IntegraPSE**, responsável pelo planejamento e acompanhamento de ações coletivas do Programa Saúde na Escola.

Este README reúne o **planejamento da primeira entrega** e a **versão funcional preparada para a segunda entrega**, com instruções de execução, documentação e pendências de finalização.

---

## 📌 Sobre o projeto

O **Programa Saúde na Escola (PSE)**, instituído pelo Decreto nº 6.286/2007, articula as áreas de Saúde e Educação para promover ações de prevenção e atenção à saúde nas escolas públicas. No cenário considerado pelo projeto, equipes intersetoriais municipais enfrentam dificuldades para localizar ações programadas, verificar o que já foi realizado ou cancelado e consolidar a quantidade de participantes atendidos, pois essas informações estão dispersas em anotações, formulários e planilhas separadas.

O projeto contempla o planejamento e a implementação, em **linguagem C**, de uma **aplicação de terminal** que centraliza o cadastro, a consulta, a atualização e o acompanhamento de ações coletivas do PSE, sem cadastro individual de estudantes ou campos destinados a dados clínicos.

**Questão norteadora:** De que forma o desenvolvimento de um sistema em linguagem C pode contribuir para organizar o registro e o acompanhamento das ações coletivas realizadas pela equipe responsável pelo Programa Saúde na Escola, apresentando informações claras e preservando a proteção dos dados dos estudantes?

**Objetivo geral:** desenvolver uma aplicação em C que auxilie a organização e o acompanhamento das ações coletivas do PSE, relacionando levantamento de requisitos, modelagem, implementação, testes e documentação.

**Usuários previstos:** coordenadores do programa, profissionais da Atenção Primária à Saúde e representantes das equipes pedagógicas. Os estudantes são beneficiários indiretos e não utilizam o sistema como operadores.

---

## 👥 Integrantes

| Nome | RA |
| --- | --- |
| Daniel Muniz Gallina | 26008793-2 |
| Murilo Bovo Bonvechio | 26011546-2 |
| Victor Hugo Maran Kalomenconkovas | 26001189-2 |

- **Curso:** Engenharia de Software
- **Série:** ESOFT2S-NA
- **Instituição:** UniCesumar
- **Ano:** 2026/2

---

## 🎯 Funcionalidades e requisitos

| Código | Funcionalidade implementada |
| --- | --- |
| RF01 | Cadastrar uma ação com código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista de participantes e situação inicial. Se a ação já for realizada, registrar também os participantes efetivos. |
| RF02 | Listar todas as ações cadastradas, exibindo seus dados de forma organizada. |
| RF03 | Pesquisar ações por código exato ou trecho do nome da escola ou do tema. |
| RF04 | Atualizar a situação entre planejada, realizada e cancelada, registrando os participantes efetivos quando realizada. |
| RF05 | Gerar um resumo com quantidades de ações por situação, total de participações efetivas, previsões e percentual de participação nas ações realizadas. |
| RF06 | Validar entradas, evitando códigos repetidos, quantidades negativas, campos obrigatórios vazios, opções inválidas e cadastros além da capacidade. |

A validação de entradas acontece dentro das operações, sem uma opção própria no menu. O campo **tema** é livre: o sistema permite diferentes tipos de ações do PSE.

**Fora do escopo desta versão:** cadastro individual de estudantes, diagnósticos, triagens, recomendações de tratamento, banco de dados, interface gráfica, aplicação web, autenticação e histórico de alterações.

---

## 🛠️ Tecnologias e organização do código

- **Linguagem do sistema:** C, compatível com C11.
- **Ambiente utilizado pela equipe nas aulas:** Dev-C++ no Windows.
- **Execução:** terminal, utilizando apenas a biblioteca padrão de C.
- **Armazenamento:** vetor de estruturas `Acao`, mantido em memória durante a execução.
- **Capacidade:** até 100 ações por sessão.
- **Estruturas utilizadas:** `struct`, vetores, condicionais, `switch`, laços de repetição e funções.
- **Organização:** funções específicas para cadastro, listagem, pesquisa, atualização, resumo e validação; a `main` controla o menu.

O sistema não grava os cadastros em arquivos. Ao encerrar, os dados da sessão são perdidos. A persistência poderá ser considerada em uma evolução futura.

---

## ▶️ Compilação e execução

### Dev-C++ — ambiente utilizado pela equipe

1. Baixe ou extraia os arquivos do projeto em uma pasta do computador. Se recebeu um ZIP, extraia antes de abrir o código.
2. Abra o **Dev-C++**, com o compilador configurado conforme utilizado nas aulas.
3. Use **Arquivo → Abrir** e selecione o arquivo **`src/main.c`**.
4. Mantenha a extensão **`.c`**, pois a implementação é em C. Não renomeie para `.cpp`.
5. Com o arquivo aberto, use **Compilar e executar** (*Compile & Run*). A localização da opção e o atalho podem variar conforme a versão e o idioma do Dev-C++.
6. Após a compilação, utilize o menu na janela do terminal. Digite uma opção e pressione **Enter**.
7. Para encerrar normalmente, escolha **6 — Sair**. Os cadastros da sessão serão descartados.

O projeto possui um único arquivo-fonte e pode ser compilado diretamente, sem criar um projeto adicional no Dev-C++. Para seguir o padrão indicado nesta documentação, utilize um compilador com suporte a C11; se necessário, ajuste o padrão da linguagem **C** nas opções do compilador utilizadas em aula.

O Dev-C++ é o ambiente de desenvolvimento; a compilação é realizada pelo compilador configurado nele. **Os comandos de terminal abaixo são alternativas, não etapas obrigatórias para executar pelo Dev-C++.**

**Verificação pendente:** a versão foi compilada e testada em Linux/GCC. A equipe ainda deve confirmar a compilação e a execução no Dev-C++ instalado em seu computador e no ambiente definido pelo professor. O uso do Dev-C++ nas aulas não significa que esta versão já tenha sido testada nele.

Referência de apoio: [documentação de compilação do Embarcadero Dev-C++](https://github.com/Embarcadero/Dev-Cpp/wiki/Compiling). A versão utilizada pela equipe pode apresentar diferenças na interface.

### Alternativa: terminal com GCC

Para os comandos abaixo, abra o terminal na pasta raiz do projeto, onde estão o `README.md` e a pasta `src/`. É necessário que o comando `gcc` esteja disponível nesse terminal.

### Linux ou macOS com GCC disponível

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic src/main.c -o pse
./pse
```

### Windows com GCC/MinGW disponível — PowerShell

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic src/main.c -o pse.exe
.\pse.exe
```

Se o comando `gcc` não for reconhecido no terminal, utilize o procedimento pelo Dev-C++ ou configure o acesso ao compilador. Ter o compilador configurado dentro do Dev-C++ não garante que o comando esteja disponível no terminal do Windows.

**Não é necessário instalar Python para compilar ou utilizar o sistema.**

---

## 🧭 Menu e utilização

| Opção | Operação |
| --- | --- |
| 1 | Cadastrar ação |
| 2 | Listar ações |
| 3 | Pesquisar ação por código, escola ou tema |
| 4 | Atualizar situação |
| 5 | Gerar resumo geral |
| 6 | Sair |

Digite uma resposta por linha e pressione **Enter**. Ao terminar uma operação, o programa retorna ao menu. Entradas inválidas geram mensagens de orientação e nova solicitação do campo.

### Regras de preenchimento

- Código inteiro positivo e único.
- Campos textuais obrigatórios com até 100 bytes; caracteres acentuados podem ocupar mais de um byte.
- Data existente no formato `DD/MM/AAAA`, com ano entre 0001 e 9999. Não há exigência de data futura.
- Quantidades inteiras não negativas, limitadas pelo tipo `int` do ambiente (`INT_MAX`).
- Situações: **1 — Planejada**, **2 — Realizada** e **3 — Cancelada**.
- Ações realizadas exigem quantidade efetiva; ações planejadas ou canceladas mantêm esse valor em zero.
- Alterar uma ação realizada para planejada ou cancelada zera seus efetivos. Não existe histórico para recuperar o valor anterior.
- Selecionar realizada novamente permite corrigir a quantidade efetiva.
- A busca por escola ou tema aceita trechos e ignora diferenças de maiúsculas/minúsculas nas letras ASCII. Acentos devem coincidir.

As mensagens do programa estão sem acentos para reduzir problemas de exibição entre terminais. Caso a entrada seja encerrada tecnicamente por **EOF**, o programa termina sem confirmar uma operação incompleta.

### Cálculo do percentual

O percentual considera apenas as ações realizadas:

```text
Percentual = (soma dos participantes efetivos das ações realizadas
              / soma dos participantes previstos nessas ações) × 100
```

Se o denominador for zero, o programa exibe `N/A`. Efetivos acima da previsão são permitidos, podendo gerar percentual superior a 100%. O total previsto de todas as ações também é mostrado, separadamente.

Os totais representam **participações acumuladas**, não estudantes únicos.

### Exemplo de uso

1. Cadastre a ação **101** com: Escola Horizonte; Saude bucal; 10/10/2026; Turmas do 6 ano; Equipe IntegraPSE; 40 participantes previstos; situação planejada.
2. Liste as ações e pesquise por escola usando o termo `horizonte`.
3. Atualize a ação 101 para realizada, informando **32 participantes efetivos**.
4. Gere o resumo: o percentual deverá ser **80%**.
5. Digite uma opção inexistente para verificar a validação do menu e, depois, escolha **6** para encerrar.

Todos os nomes e dados desse exemplo são fictícios.

---

## 🔄 Desenvolvimento e continuidade entre as entregas

O planejamento adota uma abordagem incremental, distribuída em seis sprints:

| Sprint | Foco planejado |
| --- | --- |
| 1 | Levantamento do problema, escopo, requisitos e estrutura de dados |
| 2 | Modelagem dos fluxogramas e pseudocódigos |
| 3 | Produção textual, documentação e organização do repositório |
| 4 | Implementação de cadastro, listagem e pesquisa |
| 5 | Implementação de atualização e resumo, testes e correções |
| 6 | Documentação final e preparação da apresentação |

A primeira entrega documenta a análise e o planejamento. A segunda transforma esse planejamento em uma aplicação funcional e acrescenta casos de uso, manual, testes e análise dos resultados.

O objetivo do produto e as opções do menu foram mantidos. A versão implementada detalha alguns pontos do planejamento:

| Refinamento | Justificativa |
| --- | --- |
| Limite de 100 ações e verificação antes do cadastro | Atender ao tratamento de capacidade esgotada exigido no enunciado; 100 é a capacidade escolhida para esta versão. |
| Efetivos no cadastro de ações já realizadas | Manter os dados necessários ao acompanhamento e ao resumo. |
| Validação de datas, números e tamanho dos textos | Reduzir entradas inconsistentes e respeitar os limites de memória. |
| Definição do denominador do percentual | Explicitar como os resultados das ações realizadas são comparados às previsões. |
| Tratamento de EOF | Encerrar de forma controlada quando a entrada termina. |

Essas decisões estão documentadas na segunda entrega e devem ser revisadas pela equipe. Os fluxogramas originais devem ser preservados junto aos revisados, para manter o histórico do planejamento.

---

## 🧪 Testes

Na verificação da versão preparada para a segunda entrega, o programa compilou sem avisos com GCC e **30 testes automatizados passaram**. Foram avaliados cadastro, listagem, pesquisa, atualização, resumo, base vazia, duplicidade, entradas inválidas, datas, limites de texto e armazenamento, quantidades elevadas e encerramento da entrada.

Os resultados estão em [`docs/evidencias/testes.txt`](./docs/evidencias/testes.txt) e [`docs/evidencias/testes.json`](./docs/evidencias/testes.json). Eles correspondem à versão testada; alterações no código exigem nova verificação.

### Ferramenta opcional de testes

O arquivo [`tests/testar.py`](./tests/testar.py) usa Python apenas para compilar o programa, simular entradas e conferir respostas. **O sistema é implementado em C; Python não é uma dependência de uso nem uma exigência da AEP.**

Para executar essa ferramenta, com Python 3 e GCC instalados:

```bash
python3 tests/testar.py
```

No Windows, conforme a instalação do Python:

```powershell
python tests/testar.py
```

A equipe também pode executar os cenários manualmente e registrar entrada, resultado esperado, resultado observado e situação do teste. A validação no Dev-C++ utilizado pela equipe e no ambiente do professor, com o registro dessas verificações, ainda precisa ser concluída.

---

## 📂 Documentação e organização do repositório

Os caminhos abaixo integram a documentação original e os arquivos do pacote da segunda entrega. Ao atualizar o GitHub, mantenha os nomes e as pastas para que os links funcionem.

| Caminho | Conteúdo |
| --- | --- |
| [`README.md`](./README.md) | Apresentação das duas etapas e instruções de uso |
| [`src/main.c`](./src/main.c) | Código completo do sistema em C |
| [`docs/AEP_1_Entrega_PSE_em_Acao.pdf`](./docs/AEP_1_Entrega_PSE_em_Acao.pdf) | Documento da primeira entrega |
| [`docs/fluxograma_geral.png`](./docs/fluxograma_geral.png) | Fluxograma geral original, extraído sem alteração do PDF da primeira entrega |
| [`docs/fluxograma_cadastro_acao.png`](./docs/fluxograma_cadastro_acao.png) | Fluxograma de cadastro original, extraído sem alteração do PDF da primeira entrega |
| [`docs/AEP_2_Entrega_PSE_em_Acao.pdf`](./docs/AEP_2_Entrega_PSE_em_Acao.pdf) | Versão do documento da segunda entrega, em revisão |
| [`docs/AEP_2_Entrega_PSE_em_Acao.md`](./docs/AEP_2_Entrega_PSE_em_Acao.md) | Conteúdo editável do documento da segunda entrega |
| [`docs/casos_de_uso.svg`](./docs/casos_de_uso.svg) | Diagrama de casos de uso |
| [`docs/fluxograma_geral.svg`](./docs/fluxograma_geral.svg) | Versão revisada do fluxograma geral |
| [`docs/fluxograma_cadastro.svg`](./docs/fluxograma_cadastro.svg) | Versão revisada do fluxograma de cadastro, parte A |
| [`docs/fluxograma_cadastro_continuacao.svg`](./docs/fluxograma_cadastro_continuacao.svg) | Cadastro, parte B: quantidades, situação e efetivos |
| [`docs/evidencias/`](./docs/evidencias/) | Resultados de testes, transcrição e imagens da execução |
| [`tests/testar.py`](./tests/testar.py) | Ferramenta opcional de testes automatizados |

As imagens atuais de execução foram renderizadas a partir da saída real do programa. A substituição por **capturas diretas do terminal** permanece prevista para a versão final do documento.

---

## 📈 Status das entregas

### 1ª entrega — Documento escrito

- [x] Contextualização, problema, objetivos e justificativa.
- [x] Identificação dos usuários, delimitação do escopo e limites éticos.
- [x] Requisitos funcionais e não funcionais.
- [x] Fluxogramas e pseudocódigos do planejamento.
- [x] Processo incremental e planejamento das sprints.
- [x] Documento da primeira etapa e README inicial.

### 2ª entrega — Implementação e apresentação

- [x] Versão funcional em C com menu e operações obrigatórias.
- [x] Validações e tratamento de registros inexistentes e capacidade esgotada.
- [x] Compilação e testes automatizados em Linux/GCC.
- [x] Versões dos casos de uso, requisitos atualizados e manual.
- [x] Registro dos testes e versão das considerações finais.
- [x] Revisão 2 dos fluxogramas, casos de uso e detalhamento dos testes.
- [x] Conferência e aprovação da versão revisada pela equipe.
- [x] Capturas diretas do programa executado no terminal.
- [x] Compilação e execução no Dev-C++ da equipe e validação no ambiente definido pelo professor.
- [x] Consolidação local do documento revisado.
- [x] Atualização dos arquivos no GitHub e conferência dos links publicados.
- [ ] Gravação do vídeo com os integrantes, com duração máxima de sete minutos.
- [ ] Inclusão do link do vídeo com acesso liberado para avaliação.

**Vídeo de apresentação:** ainda não disponibilizado.

---

## ⚖️ Limites éticos e limitações

O sistema deve ser utilizado exclusivamente com **dados fictícios e informações coletivas** sobre as ações do PSE. Não devem ser informados nomes de estudantes, diagnósticos, prontuários ou qualquer dado sensível individual. O programa não realiza diagnóstico, triagem médica, prescrição ou recomendação de tratamento.

Os campos livres não identificam automaticamente conteúdos inadequados; o operador deve respeitar a finalidade acadêmica e o escopo definido.

A versão atual mantém os dados apenas em memória, limita a sessão a 100 ações e não possui exclusão, edição dos demais dados cadastrais, autenticação ou histórico. Como melhorias futuras, podem ser considerados armazenamento em arquivo, novos filtros, edição cadastral e tratamento ampliado de acentos nas pesquisas.

---

## 📚 Referências

- *BRASIL.* Decreto nº 6.286, de 5 de dezembro de 2007. Institui o Programa Saúde na Escola – PSE e dá outras providências. Diário Oficial da União, Brasília, DF, 6 dez. 2007.

- *BRASIL.* Lei nº 13.853, de 8 de julho de 2019. Altera a Lei nº 13.709, de 14 de agosto de 2018, para dispor sobre a proteção de dados pessoais e para criar a Autoridade Nacional de Proteção de Dados; e dá outras providências. Diário Oficial da União, Brasília, DF, 9 jul. 2019.

- *BRASIL. Ministério da Saúde.* O que é o Programa Saúde na Escola (PSE)? Brasília, DF: Ministério da Saúde, 2025a. Disponível em: [Ministério da Saúde](https://www.gov.br/saude/pt-br/composicao/saps/pse/faq/o-que-e-o-programa). Acesso em: 19 ago. 2026.

-  *BRASIL. Ministério da Saúde.* Quais são as ações do PSE? Brasília, DF: Ministério da Saúde, 2025b. Disponível em: [Ministério da Saúde](https://www.gov.br/saude/pt-br/composicao/saps/pse/faq/quais-sao-as-acoes-do). Acesso em: 19 ago. 2026.

-  *PARANÁ. Secretaria de Estado da Saúde.* Da vacinação às atividades físicas: programa Saúde na Escola tem 48 mil ações no ano. Curitiba, PR: Secretaria da Saúde, 2025. Disponível em: [Secretaria da Saúde do Paraná](https://www.saude.pr.gov.br/Noticia/Da-vacinacao-atividades-fisicas-programa-Saude-na-Escola-tem-48-mil-acoes-no-ano). Acesso em: 22 ago. 2026.

- *SOUSA, MC; ESPERIDIÃO, MA; MEDINA, MG.* A intersetorialidade no Programa Saúde na Escola: avaliação do processo político-gerencial e das práticas de trabalho. Ciência & Saúde Coletiva, Rio de Janeiro, v. 22, n. 6, p. 1781-1790, 2017. DOI: [10.1590/1413-81232017226.24262016](https://doi.org/10.1590/1413-81232017226.24262016).

---

*Projeto de caráter estritamente acadêmico, desenvolvido no contexto da AEP 2026/2 da Unicesumar.*
