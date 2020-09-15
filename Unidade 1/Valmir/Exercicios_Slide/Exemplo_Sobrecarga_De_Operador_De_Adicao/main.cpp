#include <iostream>
using namespace std;
class tres_d{
private:
    int x, y, z;
public:
    tres_d operator+(tres_d t);
    tres_d(int x, int y, int z);
    tres_d(void);
    void mostra();
};
tres_d tres_d::operator+(tres_d t) {
    tres_d temp(0,0,0);
    temp.x = x + t.x;
    temp.y = y + t.y;
    temp.z = z + t.z;
    return (temp);
}
tres_d::tres_d(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}
void tres_d::mostra(){
    cout<<x<<" ";
    cout<<y<<" ";
    cout<<z<<" "<<endl;

}
tres_d::tres_d(void){
    x = y = z = 0;
}
int main() {
    tres_d a(2,3,4),b(10,10,10), c;
    a.mostra();
    b.mostra();
    c.mostra();
    c = a + a + b;
    c.mostra();

}
