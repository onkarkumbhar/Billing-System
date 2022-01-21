#include<iostream>
#include<string.h>

using namespace std;

void delay(int sec){
    for(int i=0;i<3600*sec;i++)
    {
        for(int j=0;j<3600;j++)
        {

        }
    }
}
void typed(string p)
{   
    for(int i=0;i<p.length();i++)
    {
        cout<<p[i];
        cout.flush();
        delay(1);
    }
}
class items{
    public:
        struct item{
            string i_name;
            float i_cost;
            struct item * next;
        };
        item * head = new item();
        int count=0;
        void show_items()
        {
            item* acc=new item();
            acc=head;
            typed("Items present.............................................\n");
            while(acc!=NULL)
            {
                cout<<acc->i_name<<"        "<<acc->i_cost<<"       \n";
                acc=acc->next;
            }
            typed("...........................................................\n\n");
            
        }
        void add_item(string name,float cost)
        {
            if(count==0)
            {
                head->i_name=name;
                head->i_cost=cost;
                head->next=NULL;
            }else{
                item* new_item = new item();
                new_item->i_name=name;
                new_item->i_cost=cost;
                new_item->next=NULL;
                item* acc=new item();
                acc=head;
                while(acc->next!=NULL)
                {
                    acc=acc->next;
                }
                acc->next=new_item;
            }
            count++;
        }

        int remove_item(string name)
        {
            item* temp=new item();
            item* acc=new item();
            acc=head;
            int flag=0;
            while(acc!=NULL)
            {
                if(acc->i_name==name)
                {
                    temp->next=acc->next;
                    flag=1;
                    count--;
                    break;
                }
                temp=acc;
                acc=acc->next;
            }
            if(flag==0)
            {
                cout<<"ERROR item not found!!!\n\n";
            }
            return flag;
        }

        int update_item(string name,float cost)
        {
            item* acc=new item();
            acc=head;
            int flag=0;
            while(acc!=NULL)
            {
                if(acc->i_name==name)
                {
                    acc->i_cost=cost;
                    flag=1;
                    break;
                }
                acc=acc->next;
            }
            if(flag==0)
            {
                cout<<"ERROR item not found!!!\n\n";
            }
            return flag;
        }

        float get_i_cost(string name)
        {
            item* acc=new item();
            acc=head;
            int flag=0;
            while(acc!=NULL)
            {
                if(acc->i_name==name)
                {
                    flag=acc->i_cost;
                    break;
                }
                acc=acc->next;
            }
            return flag;
        }
};

int main(void)
{
    string user;
    cout<<"Please enter your ID:- ";
    cin>>user;
    // Billing system
    typed("############################################################\n");
    typed("                 Welcome to Billing department              \n");
    typed("Created By: Onkar Kumbhar                                   \n");
    typed("To use type :- --help\n");
    typed("DO NOT USE SPACE SEPARATED NAMES,COMMANDS>>>>>>>>>>>>>>>>>>>\n");
    typed("Recommanded to run init command at first\n");
    typed("Recommanded to run init command at first\n");
    typed("############################################################\n\n");
    class items store;
    while(1)
    {
        string command;
        cout<<user+"@billing $$ ";
        cin>>command;

        if(command=="init")
        {
            typed("Initialization started...........................................\n");
            cout<<"If intialization done then enter 0\n\n";
            while(1)
            {
                string i_name;
                float i_cost;
                cout<<"Enter item name:- ";
                cin>>i_name;
                if(i_name=="0")
                {
                    break;
                }
                cout<<"Enter item cost:- ";
                cin>>i_cost;
                store.add_item(i_name,i_cost);
                typed("Item added successfully!!!\n");
            }
            cout<<"\n";
        }else{
            if(command=="--help")
            {
                cout<<"Here are all commands-------------------------------------\n\n";
                cout<<"init                Initialize items present\n";
                cout<<"add_item            Item will get added\n";
                cout<<"show_items          All items will be displayed\n";
                cout<<"remove_item         Item will be removed\n";
                cout<<"update_item         Item cost will be updated\n";
                cout<<"create_bill         Bill will be created to user\n";
                cout<<"exit                Program will stop running\n";
                cout<<"----------------------------------------------------------\n\n";
            }else{
                if(command=="add_item")
                {
                    string i_name;
                    float i_cost;
                    cout<<"Enter item name:- ";
                    cin>>i_name;
                    cout<<"Enter item cost:- ";
                    cin>>i_cost;
                    store.add_item(i_name,i_cost);
                    typed("Item added successfully!!!\n\n");
                }else{
                    if(command=="remove_item")
                    {
                        string i_name;
                        cout<<"Enter item name:- ";
                        cin>>i_name;
                        if(store.remove_item(i_name)){
                            typed("Item removed successfully!!!\n\n");
                        }
                    }else{
                        if(command=="update_item")
                        {
                            string i_name;
                            float i_cost;
                            cout<<"Enter item name:- ";
                            cin>>i_name;
                            cout<<"Enter item new cost:- ";
                            cin>>i_cost;
                            if(store.update_item(i_name,i_cost)){
                                typed("Item updated successfully!!!\n\n");
                            }
                        }else{
                            if(command=="create_bill")
                            {
                                string tem;
                                float siz,bill=0;
                                cout<<"Billing started...\nIf want to exit press 0\n---------------------------------------------------------\n";
                                cout<<"Item name:- ";
                                cin>>tem;
                                cout<<"Items ordered:- ";
                                cin>>siz;
                                while(tem!="0")
                                {
                                    float cost = store.get_i_cost(tem);
                                    if(cost==0)
                                    {
                                        typed("Error Item not found....Not calcualted in bill\n\n");
                                    }
                                    bill+=siz*cost;
                                    cout<<"Item name:- ";
                                    cin>>tem;
                                    cout<<"Items ordered:- ";
                                    cin>>siz;
                                }
                                cout<<"\nTotal Bill:- "<<bill<<"\n\n";
                                cout<<"------------------------------------------------------------\n\n";
                            }else{
                                if(command=="exit")
                                {
                                    typed("Thank you for using our platform...\n\n");
                                    exit(0);
                                }else{
                                    if(command=="show_items")
                                    {
                                        store.show_items();
                                    }else{
                                        cout<<"Wrong command entered...\nType --help\n\n";
                                    }
                                }
                            }
                        }
                    }
                }
            }        
        }
    }

    return 0;
}