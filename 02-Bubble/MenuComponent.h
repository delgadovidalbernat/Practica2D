#pragma once
class MenuComponent
{

public:

	virtual void build() = 0;
	virtual void addComponent(MenuComponent* component) = 0;
	virtual void delteComponent(MenuComponent* component) = 0;
	
	virtual void action() = 0;
	virtual void render() = 0;

};

