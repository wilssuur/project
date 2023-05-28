#include "funcforclient.h"
#include <iostream>
#include <vector>
#include <cstdlib>

QString get_variant1(){
    srand(time(NULL));
    QString edges = "";

    //генерация количества вершин
    int count_tops = rand() % 5 + 4;
    QString c = QString::number(count_tops);

    //генерация ребер

    QString ch;
    for (int i = 1; i < count_tops; i++){
        int count_edges_with_i = rand() % 4 + 1;
        QString start = QString::number(i);
        QString check = "";
        for (int j = 1; j <= count_edges_with_i; j++){
            int i_use = i + 1;
            int r = count_tops - i_use + 1;

            int n = i_use + (rand() % r);

            QString end = QString::number(n);
            if (not check.contains(end, Qt::CaseInsensitive)) {
                check = check + end;
                edges = edges + "(" + start + "," + end + "),";
                ch = check;
            }
        }
    }


    return  c + "+" + edges;
}



QString get_variant2(){
    srand(time(NULL));
    QString edges = "";


    //генерация количества вершин
    int count_tops = rand() % 4 + 4;
    QString c = QString::number(count_tops);
    //генерация ребер

    QString ch;
    for (int i = 1; i < count_tops; i++){
        int count_edges_with_i = rand() % 4 + 1;
        QString start = QString::number(i);
        QString check = "";
        for (int j = 1; j <= count_edges_with_i; j++){
            int i_use = i + 1;
            int r = count_tops - i_use + 1;
            int n = i_use + (rand() % r);
            int w = rand() % 12 + 1;
            QString weight = QString::number(w);
            QString end = QString::number(n);
            if (not check.contains(end, Qt::CaseInsensitive)) {
                check = check + end;
                edges = edges + "(" + start + "," + end + "," + weight + "),";
                ch = check;
            }
        }
    }


    return  c + "+" + edges;
}
