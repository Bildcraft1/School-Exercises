#include <iostream>
#include <cstdlib>
#include <random>
#include "../utils/tabulate/tabulate.hpp"

using namespace std;

std::random_device rd;
std::mt19937 rng(rd());

void caricaArrayRandom(int array[], int size) {
    uniform_int_distribution<int> random_number(0, 10);
    // Carico l'array in modo random controllando che non ci siano valori uguali, se c'è un valore uguale genero un nuovo numero
    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        array[i] = random_number(rng);
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j] && !isDuplicate) {
                i--;
                isDuplicate = true;
            }
        }
    }

}

void leggiArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void stampaRisultati(int insieme1[], int sizeInsieme1, int insieme2[], int sizeInsieme2, int intersezione[], int sizeIntersezione) {
    tabulate::Table table;
    table.add_row({"Insieme 1", "Insieme 2", "Intersezioni"});
    for (int i = 0; i < sizeInsieme1; i++) {
        if (i < sizeIntersezione) {
            table.add_row({to_string(insieme1[i]), to_string(insieme2[i]), to_string(intersezione[i])});
        } else {
            table.add_row({to_string(insieme1[i]), to_string(insieme2[i]), ""});
        }
    }

    // Formattazione Tabella
    table.format()
        .border_top(" ")
        .border_bottom(" ")
        .border_left(" ")
        .border_right(" ")
        .corner(" ");

    // Formattazione Header
    table[0].format()
        .font_color(tabulate::Color::yellow)
        .font_align(tabulate::FontAlign::center)
        .font_background_color(tabulate::Color::blue)
        .padding_top(1)
        .padding_bottom(1)
        .font_style({tabulate::FontStyle::bold});

    // Formattazione Colonne
    table.column(0).format()
        .font_color(tabulate::Color::cyan)
        .font_align(tabulate::FontAlign::center);
    
    table.column(1).format()
        .font_color(tabulate::Color::magenta)
        .font_align(tabulate::FontAlign::center);
    
    table.column(2).format()
        .font_color(tabulate::Color::cyan)
        .font_align(tabulate::FontAlign::center);

    // Formattazione Larghezza Colonne
    table.column(0).format().width(20);
    table.column(1).format().width(20);
    table.column(2).format().width(30);

    cout << table << endl;
}

void trovaIntersezioni(int insieme1[], int insieme2[], int intersezione[], int sizeInsiemi, int &sizeIntersezione) {
    for (int i = 0; i < sizeInsiemi; i++) {
        for (int j = 0; j < sizeInsiemi; j++) {
            if (insieme1[i] == insieme2[j]) {
                intersezione[sizeIntersezione] = insieme1[i];
                sizeIntersezione++;
            }
        }
    }
}

void sortArray(int array[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX_SIZE = 30;
    int insieme1[MAX_SIZE], insieme2[MAX_SIZE];
    int sizeInsiemi = 0;
    int intersezione[MAX_SIZE];
    int sizeIntersezione = 0;

    do {
        cout << "Inserisci la dimensione degli insiemi (MAX 30): ";
        cin >> sizeInsiemi;
    } while (sizeInsiemi > MAX_SIZE || sizeInsiemi < 0);

    caricaArrayRandom(insieme1, sizeInsiemi);
    caricaArrayRandom(insieme2, sizeInsiemi);

    sortArray(insieme1, sizeInsiemi);
    sortArray(insieme2, sizeInsiemi);

    trovaIntersezioni(insieme1, insieme2, intersezione, sizeInsiemi, sizeIntersezione);

    cout << endl;
    cout << "Risultati: " << endl;

    stampaRisultati(insieme1, sizeInsiemi, insieme2, sizeInsiemi, intersezione, sizeIntersezione);

    return 0;
}