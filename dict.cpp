// Do NOT add any other includes
#include "dict.h"

Dict::Dict(){

}

Dict::~Dict(){
      
}
void Dict::get_strings(string sentence){

string word;

string seprators =".,-:!\"\'( )?[ ]; @";
for (char ch : sentence) {
        if (seprators.find(ch)!=string::npos){
            if (!word.empty()) {
                st.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    word="";
}
int hashfn(string wor){
    int sum=0;
for(int i=0;i<wor.size();i++){
sum+=i*(static_cast<int>(wor[i]));
//(static_cast<int>(wor[i])+(static_cast<int>(toupper(wor[i]))));
}
return sum;












}


void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){

 

         for (char &c :sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
 sentence=sentence+" ";
   get_strings(sentence);


   for(int i=0;i<st.size();i++){
   string p=st[i];
       int c= hashfn(p);

       if(ar.size()<c+1){
ar.resize(c+1);
       }
       
       if(ar[c].empty()){


              ar[c].push_back({1,st[i]});
       }
       else{
        int l=0;
        int count=0;
        while(l!=ar[c].size()){
            if(ar[c][l].second==st[i]){
                ar[c][l].first++;
                count=1;
                break;
            }
            l++;
        }
        if(count==0){
              ar[c].push_back({1,st[i]});
        }

       }
      
   }

st.clear();


    return;
}

int Dict::get_word_count(string word){

         for (char &h : word) {
        if (h >= 'A' && h <= 'Z') {
            h = h + ('a' - 'A');
        }

         }
       int c= hashfn(word);
 if(ar.size()<c+1){
ar.resize(c+1);
       }
      
       if(ar[c].size()==0)
       {
        return 0;
       }

       else{

        int l=0;
          int count=0;
        while(l!=ar[c].size()){
            if(ar[c][l].second==word){
               
                count=1;
                break;
            }
            l++;
        }
        if(count==0){
            return 0;
        }
        else{
            return ar[c][l].first;
        }
       
       }

    return 0;
}

void Dict::dump_dictionary(string filename) {
   
    ofstream out_file(filename.c_str()); 

    ofstream ip;
    ip.open(filename,ios::app);

    for (int i = 0; i < ar.size(); i++) {
        if (!ar[i].empty()) {
            for (int j = 0; j < ar[i].size(); j++) {
                string ans = ar[i][j].second + ", " + to_string(ar[i][j].first);
                ip<< ans << std::endl;
            }
        }
    }

    out_file.close();
}




