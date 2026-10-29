#include <iostream>

int main()
{
    long long num;
    std::cin >> num;

    long long n = num;
    int count = 0;

    while (n != 0)
    {
        int dig = n % 10;

        if (dig == 4 || dig == 7)
        {
            count++;
        }
        n = n / 10;
    }
    if(count == 0){
        std::cout<<"NO"<<std::endl;
        return 0;
    }
    
    while(count!=0){
        int dig = count %10;
        if((dig!=4 )&&( dig!= 7)){
            std::cout<<"NO"<<std::endl;
            return 0;
        }
        count /= 10;
    }
        
    std::cout << "YES" << std::endl;
        
    return 0;
}