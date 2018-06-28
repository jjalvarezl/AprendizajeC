#include "SmartPointers.h"

using namespace std;

SmartPointers::SmartPointers ()
{
    m_ObjectWithoutDeleting = new string ("String pointer without deleting");
    m_ObjectWithDeleting = new string ("String pointer with deleting");
}

SmartPointers::~SmartPointers ()
{
    cerr<<"Error: We are not freeing the dynamically allocated string SmartPointers::m_ObjectWithoutDeleting of the memory"<<endl;

    cout<<"Correct: We are freeing the dynamically allocated string SmartPointers::m_ObjectWithDeleting of the memory"<<endl;
    delete m_ObjectWithDeleting;
}

void SmartPointers::UniquePtrExample()
{
    cout<<endl<<endl<<"SmartPointers::UniquePtrExample() init"<<endl;

    // unique_ptr initialization whitout make function
    unique_ptr<Song> uniqueSongPointer1 (new Song (1)); // uniqueSongPointer1 owns Song 1

    // unique_ptr initialization whit make function
    unique_ptr<Song> uniqueSongPointer2 (make_unique<Song> (2)); // uniqueSongPointer2 owns Song 2

    // unique_ptr initialization whit make function and auto
    auto uniqueSongPointer3 = make_unique<Song> (3); // uniqueSongPointer3 owns Song 3

    // Same inicialization kind as before
    auto uniqueSongPointer4 (make_unique<Song> (4)); // uniqueSongPointer4 owns Song 4

    // Accessing pointer elements
    uniqueSongPointer1->m_Author = "My author unique";
    uniqueSongPointer1->m_Name = "My name unique";
    uniqueSongPointer1->Function();

    {
        // The only way to transfeer ownership is moving the smart
        // pointer to another one

        auto uniqueSongPointer4 (move(uniqueSongPointer1)); // here uniqueSongPointer4 owns Song 1
        cout<<"Destroying uniqueSongPointer4"<<endl;

    } //Here uniqueSongPointer2 is unaccesible and unique_ptr disposed/deleted it.

    (uniqueSongPointer1 == nullptr) ?
                cout << "uniqueSongPointer1 have nothing at this point of code"<<endl :
                cerr << "Error, uniqueSongPointer1 should be null" <<endl;

    cout<<"Destroying uniqueSongPointer2"<<endl;
    cout<<"Destroying uniqueSongPointer3"<<endl;
    cout<<"SmartPointers::UniquePtrExample() finish"<<endl;
}

void SmartPointers::SharedPtrExample()
{
    cout<<endl<<endl<<"SmartPointers::SharedPtrExample() init"<<endl;

    // shared_ptr initialization whitout make function
    shared_ptr<Song> sharedSongPointer1 (new Song (4)); // sharedSongPointer1 owns Song 4

    sharedSongPointer1->m_Author = "My author shared";
    sharedSongPointer1->m_Name = "My name shared";

    // unique_ptr initialization whit make function
    shared_ptr<Song> sharedSongPointer2 (sharedSongPointer1); // sharedSongPointer1 and sharedSongPointer2 owns Song 1

    // unique_ptr initialization whit make function and auto
    auto sharedSongPointer3 (sharedSongPointer2); // sharedSongPointer1, sharedSongPointer2 and sharedSongPointer3 owns Song 1

    // unique_ptr initialization whit make_shared function and auto
    auto sharedSongPointer4 = make_shared<Song> (Song (5)); // sharedSongPointer4 owns Song 5

    // unique_ptr initialization whit make_shared function and auto
    auto sharedSongPointer5 (make_shared<Song> (Song (6))); // sharedSongPointer5 owns Song 6

    // All initializations aims to Song 4, the last one to song 5

    cout << "Showing content of uniqueSongPointer1: "<<endl;
    cout << "- Song id: "<< sharedSongPointer1->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer1->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer1->m_Name <<endl;
    cout << "Showing content of uniqueSongPointer2: "<<endl;
    cout << "- Song id: "<< sharedSongPointer2->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer2->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer2->m_Name <<endl;
    cout << "Showing content of uniqueSongPointer3: "<<endl;
    cout << "- Song id: "<< sharedSongPointer3->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer3->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer3->m_Name <<endl;

    // shared_ptr.reset function deattach reference to object
    // or aims to a new one of the same class of previous object

    sharedSongPointer1.reset();

    // Same thing happens when assign pointer to nullptr

    sharedSongPointer1 = nullptr;

    cout << "Showing content of uniqueSongPointer1 after reset: "<<endl;
    (sharedSongPointer1 == nullptr) ?
                cout << "- sharedSongPointer1 have nothing at this point of code"<<endl :
                cerr << "Error, uniqueSongPointer1 should be null" <<endl;
    cout << "Showing content of uniqueSongPointer2: "<<endl;
    cout << "- Song id: "<< sharedSongPointer2->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer2->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer2->m_Name <<endl;
    cout << "Showing content of uniqueSongPointer3: "<<endl;
    cout << "- Song id: "<< sharedSongPointer3->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer3->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer3->m_Name <<endl;

    sharedSongPointer1.reset(new Song (2));
    sharedSongPointer1->m_Author = "My author shared 2";
    sharedSongPointer1->m_Name = "My name shared 2";

    cout << "Showing content of uniqueSongPointer1 after reset to another reference: "<<endl;
    cout << "- Song id: "<< sharedSongPointer1->m_Id <<endl;
    cout << "- Song author: "<< sharedSongPointer1->m_Author <<endl;
    cout << "- Song name: "<< sharedSongPointer1->m_Name <<endl;

    cout<<"SmartPointers::SharedPtrExample() finish"<<endl;
} // Here all pointers are destroyed but, if the reference is shared with another function,
  // the object is destroyed when the last reference that aims to that object is destroyed

bool SmartPointers::WeakPtrHasExpired (std::weak_ptr<Song> weakSongPointer)
{
    if (auto song = weakSongPointer.lock())
    {
        cout<< "Printing weak pointer: " <<endl;
        cout << "- Song id: "<< song->m_Id <<endl;
        cout << "- Song author: "<< song->m_Author <<endl;
        cout << "- Song name: "<< song->m_Name <<endl;
    }
    else
    {
        cerr << "shared pointer reference expired, unable to lock content" << endl;
    }
    cout << "Control message 1" << endl;
}

void SmartPointers::WeakPtrExample()
{
    cout<<endl<<endl<<"SmartPointers::SharedPtrExample() init"<<endl;

    weak_ptr<Song> weakSongPointer1;

    {
        Song songExample (7);
        songExample.m_Author = "My weak author";
        songExample.m_Name = "My weak name";

        auto sharedSongPointer1 = make_shared<Song> (songExample); // Making shared pointer
        weakSongPointer1 = sharedSongPointer1; // Assign shared to weak pointer

        WeakPtrHasExpired(weakSongPointer1);
    }

    cout << "Control message  2" << endl;

    WeakPtrHasExpired(weakSongPointer1);

    cout<<"SmartPointers::WeakPtrExample() finish"<<endl;
}
