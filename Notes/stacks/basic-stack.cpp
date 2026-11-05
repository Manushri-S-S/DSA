#include <iostream>
#include<stack>
/*
In stacks we have basic operations like

push() - which add the element to the top of stack
top()- it shows the top element but doesnt remove it
pop() - it removes the top element but doest show it
empty()-tell is the stack is empty or not

*/

int main(){
    std::stack<int>st;
    st.push(13);
    st.push(14);
    //always check stack is empty or not before deleting anything (top and pop)
    if(!st.empty()){
        std::cout<<"deleting top element"<<st.top()<<std::endl;
        st.pop();
        std::cout<<"New top = "<<st.top()<<std::endl;
    }
    return 0;
}