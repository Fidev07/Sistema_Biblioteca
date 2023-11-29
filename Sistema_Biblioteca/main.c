#include <stdio.h>
#include <string.h>
#define MAX_LIVROS 100



// Define uma nova estrutura de dados.
typedef struct {
    int codigo;
    char titulo[100];
    char autor[50];
    int emprestado; // 0 para disponível, 1 para emprestado

}Livro;


// Função para cadastrar um livro
void cadastrarLivro(Livro* livros, int* totalLivros) {
    if (*totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido. Não é possível cadastrar mais livros. \n");
        return;

    }



    Livro novoLivro;

    printf("Digite o codigo do livro: \n");
    scanf("%d", &novoLivro.codigo);

    printf("Digite o titulo do livro: \n");
    scanf(" %[^\n]", novoLivro.titulo);

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", novoLivro.autor);

    printf("Livro cadastrado com sucesso! \n");

// Livro cadastrado inicialmente como disponível
    novoLivro.emprestado = 0;

    livros[*totalLivros] = novoLivro;
    (*totalLivros)++;
}

// Função para encontrar um livro pelo código
int encontrarLivro(Livro* livros, int totalLivros, int codigo) {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // Retorna -1 se o livro não for encontrado
}

// Função para emprestar um livro
void emprestarLivro(Livro* livros, int totalLivros) {
    int codigoLivro;
    printf("Digite o codigo do livro a ser emprestado: ");
    scanf("%d", &codigoLivro);

    int indiceLivro = encontrarLivro(livros, totalLivros, codigoLivro);

    if (indiceLivro != -1) {
        if (livros[indiceLivro].emprestado == 0) {
            livros[indiceLivro].emprestado = 1;
            printf("Livro emprestado com sucesso!\n");
        } else {
            printf("Livro já esta emprestado.\n");
        }
    } else {
        printf("Livro nao encontrado.\n");
    }
}

// Função para devolver um livro
void devolverLivro(Livro* livros, int totalLivros) {
    int codigoLivro;
    printf("Digite o codigo do livro a ser devolvido: ");
    scanf("%d", &codigoLivro);

    int indiceLivro = encontrarLivro(livros, totalLivros, codigoLivro);

    if (indiceLivro != -1) {
        if (livros[indiceLivro].emprestado == 1) {
            livros[indiceLivro].emprestado = 0;
            printf("Livro devolvido com sucesso!\n");
        } else {
            printf("Este livro nao esta emprestado.\n");
        }
    } else {
        printf("Livro nao encontrado.\n");
    }
}

// Função para listar livros emprestados
void listarEmprestados(Livro* livros, int totalLivros) {
    printf("Livros emprestados:\n");

    int emprestados = 0;
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].emprestado == 1) {
            printf("Codigo: %d, Titulo: %s, Autor: %s\n", livros[i].codigo, livros[i].titulo, livros[i].autor);
            emprestados++;
        }
    }

    if (emprestados == 0) {
        printf("Nenhum livro emprestado no momento.\n");
    }
}
// Função para exibir o menu
void exibirMenu() {
    printf("\n Menu:\n");
    printf("1 - Cadastrar Livro \n");
    printf("2 - Emprestar Livro \n");
    printf("3 - Devolver Livro \n");
    printf("4 - Listar Livros Emprestados \n");
    printf("0 - Sair \n");
    printf("Escolha uma opcao: ");
}

int main() {
    // Inicializar com valor diferente de 0 para entrar no loop
    Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int escolha = -1;

    while (escolha != 0) {
        exibirMenu();
        scanf("%d", &escolha);

 // direciona a logica conforme a escolha do usuario

        switch (escolha) {
            case 1:
                cadastrarLivro(livros, &totalLivros);
                break;
            case 2:
                emprestarLivro(livros, totalLivros);
                break;
            case 3:
                devolverLivro(livros, totalLivros);
                break;
            case 4:
                listarEmprestados(livros, totalLivros);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;

}