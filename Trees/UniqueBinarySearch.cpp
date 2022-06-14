class Solution {
public:
    double fact(int n){
        double ans=1;
        for(int i=n;i>=1;i--){
            ans=ans*i;
        }
        return (ans);
    }
    int numTrees(int n) {
        double a=fact(2*n);
        double b=fact(n+1);
        double c=fact(n);
        double ans=round(a/(b*c));
        return ans;
    }
};