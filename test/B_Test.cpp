//
// Created by alessio on 08/09/19.
//

#include <gtest/gtest.h>
#include "../Control.h"
#include "../Car.h"

struct B_Test : public testing::Test {

    Control C_control[5];
    Car *C_car;
    bool TestControl[3];

protected:
    void SetUp() override {

        cout<<"ALIVE"<<endl;
        TestControl[0]=false;
        TestControl[1]=false;
        TestControl[2]=false;
        C_car->CreateMachine1(C_control);

    }
    void TearDown() override {cout<<"DEAD"<<endl;}
};


TEST_F(B_Test, Control_Test) {


        //######## Test macchina sulla ghiaia sul primo circuito ########

    ASSERT_EQ(C_control[0].CarControl(1),true);

        //######## Test macchina sul muretto sul primo circuito ########

    if(C_control[1].CarControl(1)==2)
        TestControl[0]=true;

    ASSERT_EQ(TestControl[0],true);



        //######## Test macchina sulla ghiaia sul secondo circuito ########

    ASSERT_EQ(C_control[2].CarControl(2),true);

        //######## Test macchina sul muretto sul secondo circuito ########

    if(C_control[3].CarControl(2)==2)
        TestControl[1]=true;

    ASSERT_EQ(TestControl[1],true);



        //######## Test macchina sul muretto sul terzo circuito ########

    if(C_control[4].CarControl(3)==2)
        TestControl[2]=true;

    ASSERT_EQ(TestControl[2],true);
}
