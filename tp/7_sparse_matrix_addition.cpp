#include<iostream>
using namespace std;



class SparseMatrix{
    private:
        int matrix[100][100], rows, cols;
        int sparse[100][100];
    
    public:

        void accept_sparse_matrix(){
            cout<<"Enter rows and columns : ";
            cin>>rows>>cols;

            matrix[rows][cols];

            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    cout<<"Enter Element : matrix["<<i<<"]"<<"["<<j<<"] : ";
                    cin>>matrix[i][j];
                }
            }
        }   


        void create_sparse_matrix(){
            int k = 1;
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(matrix[i][j] != 0){
                        sparse[k][0] = i;
                        sparse[k][1] = j;
                        sparse[k][2] = matrix[i][j];
                        k++;
                    }
                }
            }

            sparse[0][0] = rows;
            sparse[0][1] = cols;
            sparse[0][2] = k-1;
        }


        void addition1D(SparseMatrix &B){
            int l1, l2, i=1, j=1, k=1;
            int result[100][3];

            l1 = sparse[0][2];
            l2 = B.sparse[0][2];

            result[0][0] = sparse[0][0];
            result[0][1] = sparse[0][1];

            while(i<=l1 && j<=l2){
                if(sparse[i][0] == B.sparse[j][0]){
                    if(sparse[i][1] == B.sparse[j][1]){
                        result[k][0] = sparse[i][0];
                        result[k][1] = sparse[i][1];
                        result[k][2] = sparse[i][2] + B.sparse[j][2];
                        i++;
                        j++;
                        k++;
                    }

                    else{
                        if(sparse[i][0] < B.sparse[j][0]){
                            result[k][0] = sparse[i][0];
                            result[k][1] = sparse[i][1];
                            result[k][2] = sparse[i][2];
                            i++;
                            k++;
                        }
                        
                        else{
                            result[k][0] = B.sparse[j][0];
                            result[k][1] = B.sparse[j][1];
                            result[k][2] = B.sparse[j][2];
                            j++;
                            k++;
                        }
                    }
                }

                else{
                    if(sparse[i][0] < B.sparse[j][0]){
                        result[k][0] = sparse[i][0];
                        result[k][1] = sparse[i][1];
                        result[k][2] = sparse[i][2];
                        i++;
                        k++;
                    }
                    else{
                        if(sparse[i][0] > B.sparse[j][0]){
                            result[k][0] = B.sparse[j][0];
                            result[k][1] = B.sparse[j][1];
                            result[k][2] = B.sparse[j][2];
                            j++;
                            k++;
                        }
                    }
                }

            }

            while((j<=l2) && (i>=l1)){
                result[k][0] = B.sparse[j][0];
                result[k][1] = B.sparse[j][1];
                result[k][2] = B.sparse[j][2];
                j++;
                k++;
            }

            while((i<=l1) && (j>=l2)){
                result[k][0] = sparse[i][0];
                result[k][1] = sparse[i][1];
                result[k][2] = sparse[i][2];
                i++;
                k++;
            }

            result[0][2] = k-1;


            cout<<"Addition of sparse Matrix : \n";

            for(int i=0; i<=result[0][2]; i++){
                for(int j=0; j<3; j++){
                    cout<<result[i][j]<<" ";
                }cout<<endl;
            }
        }
    
};

int main(){
    SparseMatrix s1, s2;
    s1.accept_sparse_matrix();
    s1.create_sparse_matrix();

    s2.accept_sparse_matrix();
    s2.create_sparse_matrix();


    s1.addition1D(s2);


    return 0;
}