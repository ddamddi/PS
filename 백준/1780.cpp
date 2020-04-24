    #include <iostream>
    #define MAX_NUM 2200
    using namespace std;

    int arr[MAX_NUM][MAX_NUM];
    int ans[3];

    bool checkArray(int a, int b, int term){
        int num = arr[a][b];
        for(int i=0; i<term; i++){
            for(int j=0; j<term; j++){
                if(num != arr[a+i][b+j])
                    return false;
            }
        }
        return true;
    }

    void divideNconquer(int a, int b, int term){

        bool isAllSame = checkArray(a, b, term);
        
        if(!isAllSame){
            int new_term = term/3;
            for(int i=0; i<3; i++){
                int new_a = a + i*new_term;
                for(int j=0; j<3; j++){
                    int new_b = b + j*new_term;
                    divideNconquer(new_a, new_b, new_term);
                }
            }
        }
        else{
            int num = arr[a][b];
            ans[num+1]++;
        }
    }

    int main(){
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(false);

        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }

        divideNconquer(0,0,n);

        for(auto x : ans)
            cout << x << '\n';
    }