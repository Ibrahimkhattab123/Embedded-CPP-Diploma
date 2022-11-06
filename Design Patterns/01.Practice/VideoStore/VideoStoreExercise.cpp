/*
Many video stores have categories of movies-such as New Release (high price),
General Release (standard price), Classic (low price), etc.... 
If the store wanted to raise the price on all New Release rentals from $5.00 to $6.50,
it would have to iterate through all of the New Release movies and raise their rental price.
That is not very convenient. 
Also, we want to decouple the concept of VideoTape and Movie 
so that the renter of the video tape can be a data member of VideoTape,
and the movie's title and rental price can be data members of Movie,
and then the two can vary independently 
(keep in mind that VideoTape is just one possible fomat--there can be DVD, BluRay, 
etc... and the whole hierarchy can be a real mess if even possible. 
What would be a suitable choice of design pattern to handle this situation?
*/

/*
A possible solutios is using the composing design pattern 
Make video categories like: Film, Serie, Documentary and others
Each catagory has a type like: history, science, romantic, 
*/

/*
The client should be a person who would rent the DVD Video or buy a member an access to the film on the internet
*/

/*
First: Build an abstract class, so the person can give a name of the film an the type of the video "lief"
the person has the access to know the price and how to watch the video
*/

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

