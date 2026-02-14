#include<iostream>
using namespace std;
using ll = long long;
const ll modnum = 998244353;
ll ksm(ll a,ll b,ll p){
    ll ans = 1;
    while(b){
        if(b&1) ans = ((ans%p) * (a%p))%p;
        a = ((a%p)*(a%p))%p;
        b >>=1;
    }
    return ans;
}
ll c,p_led[10],p_led_on[10],p_led_off[10],T,p_num[10];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll b100 = ksm(100,modnum-2,modnum);
    cin>>T;
    while(T--){
        cin>>c;
        for(int i=1;i<=7;i++){
            cin>>p_led[i];
            p_led_on[i] = ((p_led[i] % modnum) * (b100 % modnum)) % modnum;
            p_led_off[i] = (((100 - p_led[i]) % modnum) * (b100 % modnum)) % modnum;
        }
        p_num[0] =  p_led_on[1] * p_led_on[2] % modnum * p_led_on[3] % modnum * p_led_off[4] % modnum * p_led_on[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        p_num[1] =  p_led_off[1] * p_led_off[2] % modnum * p_led_on[3] % modnum * p_led_off[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_off[7] % modnum;
        p_num[2] =  p_led_on[1] * p_led_off[2] % modnum * p_led_on[3] % modnum * p_led_on[4] % modnum * p_led_on[5] % modnum * p_led_off[6] % modnum * p_led_on[7] % modnum;
        p_num[3] =  p_led_on[1] * p_led_off[2] % modnum * p_led_on[3] % modnum * p_led_on[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        p_num[4] =  p_led_off[1] * p_led_on[2] % modnum * p_led_on[3] % modnum * p_led_on[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_off[7] % modnum;
        p_num[5] =  p_led_on[1] * p_led_on[2] % modnum * p_led_off[3] % modnum * p_led_on[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        p_num[6] =  p_led_on[1] * p_led_on[2] % modnum * p_led_off[3] % modnum * p_led_on[4] % modnum * p_led_on[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        p_num[7] =  p_led_on[1] * p_led_off[2] % modnum * p_led_on[3] % modnum * p_led_off[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_off[7] % modnum;
        p_num[8] =  p_led_on[1] * p_led_on[2] % modnum * p_led_on[3] % modnum * p_led_on[4] % modnum * p_led_on[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        p_num[9] =  p_led_on[1] * p_led_on[2] % modnum * p_led_on[3] % modnum * p_led_on[4] % modnum * p_led_off[5] % modnum * p_led_on[6] % modnum * p_led_on[7] % modnum;
        ll ans = 0;
        for(ll num1= 0; num1<=c;num1++){
            ll num2 = c - num1;
            ll ptmp = 1;
            int w = num1 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num1 / 10 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num1 / 100 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num1 / 1000 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num2 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num2 / 10 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num2 / 100 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            w = num2 / 1000 % 10;
            ptmp = (ptmp % modnum) * (p_num[w] % modnum) % modnum;
            ans = ((ans % modnum) + (ptmp % modnum)) % modnum;
        }
        cout<<ans<<endl;
    }
}