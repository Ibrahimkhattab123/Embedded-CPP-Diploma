#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Graphics
{
public:
    ~Graphics(){};
    virtual void draw() const = 0;
    virtual void remove(Graphics *g){};
    virtual void add(Graphics *g){};
    virtual void getChild(int){};
};

class Line : public Graphics
{
public:
    virtual void draw() const
    {
        std::cout << "draw line ______" << std::endl;
    }
};
class Rectangle : public Graphics
{
public:
    virtual void draw() const
    {
        std::cout << "draw rect " << std::endl;
    }
};
class Text : public Graphics
{
public:
    virtual void draw() const
    {
        std::cout << "draw text " << std::endl;
    }
};
class Picture : public Graphics
{
public:
    void draw() const
    {
        // for each element in gList, call the draw member function
        std::for_each(graphList.begin(), graphList.end(), std::mem_fun(&Graphics::draw));
    }

    void add(Graphics *aGraphic)
    {
        graphList.push_back(aGraphic);
    }

private:
    std::vector<Graphics *> graphList;
};

int main()
{
      Line line;
  line.draw();
  Rectangle rect;
  rect.draw();
  Text text;
  text.draw();

  Picture pic;
  pic.add(&line);
  pic.add(&rect);
  pic.add(&text);
  pic.add(&rect);
  pic.draw();
    return 0;
}