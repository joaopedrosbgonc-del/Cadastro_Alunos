# Cadastro de Alunos — Documento de Requisitos e Planejamento

**Entrega 1 (1º Bimestre) — Fundamentos e Estrutura Base**
**Equipe:** Andre Luiz Silva, Guilherme Coutinho, João Pedro dos Santos, João Victor Santana e Paulo Arthur Sousa Ferreira
**Linguagem:** C | **Plataforma:** Windows (terminal) | **Repositório:** `Cadastro_Alunos`

---

## 1. Definição do problema

Instituições e turmas pequenas precisam controlar quem são seus alunos, mas muitas vezes fazem isso em papel ou em planilhas soltas, o que gera erros, dados duplicados e dificuldade para consultar informações.

O objetivo deste projeto é desenvolver um **sistema de cadastro de alunos em linguagem C**, executado no terminal, que permita registrar, consultar e remover alunos de forma simples por meio de um menu interativo.

## 2. Escopo

**Dentro do escopo (Entrega 1):**
- Menu principal interativo no terminal.
- Cadastro de alunos (nome e curso), com matrícula gerada automaticamente.
- Listagem dos alunos cadastrados.
- Busca de aluno por matrícula.
- Remoção de aluno por matrícula.

**Fora do escopo (por enquanto):**
- Edição das informações do aluno.
- Gravação dos dados em arquivo ou banco de dados.
- Interface gráfica e versão multiplataforma.

## 3. Requisitos funcionais

| Código | Requisito | Situação |
|--------|-----------|----------|
| RF01 | O sistema deve exibir um menu principal com as opções disponíveis e repeti-lo até o usuário escolher sair. | Implementado |
| RF02 | O sistema deve cadastrar um aluno informando nome e curso. | Implementado |
| RF03 | O sistema deve gerar automaticamente a matrícula do aluno, iniciando em 1000. | Implementado |
| RF04 | O sistema deve listar todos os alunos cadastrados (nome e matrícula). | Implementado |
| RF05 | O sistema deve buscar um aluno pela matrícula e exibir seus dados. | Planejado |
| RF06 | O sistema deve remover um aluno a partir da matrícula informada, avisando se ela não existir. | Implementado |
| RF07 | O sistema deve permitir editar as informações de um aluno. | Implementado |

## 4. Requisitos não funcionais

| Código | Requisito |
|--------|-----------|
| RNF01 | O sistema deve ser escrito em linguagem C e executado no terminal do Windows. |
| RNF02 | O sistema deve comportar até 100 alunos cadastrados. |
| RNF03 | Os dados ficam apenas na memória e são perdidos ao fechar o programa. |
| RNF04 | O código deve ser organizado em funções (modularização) e versionado com Git/GitHub. |

## 5. Casos de uso

| Caso de uso | Ator | Fluxo principal |
|-------------|------|-----------------|
| **Cadastrar aluno** | Usuário | 1. Escolhe a opção 1 no menu. 2. Informa o nome e o curso. 3. O sistema gera a matrícula e confirma o cadastro. |
| **Listar alunos** | Usuário | 1. Escolhe a opção 2. 2. O sistema exibe nome e matrícula de cada aluno cadastrado. |
| **Buscar aluno** | Usuário | 1. Informa a matrícula. 2. O sistema exibe os dados do aluno ou avisa que não foi encontrado. |
| **Remover aluno** | Usuário | 1. Escolhe a opção 4. 2. Informa a matrícula. 3. O sistema remove o aluno e confirma, ou avisa que não foi encontrado. |

## 6. Estrutura de dados principal

Cada aluno é representado por uma estrutura (`struct`) e os alunos ficam guardados em um **vetor** de até 100 posições:

```c
typedef struct {
    char nome[80];
    char curso[30];
    int matricula;
} Aluno;

Aluno alunos[100];   // vetor de alunos
int total_alunos;    // quantidade de alunos cadastrados
```

A variável `total_alunos` indica quantas posições do vetor estão em uso. Para remover um aluno, os elementos seguintes são deslocados uma posição para frente e o total é reduzido em 1.

## 7. Organização do código (modularização)

| Módulo | Função |
|--------|--------|
| Menu principal | Laço `do...while` com `switch` que chama cada funcionalidade. |
| `titulo()` | Exibe o cabeçalho e as opções do menu. |
| `loading()` | Exibe uma animação simples de carregamento. |
| `cadastrarAluno()` | Lê nome e curso, gera a matrícula e guarda no vetor. |
| `listarAlunos()` | Percorre o vetor e exibe os alunos cadastrados. |
| `buscarAluno()` | Procura um aluno pela matrícula. |
| `removerAluno()` | Remove um aluno pela matrícula (já implementada como função). |

## 8. Limitações conhecidas e melhorias futuras

- O limite de 100 alunos ainda não é validado no cadastro.
- Após remover alunos, a matrícula gerada (`1000 + total_alunos`) pode se repetir; é preciso garantir matrículas únicas.
- Implementar a edição de informações do aluno.
- Salvar os dados em arquivo para não perdê-los ao fechar o programa.
- Tornar o programa multiplataforma (hoje usa `windows.h`, `cls` e `pause`).

## 9. Organização da equipe e do repositório

- O código da entrega fica na branch **`entrega-1`**.
- Cada integrante trabalha em uma branch própria para a sua funcionalidade e faz o merge ao final.
- Mínimo de 3 commits distintos da equipe, com mensagens descritivas.
- Divisão de tarefas: [preencher — quem ficou com cadastrar, listar, buscar, remover e documentação].
