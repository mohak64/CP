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
