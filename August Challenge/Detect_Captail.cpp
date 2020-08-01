class Solution {
public:
bool detectCapitalUse(string word) {
bool ans = true;
int count = 0;
for(int i = 0 ; i<word.length() ; i++){
if(word[i] >='A' && word[i] <='Z'){
++count;
}
}

if(count == 1 && (word[0]>='A' && word[0]<='Z')){
return true;
}

else if(count == word.length()){
return true;
}

else if(count == 0){
return true;
}
else{
return false;
}

}
};