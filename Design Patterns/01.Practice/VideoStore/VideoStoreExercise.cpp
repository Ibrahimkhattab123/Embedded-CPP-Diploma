#include "VideoCategories.hpp"

int main ()
{
    CategoryFatory *VideoCreator = new CategoryFatory();
    std::shared_ptr<IVideo> Video;
    Video = VideoCreator->CreateVideo("VideoTape DVD", Rentable);

    Video = VideoCreator->CreateVideo("Harry Potter", NotRentable, Film, Horror);

    std::cout << Video->GetName() << std::endl;
    std::cout << Video->GetPrice() << std::endl;
    Video->HowToWatch();



    return 0;
}

