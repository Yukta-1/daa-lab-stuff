#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef vector<vector<int>> matrix;
matrix init (int len) {
    matrix M;
    for (int i = 0; i < len; i++){
        vector<int> row;
        for (int j = 0; j < len; j++)
            row.push_back(0);
        M.push_back(row);
    }
    return M;
}

matrix MATfill (int len) {
    matrix M;
    for (int i = 0; i < len; i++){
        vector<int> row;
        for (int j = 0; j < len; j++)
            row.push_back(rand()%len);
        M.push_back(row);
    }
    return M;
}


matrix Quad (matrix M, int qno) {
    matrix Q;
    int starth, startv, endh, endv, i ,j;
    if (qno == 1){
        starth = startv = 0;
        endh = endv = M.size()/2;
    }
    else if (qno == 2){
        starth = 0;
        startv = M.size()/2;
        endh = M.size()/2;
        endv = M.size();
    }
    else if (qno == 3){
        starth  = M.size()/2;
        startv = 0;
        endh = M.size();
        endv = M.size()/2;
    }
    else if (qno == 4){
        starth = startv = M.size()/2;
        endh = endv = M.size();
    }
    for (i = starth; i < endh; i++){
        vector<int> row;
        for (j = startv; j < endv; j++)
            row.push_back(M[i][j]);
        Q.push_back(row);
    }
    return Q;
}
void Add (matrix &C, matrix A, matrix B, int starth, int endh, int startv, int endv) {
    for (int i = startv; i < endv; i++){
        for (int j = starth; j < endh; j++)
            C[i][j] = A[i - startv][j - starth] + B[i - startv][j - starth];
    }
}

void matrixPrint(matrix M) {
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); j++){
            cout<< M[i][j]<< " ";
        }
        cout<< "\n";
    }
}
matrix DivConquerProd(matrix A, matrix B) {
    int len = A.size();
    matrix C = init(len);
    if (len == 1)
        C[0][0] = A[0][0]*B[0][0];
    else{
        // Add(C, A, B, starth, endh, startv, endv)
        Add(C, DivConquerProd(Quad(A, 1), Quad(B, 1)), DivConquerProd(Quad(A, 2), Quad(B, 3)), 0, len/2, 0, len/2);
        Add(C, DivConquerProd(Quad(A, 1), Quad(B, 2)), DivConquerProd(Quad(A, 2), Quad(B, 4)), len/2, len, 0, len/2);
        Add(C, DivConquerProd(Quad(A, 3), Quad(B, 1)), DivConquerProd(Quad(A, 4), Quad(B, 3)), 0, len/2, len/2, len);
        Add(C, DivConquerProd(Quad(A, 3), Quad(B, 2)), DivConquerProd(Quad(A, 4), Quad(B, 4)), len/2, len, len/2, len);
    }
    return C;
}
int main()
{
    int N=32;
    matrix A = MATfill(N);
    matrix B = MATfill(N);

    

    auto start = high_resolution_clock::now();
    matrix C = DivConquerProd(A, B);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    matrixPrint(C);
    cout<<endl;
    cout << "Time taken by function is : "<< duration.count() << " ns" << endl;
    return 0;
}