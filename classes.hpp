#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

class IItem
{
virtual int GetType()=0;
};

class IWeapon: public IItem
{
 protected:
    int Crit;
 public:
    int Att;
    int l_uderzen;
    std::string _name;

 public:
    IWeapon(int a, int b,std::string name, int c);
    virtual int GetType() override;
    virtual int Attack()=0;
    bool IsCriticalHit();
};

class Hammer: public IWeapon
{
public:
    int GetType() override;
  Hammer (int a, int b, std::string name="Default Hammer", int c=1);
  int Attack() override;
  void Attack_gen();
};

class Dagger: public IWeapon
{
public:
    int GetType() override;
    Dagger (int a, int b, std::string name="Default Dagger", int c=2);
    int Attack() override;
    void Attack_gen();
};

class IArmor: public IItem
{
  public:
    int Def;

  public:
    IArmor(int a);
    virtual int GetType() override;
    virtual int GetDefence(int a)=0;
};

class Helm: public IArmor
{
public:
    Helm (int a = 300);
    int GetType() override;
    int GetDefence(int a) override;
};

class Chest: public IArmor
{
public:
    Chest (int a = 1500);
    int GetType() override;
    int GetDefence(int a) override;
};

class Leg: public IArmor
{
public:
    Leg (int a = 1000);
    int GetType() override;
    int GetDefence(int a) override;
};

class Gloves: public IArmor
{
public:
    Gloves (int a = 100);
    int GetType() override;
    int GetDefence(int a) override;
};

class Boots: public IArmor
{
public:
    Boots (int a = 300);
    int GetType() override;
    int GetDefence(int a) override;
};



class IPlayer
{
  protected:
    //IWeapon *_b;
    IArmor *_h;
    IArmor *_c;
    IArmor *_l;
    IArmor *_g;
    IArmor *_bo;
    public:
    IWeapon *_b;
    int _hp;
    int _max_hp;
    std::string _name;

public:
    IPlayer(int a,  std::string n="Default", IWeapon *b = new Hammer(2000, 30), IArmor *h = new Helm(), IArmor *c = new Chest(), IArmor *l = new Leg(), IArmor *g = new Gloves(), IArmor *bo = new Boots());
    void GetWeapon(IWeapon *a);
    void GetArmor(IArmor *a);
    int TakeDamage(IPlayer opp);
};




