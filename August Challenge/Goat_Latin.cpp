class Solution {
public:
    bool checkVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        return false;
    }
    string toGoatLatin(string S) {
        S = S+" ";
        int i, l = S.size(), a = 0;
        string app = "a", word = "", ans = "";
        for(i=0;i<l;i++)
        {
            if(S[i]==' ')
            {
                word = S.substr(a,i-a);
                if(!checkVowel(word[0]))
                    word = word.substr(1)+word[0];
                word += ("ma"+app);
                app += "a";
                ans += (word+" ");
                a = i+1;
            }
        }
        return ans.substr(0,ans.size()-1);
    }
};