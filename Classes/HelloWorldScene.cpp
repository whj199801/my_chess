#include "HelloWorldScene.h"
#include"cocos2d.h"
#include "iostream"
#include"Judge.h"
#include"Change.h"
#define __HELLOWORLD_SCENE_H__

USING_NS_CC;
Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

 
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	BoardInit();//初始化 创建棋盘数组
	
	auto chessboard = Sprite::create("MainWnd1.png");
	//Size visibleSize = Director::getInstance()->getWinSize();
	chessboard->setScale(visibleSize.width / 375, visibleSize.height / 267);
	chessboard->setAnchorPoint(Point(0, 0));
	chessboard->setPosition(Point(15, 0));
	//chessboard->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	//chessboard->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(chessboard, 0);



	//初始化 添加四颗棋子
	auto Black = Sprite::create("Chessmanblack.png");
	Black->setPosition(Point(109, 167));
	this->addChild(Black);
	chessing(1, 3, 4);
	chessing(1, 4, 3);
	chessing(2, 3, 3);
	chessing(2, 4, 4);
	setVisible(2);
	//加入菜单
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	auto start_button = MenuItemImage::create(
		"start_normal.png",
		"start_selected.png",
		CC_CALLBACK_1(HelloWorld::menuStart, this));
	auto regret_button = MenuItemImage::create(
		"regret_normal.png",
		"regret_selected.png",
		CC_CALLBACK_1(HelloWorld::menuRegret, this));


	// create menu, it's an autorelease object
	auto menu = Menu::create(start_button ,regret_button, closeItem, NULL);
	menu->setPosition(225, 32);
	menu->alignItemsHorizontallyWithPadding(15);
	this->addChild(menu, 1);

	//创建鼠标监听
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	return true;
}


bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{	
	Point  location = touch->getLocation();
	//CCLOG("%f,%f", location.x,location.y);
	//设置px，py为棋盘位置坐标
	//int px, py;
	px = location.x;
	py = location.y;
	//CCLOG("%lf %lf", location.x, location.y);
	//CCLOG("%d %d", px, py);
	PlaceCount(&px, &py);

	//CCLOG("%d %d", px, py);
	//计算得到 px py 分别为棋盘上对应的坐标，且px py为 全局变量
	
	auto Black = Sprite::create("Chessmanblack.png");
	auto White = Sprite::create("Chessmanwhite.png");
	Black->setAnchorPoint(Point(0.5, 0.5));//设置描点
	White->setAnchorPoint(Point(0.5, 0.5));

	change();
//	for(int i=0;i<8;i++)
//	CCLOG("%d %d", judge1[i],i);
	
	return true;
}
 bool HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	return true;
}
void HelloWorld::menuStart(Ref* pSender)
{

}
void HelloWorld::menuRegret(Ref* pSender)
{}

//初始化棋子
bool HelloWorld::chessing(int turn, int x, int y)//包括 清除下子框，board数组赋值
{
	//移除上一部的框
	for (int i = 0; i < sum; i++)
	{
		auto Select = (Sprite*)this->getChildByTag(a[i]);
		this->removeChild(Select);
		for (int a = 0; a < 8; a++)
		{
			for (int b = 0; b < 8; b++)
				board1[a][b] = 0;
		}
	}

		if (turn == 1)
		{
			auto Black = Sprite::create("Chessmanblack.png");
			Black->setPosition(Point(x * 28 + 137, y * 28 + 70));
			this->addChild(Black);
			//Black->setTag(100*x+y);//添加标签
			board[x][y] = 1;
			count++;
			setVisible(turn);
			auto White = Sprite::create("Chessmanwhite.png");
			White->setPosition(Point(109, 167));
			this->addChild(White);
		
		}
		else
			if (turn == 2)
			{	
				auto White = Sprite::create("Chessmanwhite.png");
				White->setPosition(Point(x * 28 + 137, y * 28 + 70));
				this->addChild(White);
				//White->setTag(100 * x + y);//添加标签
				board[x][y] = 2;
				count++;
				setVisible(turn);
				auto Black = Sprite::create("Chessmanblack.png");
				Black->setPosition(Point(109, 167));
				this->addChild(Black);
			}
	
	return true;
}

//为棋盘添加下子框
bool HelloWorld::setVisible(int ChessColor)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			judge( 3- ChessColor, i, j);
			/*if (judge(3-ChessColor, i, j) == 0||judge(3-ChessColor,i,j)==1||judge(3 - ChessColor, i, j) == 2
				|| judge(3 - ChessColor, i, j) == 3||judge(3-ChessColor,i,j)==4||judge(3-ChessColor,i,j)==5||
				judge(3-ChessColor,i,j)==6||judge(3-ChessColor,i,j)==7)*/
			if (judge1[0]==1|| judge1[1] == 1 || judge1[2] == 1 || judge1[3] == 1 || judge1[4] == 1
				|| judge1[5] == 1 || judge1[6] == 1 || judge1[7] == 1 )
				if( board[i][j] == 0)
				{	
					auto Select = Sprite::create("canset.png");
					Select->setPosition(Point(i * 28 + 137, j * 28 + 70));
					this->addChild(Select);
					board1[i][j] = 1;
					Select->setTag(8 * i + j);
					a[sum] = (8 * i + j);
					sum++;
					for (int i = 0; i < 8; i++)
						CCLOG("%d %d", judge1[i], i);
					for (int i = 0; i < 8; i++)
						judge1[i] = 0;
				}
		}
	}
	return true;
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();
}

void HelloWorld::BoardInit()
{
		for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
	}
		for (int a = 0; a < 8; a++)
		{
			for (int b = 0; b < 8; b++)
				board1[a][b] = 0;
		}
		for (int i = 0; i < 8; i++)
			judge1[i] = 0;

}
void HelloWorld::PlaceCount(int *x, int *y)
{
	if (*x > 123 && *y > 61 && *x < 342 && *y < 276)
	{
		if ((*x - 137) % 27 < 13.5)
			*x = (*x - 137) / 27;
		else
			*x = (*x - 137) / 27 + 1;
		if ((*y - 70) % 27 < 13.5)
			*y = (*y - 70) / 27;
		else
			*y = (*y - 70) / 27 + 1;
	}
}

bool HelloWorld::chessing1(int turn, int x, int y)//包括 清除下子框，board数组赋值
{
	//移除上一部的框
	for (int i = 0; i < sum; i++)
	{
		auto Select = (Sprite*)this->getChildByTag(a[i]);
		this->removeChild(Select);
		for (int a = 0; a < 8; a++)
		{
			for (int b = 0; b < 8; b++)
				board1[a][b] = 0;
		}
	}

	if (turn == 1)
	{
		auto Black = Sprite::create("Chessmanblack.png");
		Black->setPosition(Point(x * 28 + 137, y * 28 + 70));
		this->addChild(Black);
		//Black->setTag(100*x+y);//添加标签
		board[x][y] = 1;
		count++;
		//setVisible(turn);
		auto White = Sprite::create("Chessmanwhite.png");
		White->setPosition(Point(109, 167));
		this->addChild(White);

	}
	else
		if (turn == 2)
		{
			auto White = Sprite::create("Chessmanwhite.png");
			White->setPosition(Point(x * 28 + 137, y * 28 + 70));
			this->addChild(White);
			//White->setTag(100 * x + y);//添加标签
			board[x][y] = 2;
			count++;
			//setVisible(turn);
			auto Black = Sprite::create("Chessmanblack.png");
			Black->setPosition(Point(109, 167));
			this->addChild(Black);
		}

	return true;
}
