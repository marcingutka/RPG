#include "classes.hpp"
#include <vector>
#include <iterator>

int main()
{
IWeapon *da = new Dagger(400, 70,"Dagger 4000x2");
IArmor *h = new Helm(400);
IArmor *c = new Chest(2000);
IArmor *l = new Leg(1000);
IArmor *g = new Gloves(200);
IArmor *bo = new Boots(300);

IWeapon *ha = new Hammer(8000, 20,"Hammer 8000x1");
IArmor *h2 = new Helm(400);
IArmor *c2 = new Chest(2000);
IArmor *l2 = new Leg(1000);
IArmor *g2 = new Gloves(200);
IArmor *bo2 = new Boots(300);

IPlayer p1(30000,"Kronos",da,h,c,l,g,bo);
IPlayer p2(30000,"Adanos",ha,h2,c2,l2,g2,bo2);

IWeapon *da1 = new Dagger(300, 70,"Dagger 300x3", 3);
IWeapon *ha1 = new Hammer(900, 10,"Minotaur's Hammer 900x1", 1);

int ilosc_broni = 2;
std::vector<IWeapon*> bronie{da, da1, ha, ha1};
auto wh = std::begin(bronie);
auto wh1 = std::rbegin(bronie);

int a1=0;

for (int j=0; j<ilosc_broni; j++)
{
    std::cout<<std::endl<<"Walka nr "<<j+1<<std::endl;

    p1.GetWeapon(*wh);
    p2.GetWeapon(*wh1);



    int n_prob=1000;
    int p1w = 0;
    int p2w = 0;

    std::cout<<std::endl<<p1._name<<" ma bron: "<<p1._b->_name<<std::endl;
    std::cout<<p2._name<<" ma bron: "<<p2._b->_name<<std::endl<<std::endl;
    std::cout<<"Zaczyna " <<p1._name<<std::endl;

    for (int i=0;i<n_prob;i++)
    {
        int a=0;
         a = p1.TakeDamage(p2);
    if (a==1)
    {
        p2w++;
    }
    if (a==2)
    {
         p1w++;
    }
    a1=a;

    p1._hp=p1._max_hp;
    p2._hp=p2._max_hp;

    }

    double pr = (static_cast<double>(p1w)/static_cast<double>(n_prob))*100;
    double pr2 = (static_cast<double>(p2w)/static_cast<double>(n_prob))*100;
    std::cout<<p1._name<<" wygral "<<p1w<<"/"<<n_prob<<" ["<<pr<<"%] razy, a "<<p2._name<<" wygral "<<p2w<<"/"<<n_prob<<" ["<<pr2<<"%] razy."<<std::endl;
    p1w = 0;
    p2w = 0;

    std::cout<<std::endl;
    std::cout<<"Zaczyna " <<p2._name<<std::endl;

    for (int i=0;i<n_prob;i++)
    {
        int a=0;
         a = p2.TakeDamage(p1);
    if (a==1)
    {
        p1w++;
    }
    if (a==2)
    {
        p2w++;
    }
    p1._hp=p1._max_hp;
    p2._hp=p2._max_hp;

    }
    pr = (static_cast<double>(p1w)/static_cast<double>(n_prob))*100;
    pr2 = (static_cast<double>(p2w)/static_cast<double>(n_prob))*100;
    std::cout<<p2._name<<" wygral "<<p2w<<"/"<<n_prob<<" ["<<pr2<<"%] razy, a "<<p1._name<<" wygral "<<p1w<<"/"<<n_prob<<" ["<<pr<<"%] razy."<<std::endl<<std::endl;
    wh++;
    wh1++;
}
if (a1==-1)
{
     std::cout<<"Nikt nie moze zadac zadnych obrazen"<<std::endl;

}
return 0;
}
