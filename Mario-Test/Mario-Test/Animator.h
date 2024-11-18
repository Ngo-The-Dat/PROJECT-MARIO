#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <list>
#include <utility>

// A facade, provide simple interface for low-level handling. a manager for the
// sprite that each enemy holds. so in total for each entity, There is a sprite,
// entity reference the sprite, the Animator reference the sprite too and manage
// it When adding a entity to the game, you need to load it with its
// corresponding texture each game cycle, you need to update the entity states
// (or its derivative states), along with
class Animator {
public:
    // Contain a animation rout such as mario-swim-left, which is created from as
    // many texture as wantted via addFrames
    struct Animation {
        std::string m_Name;        // for find animation query
        std::string m_TextureName; // for AssetManager query
        std::vector<sf::IntRect> m_Frames;
        sf::Time m_Duration;
        bool m_Looping;

        Animation(std::string const& name, std::string const& textureName,
            sf::Time const& duration, bool looping);

        void AddFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize,
            unsigned int frames);
    };

    Animator(sf::Sprite& sprite);
    void
        copy(const Animator& other); // copy the std::list of Animator, need calling
    // setAnimation prefrably right after
    Animator::Animation& CreateAnimation(std::string const& name,
        std::string const& textureName,
        sf::Time const& duration,
        bool loop = false);
    void Update(sf::Time const& dt);

    // return if the swith was successful
    bool SwitchAnimation(std::string const&);
    std::string GetCurrentAnimationName() const;

private:
    // private modethods
    Animator::Animation* FindAnimation(std::string const& name);
    void SwitchAnimation(Animator::Animation* animation);
    Animator(const Animator
        & other); // Copy is prohibited, must ensure there exist a sprite
    Animator& operator=(const Animator&) {} // same here

    // Ref to sprire
    sf::Sprite& m_Sprite;
    sf::Time m_CurrentTime;

    // ensure operation on this class doesn't invalidate previous made pointer by
    // createAnimation
    std::list<Animator::Animation> m_Animations;
    Animator::Animation* m_CurrentAnimation;
};
