//
// Created by alessio on 28/08/19.
//

#include "gtest/gtest.h"
#include "../Collision.h"
#include "../Car.h"
#include "../Cars_Cpu.h"

struct A_Test : public testing::Test {

    Collision T_collision[2];
    Car *car;
    Cars_Cpu *carscpu;

protected:
    void SetUp() override {

        cout<<"ALIVE"<<endl;

        car->CreateMachine(T_collision);
        carscpu->CreateCpu(T_collision);

    }
    void TearDown() override {cout<<"DEAD"<<endl; delete car; delete carscpu;}
};

TEST_F(A_Test, Trajectory_test) {

        //######## Test fra macchina utente e macchina Cpu ########

    ASSERT_EQ(T_collision[0].CarPlayer_Menagement(),true);


        //######## Test fra macchina cpu e macchina utente ########

    ASSERT_EQ(T_collision[1].Cpu_Menagement(0),true);

}
