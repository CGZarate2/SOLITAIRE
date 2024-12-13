#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <map>
#include <string>

class AudioManager {
private:
    std::map<std::string, sf::Music> audios;

public:
    AudioManager();
    bool loadAudio(const std::string& name, const std::string& filePath);
    void play(const std::string& name);
    void stop(const std::string& name);
    sf::SoundSource::Status getStatus(const std::string& name) const;
};

#endif
