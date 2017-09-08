class Toy {
public:
    virtual void talk() const=0;
};
class Dog: public Toy 
{
public:
    void talk()const
    {
        printf("Wow");
    }
};
class Cat: public Toy 
{
public:
    void talk()const
    {
        printf("Meow");
    }
};
class ToyFactory 
{
public:
    Toy* getToy(string& type) 
    {
        Toy* toy;
        if(type == "Dog")
             toy = new Dog();
        else
             toy = new Cat();
        return toy;
    }
};
