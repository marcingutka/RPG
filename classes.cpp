#include "classes.hpp"


int IItem::GetType(){};

IWeapon::IWeapon(int a, int b, std::string name, int c):Att(a), Crit(b),_name(name), l_uderzen(c){}
    int IWeapon::GetType(){};
    int IWeapon::Attack(){};
    bool IWeapon::IsCriticalHit()
    {

        std::random_device rd;
           std::mt19937 gen(rd());
           std::uniform_int_distribution<> dis(1, 100);
        if (dis(gen)>=Crit)
        {
            return false;
        }
        else return true;
    }



  int Hammer::GetType(){return 21;}
  Hammer::Hammer(int a, int b,std::string name, int c):IWeapon(a, b,name, c){}
  int Hammer::Attack()
  {       if (IsCriticalHit()==true)
          {
              return Att*2;
          }
          else
          {
              return Att;
          }
  }
  void Hammer::Attack_gen()
  {
      for (int i=1; i<=this->l_uderzen;i++)
      {
          this->Attack();
      }
  }

  int Dagger::GetType(){return 22;}
    Dagger::Dagger(int a, int b,std::string name, int c):IWeapon(a, b,name, c){}
    int Dagger::Attack()
    {
        if (IsCriticalHit()==true)
        {
            return Att*2;
        }
        else
        {
            return Att;
        }
    }

    void Dagger::Attack_gen()
    {
        for (int i=1; i<=this->l_uderzen;i++)
        {
            this->Attack();
        }
    }

    IArmor::IArmor(int a):Def(a){}
    int IArmor::GetType(){}
    int IArmor::GetDefence(int a){}

    Helm::Helm(int a):IArmor(a){}
    int Helm::GetType() {return 30;}
    int Helm::GetDefence(int a)
    {
        this->Def = a;
    }

    Chest::Chest(int a):IArmor(a){}
    int Chest::GetType() {return 31;}
    int Chest::GetDefence(int a)
    {
        this->Def = a;
    }

    Leg::Leg(int a):IArmor(a){}
    int Leg::GetType() {return 32;}
    int Leg::GetDefence(int a)
    {
        this->Def = a;
    }

    Gloves::Gloves(int a):IArmor(a){}
    int Gloves::GetType() {return 33;}
    int Gloves::GetDefence(int a)
    {
        this->Def = a;
    }

    Boots::Boots(int a):IArmor(a){}
    int Boots::GetType() {return 34;}
    int Boots::GetDefence(int a)
    {
        this->Def = a;
    }

    IPlayer::IPlayer(int a, std::string n, IWeapon *b, IArmor *h, IArmor *c, IArmor *l, IArmor *g, IArmor *bo): _max_hp(a), _hp(a),_b(b), _h(h), _c(c), _name(n), _l(l),_g(g), _bo(bo){}
    void IPlayer::GetWeapon(IWeapon *a)
    {
        this->_b = a;
    }
    void IPlayer::GetArmor(IArmor *a)
    {
        switch(a->GetType())
        {
            case 30:
            this->_h = a;
            break;

            case 31:
            this->_c =a;
            break;

            case 32:
            this->_l =a;
            break;

            case 33:
            this->_g =a;
            break;

            case 34:
            this->_bo =a;
            break;

        default:
            std::cout<<"wybrales zly typ zbroi";

        }
    }

    int IPlayer::TakeDamage(IPlayer opp)
    {
        if(((opp._h->Def + opp._c->Def+opp._l->Def+opp._g->Def+opp._bo->Def)<(2*(this->_b->Att)))||((this->_h->Def + this->_c->Def+this->_l->Def+this->_g->Def+this->_bo->Def)<(2*(opp._b->Att))))
        {
        int damage_received=0;
        int damage_received_opp = 0;
        while (this->_hp>0 && opp._hp>0)
        {
            {
            for (int i=1; i<=this->_b->l_uderzen; i++)
            {

            damage_received_opp = (opp._h->Def + opp._c->Def+opp._l->Def+opp._g->Def+opp._bo->Def) - this->_b->Attack();
            if(damage_received_opp < 0)
            {
                opp._hp=opp._hp+damage_received_opp;
            }
            else damage_received_opp=0;

            if (opp._hp<=0)
            {
                return 2;
            }
            damage_received_opp=0;
            }

            if(opp._hp>0);
            {
                for (int i=1; i<=opp._b->l_uderzen; i++)
                {

                damage_received = (this->_h->Def + this->_c->Def+this->_l->Def+this->_g->Def+this->_bo->Def) - opp._b->Attack();
                if(damage_received < 0)
                    {
                        this->_hp=this->_hp+damage_received;
                    }
                else damage_received=0;

                if (this->_hp<=0)
                {
                    return 1;
                }
                damage_received=0;
                }
            }

        }
        }
        else
        {
            return -1;
        }
    }








