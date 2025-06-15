# 🏰 Xadrez Interativo em C

<img src=src/Tabuleiro.png alt="Tabuleiro Gerado por IA" width="35%">

Um programa interativo em C que demonstra os movimentos das peças de xadrez com visualização colorida no terminal.

## 📋 Índice
- [Funcionalidades](#-Funcionalidades)
- [Tecnologias](#-Tecnologias)
- [Como Executar](#-como-executar)
- [Estrutura do Código](#-estrutura-do-código)
- [Capturas de Tela](#️-capturas-de-tela)
- [Executável](#-arquivo--executável)
- [Contato](#️-contato)

## 🎯 Funcionalidades

- Movimentos realistas das peças:
  - ♖ Torre (movimentos em cruz)
  - ♗ Bispo (movimentos diagonais)
  - ♘ Cavalo (movimentos em L)
- Tabuleiro colorido interativo
- Animação dos movimentos
- Validação de jogadas
- Interface amigável

## 🛠️ Implementação

### Estrutura do Código


<img src=src/Estrutura_codigo.svg alt="Estrutura do Código" width="30%">


### Principais Funções

1. **`printBoard()`** - Exibe o tabuleiro colorido:
   - Cabeçalho das colunas (A-H)
   - Numeração das linhas (1-8)
   - Peças representadas por caracteres coloridos


2. **`moveRook()`** - Implementa o movimento da Torre:
   - Seleção de posição inicial
   - Mostra possíveis movimentos (marcados com 'X')
   - Animação do movimento selecionado


3. **`moveBishop()`** - Implementa o movimento do Bispo:
   - Seleção de posição inicial
   - Mostra possíveis movimentos diagonais
   - Animação do movimento selecionado


4. **`showKnightMoves()`** - Implementa o movimento do Cavalo:
   - Seleção de posição inicial
   - Mostra 8 possíveis movimentos em "L" (numerados)
   - Seleção do movimento desejado

### Sistema de Cores

O programa utiliza uma paleta de cores vibrantes para melhor visualização:

| Cor          | Código | Uso                     |
|--------------|--------|-------------------------|
| Vermelho     | 12     | Torre                   |
| Verde        | 10     | Bispo                   |
| Amarelo      | 14     | Título do menu          |
| Azul         | 9      | Células do tabuleiro    |
| Branco       | 15     | Texto principal         |
| Magenta      | 13     | Movimentos possíveis    |




## 💻 Tecnologias

- Linguagem C padrão (C99)
- Biblioteca Windows.h para cores (somente Windows)
- Conio.h para entrada/saída

## 🚀 Como Executar

### 📋 Pré-requisitos

- Compilador **GCC (GNU Compiler Collection)**
- Terminal básico

### 📥 Instalação

Clone o repositório:

```bash
git clone https://github.com/WillianCiurlleti/Jogo_xadraz.git
```

Acesse o diretório:

```bash
cd xadrez
```

Compile o programa:

```bash
gcc xadrez.c -o xadrez
```

---


## 🧩 Estrutura do Código
```c
// Principais componentes:
#define BOARD_SIZE 8          // Tamanho do tabuleiro
char board[BOARD_SIZE][BOARD_SIZE]; // Matriz do tabuleiro

// Funções principais:
void initializeBoard();       // Inicializa o tabuleiro
void printBoard();            // Exibe o tabuleiro colorido
void moveRook();              // Lógica da Torre
void moveBishop();            // Lógica do Bispo
void showKnightMoves();       // Lógica do Cavalo
bool isValidPosition();       // Valida coordenadas
```

## 🖼️ Capturas de Tela

Menu Principal

<img src=src/Tela_inicial.png alt="Exibe o tabuleiro" width="30%">


Movimento da Torre

<img src=src/Movimento_torre.png alt="Exibe movimento da Torre" width="30%">

Movimento do Bispo

<img src=src/Movimento_bispo.png alt="Exibe movimento da Bispo" width="30%">

Movimento do Cavalo

<img src=src/Movimento_cavalo.png alt="Exibe movimento da Cavalo" width="30%">


## 📦 Arquivo  Executável

- [Xadrez.exe](xadrez.exe)


---
## ✉️ Contato

**Desenvolvedor:** Willian César  Ciurlleti    
🔗 LinkedIn: [linkedin.com/in/willian-ciurlleti](https://www.linkedin.com/in/willian-ciurlleti/)

---

<div align="center">
  <p>Desenvolvido com ❤️ usando C</p>
  <img src="https://img.shields.io/github/stars/WillianCiurlleti/Jogo_xadraz?style=social" alt="Stars">
</div>
