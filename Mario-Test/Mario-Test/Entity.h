#pragma once

// reimplementation of entity, aim to work for tiles as wells.

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <utility>

class Animator;

// simple class shouldn't really need a separate implementation file, the
// compile time is in significant. Too lazy to implement rn
class Entity : public sf::Sprite {
	// base Transformable have position implemented as a sf::Vector2f, so we will
	// do the same to implement similar feature such as velocity vector base
	// Sprite only keep a reference to its data, which is keep inside sf::Texture,
	// so Texture must always be alive and outside of this class. Class Resources
	// may handle this
public:
	Entity(const sf::Vector2f& position = { 0, 0 });
	Entity(sf::Vector2f position, sf::Vector2f velocity);
	void Acknowledge(Animator& ani);

	// IMPORTANT,This hold its own clock and self contain its update,
	// you can do everything here, setState, collison checking, switching
	// texture... though you MUST NOT NOT UPDATE ANIMATOR here, that aren't meant
	// to be called inside even't loop
	virtual void update();
	virtual void setHitBox(sf::FloatRect hitBox);
	// getter setters
	// already defined setPosition(), setOrigin(), ...
	const sf::Vector2f& getVelocity() const;
	void setVelocity(const sf::Vector2f velocity);
	sf::FloatRect getHitBox() const;
protected:
	sf::FloatRect m_hitBox;
	virtual void init(); // helper function that is called internally
	sf::Vector2f m_originVelocity;
	Animator* m_pani{ nullptr };
	sf::Clock m_textureClock{};
	Entity(const Entity& other) = default; // can't be inherted after creation
	Entity& operator=(const Entity& other) = default;
};