#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Общий интерфейс для всех музыкальных компонентов
class MusicComponent {
public:
    virtual int totalDuration() const = 0;
    virtual ~MusicComponent() {} // Виртуальный деструктор для правильной очистки памяти
};

// Отдельный музыкальный трек (Leaf)
class Track : public MusicComponent {
private:
    string trackName;
    int durationSeconds;

public:
    Track(const string& name, int seconds) : trackName(name), durationSeconds(seconds) {}

    int totalDuration() const override {
        return durationSeconds;
    }

    void displayTrackDetails() const {
        cout << "Трек: \"" << trackName << "\" Продолжительность: " << durationSeconds << " секунд\n";
    }
};

// Группа треков (плейлист, композитный компонент)
class Playlist : public MusicComponent {
private:
    string playlistName;
    vector<MusicComponent*> tracksAndPlaylists;

public:
    Playlist(const string& name) : playlistName(name) {}

    void add(MusicComponent* component) {
        tracksAndPlaylists.push_back(component);
    }

    int totalDuration() const override {
        int totalTime = 0;
        for (auto component : tracksAndPlaylists) {
            totalTime += component->totalDuration();
        }
        return totalTime;
    }

    void displayPlaylistDetails() const {
        cout << "Плейлист: \"" << playlistName << "\"\n";
        for (auto component : tracksAndPlaylists) {
            dynamic_cast<Track*>(component)->displayTrackDetails();
        }
        cout << "Общая продолжительность плейлиста: " << totalDuration() << " секунд\n\n";
    }
};

// Тестовая функция
void testTotalDuration() {
    // Треки
    Track t1("Трек #1", 180);
    Track t2("Трек #2", 240);
    Track t3("Трек #3", 120);

    // Первый плейлист
    Playlist pl1("Первый плейлист");
    pl1.add(&t1);
    pl1.add(&t2);

    // Второй плейлист
    Playlist pl2("Второй плейлист");
    pl2.add(&t3);

    // Главный плейлист, содержащий первый и второй плейлисты
    Playlist masterPl("Главная библиотека");
    masterPl.add(&pl1);
    masterPl.add(&pl2);

    // Вычислим итоговую длительность всего дерева плейлистов
    cout << "Итоговая общая продолжительность главной библиотеки: "
        << masterPl.totalDuration() << " секунд\n";

    // Дополнительно выведем подробную информацию о каждом плейлисте
    pl1.displayPlaylistDetails();
    pl2.displayPlaylistDetails();
}