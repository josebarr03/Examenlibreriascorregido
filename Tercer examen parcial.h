#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>
void tercerexamen();
// Primer ejercicio
void instrucciones();
char AskYesNo(string question);
char HumanSymbol(char numberdice);
char opponent(char player);
char winner(const vector<char> board);
void displayBoard(const vector <char>& board);
int askNumber(string question, int high, int low);
bool isLegal(const vector<char>& board, int move);
int playerMove(const vector<char>& board, int move);
char dice(vector<char>& numbers);
// Segundo ejercicio
void segundoejercicio();

using namespace std;

const char NO_ONE = 'N';
const char EMPTY = ' '; //Constante global para determinar el valor en los espacios que en este caso es vacio
const char  X = 'X'; //Creamos una variable global porque es un valor que es parte del juego
const char  O = 'O'; //Creamos una variable global porque es un valor que es parte del juego
const char TIE = 'T';
vector<char> numbers = { '1', '2', '3', '4', '5', '6' };

void tercerexamen(char numberdice)
{
    segundoejercicio();
    setlocale(LC_ALL, "spanish");
    char validation;
    char player = HumanSymbol(numberdice); //Para que tome el valor de la funcion que creamos abajo en caso de querer comenzar primero
    char computer = opponent(player); //Para que tome el valor contrario que elija el jugador usando la funcion de opponent
    char turn = X; //porque es mas natural que el juego inicie con la X. Toma su valor de la constante global

    const int NUM_SQUARES = 9; //Contsante para declarar el tamaño
    vector<char> board(NUM_SQUARES, EMPTY); /// 10 es el numero de espacios y los espacios van a estar vacios
    int move;
    char numberdice = dice(numbers);

    instrucciones(); // Mostrar instrucciones. Va a dejar que el jugador elija la letra
    cout << "El numero elegido por el dado es: " << numberdice << endl;

    while (winner(board) == NO_ONE)
    {
        if (turn == player)
        {
            cout << "Que posicion desea reemplazar?" << endl;
            cin >> move;
            cout << endl;

            board[move] = player;
            displayBoard(board);
            playerMove(board, move);
        }
        else
        {

        }
    }
}
// Primer ejercicio
void instrucciones()
{
    cout << "\nBienvenido: \n";
    cout << "\nElige una posicion entre el 0 y el 8.\n\n";
    cout << "|0|1|2|\n";
    cout << "|3|4|5|\n";
    cout << "|6|7|8|\n";

    cout << "\nQue comience la batalla!\n";
}
char HumanSymbol(char numberdice)
{
    char gofirst = AskYesNo("Se va a lanzar un dado. Si atinas si el numero es par o impar comienzas. Que elijes?");

    if (gofirst == 'p')
    {
        if (numberdice % 2 == 0)
        {
            return X;
        }
        else
        {
            return O;
        }
    }
    else if (gofirst == 'i')
    {
        if (numberdice % 2 == 0)
        {
            return O;
        }
        else
        {
            return X;
        }
    }
}
char AskYesNo(string question) //Esta es una funcion exclusivamente para obtener algo del answer que en este caso es Yes o No
{
    char answer;
    do
    {
        cout << "\n" << question << "(p/i)"; //
        cin >> answer;

    } while (answer != 'p' && answer != 'i'); //

    return answer;
}
char opponent(char player)
{

    if (player == X)

    {
        return O;

    }

    else
    {
        return X;
    }
}
char winner(const vector<char> board)
{
    //Son todas las posibilidades para ganar
    const int WINNING_POS[8][3] = { {0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {2, 4, 6},
                                    {0, 4, 8}, };

    const int TOTAL_ROWS = 8;

    //Para regresar al ganador.
    //Logica: el for nes para ir aumentando de fila en fila porque ahí está cada condicion de gane
    //los diferentes IFs es para que se cumpla suponiendo que la X esta en el espacio 0,1,2 y 3,4,5, etc.
    //porque si el espacio 1 es igual al 2 y el 2 al 3, entonces se cumple el win
    for (int row = 0; row < TOTAL_ROWS; row++)
    {

        if ((board[WINNING_POS[row][0]] != EMPTY) && //Para que el espacio no este vacio
            (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) && // [row] es la fila y [] es el numero de la columna
            (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]])) // [row] es la fila y [] es el numero de la columna
        {
            return board[WINNING_POS[row][0]];

        }
    }

    //Para regresar si es un empate. Porque checa todo el tablero que este llenom y si esta lleno y no hubo un ganador
    //por la fucnion de arriba, significa que nadie gano

    if (count(board.begin(), board.end(), EMPTY) == 0) //el count es una funcion que se reinicia
    {
        return TIE;
    }

    //regresar que nadie ha ganado todavia

    return NO_ONE;

}
void displayBoard(const vector <char>& board)
{
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}
int playerMove(const vector<char>& board, int move)
{
    int number = askNumber("Elige un espacio entre: ", 8, 0);
    bool legal = isLegal(board, move);
    do
    {
        number;
        legal;
    } while (!legal);

    return number;
}
int askNumber(string question, int high, int low)
{
    string input;
    bool isValid = false;
    bool isValidRange = false;
    int number = 0;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        cout << question << low << " y " << high << endl;
        getline(cin, input);
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isValid = false;
                break;
            }
            else
            {
                isValid = true;
                break;
            }
        }
        if (!isValid)
        {
            cout << "Entrada invalida, por favor elige solo numeros" << endl;
        }
        else
        {
            number = stoi(input);
            isValidRange = number <= high && number >= low;
        }

        if (!isValidRange && isValid)
        {
            cout << "Entrada invalida, elige un numero del 0 al 8" << endl;
        }
    } while (!isValid || !isValidRange || input.empty());
    return number;
}
bool isLegal(const vector<char>& board, int move)
{
    if (board[move] == EMPTY)
    {
        return true;
    }
    else
    {
        return false;
        cout << "El espacio y esta ocupado, escoja otro" << endl;
    }
}
char dice(vector<char>& numbers)
{
    srand(time(NULL));
    int numberRandomIndex = (rand() % numbers.size());
    char numberSelected = numbers[numberRandomIndex];

    return numberSelected;
}
//
void segundoejercicio()
{
    const int ROWS = 3; // Declaracion entero constante del numero filas
    const int COLUMNS = 4; // Declaracion entero constante del numero columnas
    int resultadosuma;
    int board[ROWS][COLUMNS] = { { 2 , 3 , 1 , 4 },
                                    { 9 , 8 , 7 , 9 },
                                    { 3 , 2 , 1 , 5 }}; // Matriz
    for (int i = 0; i < ROWS; i++) // ciclo for para crear la tabla donde posteriormente se pondran caracteres
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];
        }
        cout << endl << endl;
    }
    resultadosuma = board[0][0] + board[0][3] + board[1][1] + board[2][1];
    cout << resultadosuma;
}