//
//  main.cpp
//  Hill Climbing 8Queen Problem for AI class
//
//  Created by Nima Aghli on 1/22/17.
//  Copyright © 2017 Nima Aghli. All rights reserved.
//  boardsize can be changed in boardsize variable
//  Intial postions of queens are generated randomly
//  in order to modify queens initial postions one can modify mattrix[][] variable 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<vector<uint16_t>> matrix;
int boardSize =8;
void printBoard(vector<vector<uint16_t>> &mat);
uint16_t calculateH(vector<vector<uint16_t>> &mat,vector<uint8_t> &queenpos);

int main(int argc, const char * argv[]) {
    matrix.resize(boardSize,vector<uint16_t>(boardSize,0));
    vector<uint16_t> row ;
    vector<uint8_t> queenpos;
    uint8_t rnd;
    srand (time(NULL)); //seed the random number generator
    for(uint8_t i=0;i<boardSize;++i){
        rnd=rand()% 8;
        printf("random number is : %i  and i=%i \n",rnd,i);
        matrix[rnd][i]=1;
        queenpos.push_back(rnd);
        
    }
    
    
//// this parts runs the algorthm //////
    uint8_t h;
    uint8_t h_temp;
    uint8_t index_i;
    uint8_t index_j;
    uint8_t original;
    h=calculateH(matrix,queenpos);
    for(int p=1;p<10;p++) // alow up to 10 step on shoulder
    {
    printf("Initial H value Is : %i \n",h);
    printf("Current Board State is :\n");
    printBoard(matrix);
    
    for(uint8_t i=0;i<boardSize;++i){
        original=queenpos.at(i);
        //printf("orginal is %i\n",original);
        matrix[original][i]=0;
        //printBoard(matrix);
        //printf("new row \n");
        
        for(uint8_t j=0;j<boardSize;++j){
            if(j==original){
                //queenpos.at(i)=original;
                //matrix[j][i]=0;
                //matrix[original][i]=1;
                continue;
            }
            
            matrix[j][i]=1;
            queenpos.at(i)=j;
            h_temp=calculateH(matrix, queenpos);
            if(h_temp<=h){
                h=h_temp;
                index_i=i;
                index_j=j;
            }
         //printBoard(matrix);
         matrix[j][i]=0;
         
        }
        queenpos.at(i)=original;
        matrix[original][i]=1;
        
    }
    printf("New H value is %i move queen in column %i to row %i \n",h,index_j,index_i);
    printBoard(matrix);
    matrix[queenpos.at(index_j)][index_j]=0;
    matrix[index_i][index_j]=1;
    queenpos.at(index_j)=index_i;
    //printf("neq quein pos is %i \n ",queenpos.at(index_j));
    //printBoard(matrix);
    }

    
    
    //printf("valuse is: %i \n",calculateH(matrix));
    return 0;
}

uint16_t calculateH(vector<vector<uint16_t>> &mat,vector<uint8_t> &queenpos){
    int t;
    int h=0;
    for(uint8_t j=1;j<boardSize;++j){
        t=queenpos.at(j-1);
        //printf("t value is %i \n",t);
        for(uint8_t i=j;i<boardSize;++i){
            if(t==0){break;}
            if(matrix[--t][i]==1){h++;}
            //printf("diag value is %i \n",matrix[--t][i]);
        }
    }
    
    t=0;
    for(uint8_t j=1;j<boardSize;++j){
        t=queenpos.at(j-1);
        //printf("t value is %i \n",t);
        for(uint8_t i=j;i<boardSize;++i){
            if(t==boardSize-1){break;}
            if(matrix[++t][i]==1){h++;}
            //printf("diag value is %i \n",matrix[++t][i]);
        }
    }
    
    for(uint8_t j=1;j<boardSize;++j){
        t=queenpos.at(j-1);
        //printf("t value is %i \n",t);
        for(uint8_t i=j;i<boardSize;++i){
            if(t==boardSize){break;}
            if(matrix[t][i]==1){h++;}
            //printf("diag value is %i \n",matrix[t][i]);
        }
    }
    return h;
}
void printBoard(vector<vector<uint16_t>> &mat){
    for(uint8_t i=0;i<boardSize;++i){
        for(uint8_t j=0;j<boardSize;++j){
        printf("%i ",mat[i][j]);
        }
        printf("\n");
        
    }
    printf("...............\n");
}