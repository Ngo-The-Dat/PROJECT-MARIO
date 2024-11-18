#include "Animator.h"
#include "AssetManager.h"

Animator::Animator(sf::Sprite& sprite)
    : m_Sprite(sprite), m_CurrentTime(), m_Animations(), m_CurrentAnimation(nullptr) {}

//return a reference to animations, it will manage the memory, you edit with addFrames
Animator::Animation& Animator::CreateAnimation(std::string const& name,
    std::string const& textureName,
    sf::Time const& duration,
    bool loop) {

    m_Animations.push_back(
        Animator::Animation(name, textureName, duration, loop));
    // If we don't have any other animations, use that as current animation
    if (m_CurrentAnimation == nullptr)
        SwitchAnimation(&m_Animations.back());
    return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation) {
    if (animation != nullptr) {
        m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
    }

    m_CurrentAnimation = animation;
    m_CurrentTime = sf::Time::Zero; // reset time for this animation
}

//return false if no Animatio to switch. 
bool Animator::SwitchAnimation(const std::string& name) {
    auto animation = FindAnimation(name);
    if (animation != nullptr) {
        SwitchAnimation(animation);
        return true;
    }
    return false;
}

Animator::Animation* Animator::FindAnimation(std::string const& name) {
    for (auto it = m_Animations.begin(); it != m_Animations.end(); ++it) {
        if (it->m_Name == name)
            return &*it;
    }
    return nullptr;
}

std::string Animator::GetCurrentAnimationName() const {
    if (m_CurrentAnimation != nullptr)
        return m_CurrentAnimation->m_Name;

    return "";
}

//call once per display cycle,
void Animator::Update(const sf::Time& dt) {
    if (m_CurrentAnimation == nullptr)
        return;
    m_CurrentTime += dt;

    float scaledTime =
        (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
    int numFrames = m_CurrentAnimation->m_Frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);

    if (m_CurrentAnimation->m_Looping)
        currentFrame %= numFrames;
    else if (currentFrame >= numFrames)
        currentFrame = numFrames - 1; // show last frame

    m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}
void Animator::Animation::AddFrames(sf::Vector2i const& startFrom,
    sf::Vector2i const& frameSize,
    unsigned int frames) {
    sf::Vector2i current = startFrom;
    for (unsigned int i{ 0 }; i < frames; ++i) {
        m_Frames.push_back(
            sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
        current.x += frameSize.x;
    }
}
Animator::Animation::Animation(std::string const& name,
    std::string const& textureName,
    sf::Time const& duration, bool looping)
    : m_Name(name), m_TextureName(textureName), m_Frames(), m_Duration(duration),
    m_Looping(looping) {}

void Animator::copy(const Animator& other) {
    m_Animations = other.m_Animations;
}