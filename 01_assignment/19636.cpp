#include <iostream>
#include <cmath>

using namespace std;

// 체중: 일일 에너지 섭취량 - 일일 에너지 소비량(기초(I)+활동(A))만큼 더해짐
// |에너지 섭취량- 에너지 소비량| > T -> 일일 기초 대사량 L 만큼 더해짐
// L: (일일 에너지 섭취량 - 에너지 소비량)/2
// 사망, yoyo, no

struct Person {
    int W, I, B;
};

int main(){
    Person desi_b;
    Person desi_a;
    int date, T, daily_I, daily_A;

    cin >> desi_b.W >> desi_b.I >> T;
    desi_b.B = desi_b.I;

    cin >> date >> daily_I >> daily_A;

    int noWeight = desi_b.W;
    int noBMR = desi_b.B; 

    for(int i = 0; i < date; i++){
        noWeight += daily_I - (noBMR + daily_A);

        if(noWeight <= 0){
            cout << "Danger Diet";
            return 0;
        }
    }

    cout << noWeight << " " << desi_b.B << "\n";


    desi_a.W = desi_b.W;
    desi_a.B =  desi_b.B;

    for(int i = 0; i < date; i++){
        int daily_w = daily_I - (desi_a.B + daily_A);
        desi_a.W += daily_w;
        
        if(abs(daily_w) > T){
            desi_a.B += floor(daily_w / 2.0);
        }

        if (desi_a.W <= 0 || desi_a.B <= 0) {
            cout << "Danger Diet\n";
            return 0;
        }

    }

    cout << desi_a.W << " " << desi_a.B << "\n";

    if (daily_I > desi_a.B){
        cout << "YOYO\n";
    }else{
        cout << "NO\n";
    }

    return 0;


}