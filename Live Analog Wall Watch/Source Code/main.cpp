#include<iostream>
#include<time.h>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/Event.hpp>
#include<SFML/Graphics/Color.hpp>
#include<SFML/Graphics/Circleshape.hpp>
#include<SFML/Graphics/Text.hpp>
#include<SFML/Graphics/VertexArray.hpp>
#include<SFML/Graphics/RectangleShape.hpp>
#include<SFML/Graphics/CircleShape.hpp>
#include<math.h>
#define PI 3.1415926536
double DegToRad(int Degrees){return PI*Degrees/180;}
const int Width_RenderWindow=675,Height_RenderWindow=675;
const int RadiusCircleClock=275;
sf::RectangleShape LongStrips[12];
const int RadiusCircleMiddleRenderWindow=7;
sf::CircleShape CircleMiddleRenderWindow;
const int HourRectangleWidth=5,HourRectangleHeight=RadiusCircleClock-150,MinuteRectangleWidth=4,MinuteRectangleHeight=RadiusCircleClock-60;
const int SecondRectangleWidth=3,SecondRectangleHeight=RadiusCircleClock-50;
int WidthLongStrip=25,HeightLongStrip=4,WidthShortStrip=WidthLongStrip-2,HeightShortStrip=HeightLongStrip-2;
sf::RectangleShape ShortStrips[48];
sf::RectangleShape HourRectangle;
sf::RectangleShape MinuteRectangle;
sf::RectangleShape SecondRectangle;
sf::RenderWindow app(sf::VideoMode(Width_RenderWindow,Height_RenderWindow),"Clock");
sf::Text ClockText;
sf::Text HourStripsText[12];
sf::CircleShape CircleClock;
sf::RectangleShape BackgroundRenderWindow;
sf::Font font;
class Clock
{
public:
    void setClock()
    {
        BackgroundRenderWindow.setSize(sf::Vector2f(Width_RenderWindow,Height_RenderWindow));
        CircleClock.setPointCount(360);
        CircleClock.setFillColor(sf::Color::Black);
        CircleClock.setPosition(sf::Vector2f(Width_RenderWindow/2-RadiusCircleClock,Height_RenderWindow/2-RadiusCircleClock));
        CircleClock.setOutlineColor(sf::Color::Red);
        CircleClock.setOutlineThickness(5);
        CircleClock.setRadius(RadiusCircleClock);
        for(int i=0;i<12;i++)
        {
            LongStrips[i].setFillColor(sf::Color::Green);
            LongStrips[i].setSize(sf::Vector2f(WidthLongStrip,HeightLongStrip));
            LongStrips[i].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(30*i)),Height_RenderWindow/2-RadiusCircleClock*sin(DegToRad(30*i))));
            LongStrips[i].setRotation(180-30*i);
            HourStripsText[i].setFont(font);
            std::string NumberString=std::to_string(i+1);
            HourStripsText[i].setString(NumberString);
            HourStripsText[i].setCharacterSize(25);
        }
        HourStripsText[0].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(60))-30,Height_RenderWindow/2-RadiusCircleClock*sin(DegToRad(60))+15));
        HourStripsText[1].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(30))-42,Height_RenderWindow/2-RadiusCircleClock*sin(DegToRad(30))-2));
        HourStripsText[2].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock-43,Height_RenderWindow/2-23));
        HourStripsText[3].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(-30))-45,Height_RenderWindow/2-RadiusCircleClock*sin(DegToRad(-30))-40));
        HourStripsText[4].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(-60))-25,Height_RenderWindow/2-+RadiusCircleClock*sin(DegToRad(-60))-60));
        HourStripsText[5].setPosition(sf::Vector2f(Width_RenderWindow/2-5,Height_RenderWindow/2+RadiusCircleClock-60));
        HourStripsText[6].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(120))+15,Height_RenderWindow/2+RadiusCircleClock*sin(DegToRad(120))-55));
        HourStripsText[7].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(150))+28,Height_RenderWindow/2+RadiusCircleClock*sin(DegToRad(150))-30));
        HourStripsText[8].setPosition(sf::Vector2f(Width_RenderWindow/2-RadiusCircleClock+30,Height_RenderWindow/2-18));
        HourStripsText[9].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(210))+25,Height_RenderWindow/2+RadiusCircleClock*sin(DegToRad(210))));
        HourStripsText[10].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(240))+5,Height_RenderWindow/2+RadiusCircleClock*sin(DegToRad(240))+18));
        HourStripsText[11].setPosition(sf::Vector2f(Width_RenderWindow/2-15,Height_RenderWindow/2-RadiusCircleClock+18));
        int counter=-1;
        for(int i=0;i<48;i++)
        {
            ShortStrips[i].setFillColor(sf::Color(0,128,0));
            ShortStrips[i].setSize(sf::Vector2f(WidthShortStrip,HeightShortStrip));
            ShortStrips[i].setPosition(sf::Vector2f(Width_RenderWindow/2+RadiusCircleClock*cos(DegToRad(6*counter)),Height_RenderWindow/2-RadiusCircleClock*sin(DegToRad(6*counter))));
            ShortStrips[i].setRotation(180-6*counter);
            if(i%4==0)
                counter+=2;
            else counter++;
        }
        CircleMiddleRenderWindow.setRadius(RadiusCircleMiddleRenderWindow);
        CircleMiddleRenderWindow.setFillColor(sf::Color(80,80,80));
        CircleMiddleRenderWindow.setPosition(sf::Vector2f(Width_RenderWindow/2-RadiusCircleMiddleRenderWindow,Height_RenderWindow/2-RadiusCircleMiddleRenderWindow));
        SecondRectangle.setSize(sf::Vector2f(SecondRectangleWidth,SecondRectangleHeight));
        SecondRectangle.setFillColor(sf::Color(192,0,0));
        MinuteRectangle.setSize(sf::Vector2f(MinuteRectangleWidth,MinuteRectangleHeight));
        HourRectangle.setSize(sf::Vector2f(HourRectangleWidth,HourRectangleHeight));
    }
    Clock()
    {
        app.setFramerateLimit(60);
        if(!font.loadFromFile("constanb.ttf"))
        {
            std::cout<<"Error in Loading (constanb.ttf) or not Found\n";
            return;
        }
        setClock();
        while(app.isOpen())
        {
            time_t CurrentTime;
            time(&CurrentTime);
            tm *timeInformation=localtime(&CurrentTime);
            int Second=timeInformation->tm_sec;
            int Minute=timeInformation->tm_min;
            int Hour=timeInformation->tm_hour;
            if(Hour>12)Hour-=12;
            SecondRectangle.setPosition(sf::Vector2f(Width_RenderWindow/2,Height_RenderWindow/2));
            SecondRectangle.setRotation(6*Second+180);
            MinuteRectangle.setPosition(sf::Vector2f(Width_RenderWindow/2,Height_RenderWindow/2));
            MinuteRectangle.setRotation(6*Minute+180+Second/10);
            HourRectangle.setPosition(sf::Vector2f(Width_RenderWindow/2,Height_RenderWindow/2));
            HourRectangle.setRotation(30*Hour+180+Minute/2);
            sf::Event event;
            while(app.pollEvent(event))
            {
                if(((event.type==sf::Event::KeyPressed)&&(event.key.code==sf::Keyboard::Space))||(event.type==event.Closed))
                    app.close();
                if(event.type==sf::Event::Resized)
                    app.setSize(sf::Vector2u(Width_RenderWindow,Height_RenderWindow));
            }
            app.clear();
            app.draw(BackgroundRenderWindow);
            app.draw(CircleClock);
            for(int i=0;i<12;i++)
            {
                app.draw(LongStrips[i]);
                app.draw(HourStripsText[i]);
            }
            for(int i=0;i<48;i++)
                app.draw(ShortStrips[i]);
            app.draw(CircleMiddleRenderWindow);
            app.draw(HourRectangle);
            app.draw(MinuteRectangle);
            app.draw(SecondRectangle);
            app.display();
        }
    }
};
int main(int argc,char *argv[])
{
    Clock clk;
    return 0;
}
