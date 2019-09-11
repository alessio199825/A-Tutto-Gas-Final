//
// Created by alessio on 08/09/19.
//

#include <gtest/gtest.h>
#include "../A_Star.h"

struct C_Test : public testing::Test {

    A_Star Astar[2];
    bool Control_Middle[2];
    bool Control_Start[2];

protected:

    void SetUp() override {

        cout<<"ALIVE"<<endl;
        Astar[0].astar(3, 1);
        Astar[1].astar(4, 1);

        for(int i=0; i<2; i++){
            Control_Middle[i]=false;
            Control_Start[i]=false;
        }

        for(int i=0; i<40 ; i++) {

            if (Astar[0].getX_trajectory(i, 3) == 362 && Astar[0].getY_trajectory(i, 3) == 68)
                Control_Middle[0]=true;

            if (Astar[1].getX_trajectory(i, 4) == 362 && Astar[1].getY_trajectory(i, 4) == 68)
                Control_Middle[1]=true;
        }

    }
    void TearDown() override {cout<<"DEAD"<<endl; }
};

TEST_F(C_Test, Trajectory_test) {

        //######## Test sulla traiettoria della macchina 3 del computer sul primo circuito ########

                        //######## Test alla partenza ########

        if (Astar[0].getX_trajectory(0, 3) == 162 && Astar[0].getY_trajectory(0, 3) == 468){

            Control_Start[0]=true;
        }
            ASSERT_EQ(Control_Start[0],true);

                        //######## Test in piena gara ########

        ASSERT_EQ(Control_Middle[0],true);



        //######## Test sulla traiettoria della macchina 4 del computer sul primo circuito ########

                        //######## Test alla partenza ########

        if (Astar[1].getX_trajectory(0, 4) == 222 && Astar[1].getY_trajectory(0, 4) == 508){

            Control_Start[1]=true;
        }
            ASSERT_EQ(Control_Start[1],true);

                        //######## Test in piena gara ########

        ASSERT_EQ(Control_Middle[1],true);

}
