#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

string p;
map<char, bool> chutou;
vector<string> palavras;
vector<char> chutes_errados;

void imprimePalavra(string palavra, map<char, bool> chutou)
{
    for (char l : palavra)
    {
        if (chutou[l])
        {
            cout << l << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool verificaletra(char letra, string palavra)
{
    for (char l : palavra)
    {
        if (l == letra)
        {
            chutou[l] = true;
            return true;
        }
    }
    return false;
}

void imprimeChutesErrados(vector<char> v)
{
    for (char c : v)
    {
        cout << c << " ";
    }
    cout << endl;
}

void mapeia_palavra(map<char, bool> &chutes, string palavra)
{
    for (char c : palavra)
    {
        chutes.insert(pair<char, bool>(c, false));
    }
}

bool nao_acertou()
{
    for (char letra : p)
    {
        if (!chutou[letra])
        {
            return true;
        }
    }
    return false;
}

bool nao_enforcou(int tentativas)
{
    return chutes_errados.size() < tentativas;
}

void define_palavra()

{
    srand(time(NULL));
    p = palavras[rand() % palavras.size()];
}

vector<string> le_palavra()
{
    vector<string> novas_palavras;
    ifstream arquivo;
    arquivo.open("palavra.txt");
    if (arquivo.is_open())
    {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        for (int i = 0; i < quantidade_palavras; i++)
        {
            string s;
            arquivo >> s;
            novas_palavras.push_back(s);
        }
    }
    arquivo.close();
    return novas_palavras;
}

void salva_arquivo(vector<string> Nlista)
{
    ofstream arquivo;
    arquivo.open("palavra.txt");
    if (arquivo.is_open())
    {
        arquivo << Nlista.size() << endl;
        for (string s : Nlista)
        {
            arquivo << s << endl;
        }
        arquivo.close();
    }
}

void adiciona_palavra(string nova)
{
    vector<string> lista = le_palavra();
    lista.push_back(nova);

    salva_arquivo(lista);
}

void adiciona()
{
    cout << "Quer adicionar palavras ao banco?" << endl;
    cout << "Sim (1) | Nao (2)" << endl;

    int r;
    cin >> r;
    string Npalavra;
    switch (r)
    {
    case 1:
        cout << "Digite a nova palavra: ";
        cin >> Npalavra;
        adiciona_palavra(Npalavra);
        break;
    case 2:
    default:
        cout << "Obrigado por jogar" << endl;
        break;
    }
}

int main()
{
    palavras = le_palavra();
    define_palavra();

    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;

    mapeia_palavra(chutou, p);
    bool acertou_palavra = false;
    bool perdeu = false;

    while (nao_acertou() && nao_enforcou(10))
    {
        cout << "Restam " << 10 - chutes_errados.size() << " tentativas" << endl;

        cout << "Chutes Errados: ";
        imprimeChutesErrados(chutes_errados);
        imprimePalavra(p, chutou);

        char chute;
        cout << "Chute uma LETRA: ";
        cin >> chute;

        bool resultado = verificaletra(chute, p);

        if (resultado)
        {
            cout << "Letra existe na palavra" << endl;
        }
        else
        {
            // tentativas--;
            chutes_errados.push_back(chute);
            cout << "Letra nao existe" << endl;
        }
    }
    if (!nao_acertou())
    {
        cout << "Parabens, voce acertou a palavra " << p << endl;
    }
    else
    {
        cout << "Que pena, voce foi enforcado! A palavra era " << p << endl;
    }
    adiciona();
    return 0;
}
