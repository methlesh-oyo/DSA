/*
	Square Matrix Multiply Recusrsive - SMMR

	C11 = A11.B11 + A12.B21
	C12 = A11.B12 + A12.B22
	C21 = A21.B11 + A22.B21
	C22 = A21.B12 + A22.B22

	Code assumes A and B having same size, and size is perfect power of 2.
*/

#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

vector<vi> add(vector<vi> A, vector<vi> B){
	vector<vi> C;
	int n=A.size();
	vi temp(n);
	for(int i=0; i<n; i++){
		C.push_back(temp);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}


vector<vi> SMMR(vector<vi> A, vector<vi> B){
	int n = A.size();
	vector<vi> C;
	vi temp;
	if(n==1){
		temp.push_back(A[0][0] * B[0][0]);
		C.push_back(temp);
		return C;
	}
	vector<vi> A11, A12, A21, A22;
	vector<vi> B11, B12, B21, B22;
	vector<vi> C11, C12, C21, C22;
	temp.assign(n/2, 0);
	for(int i=0; i<n/2; i++){
		A11.push_back(temp);
		A12.push_back(temp);
		A21.push_back(temp);
		A22.push_back(temp);

		B11.push_back(temp);
		B12.push_back(temp);
		B21.push_back(temp);
		B22.push_back(temp);
	}

	// A11
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			A11[i][j] = A[i][j];
		}
	}
	// A12
	for(int i=0; i<n/2; i++){
		for(int j=n/2; j<n; j++){
			A12[i][j - n/2] = A[i][j];
		}
	}
	// A21
	for(int i=n/2; i<n; i++){
		for(int j=0; j<n/2; j++){
			A21[i - n/2][j] = A[i][j];
		}
	}
	// A22
	for(int i=n/2; i<n; i++){
		for(int j=n/2; j<n; j++){
			A22[i - n/2][j - n/2] = A[i][j];
		}
	}

	// B11
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			B11[i][j] = B[i][j];
		}
	}
	// B12
	for(int i=0; i<n/2; i++){
		for(int j=n/2; j<n; j++){
			B12[i][j - n/2] = B[i][j];
		}
	}
	// B21
	for(int i=n/2; i<n; i++){
		for(int j=0; j<n/2; j++){
			B21[i - n/2][j] = B[i][j];
		}
	}
	// B22
	for(int i=n/2; i<n; i++){
		for(int j=n/2; j<n; j++){
			B22[i - n/2][j - n/2] = B[i][j];
		}
	}
   
	C11 = add(SMMR(A11, B11), SMMR(A12, B21));
	C12 = add(SMMR(A11, B12), SMMR(A12, B22));
	C21 = add(SMMR(A21, B11), SMMR(A22, B21));
	C22 = add(SMMR(A21, B12), SMMR(A22, B22));
    
    temp.assign(n, 0);
	for(int i=0; i<n; i++){
		C.push_back(temp);
	}
    
	// C11
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			C[i][j] = C11[i][j];
		}
	}
	// C12
	for(int i=0; i<n/2; i++){
		for(int j=n/2; j<n; j++){
			C[i][j] = C12[i][j - n/2];
		}
	}
	// C21
	for(int i=n/2; i<n; i++){
		for(int j=0; j<n/2; j++){
			C[i][j] = C21[i - n/2][j];
		}
	}
	// C22
	for(int i=n/2; i<n; i++){
		for(int j=n/2; j<n; j++){
			C[i][j] = C22[i - n/2][j - n/2];
		}
	}
    
	return C;
}

int main(){
    vector<vi> A, B;
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        vi tmp;
        for(int j=0; j<n; j++){       
            cin>>x;
            tmp.push_back(x);
        }
        A.push_back(tmp);
    }
    
    for(int i=0; i<n; i++){
        vi tmp;
        for(int j=0; j<n; j++){       
            cin>>x;
            tmp.push_back(x);
        }
        B.push_back(tmp);
    }
    A=SMMR(A, B);
    cout<<"A.B is:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
	return 0; 
}
