#include<iostream>
using namespace std;

struct Term{
    int coeff;
    int exp;;
}

int readPoly(Term poly[]){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>poly[i].coeff>>poly[i].exp;
    }
    return 0;
}

void printPoly(Term poly[], int n) {
    if (n == 0) { cout << "0\n"; return; }
    for (int i = 0; i < n; ++i) {
        int c = poly[i].coeff;
        int e = poly[i].exp;
        if (i > 0) cout << (c >= 0 ? " + " : " - ");
        if (c < 0) c = -c;
        if (!(c == 1 && e != 0)) cout << c;
        if (e != 0) {
            cout << "x";
            if (e != 1) cout << "^" << e;
        }
    }
    cout << "\n";
}

int addPoly(Term A[], int na, Term B[], int nb, Term C[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (A[i].exp == B[j].exp) {
            int s = A[i].coeff + B[j].coeff;
            if (s != 0) { C[k].coeff = s; C[k].exp = A[i].exp; ++k; }
            ++i; ++j;
        } else if (A[i].exp > B[j].exp) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < na) C[k++] = A[i++];
    while (j < nb) C[k++] = B[j++];
    return k;
}


int mulPoly(Term A[], int na, Term B[], int nb, Term C[]) {
    int cnt = 0;
    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < nb; ++j) {
            int coeff = A[i].coeff * B[j].coeff;
            int exp   = A[i].exp + B[j].exp;
            int found = -1;
            for (int t = 0; t < cnt; ++t) {
                if (C[t].exp == exp) { found = t; break; }
            }
            if (found != -1) {
                C[found].coeff += coeff;
            } else {
                C[cnt].coeff = coeff;
                C[cnt].exp   = exp;
                ++cnt;
            }
        }
    }
    int write = 0;
    for (int i = 0; i < cnt; ++i) {
        if (C[i].coeff != 0) C[write++] = C[i];
    }
    cnt = write;
    for (int i = 0; i < cnt; ++i) {
        int mx = i;
        for (int j = i+1; j < cnt; ++j) if (C[j].exp > C[mx].exp) mx = j;
        if (mx != i) {
            Term tmp = C[i]; C[i] = C[mx]; C[mx] = tmp;
        }
    }
    return cnt;
}

int main(){

    cout << "Input format:\n";
    cout << "n  (number of terms for poly A)\ncoeff1 exp1\ncoeff2 exp2\n... (terms in descending exponent order)\n";
    cout << "Then same for poly B.\n\n";

    Term A[MAX_TERMS], B[MAX_TERMS], C[MAX_TERMS];

    cout << "Enter polynomial A:\n";
    int na = readPoly(A);

    cout << "Enter polynomial B:\n";
    int nb = readPoly(B);

    cout << "\nA = ";
    printPoly(A, na);
    cout << "B = ";
    printPoly(B, nb);

    int nc = addPoly(A, na, B, nb, C);
    cout << "\nA + B = ";
    printPoly(C, nc);

    int nd = mulPoly(A, na, B, nb, C);
    cout << "A * B = ";
    printPoly(C, nd);
    
    return 0;
}