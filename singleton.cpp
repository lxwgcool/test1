/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// Example program
#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

//singleton
class A
{    
private:
    A();    
    ~A(){};
    A(const A&);
    A& operator = (const A&);
    
public:
    static A* GetInstance()
    {
       if(m_pA == NULL)
       {
            pthread_mutex_lock(&m_Mutex);
            if(m_pA == NULL)
                m_pA = new A();
            pthread_mutex_unlock(&m_Mutex);
       }
       return m_pA;
    }
    
    void Show();

private:
    static A* m_pA;
    static int m_iValue;
    static pthread_mutex_t m_Mutex;

    class DeA
    {
    public:
        ~DeA()
        {
            if(A::m_pA != NULL)
            {
                delete A::m_pA;
                A::m_pA = NULL;
            }
        }
    };

    static DeA m_DeA;
};

pthread_mutex_t A::m_Mutex;
int A::m_iValue = 1;

A* A::m_pA = NULL;
A::A()
{
    m_iValue = 0;
    pthread_mutex_init(&m_Mutex, NULL);
}

void A::Show()
{
    cout << "I am lxwgcool" << endl;
}

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
    
  A* pTemp = A::GetInstance();      
  pTemp->Show();
}
