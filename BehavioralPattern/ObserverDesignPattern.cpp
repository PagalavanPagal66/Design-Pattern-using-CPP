#include <iostream>
#include <vector>
#include <list>
#include <string>
class Observer
{
private:
    int m_id;
    std::string m_name;

public:
    Observer(int pid, std::string pname)
    {
        this->m_id = pid;
        this->m_name = pname;
    }
    void notification()
    {
        std::cout << "Got notification by " << m_name << " with user ID " << m_id << "\n";
    }
};

class Publisher
{
private:
    std::list<Observer*> m_observers;

public:
    void add(Observer* pobserver)
    {
        m_observers.push_back(pobserver);
    }
    void remove(Observer* pobserver)
    {
        m_observers.remove(pobserver);
    }
    void publish()
    {
        for (Observer* iter : m_observers)
        {
            iter->notification();
        }
    }
    int getsize()
    {
        return m_observers.size();
    }
};

//int main()
//{
//    Publisher publisher = Publisher();
//    Observer* pagal = new Observer(1, "Pagal");
//    Observer* dilli = new Observer(2, "Dilli");
//    Observer* dhash = new Observer(3, "Dhash");
//    Observer* asvin = new Observer(4, "Asvin");
//    publisher.add(pagal);
//    publisher.add(dilli);
//    publisher.add(dhash);
//    publisher.add(asvin);
//    publisher.publish();
//    std::cout << publisher.getsize() << std::endl;
//    publisher.remove(dhash);
//    std::cout << publisher.getsize() << std::endl;
//    publisher.publish();
//    return 0;
//}