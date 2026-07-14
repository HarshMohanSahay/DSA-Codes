class Solution {
public:
    void evaluate(stack<char>&oper,stack<char>&opn){
        char op = oper.top();
        oper.pop();
        bool ans;
        if(op=='&'){
             ans = true;
             while(opn.top()!='('){
                ans &= (opn.top()=='t');
                opn.pop();
             }
             opn.pop();
        }
         else if(op=='|'){
              ans = false;
             while(opn.top()!='('){
                ans |= (opn.top()=='t');
                opn.pop();
             }
             opn.pop();
        }
         else if(op=='!'){
             ans = (opn.top()=='t');
             ans = !ans;
             opn.pop();
             opn.pop();

        }
        if(ans==true)opn.push('t');
        else opn.push('f');

    }
    bool parseBoolExpr(string expression) {
        stack<char> oper,opn;
        int n = expression.size();

        for(int i = 0;i<n;i++){
            if(expression[i]=='&'||expression[i]=='|'||expression[i]=='!'){
                oper.push(expression[i]);
            }
            
            
            else if(expression[i]=='('||expression[i]=='t'||expression[i]=='f'){
                 opn.push(expression[i]);            
            }
            else if(expression[i]==')'){
                 evaluate(oper,opn);
            }
        }
        if(opn.top()=='t')return true;
        else return false;
        
    }
};