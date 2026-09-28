class Solution {
public:
    int numUniqueEmails(const vector<string>& emails) {
        unordered_set<string> sent;
        sent.reserve(emails.size());
        for(const string& email:emails){
            string address;
            address.reserve(email.length());
            size_t ati = email.find('@');
            for(size_t i=0;i<ati;++i){
                if(email[i]=='+'){break;}
                if(email[i]!='.'){address.push_back(email[i]);}
            }
            address.append(email,ati);
            sent.insert(move(address));
        }
        return sent.size();
    }
};