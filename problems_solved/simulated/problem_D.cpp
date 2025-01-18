    #include <iostream>
    #include <vector>
    using namespace std;

    class problem_D{
    public:
        void jumpingFrog(int n, int x){
            int c=1;
            while (n-x>=0){
                cout<<c<<" ";
                c+=x;

                n-=x;
            }
        }
    };

    int main(){
        int n, x;

        cin >> n;
        cin >> x;

        problem_D problemD;
        problemD.jumpingFrog(n, x);

        return 0;
    }