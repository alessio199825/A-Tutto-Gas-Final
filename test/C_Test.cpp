//
// Created by alessio on 08/09/19.
//

#include <gtest/gtest.h>
#include "../A_Star.h"

struct C_Test : public testing::Test {

    A_Star Astar[3];
    bool Control_Middle[3];
    bool Control_Start[3];

protected:

    void SetUp() override {

        cout<<"ALIVE"<<endl;
        Astar[0].astar(2, 1);
        Astar[1].astar(3, 2);
        Astar[2].astar(4, 3);

        for(int i=0; i<2; i++){
            Control_Middle[i]=false;
            Control_Start[i]=false;
        }

        for(int i=0; i<16 ; i++) {

            if (Astar[0].getX2(i) == 182 && Astar[0].getY2(i) == 508)
                Control_Middle[0]=true;

            if (Astar[1].getX2(i) == 82 && Astar[1].getY2(i) == 396)
                Control_Middle[1]=true;

            if (Astar[2].getX2(i) == 412 && Astar[2].getY2(i) == 52)
                Control_Middle[2]=true;
        }

    }
    void TearDown() override {cout<<"DEAD"<<endl; }
};

TEST_F(C_Test, Trajectory_test) {

        //######## Test sulla traiettoria della macchina 2 del computer sul primo circuito ########

                        //######## Test alla partenza ########

        if (Astar[0].getX1() == 222 && Astar[0].getY1() == 428){

            Control_Start[0]=true;
        }
            ASSERT_EQ(Control_Start[0],true);

                        //######## Test in piena gara ########

        ASSERT_EQ(Control_Middle[0],true);



        //######## Test sulla traiettoria della macchina 3 del computer sul secondo circuito ########

                        //######## Test alla partenza ########

        if (Astar[1].getX1() == 302 && Astar[1].getY1() == 36){

            Control_Start[1]=true;
        }
            ASSERT_EQ(Control_Start[1],true);

                        //######## Test in piena gara ########

        ASSERT_EQ(Control_Middle[1],true);




        //######## Test sulla traiettoria della macchina 4 del computer sul terzo circuito ########

                        //######## Test alla partenza ########

        if (Astar[2].getX1() == 732 && Astar[2].getY1() == 552){

            Control_Start[2]=true;
        }
            ASSERT_EQ(Control_Start[2],true);

                        //######## Test in piena gara ########

        ASSERT_EQ(Control_Middle[2],true);

}
