#include "VideoCategories.hpp"
IVideo::~IVideo(){}

// Video Tape implementation
VideoTape::VideoTape(std::string _VideoName)
    : VideoName(_VideoName)
{
    std::cout << "new tape category has been created: " << this->VideoName << "." << std::endl;
};
std::string VideoTape::GetName() const
{
    return this->VideoName;
}
void VideoTape::HowToWatch() const
{
    std::cout << "The Content of the tape can be watched using a DVD driver." << std::endl;
}

double VideoTape::GetPrice() const
{
    std::cout << "you taped a category name, not a video name." << std::endl;
    return 0.0;
}

// VideoTapeFilm inplementation
VideoTapeFilm::VideoTapeFilm(std::string _VideoName, VideoType _FilmType)
    : VideoName(_VideoName), Film_t(_FilmType), Price(7.30)
{
    std::cout<< "Tape Film was created: " << this->VideoName << "." << std::endl;
}
double VideoTapeFilm::GetPrice() const
{
    return this->Price;
}
// VideoTapeSerie inplementation
VideoTapeSerie::VideoTapeSerie(std::string _VideoName, VideoType _FilmType)
    : VideoName(_VideoName), Film_t(_FilmType), Price(4.50)
{
    std::cout<< "Tape Serie was created: " << this->VideoName << "." << std::endl;

}
double VideoTapeSerie::GetPrice() const
{
    return this->Price;
}

// VideoOnline implemntation
VideoOnline::VideoOnline(){}

VideoOnline::VideoOnline(std::string _VideoName)
    : VideoName(_VideoName)
{
    std::cout << "new online category has been created:" << this->VideoName << "." << std::endl;
};

std::string VideoOnline::GetName() const
{
    return this->VideoName;
}
void VideoOnline::HowToWatch() const
{
    std::cout << "The Content can be watched on our website: www.videopal.com" << std::endl;
}

double VideoOnline::GetPrice() const
{
    std::cout << "you taped a category name, not a video name" << std::endl;
    return 0.0;
}

//VideoOnlineFilm implementation
VideoOnlineFilm::VideoOnlineFilm(std::string _VideoName, VideoType _FilmType)
    : VideoName(_VideoName), Film_t(_FilmType), Price(3.30)
{
    std::cout<< "Online Film was created: " << this->VideoName << "." << std::endl;
}
double VideoOnlineFilm::GetPrice() const
{
    return this->Price;
}

VideoOnlineSerie::VideoOnlineSerie(std::string _VideoName, VideoType _FilmType)
    : VideoName(_VideoName), Film_t(_FilmType), Price(5.50)
{
    std::cout<< "Online Serie was created: " << this->VideoName << "." << std::endl;
}
double VideoOnlineSerie::GetPrice() const
{
    return this->Price;
}

std::shared_ptr<IVideo> CategoryFatory::CreateVideo(std::string _VideoName, IsRentable _IsRentable, VideoSort _VideoSort, VideoType _VideoType)
{
    if ((_IsRentable == Rentable) && (_VideoSort == Film))
    {
        return std::make_shared<VideoTapeFilm>(_VideoName, _VideoType);
    }
    else if ((_IsRentable == Rentable) && (_VideoSort == Serie))
    {
        return std::make_shared<VideoTapeSerie>(_VideoName, _VideoType);

    }
    else if ((_IsRentable == NotRentable) && (_VideoSort == Film))
    {
        return std::make_shared<VideoOnlineFilm>(_VideoName, _VideoType);
    }
    else //if ((_IsRentable == NotRentable) && (_VideoSort == Serie))
    {
        return std::make_shared<VideoOnlineSerie>(_VideoName, _VideoType);
    }
} 

std::shared_ptr<IVideo> CategoryFatory::CreateVideo(std::string _VideoName, IsRentable _IsRentable)
{
    std::shared_ptr<IVideo> CategoryCreated;
    if ((_IsRentable == Rentable))
    {
        CategoryCreated = std::make_shared<VideoTape>(_VideoName);
        return CategoryCreated; 
    }
    else //if ((_IsRentable == NotRentable))
    {
        CategoryCreated = std::make_shared<VideoOnline>(_VideoName);
        return CategoryCreated;
    }
    
}

//composite pattern
void LiefComponent::AddItem(std::shared_ptr<IVideo>& _Item)
{
    std::cout << "New Category has been added: " << _Item->GetName() << std::endl;
}
void LiefComponent::removeItem(std::shared_ptr<IVideo> &_Item)
{}
void LiefComponent::DeleteItem(std::shared_ptr<IVideo>& _Item)
{
    _Item->~IVideo();
}

void ComopsiteComponent::AddItem(std::shared_ptr<IVideo>& _Item)
{
    std::cout << "New Video has been added: " << _Item->GetName() << std::endl;
    this->VideoFile.emplace_back(_Item);
}
void ComopsiteComponent::removeItem(std::shared_ptr<IVideo> &_Item)
{
    this->VideoFile.pop_back();
    std::cout << "Video: " << _Item->GetName() << " has been removed." << std::endl; 
}
void ComopsiteComponent::DeleteItem(std::shared_ptr<IVideo>& _Item)
{
    _Item->~IVideo();
}
void ComopsiteComponent::DisplayItems()
{
    std::cout << "Videos to rent/access:" << std::endl;
    for(auto& item : this->VideoFile)
    {
       std::cout << item->GetName() << "   " << std::endl;
    }
}






