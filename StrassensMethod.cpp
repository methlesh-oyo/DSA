/*
	Square Matrix Multiply Recusrsive (Strassen's Method) - SM

	S1  = B12 - B22
	S2  = A11 + A12
	S3  = A21 + A22
	S4  = B21 - B11
	S5  = A11 + A22
	S6  = B11 + B22
	S7  = A12 - A22
	S8  = B21 + B22
	S9  = A11 - A21
	S10 = B11 + B12


	P1 = A11.S1
	P2 = S2.B22
	P3 = S3.B11
	P4 = A22.S4
	P5 = S5.S6
	P6 = S7.S8
	P7 = S9.S10

	C11 = P5 + P4 - P2 + P6
	C12 = P1 + P2
	C21 = P3 + P4
	C22 = P5 + P1 - P3 - P7

	Code assumes A and B having same size, and size is perfect power of 2.
*/

#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

// mode=0 for subtraction, mode=1 for addition
vector<vi> add(vector<vi> A, vector<vi> B, bool mode){
	vector<vi> C;
	int n=A.size();
	vi temp(n);
	for(int i=0; i<n; i++){
		C.push_back(temp);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){ 
			if(mode)
				C[i][j] = A[i][j] + B[i][j];
			else 
				C[i][j] = A[i][j] - B[i][j];

		}
	}
	return C;
}


vector<vi> SM(vector<vi> A, vector<vi> B){
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
   
   	vector<vi> S1  = add(B12, B22, 0);
   	vector<vi> S2  = add(A11, A12, 1);
   	vector<vi> S3  = add(A21, A22, 1);
   	vector<vi> S4  = add(B21, B11, 0);
   	vector<vi> S5  = add(A11, A22, 1);
   	vector<vi> S6  = add(B11, B22, 1);
   	vector<vi> S7  = add(A12, A22, 0);
   	vector<vi> S8  = add(B21, B22, 1);
   	vector<vi> S9  = add(A11, A21, 0);
   	vector<vi> S10 = add(B11, B12, 1);

   	vector<vi> P1 = SM(A11, S1);
	vector<vi> P2 = SM(S2, B22);
	vector<vi> P3 = SM(S3, B11);
	vector<vi> P4 = SM(A22, S4);
	vector<vi> P5 = SM(S5, S6);
	vector<vi> P6 = SM(S7, S8);
	vector<vi> P7 = SM(S9, S10);

	C11 = add(add(add(P5, P4, 1), P2, 0), P6, 1);
	C12 = add(P1, P2, 1);
	C21 = add(P3, P4, 1);
	C22 = add(add(P5, P1, 1), add(P3, P7, 1), 0);
    
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
    A=SM(A, B);
    cout<<"A.B is:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
	return 0; 
}

/*
Testcase:
4
5 7 9 10
2 3 3 8
8 10 2 3
3 3 4 8

3 10 12 18
12 1 4 9
9 10 12 2
3 12 4 10

Answer:
A.B is:
210 267 236 271 
93 149 104 149 
171 146 172 268 
105 169 128 169 
*/
