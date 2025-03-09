#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    string kode;
    float rating;
};


string tampilkanFilm(Film* film, int n) {
    string output = "Data Film:\n";
    for (int i = 0; i < n; i++) {
        output += "Kode: " + film[i].kode + 
                  ", Judul: " + film[i].judul + 
                  ", Rating: " + to_string(film[i].rating) + "\n";
    }
    return output;
}

int sequentialSearch(Film* film, int n, string kode) {
    for (int i = 0; i < n; i++) {
        if (film[i].kode == kode)
            return i;
    }
    return -1;
}

int binarySearch(Film* film, int left, int right, string judul) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (film[mid].judul == judul)
        return mid;
        if (film[mid].judul < judul)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


Film* quickSort(Film* film, int left, int right) {
    if (left >= right) return film;
    int i = left, j = right;
    float pivot = film[(left + right) / 2].rating;

    while (i <= j) {
        while (film[i].rating < pivot) i++;
        while (film[j].rating > pivot) j--;
        if (i <= j) {
            swap(film[i], film[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(film, left, j);
    if (i < right) quickSort(film, i, right);
    return film;
}

Film* bubbleSort(Film* film, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (film[j].rating < film[j + 1].rating) {
                swap(film[j], film[j + 1]);
            }
        }
    }
    return film;
}

int main() {
    int n = 5;
    Film film[5] = {
        {"One Piece", "A001", 9.0},
        {"The Godfather", "B002", 9.2},
        {"Interstellar", "J003", 8.9},
        {"Divergent", "S004", 8.5},
        {"Ashiap Man", "I005", 2.0}
    };
    cout << "===== Data Awal =====\n" << tampilkanFilm(film, n) << endl;
    // Sequential Search
    string kodeCari = "J003";
    int result = sequentialSearch(film, n, kodeCari);
    if (result != -1)
        cout << "Film dengan kode " << kodeCari << " ditemukan: " << film[result].judul << endl;
    else
        cout << "Film dengan kode " << kodeCari << " tidak ditemukan.\n";

    // Quick Sort 
    quickSort(film, 0, n - 1);
    cout << "\nSetelah Quick Sort Ascending berdasarkan Rating:\n" << tampilkanFilm(film, n);

    // Binary Search 
    string judulCari = "The Godfather";
    result = binarySearch(film, 0, n - 1, judulCari);
    if (result != -1)
        cout << "Film dengan judul " << judulCari << " ditemukan.\n";
    else
        cout << "Film dengan judul " << judulCari << " tidak ditemukan.\n";

    // Bubble Sort 
    bubbleSort(film, n);
    cout << "\nSetelah Bubble Sort Descending berdasarkan Rating:\n" << tampilkanFilm(film, n);

    return 0;
}