/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void menuStart(Ref* pSender);
	void menuRegret(Ref* pSender);
	bool chessing(int turn, int x, int y);
	bool chessing1(int turn, int x, int y);
	int judge(int ChessColor,  int x, int y);
	void BoardInit();
	void PlaceCount(int *x, int *y);
	void change();
	bool setVisible(int ChessColor);
    virtual bool onTouchBegan(Touch *touch,Event *unused_event);
	virtual bool onTouchEnded(Touch *touch, Event *unused_event);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	int count = 1;
	int turn=1;
	int board[8][8];
	int board1[8][8];
	int px, py;
	int a[1000];
	int sum=0;
	int judge1[8];
};

#endif // __HELLOWORLD_SCENE_H__
