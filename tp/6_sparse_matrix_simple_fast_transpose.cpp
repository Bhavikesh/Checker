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

        void transposeMatrix(){
            int transpose[100][3];
            int k = 1;
            for(int z=0; z<sparse[0][1]; z++){
                for(int i=1; i<=sparse[0][2]; i++){
                    if(sparse[i][1] == z){
                        transpose[k][0] = sparse[i][1];
                        transpose[k][1] = sparse[i][0];
                        transpose[k][2] = sparse[i][2];
                        k++;
                    }
                }
            }

            transpose[0][0] = sparse[0][1];
            transpose[0][1] = sparse[0][0];
            transpose[0][2] = sparse[0][2];

            for(int i=0; i<=transpose[0][2]; i++){
                for(int j=0; j<3;j++){
                    cout<<transpose[i][j]<<" ";
                }cout<<endl;    
            }
        }

        void displaySparse(){
            for(int i=0; i<=sparse[0][2]; i++){
                for(int j=0; j<3;j++){
                    cout<<sparse[i][j]<<" ";
                }cout<<endl;    
            }
        }


        void fastTranspose(){
            int result[100][3], loc, col_no;
            int total[sparse[0][1]];
            int index[sparse[0][1]+1];

            for(int i=0; i<sparse[0][1]; i++){
                total[i] = 0;
            }

            for(int i=1; i<=sparse[0][2]; i++){
                col_no = sparse[i][1];
                total[col_no]++;
            }

            index[0] = 1;

            for(int i=1; i<=sparse[0][1]; i++){
                index[i] = index[i-1] + total[i-1];
            }

            result[0][0] = sparse[0][1];
            result[0][1] = sparse[0][0];
            result[0][2] = sparse[0][2];

            for(int i=1; i<=sparse[0][2]; i++){
                col_no = sparse[i][1];
                loc = index[col_no];
                result[loc][0] = sparse[i][1];
                result[loc][1] = sparse[i][0];
                result[loc][2] = sparse[i][2];
                index[col_no]++;
            }

            for(int i=0; i<=result[0][2]; i++){
                for(int j=0; j<3;j++){
                    cout<<result[i][j]<<" ";
                }cout<<endl;    
            }
        }
    

};




int main(){
    SparseMatrix s;
    s.accept_sparse_matrix();
    s.create_sparse_matrix();
    cout<<"--------------------------"<<endl;
    s.displaySparse();
    cout<<"--------------------------"<<endl;
    s.transposeMatrix();
    cout<<"--------------------------"<<endl;
    s.fastTranspose();
    cout<<"--------------------------"<<endl;
}