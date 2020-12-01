#include "functions.h"
void breeding(list<bunny>&db)
{
    int tcount=0,mcount=0;
    string male="male";
    string female="female";
    int maleCount=0,femCount=0;
    list<bunny>::iterator iter;

    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        tcount++;

        if((male==iter->getGender()))
            maleCount++;
        if((female==iter->getGender()))
            femCount++;
    }
    cout<<"\t\t\t--In Previous Turn: \n";
    cout<<"\t\t\t\tMale:"<<maleCount<<"\n";
    cout<<"\t\t\t\tFemale:"<<femCount<<"\n\n";
    list<bunny>::iterator iter1;
    for(iter1=db.begin(); iter1!=db.end(); ++iter1)
    {
        mcount++;
        if(mcount>=tcount+1)
            break;
        if(iter1->getGender()==female&& iter1->getRadioactive()==false)
        {

            //std::unique_ptr<bunny> temp = make_unique<bunny>(iter1->getColor());
            bunny temp(iter1->getColor());
            db.push_back(temp);
        }
    }
}

void checkRadioactivity(list<bunny>&db)
{
    int Rcount=0,remCount=0,RcountFalse=0,nonRCount=0;
    list<bunny>::iterator iter,iter1;

    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        if(iter->getRadioactive()==true)
            Rcount++;
        if(iter->getRadioactive()==false)
            nonRCount++;

    }
    cout<<"\n\t\t\t\tRADIO-ACTIVE Bunny count: "<<Rcount<<"\n";
    cout<<"\t\t\t\tNon-RADIO-ACTIVE Bunny count: "<<nonRCount<<"\n";
    cout<<"\t\t\t\tTotal Bunny count: "<<db.size()<<"\n";

    remCount=Rcount;
    if(Rcount>=1)
    {
        while(remCount!=0)
        {

        for(iter=db.begin(); iter!=db.end(); ++iter)
        {
            RcountFalse=0;
            for(iter1=db.begin(); iter1!=db.end(); ++iter1)
            {
              if(iter1->getRadioactive()==false)
                    RcountFalse++;

            }

            if(RcountFalse==0)
            {
                cout<<"\n\n\t\t\t\tAll are Radio Active\n";
                remCount=0;
                break;
            }
            else
            {
                if(iter->getRadioactive()==false)
                {
                    --remCount;
                    cout<<"\n\t\t\t\t"<<"Bunny "<<iter->getName()<<"  changed to Radio Active";
                    iter->setRadioactive(true);
                    break;

                }
            }

        }


        }

    }
}

void GenerateNextTurn(list<bunny> &db)
{
    int ocount=0;
    list<bunny>::iterator iter;
    fstream fcout;
    fcout.open("OUTPUT_LOG.txt",ios::out|ios::app);


    cout<<"Count\tName\t\t\tGender\tCOlor\tRadio\tAge\n";
    cout<<"-------------------------------------------------------------------------------------------------------\n";


    fcout<<"Count\tName\t\t\tGender\tCOlor\tRadio\tAge\n";
    fcout<<"-------------------------------------------------------------------------------------------------------\n";

    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        //cout<<"\nObject count:"<<++ocount<<"\n";

        cout<<"\n"<<++ocount<<"\t";
        fcout<<"\n"<<ocount<<"\t";
        switch(iter->getRadioactive())
        {
        case 0:
            if(iter->getAge()>5)
            {
                cout<<"\t\t\tNon-Radio-Active Bunny "<<iter->getName()<<" expired\n";
                 fcout<<"\t\t\tNon-Radio-Active Bunny "<<iter->getName()<<" expired\n";
                 iter=db.erase(iter);
                 iter--;
                break;
            }

           // cout<<"-------------------------------------------------------------------------------------------------------\n";
            cout<<"Bunny "<<iter->getName()<<"\t\t";
            cout<<iter->getGender()<<"\t";
            cout<<iter->getColor()<<"\t";
            cout<<iter->getRadioactive()<<"\t";
            cout<<iter->getAge()<<"\n";

            fcout<<"Bunny "<<iter->getName()<<"\t\t";
            fcout<<iter->getGender()<<"\t";
            fcout<<iter->getColor()<<"\t";
            fcout<<iter->getRadioactive()<<"\t";
            fcout<<iter->getAge()<<"\n";
            iter->setAge(iter->getAge() + 1);
           // cout<<"-------------------------------------------------------------------------------------------------------\n";


            break;

        case 1:
            if(iter->getAge() >=10)
            {
                cout<<"\t\t\tRadio-Active Bunny "<<iter->getName()<<" expired\n";
                fcout<<"\t\t\tRadio-Active Bunny "<<iter->getName()<<" expired\n";
                iter=db.erase(iter);
                iter--;
                break;
            }


            //cout<<"-------------------------------------------------------------------------------------------------------\n";
            cout<<"Bunny "<<iter->getName()<<"\t\t";
            cout<<iter->getGender()<<"\t";
            cout<<iter->getColor()<<"\t";
            cout<<iter->getRadioactive()<<"\t";
            cout<<iter->getAge()<<"\n";



            fcout<<"Bunny "<<iter->getName()<<"\t\t";
            fcout<<iter->getGender()<<"\t";
            fcout<<iter->getColor()<<"\t";
            fcout<<iter->getRadioactive()<<"\t";
            fcout<<iter->getAge()<<"\n";
            iter->setAge(iter->getAge() + 1);
             //cout<<"-------------------------------------------------------------------------------------------------------\n";


            break;

        default:
            cout<<"Bunny "<<iter->getName()<<"\t\t";
            cout<<iter->getGender()<<"\t";
            cout<<iter->getColor()<<"\t";
            cout<<iter->getRadioactive()<<"\t";
            cout<<iter->getAge()<<"\n";

            fcout<<"Bunny "<<iter->getName()<<"\t\t";
            fcout<<iter->getGender()<<"\t";
            fcout<<iter->getColor()<<"\t";
            fcout<<iter->getRadioactive()<<"\t";
            fcout<<iter->getAge()<<"\n";
            fcout<<"Default";  break;
            iter->setAge(iter->getAge() + 1);
        }
    }

    /*int it = std::count_if (db.begin(), db.end(), [](bunny& ref){
            return ref.getRadioactive()==false;
    });
    cout<<"count "<<it;*/



fcout.close();
}
void delete_extra(list<bunny>&db)
{
    int ocount=0,n=0;
    if(db.size()==0)
    {
        cout<<"\n\n\t\t\t\t----------All Bunnies died----------\n";
        std::exit(1);
    }
   list<bunny>::iterator iter;
       if(db.size()>100)
          {
              list<bunny>::iterator it;
              for(it=db.begin(); it!=db.end(); ++it)
              {
                  n++;
                  if(n>db.size()/2)
                      break;
                  cout<<"\n Bunny "<<it->getName()<<"was killed<===============================================";
                   it=db.erase(it);
                   it--;
             }


          }
}




