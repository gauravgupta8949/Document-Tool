// Do NOT add any other includes
#include "search.h"

SearchEngine::SearchEngine(){
  
}

SearchEngine::~SearchEngine(){
   
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
     for (char &c :sentence) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
     }
      
      


        if(store.empty()){
            store.push_back({sentence,{ book_code,page,paragraph,sentence_no}});
       }
else{
    int l=0;
    int count=0;
    while(l<store.size()){
        if(store[l].first!=sentence){
            count=1;
break;
        }
        else if ((store[l].second)[0]!=book_code)
        {
            count=1;
            break;
        }

         else if ((store[l].second)[1]!=page)
        {
            count=1;
            break;
        }
         else if ((store[l].second)[2]!=paragraph)
        {
            count=1;
            break;
        }
         else if ((store[l].second)[4]!=sentence_no)
        {
            count=1;
            break;
        }
       
    }
    if(count==1){
        store.push_back({sentence,{ book_code,page,paragraph,sentence_no}});
    }
}


    return;
}








void searching(std::string text, std::string pattern,vector<int>& l) {
const int t = 256;
const int w = 1283;
int tlen = text.length();
int plen = pattern.length();

    int flag;
    int c = 1, i = 0;

   
    int hash_p = 0, hash = 0;
    while (i < plen) {
        hash_p = (hash_p * t + pattern[i]) % w;
        hash = (hash * t + text[i]) % w;
        i++;
    }

   
    for (int i = 1; i <= plen - 1; i++)
        c = (c * t) % w;

    i = 0;
    while (i <= tlen - plen) {
        if (hash_p == hash) {
            flag = 1;
            for (int j = 0; j < plen; j++) {
                if (pattern[j] == text[i + j]) {
                    continue;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                l.push_back(i);
            }
        }

      
        if (i < tlen - plen) {
            hash = ((t * (hash - text[i] * c) + text[i + plen]) % w);
            if (hash < 0) {
                hash = hash + w;
            }
        }
        i++;
    }

}




Node* linklist(const std::vector<Node*>& nodes) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (Node* node : nodes) {
        Node* newNode = new Node(node->book_code,node->page,node->paragraph,node->sentence_no,node->offset);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->right = newNode;
            tail = newNode;
        }
    }
tail->right=nullptr;
    return head;
}

















Node* SearchEngine::search(string pattern, int& n_matches){
n_matches=0;
  vector<int> l;
     for (char &c :pattern) {


        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
     }
     vector<Node*> lp;


     for(int i=0;i<store.size();i++){
if(store[i].first.size()<pattern.size()){

    continue;
}
else{
searching(store[i].first,pattern,l);


int s=0;
while(s<l.size()){
    Node* node=new Node((store[i].second)[0],(store[i].second)[1],(store[i].second)[2],(store[i].second)[3],l[s]);//gettting error here
lp.push_back(node);
s++;
}
l.clear();
}
     }
n_matches=lp.size();
   return linklist(lp);


}

// int main() {
//     SearchEngine t;

// t.insert_sentence(1,1,1,1,"is a good boy");
// t.insert_sentence(1,1,1,2,"mayank is a good boy");
// t.insert_sentence(1,1,1,3,"gopal is a good boy");
// t.insert_sentence(1,1,1,4,"ram is a good boy");
// t.insert_sentence(1,1,1,5,"galla is a good boy");
// int n=0;
// Node* head=t.search("is",n);

// while(head!=nullptr){
      
//       cout<<head->book_code<<" "<<head->page<<" "<<head->paragraph<<" "<<head->sentence_no<<" "<<head->offset<<endl;
//         head = head->right;
    

// }



//     return 0;
// }