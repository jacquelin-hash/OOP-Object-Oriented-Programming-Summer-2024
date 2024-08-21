#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 1.Base Class Notification 
class Notification{
    protected:
        string message;

    public:
        // constructor intializing message variable
        Notification(const string& msg): message(msg) {}
        virtual void send() = 0; 
        virtual ~Notification() {}
};

// 2.Derived Class: EmailNotification and SMS Notification
class EmailNotification: public Notification{
public:
    // constructor 
    EmailNotification(const string& msg): Notification(msg) {}

    virtual void send() override {
        cout << "Sending email: " << message << endl;
    }
};

class SMSNotification: public Notification{
public:
    // constructor
    SMSNotification(const string& msg) : Notification(msg) {}

    virtual void send() override{ 
        cout << "Sending SMS:" << message << endl;
    }

};
// 3.Notification Manager Class
// contains a vector of pointers to Notification
class NotificationManager{
private:
    vector <Notification*> vecNotification;

public:
    void addNotification(Notification* notification) {
        vecNotification.push_back(notification);
    }

    void sendAll(){ // polymorphism
        for(int i = 0; i < vecNotification.size();i++){
            vecNotification[i]->send(); //use the arrrow when you have a pointer to an object
        }
    }
};

// 4.Main function 
int main(){
    NotificationManager manager;

    Notification* email1 = new EmailNotification("Meeting at 10 AM");
    Notification* email2 = new EmailNotification("Project deadline is tomorrow");
    // Notification* sms1 = new SMSNotification("Your package has been delivered");
    // Notification* sms2 = new SMSNotification("Your verification code is 123456");

    // manager.addNotification(email1);
    // manager.addNotification(email2);
    // manager.addNotification(sms1);
    // manager.addNotification(sms2);

    manager.sendAll();
    // delete from the heap
    delete email1;
    delete email2;
    return 0;
}