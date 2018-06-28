#include "Song.h"

using namespace std;

Song::Song(const int id)
{
    cout << "Song::Song, id: " << id <<endl;
    m_Id = id;
}

Song::~Song()
{
    cout << "Song::~Song, id: " << m_Id <<endl;
}

void Song::Function()
{
    cout << "Song::Function" << endl;
}
