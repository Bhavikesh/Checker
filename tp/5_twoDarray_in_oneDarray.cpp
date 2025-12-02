#include<iostream>
using namespace std;

class Matrix1D{
    private:
        int *arr; 
        int rows, cols;
        int size;
        bool rowMajor;

    public:

        Matrix1D(int r, int c, bool isRowMajor){
            rows = r;
            cols = c;
            rowMajor = isRowMajor;

            size = rows*cols;
            arr = new int[size];
            for(int i=0; i<size; i++){
                arr[i] = 0;
            }
        }

        ~Matrix1D(){
            delete []arr;
        }

        int indexof(int r, int c){
            if(rowMajor){
                return r * cols + c;
            }
            else{
                return c * rows + r;
            }
        }

        void set(int r, int c, int val){
            int indx = indexof(r,c);
            arr[indx] = val;
        }

        int get(int r, int c){
            int indx = indexof(r,c);
            return arr[indx];
        }

        void print(){
            cout<<"\nMatrix ("<<rows<<" x "<<cols<<")"<<"Layout : "<< (rowMajor?"Row Major\n":"Column Major\n")<<endl;
            for(int i = 0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    int indx = indexof(i,j);
                    cout<<arr[indx]<<" ("<<arr + indx<<")"<<endl;  
                }
                cout<<endl;
            }   
        }

        void insert1D(int pos, int val){
            if(pos<0) pos = 0;
            if(pos>size) pos = size;

            int *newArr = new int[size+1];

            for(int i=0; i<pos; i++){
                newArr[i] = arr[i];
            }

            newArr[pos] = val;

            for(int i = pos; i<size; i++){
                newArr[i+1] = arr[i];
            }

            delete []arr;
            arr = newArr;
            size +=1;
        }

        void delete1D(int pos){
            int *newArr = new int[size-1];

            for(int i=0; i<pos; i++){
                newArr[i] = arr[i];
            }

            for(int i=pos+1; i<size; i++){
                newArr[i-1] = arr[i];
            }

            delete []arr;
            arr = newArr;
            size -=1;
        }

        static Matrix1D* merge(Matrix1D &A, Matrix1D &B){

            Matrix1D* M = new Matrix1D(1, A.size + B.size, A.rowMajor);

            int k=0;
            
            for(int i=0; i<A.size; i++){
                M->arr[k++] = A.arr[i];
            }

            for(int i=0; i<B.size; i++){
                M->arr[k++] = B.arr[i];
            }

            return M;
        }


        void fill(){
            cout<<"Enter "<<size << "Values : "<<endl;

            int r=0, c=0;

            for(int i=0; i<size; i++){
                int v;
                cin>>v;
                set(r,c,v);

                c++;
                if(c==cols){
                    c=0;
                    r++;
                }
            }

        }

};


int main(){
    int r,c,layout;

    cout<<"Enter rows and cols : ";
    cin>>r>>c;

    cout<<"Enter layout \n1 = Row major\n0 = column major\n";
    cin>>layout;

    Matrix1D A(r,c,layout==1);
    A.fill();

    int choice;
    while(true){
        cout<<"\nMenu\n";
        cout<<"1) Print matrix with address\n";
        cout<<"2) Insert at 1D pos\n";
        cout<<"3) Delete at 1D pos\n";
        cout<<"4) Merge with another matrix\n";
        cout<<"0) Exit\n0";

        cout<<"Enter choice";
        cin>>choice;

        if(choice == 1){
            A.print();
        }

        if(choice == 2){
            int pos,val;
            cout<<"Enter pos and value : ";
            cin>>pos>>val;
            A.insert1D(pos,val);
            cout<<"Inserted\n";
        }

        if(choice == 3){
            int pos;
            cout<<"Enter pos : ";
            cin>>pos;
            A.delete1D(pos);
            cout<<"Deleted\n";
        }

        if(choice == 4){
            int r2, c2, l2;
            cout<<"Enter rows and columns for matrix B : ";
            cin>>r2>>c2;

            cout<<"Layout :\n1 = Row major\n0 = Column major\n";
            cin>>l2;

            Matrix1D B(r2,c2,l2==1);
            B.fill();

            Matrix1D* M = Matrix1D::merge(A,B);

            cout<<"Merged Matrix\n";
            M->print();

            delete M;
        }

        else if(choice == 0) break;
    }

    return 0;
}