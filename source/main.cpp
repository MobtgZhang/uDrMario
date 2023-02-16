/*！
 * @author: Mobtgzhang
 * Created on: 02/16/2023
 * 
*/
# include<stdexcept>
# include<iostream>
# include "GameEngine.h"

int main(int argv,char** args){
    GameEngine game;
    // 初始化游戏
    try{
        game.init();
    }catch(std::runtime_error &e){
        std::cout<<e.what()<<std::endl;
        exit(-1);
    }
    // 开始主游戏循环
    game.mainLoop();
    game.terminate();
    return 0;
}