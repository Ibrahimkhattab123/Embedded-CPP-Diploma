#ifndef _VIDEO_CATEGORIES_H_
#define _VIDEO_CATEGORIES_H_

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>
#include <typeinfo>
#include <vector>

constexpr double NEW_CLIENT_AMOUNT = 0;

enum VideoType
{
    Action,
    Romance,
    Horror,
    Comedy,
    SciFi
};
enum VideoSort
{
    Film,
    Serie
};

enum IsRentable
{
    Rentable,
    NotRentable
};
// std::map<std::string, double> PricesList{{"OnlineFilm", 3.30},
//                                          {"OnlineSerie", 5.50},
//                                          {"TapeFilm", 7.30},
//                                          {"TapeSerie", 4.50}};
class IVideo
{
public:
    ~IVideo();
    virtual std::string GetName() const = 0;
    virtual double GetPrice() const = 0;
    virtual void HowToWatch() const = 0;

private:
    std::string VideoName;
    double Price;
};

class VideoTape : public IVideo
{
public:
    VideoTape() {}
    VideoTape(std::string _VideoName);
    std::string GetName() const override;
    double GetPrice() const override;
    void HowToWatch() const override;

private:
    std::string VideoName;
};

class VideoTapeFilm : public VideoTape
{
public:
    VideoTapeFilm(std::string _VideoName, VideoType _FilmType);
    double GetPrice() const override;

private:
    std::string VideoName;
    double Price;
    VideoType Film_t;
};

class VideoTapeSerie : public VideoTape
{
public:
    VideoTapeSerie(std::string _VideoName, VideoType _FilmType);
    double GetPrice() const override;

private:
    std::string VideoName;
    double Price;
    VideoType Film_t;
};

class VideoOnline : public IVideo
{
public:
    VideoOnline();
    VideoOnline(std::string _VideoName);
    std::string GetName() const override;
    double GetPrice() const override;
    void HowToWatch() const override;

private:
    std::string VideoName;
};
class VideoOnlineFilm : public VideoOnline
{
public:
    VideoOnlineFilm(std::string _VideoName, VideoType _FilmType);
    double GetPrice() const override;

private:
    std::string VideoName;
    double Price;
    VideoType Film_t;
};
class VideoOnlineSerie : public VideoOnline
{
public:
    VideoOnlineSerie(std::string _VideoName, VideoType _FilmType);
    double GetPrice() const override;

private:
    std::string VideoName;
    double Price;
    VideoType Film_t;
};

class CreateCategory
{
public:
    virtual std::shared_ptr<IVideo> CreateVideo(std::string _VideoName, IsRentable _IsRentable, VideoSort _VideoSort, VideoType _VideoType) = 0;
    virtual std::shared_ptr<IVideo> CreateVideo(std::string _VideoName, IsRentable _IsRentable) = 0;
};

class CategoryFatory : public CreateCategory
{
public:
    std::shared_ptr<IVideo> CreateVideo(std::string _VideoName, IsRentable _IsRentable, VideoSort _VideoSort, VideoType _VideoType_IsRentable) override;
    std::shared_ptr<IVideo> CreateVideo(std::string _VideoName, IsRentable _IsRentable) override;
};

// Composite
class IVideoOrder
{
public:
    virtual void AddItem(std::shared_ptr<IVideo> &_Item) = 0;
    virtual void removeItem(std::shared_ptr<IVideo> &_Item) = 0;
    virtual void DeleteItem(std::shared_ptr<IVideo> &_Item) = 0;
};

class LiefComponent : public IVideoOrder
{
public:
    void AddItem(std::shared_ptr<IVideo> &_Item) override;
    void removeItem(std::shared_ptr<IVideo> &_Item) override;
    void DeleteItem(std::shared_ptr<IVideo> &_Item) override;

private:
};

class ComopsiteComponent : public IVideoOrder
{
public:
    void AddItem(std::shared_ptr<IVideo> &_Item) override;
    void removeItem(std::shared_ptr<IVideo> &_Item) override;
    void DeleteItem(std::shared_ptr<IVideo> &_Item) override;
    void DisplayItems();

private:
    std::vector<std::shared_ptr<IVideo>> VideoFile;
};

#endif //_VIDEO_CATEGORIES_H_