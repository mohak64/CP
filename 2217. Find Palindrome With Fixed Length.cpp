#define all(x) x.begin(),x.end()

class Solution {
public:
    long long nthpalindrome(long long n,int k){
        
		// calculating power to find starting index
        int half = (k+1)>>1;
        
		// starting i.e 10
        int starting = pow(10,half-1);
        
		// ending i.e 99
        int ending = pow(10,half)-1;
        
		// if at nth index a palindrome of lenght K no exist
        if( n>(ending-starting+1) )
            return -1;
        
		// convert to string
        string front = to_string(starting+n-1);
        
        string end;
        
        if( k%2 ){
		// for odd case we leave last one i.e front= 123
		// end = rev(12)  so ans = 123+ rev(12)= 123+21
            end=front.substr(0,half-1);
            reverse(all(end));
        }else{
		// In case of even just reverse it
            end=front.substr(0,half);
            reverse(all(end));
        }
        
        
        return stoll(front+end);
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        
        for( int x: queries )
            ans.push_back( nthpalindrome(x,intLength) );
        
        return ans;
    }
};

//formula
Only the first (intLength + 1) / 2 characters matter. The remaining characters are just a reflection.

Say intLength == 7, so we consider only 4 characters. The minimum number is 1000 and maximum - 9999.

Therefore, we can have 9999 - 1000 + 1 == 9000 palindromes. To find out the palindrome, we add a q - 1 to the minimum number, reverse, and concatenate.

For example, for query 8765, the base number is 1000 + 8765 - 1 == 9764. Concatenating it with 679, we get 9764679 as the result.

C++
The code could be shorter if we use string operations, but I wanted to avoid those for the efficiency.

int reverse(long long n, bool skip) {
    long long res = 0;
    for (n = skip ? n / 10 : n; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
vector<long long> kthPalindrome(vector<int>& queries, int sz) {
    vector<long long> res;
    long long start = pow(10, (sz + 1) / 2 - 1), end = pow(10, (sz + 1 ) / 2), mul = pow(10, sz / 2);    
    for (int q : queries)
        res.push_back(start + q > end ? -1 : 
            (start + q - 1) * mul + reverse(start + q - 1, sz % 2));
    return res;
}
