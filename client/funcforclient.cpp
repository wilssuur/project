#include "funcforclient.h"


QString get_variant(int tasknumber){
    if (tasknumber ==1){
        QString var = "";
        for (int i = 0; i+2; 7){
            var += "("+QString::number(i)+", "+QString::number(i+1)+")";
        }
        return var;
    }
    else if (tasknumber == 2){
        QString var = "";
        for (int i = 0; i+2; 7){
            var += "("+QString::number(i)+", "+QString::number(i+1)+")";
        }
        return var;
    }
    else if (tasknumber == 3){
        QString var = "";
        for (int i = 0; i+2; 7){
            var += "("+QString::number(i)+", "+QString::number(i+1)+")";
        }
        return var;
    }
    else {
        QString var = "Ошибка";
        return var;
    }
}
