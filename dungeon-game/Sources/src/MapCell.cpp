#include "MapCell.h"

MapCell::MapCell()
{
    id =  ' ';
}

bool MapCell::IsBlocked(){
    if(id == '1'){
        return true;
    }else{
        return false;
    }
}