#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Usuario {
    string nome;
    string email;
    string senha;
};

void CadastrarUsuario(vector<Usuario> &usuarios);
void ExibirLista(const vector<Usuario> &usuarios);
bool FazerLogin(const vector<Usuario> &usuarios);

void CadastrarUsuario(vector<Usuario> &usuarios) {
    string nome, email, senha;
    cout << "Insira o nome do usuário: ";
    cin >> nome;
    cout << "Insira o email do usuário: ";
    cin >> email;
    cout << "Insira a senha do usuário: ";
    cin >> senha;

    Usuario novo_usuario = {nome, email, senha};
    usuarios.push_back(novo_usuario);
    cout << "Usuário cadastrado com sucesso!\n";
}

void ExibirLista(const vector<Usuario> &usuarios) {
    cout << "\nLista de usuários:\n";
    for (const auto &usuario : usuarios) {
        cout << usuario.nome << " - " << usuario.email << endl;
    }
}

bool FazerLogin(const vector<Usuario> &usuarios) {
    string email, senha;
    cout << "Insira seu email: ";
    cin >> email;
    cout << "Insira sua senha: ";
    cin >> senha;

    for (const auto &usuario : usuarios) {
        if (usuario.email == email && usuario.senha == senha) {
            cout << "Você está logado!\n";
            return true;
}
}
    cout << "Email ou senha incorretos. Tente novamente.\n";
    return false;
}

int main() {
  vector<Usuario> usuarios;
  int opcao_desejada;
  bool continuar = true;
  bool logado = false;

  cout << "Bem vindo ao sistema de cadastro de usuario\n";
  while (continuar) {
    cout << "\nMenu de opções:";
    cout << "\n1. Cadastrar usuario";
    cout << "\n2. Fazer login";
    cout << "\n3. Exibir lista (apenas para usuários logados)";
    cout << "\n4. Sair do sistema";
    cout << "\nDigite a opção desejada: ";
    cin >> opcao_desejada;

      switch (opcao_desejada) {
        case 1:
          CadastrarUsuario(usuarios);
            break;
        case 2:
          logado = FazerLogin(usuarios);
            break;
        case 3:
          if (logado) {
          ExibirLista(usuarios);
}           else {
            cout << "Você precisa estar logado para exibir a lista de usuários.\n";
}
            break;
        case 4:
           cout << "Saindo do sistema\n";
            continuar = false;
            break;
            default:
           cout << "Opção inválida. Por favor, escolha uma opção válida.\n";
            break;
}
}
    return 0;
}
