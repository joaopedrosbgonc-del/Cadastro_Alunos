# Cadastro de Alunos

Sistema de cadastro de alunos desenvolvido em C, executado no terminal. Permite cadastrar, listar e remover alunos por meio de um menu interativo.

Atenção: o programa usa `windows.h`, `cls` e `pause`, portanto funciona apenas no Windows.

## Funcionalidades

| Opção | Descrição | Status |
|-------|-----------|--------|
| 1 | Cadastrar um aluno (nome e curso) | Disponível |
| 2 | Listar alunos cadastrados | Disponível |
| 3 | Editar informações |  Disponivel
| 4 | Remover aluno pela matrícula | Disponível |
| 0 | Sair | Disponível |

## Como funciona

- Cada aluno possui nome, curso e matrícula.
- A matrícula é gerada automaticamente, começando em `1000`.
- O sistema comporta até 100 alunos.
- Os dados ficam apenas na memória e são perdidos ao fechar o programa.

## Estrutura do projeto

```
Cadastro_Alunos/
├── main.c      # Código-fonte
├── output/     # Arquivos gerados na compilação
└── .gitignore
```

## Pré-requisitos

- Windows
- Compilador C (por exemplo, GCC via [MinGW-w64](https://www.mingw-w64.org/))

## Como compilar e executar

```bash
git clone https://github.com/joaopedrosbgonc-del/Cadastro_Alunos.git
cd Cadastro_Alunos
gcc main.c -o output/cadastro_alunos.exe
output\cadastro_alunos.exe
```

## Exemplo de uso

```
=====================================
 Cadastro de alunos
=====================================

1 - Cadastrar um aluno
2 - Alunos cadastrados
3 - Editar informacoes
4 - Remover aluno
0 - Sair

O que quer fazer? [Escreva o numero]
-->
```

## Melhorias futuras

- Implementar a edição de informações
- Validar o limite de 100 alunos
- Garantir matrículas únicas após remoções
- Salvar os dados em arquivo
- Tornar o programa multiplataforma
