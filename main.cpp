#include <iostream>
#include <string>
#include <vector>
using namespace std;
class  Matrix
{
private:
    int m, n;
    vector<int> mvec;
public:
    Matrix(int x, int y): m(x), n(y), mvec(vector<int>(x*y, 1)){};

    int getm(){
        return m;
    }
    int getn(){
        return n;
    }

    void set(int p, int q){
        mvec.at(p) = q;
    }
    int get(int p){
        return mvec.at(p);
    }

    int &Matrix::operator()(int row, int col)
    {
        int pos{0};
        pos = m*row + col;
        return mvec.at(pos);
    }

    void Matrix::print()
    {
        for(int i =0; i < m; i++)
        {
            for(int j =0; j < n; j++)
            {
                cout<< mvec.at(m*i+j) << " ";
            }
            cout << "\n";
        }
        cout<<"\n";
    }

    Matrix operator+(const Matrix& B) const {
        if ((this->m != B.m) || (this->n != B.n))
        {
            cout << "Matrix size ERROR!";
            return Matrix(0, 0);
        }

        Matrix M (B.m, B.n);
        for ( int i =0; i<M.mvec.size(); i++)
        {
            M.mvec.at(i) = this->mvec.at(i) + B.mvec.at(i);
        }
        return M;
    }

    Matrix operator+=( Matrix& B)  {
        if ((this->m != B.m) || (this->n != B.n))
        {
            cout << "Matrix size ERROR!";
            return Matrix(0, 0);
        }

        Matrix M (B.m, B.n);
        for ( int i =0; i<M.mvec.size(); i++)
        {
            M.mvec.at(i) = this->mvec.at(i) + B.mvec.at(i);
            this->set(i,  M.mvec.at(i));
        }
        return M;
    }

    Matrix operator-=( Matrix& B)  {
        if ((this->m != B.m) || (this->n != B.n))
        {
            cout << "Matrix size ERROR!";
            return Matrix(0, 0);
        }

        Matrix M (B.m, B.n);
        for ( int i =0; i<M.mvec.size(); i++)
        {
            M.mvec.at(i) = this->mvec.at(i) - B.mvec.at(i);
            this->set(i,  M.mvec.at(i));
        }
        return M;
    }

    Matrix operator*( int l) {
        Matrix M (this->m, this->n);
        for ( int i =0; i<this->mvec.size(); i++)
        {
            this->set(i,  this->mvec.at(i)*l);
            M.set(i, this->mvec.at(i));
        }
        return M;
    }

    Matrix operator<<( int l) {
        Matrix M (this->m, this->n);
        for ( int i =0; i<this->mvec.size(); i++)
        {
            this->set(i,  this->mvec.at(i)+l);
            M.set(i, this->mvec.at(i));
        }
        return M;
    }

    Matrix operator>>( int l) {
        Matrix M (this->m, this->n);
        for ( int i =0; i<this->mvec.size(); i++)
        {
            this->set(i,  this->mvec.at(i)-l);
            M.set(i, this->mvec.at(i));
        }
        return M;
    }


};



int main()
{
    Matrix M1(3, 3);
    Matrix M2(3, 3);
    Matrix M(3, 3);
    M1 +=M2;
    M1.print();
    M2 -= M1;
    M2.print();
    M1.print();
    M = M1 * 3;
    M.print();
    M<<3;
    M.print();
    M>>4;
    M.print();
    return 0;
}