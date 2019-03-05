#include "MenuScene.h"
#include "HelloWorldScene.h"
Scene* MenuScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MenuScene::create();
	scene->addChild(layer);

	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto item = MenuItemFont::create("Game Start",
		CC_CALLBACK_1(MenuScene::changeScene, this));
	auto menu = Menu::create(item, NULL);
	menu->alignItemsHorizontally();
	this->addChild(menu);
	//auto action_0 = MoveBy::create(1.0, Point(-50, 50));
	//auto action_1 = JumpBy::create(5.0, Point(50, -50), 150, 5);
	//auto action_2 = Sequence::create(action_0, action_1, NULL);
	//menu->runAction(action_1);
	return true;
}

void MenuScene::changeScene(Ref *sender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}
