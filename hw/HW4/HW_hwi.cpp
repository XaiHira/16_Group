#include <iostream>
#include <iomanip>
using namespace std;

class Material {
protected:
    string name;
    int nCount;
public:
    string getName() {
        return name;
    }
    int getAmount() {
        return nCount;
    }
    void setAmount(int amount) {
        this->nCount = amount;
    }
    bool subAmount(int amount) {
        if (this->nCount <= 0)
            return false;
        else
            this->nCount -= amount;
        return true;
    }
};

class Coffee : public Material {
public:
    Coffee() {
        name = "Coffee";
        nCount = 3;
    }
};

class Sugar : public Material {
public:
    Sugar() {
        name = "Sugar";
        nCount = 3;
    }
};

class Cream : public Material {
public:
    Cream() {
        name = "Cream";
        nCount = 3;
    }
};

class Water : public Material {
public:
    Water() {
        name = "Water";
        nCount = 3;
    }
};

class Cup : public Material {
public:
    Cup() {
        name = "Cup";
        nCount = 3;
    }
};

class CoffeeMachine {
    Material* mat[]; 
public:
    CoffeeMachine() { 
        cout << "-----��ǰ Ŀ�� ���Ǳ� �մϴ�.-----" << endl;
        mat[0] = new Coffee();
        mat[1] = new Sugar();
        mat[2] = new Cream();
        mat[3] = new Water();
        mat[4] = new Cup();
        showCoffeeMachineState();
        cout << endl;
    }
    void showCoffeeMachineState() { 
        for (int i = 0; i < 5; i++) {
            cout << setw(10) << mat[i]->getName();
            for (int j = 0; j < mat[i]->getAmount(); j++)
                cout << "*";
            cout << endl;
        }
    }
    void start() { 
        int num;
        while (true) {
            showMenu();
            num = selectMenu();

            if (num == 3) { 
                for (int i = 0; i < 5; i++) {
                    mat[i]->setAmount(3);
                }
                cout << "��� ���� ä��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                continue;
            }
            else if (num == 4) {  
                cout << "���α׷��� �����մϴ�..." << endl;
                exit(0);
            }

            if (mat[0]->subAmount(1) == false) { 
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (mat[3]->subAmount(1) == false) { 
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }
            if (mat[4]->subAmount(1) == false) {
                cout << "��ᰡ �����մϴ�." << endl;
                showCoffeeMachineState();
                continue;
            }
            
            switch (num) {
            case 0:
                if (mat[2]->subAmount(1) == false) { 
                    cout << "��ᰡ �����մϴ�." << endl;
                    showCoffeeMachineState();
                    continue;
                }

                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;

            case 1: 
                if (mat[1]->subAmount(1) == false) { 
                    cout << "��ᰡ �����մϴ�." << endl;
                    showCoffeeMachineState();
                    continue;
                }

                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                cout << endl;
                break;
            case 2: 
                cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << endl;
                showCoffeeMachineState();
                break;
            default:
                cout << "�߸� �Է� �ϼ̽��ϴ�." << endl << endl;
                break;
            }
        }
    }
    void showMenu() {
        cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
    }
    int selectMenu() {
        int num;
        cin >> num;
        return num;
    }
};

int main() {
    cout.setf(ios::left);
    CoffeeMachine c;
    c.start();
}
