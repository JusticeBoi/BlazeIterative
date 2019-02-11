//
// Created by oguz on 02/12/19.
//
//
#ifndef BLAZE_ITERATIVE_READERS_MTX_READER_HPP
#define BLAZE_ITERATIVE_READERS_MTX_READER_HPP
#include "IterativeCommon.hpp"
#include <iostream>
#include <fstream>


     template<typename MatrixType>
     MatrixType ReadMtxFormatBlaze( const std::string& path )
     {
             std::ifstream read(path);
             if(read.is_open())
             {
                 std::string line;
                 bool is_sym = false;

                 while (true)
                 {
                     std::getline(read,line);
                     if ( line.substr(0,2) == "%%" && line.find("symmetric") != std::string::npos )
                     {
                             is_sym = true;
                     }

                    if ( std::isdigit(line[0]) ) break;
                 }

                 int tmp_row = 0;
                 int total_no_of_entries = 0;
                 int tmp_col = 0;
                 double tmp_val = 0.0;

                 std::istringstream iss(line);
                 iss >> tmp_row >> tmp_col >> total_no_of_entries;

                 iss.clear();


                 if ( tmp_row != tmp_col || !tmp_row || !tmp_col )
                 {
                     std::cout <<" read something wrong, returning! " <<'\n';
                     return MatrixType();
                 }


                 MatrixType A(tmp_row,tmp_col);

                 while( read >> tmp_row)
                 {
                     read >> tmp_col;
                     read >> tmp_val;

                     A(tmp_row-1, tmp_col-1 ) = tmp_val;

                     if ( is_sym && tmp_col != tmp_row )
                     {
                         A(tmp_col-1, tmp_row-1 ) = tmp_val;
                     }
                 }
                 return A;
             }
             else
             {
                 std::cout <<"not open " <<'\n';
             }
             read.close();
   }

#endif
