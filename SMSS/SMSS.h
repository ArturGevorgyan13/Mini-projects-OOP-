#ifndef _SMSS
#define _SMSS

#include <iostream>
#include <vector>

class Song{

private:
    std::string title;
    std::string artist;
    std::string length;

public:
    Song()=default;

    Song(std::string t,std::string a,std::string l);

    Song(const Song& other)=default;

    Song(Song&& other)=default;

    Song& operator=(const Song& other);

    Song& operator=(Song&& other);

    virtual ~Song()=0;

public:
    std::string gettitle() const;

    std::string getartist() const;

    std::string getlength() const;

    void settitle();

    void setartist();

    void setlength();

};

class Rock: public Song{

public:
    Rock()=default;

    Rock(std::string t,std::string a,std::string l);

    Rock(const Rock& other)=default;

    Rock(Rock&& other)=default;

    Rock& operator=(const Rock& other);

    Rock& operator=(Rock&& other);

    ~Rock()=default;

};

class Pop: public Song{

public:
    Pop()=default;

    Pop(std::string t,std::string a,std::string l);

    Pop(const Pop& other)=default;

    Pop(Pop&& other)=default;

    Pop& operator=(const Pop& other);

    Pop& operator=(Pop&& other);

    ~Pop()=default;

};

class Album{

private:
    std::string title;
    std::string artist;
    std::string releasedata;

public:
    Album()=default;

    Album(std::string t,std::string a,std::string r);

    Album(const Album& other)=default;

    Album(Album&& other)=default;

    Album& operator=(const Album& other);

    Album operator=(Album&& other);

    ~Album()=default;

public:
    std::string gettitle() const;

    std::string getartist() const;

    std::string getreleasedata() const;

    void settitle();

    void setartist();

    void setreleasedata();

};

class Playlist{

private:
    std::string name;
    std::vector<Song*> songs;

public:
    Playlist()=default;

    Playlist(std::string n,std::vector<Song*> s);

    Playlist(const Playlist& other)=default;

    Playlist(Playlist&& other)=default;

    Playlist& operator=(const Playlist& other);

    Playlist& operator=(Playlist&& other);

    ~Playlist()=default;

public:
    std::string getname();

    void setname();

public:
    void addSong(Song* s);

};

class IProgram{

public:
    virtual void searchSong(Song* s)=0;

    void listenSong(Song* s);

    virtual void addPlaylist()=0;

    virtual void deletePlaylist(Playlist* p)=0;

    virtual void addSongToPlaylist(Song* s,Playlist* p)=0;

    virtual void deleteSongFromPlaylist(Song* s,Playlist* p)=0;

    virtual void addAlbum()=0;

    virtual void deleteAlbum(Album* a)=0;

    virtual void viewHistory()=0;

};

class Program: public IProgram{

private:
    std::vector<Album*> albums;
    std::vector<Playlist*> playlists;

public:
    Program()=default;

    Program(std::vector<Album*> a,std::vector<Playlist*> p);

    Program(const Program& other);

    Program(Program&& other);

    Program& operator=(const Program& other);

    Program& operator=(Program&& other);

    virtual ~Program();

public:
    void searchSong(Song* s) override;

    void deleteSongFromPlaylist(Song* s,Playlist* p) override;

    void addAlbum() override;

    void deleteAlbum(Album* a) override;
    
    void addPlaylist() override;

    void deletePlaylist(Playlist* p) override;

    void addSongToPlaylist(Song* s,Playlist* p) override;

    void viewHistory() override;

};

#endif 