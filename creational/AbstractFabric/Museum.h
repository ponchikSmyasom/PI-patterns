#pragma once
#include <iostream>
#include <memory>

using namespace std;

//
//
//интерфейс картины
class Picture
{
public:
	virtual void display() const = 0;
	virtual ~Picture() {};
};

class AbstractionismPic : public Picture
{
public:
	void display() const override { cout << "Абстрактная картина: хаотичные формы и яркие цвета" << endl; }
};

class MinimalismPic : public Picture
{
public:
	void display() const override { cout << "Минималистичная картина: простые линии, сдержанные цвета" << endl; }
};

//
//
//интерфейс статуэток
class Figurine
{
public:
	virtual void display() const = 0;
	virtual ~Figurine() {};
};

class AbstractionismFig : public Figurine
{
public:
	void display() const override { cout << "Абстрактная статуэтка: непонятные формы, глубокий смысл" << endl; }
};

class MinimalismFig : public Figurine
{
public:
	void display() const override { cout << "Минималистичная статуэтка: геометрические формы" << endl; }
};

//
//
//интерфэйс арт-обЪектов
class ArtObject
{
public:
	virtual void display() const = 0;
	virtual ~ArtObject() {};
};

class AbstractionismArt : public ArtObject
{
public:
	void display() const override { cout << "Абстрактный арт-объект: интерактивная инсталляция" << endl; }
};

class MinimalismArt : public ArtObject
{
public:
	void display() const override { cout << "Минималистичный арт-объект: лаконичность и простота" << endl; }
};

//
//
// Абстрактная фабрика знает обо всех абстрактных типах продуктов
class GuiFactory
{
public:
	virtual unique_ptr<Picture> createPicture() const = 0;
	virtual unique_ptr<Figurine> createFigurine() const = 0;
	virtual unique_ptr<ArtObject> createArtObject() const = 0;
	virtual ~GuiFactory() {};
};

class AbstractionismFactory : public GuiFactory
{
public:
	unique_ptr<Picture> createPicture() const override { return make_unique<AbstractionismPic>(); }
	unique_ptr<Figurine> createFigurine() const override { return make_unique<AbstractionismFig>(); }
	unique_ptr<ArtObject> createArtObject() const override { return make_unique<AbstractionismArt>(); }
};

class MinimalismFactory : public GuiFactory
{
public:
	unique_ptr<Picture> createPicture() const override { return make_unique<MinimalismPic>(); }
	unique_ptr<Figurine> createFigurine() const override { return make_unique<MinimalismFig>(); }
	unique_ptr<ArtObject> createArtObject() const override { return make_unique<MinimalismArt>(); }
};


class Application
{
	unique_ptr<GuiFactory> factory_;
	unique_ptr<Picture> picture_;
public:
	Application(unique_ptr<GuiFactory> factory) :factory_(move(factory)) { createExhibition(); };
	void createExhibition() 
	{
		picture_ = factory_->createPicture();
	}
	void look() { picture_->display(); }
};

