class Solution {
public:
     unordered_map<string, string> monthMap = {
            {"Jan", "01"},
            {"Feb", "02"}, 
            {"Mar","03"}, 
            {"Apr","04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}
    };
    
    string reformatDate(string date) {
        int n=date.size();
        //int date=0;
        int y=0;
        string month="";
        vector<string> x;
        
        int i=0;
        while(i<n){
            //int y=0;
            while(isdigit(date[i])){
                y=y*10+(date[i]-'0');
                i++;
            }
            
            x.push_back(to_string(y));
            y=0;
            
           if(i>0 && date[i-1] == ' '){
               while(isalpha(date[i])){
                   month+=date[i];
                   i++;
               }
           }
            
            i++;
            
        }
        
        string m=monthMap[month];
        
        string res="";
        string year="";
        for(int j=0; j<x.size(); j++){
            if(x[j].size()==4)
                year=x[j];
        }
        
        if(x[0].size()==1)
            x[0]='0'+x[0];
        
        res=year+'-'+m+'-'+x[0];
        
        return res;
    }
};