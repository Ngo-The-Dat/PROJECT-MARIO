#include "Entity.h"
#include "Animator.h"

Entity::Entity(const sf::Vector2f& position) {
	// not sure should setPosition be called early or wait until child is
	// already initialized, but not important
	setPosition(position);
}

Entity::Entity(sf::Vector2f position, sf::Vector2f velocity):
	m_originVelocity(velocity)
{
	this->setPosition(position);
	this->m_hitBox = sf::FloatRect(sf::Vector2f(position), sf::Vector2f(16.0f, 16.0f));
}

void Entity::update() {
	static sf::Clock clock{};
	m_pani->Update(clock.restart());
}

void Entity::setHitBox(sf::FloatRect hitBox)
{
	m_hitBox = hitBox;
}

const sf::Vector2f& Entity::getVelocity() const { return m_originVelocity; }
void Entity::setVelocity(const sf::Vector2f velocity) { m_originVelocity = velocity; }
sf::FloatRect Entity::getHitBox() const
{
	return m_hitBox;
}
void Entity::Acknowledge(Animator& ani) { m_pani = &ani; }
void Entity::init() {
	// addAnimations to m_pani
}