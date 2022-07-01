class Solution {
public:
    string getHint(string secret, string guess) {
        int a[10]={0};
        int b[10]={0};
        int cows=0;
        int bulls=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                a[secret[i]-'0']++;
                b[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=min(a[i],b[i]);
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};