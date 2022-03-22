#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace ariel;

 
        
      void Notebook::write(int page,int row, int column, Direction h, string a){
          if(Map[page][row][column]=='~' || Map[page][row][column]== ' '){
              throw invalid_argument("there is already values there, write in other place\n");
          }
          if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
          int f = a.size();
          int l = (int)column+f;
          if(column>100 || l>100){
              throw invalid_argument("each row has only 100 chracters\n");
          }

          if(Direction::Horizontal== h){
              int j = 0;
          for(unsigned int i = 0; i<a.length();i++,j++){
           if(Map[page][row][column+j]=='~' || Map[page][row][column+j]== ' '){
              throw invalid_argument("there is already values there, write in other place\n");
          }
          else{
          Map[page][row][column+j] = a.at(i);
          }
          }
          }
          if(Direction::Vertical==h){
        int k = 0;
        for(unsigned int i = 0; i<a.length();i++,k++){
                    if(Map[page][row+k][column]=='~' || Map[page][row+k][column]== ' '){
              throw invalid_argument("there is already values there, write in other place\n");
          }else{
          Map[page][row+k][column] = a.at(i);
          }
          }
          } 
      }
      string Notebook::read(int page, int row, int column, Direction v,  int length){
           if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
          if(column>100 || column+length>100){
              throw invalid_argument("each row has only 100 chracters\n");
          }
           string s;
          
           if(Direction::Horizontal== v){
          for(int i = 0; i<length;i++){
              if(Map[page][row][column+i]>0 && Map[page][row][column+i]<127){
                   s = s+ Map[page][row][column+i];
            
              }
          else{
               s = s + "_";
          }
          }
          }
          if(Direction::Vertical==v){
              for(int i = 0; i<length;i++){
            if(Map[page][row+i][column]>0 && Map[page][row+i][column+i]<127){
                   s = s+ Map[page][row+i][column];
            
              }
          else{
               s = s + "_";
          }
          }
        

      }
      return s;
      }
       void Notebook::erase(int page,int row, int column, Direction v,  int length){

            if(page<0 || row<0 || column<0){
              throw invalid_argument("negetive value is not good\n");
          }
          if(column>100 || column+length>100){
              throw invalid_argument("each row has only 100 chracters\n");
          }
         if(Direction::Horizontal== v){

          for(int i = 0; i<=length;i++){
          Map[page][row][column+i] = '~';
          }
          }
          if(Direction::Vertical==v){
              for(int i = 0; i<=length;i++){
          Map[page][row+i][column] = '~';
          }
       }

       }
       void Notebook::show(int page){
       
           for(int i = 0;i<=200;i++){
               for(int j = 0;j<100;j++){
                   if((Map[page][i][j]>0 &&Map[page][i][j]<127)){
                  cout<< Map[page][i][j];
                   }
                   else{
                     cout << "_";
                   }
               }
               cout<< endl;
            
           }
       }
       

       


    
