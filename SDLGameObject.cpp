#include "SDLGameObject.h"
#include "Game.h"
SDLGameObject::SDLGameObject() : GameObject(),
								m_position(Vector2D(0,0)),
								m_velocity(Vector2D(0,0)),
								m_acceleration(Vector2D(0,0)),
								m_width(0),
								m_height(0),
								m_textureID(""),
								m_currentRow(1),
								m_currentFrame(0),
								m_numFrames(0)
{

}

void SDLGameObject::load(const LoaderParams* pParams)
{
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_velocity = Vector2D(0,0);
	m_acceleration = Vector2D(0,0);
	m_width = pParams->getWidth(); 
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID(); 
	m_currentRow, m_currentFrame = 1; 
	m_numFrames = pParams->getNumFrames();
}

void SDLGameObject::draw()
{
	if(m_velocity.getX() > 0)
	{
		TheTextureManager::instance()->drawFrame(
			m_textureID,
			(int)m_position.getX(),
			(int)m_position.getY(),
			m_width,
			m_height, 
			m_currentRow, 
			m_currentFrame, 
			TheGame::instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL
		);
	}
	else
	{
		TheTextureManager::instance()->drawFrame(
			m_textureID,
			(int)m_position.getX(),
			(int)m_position.getY(),
			m_width,
			m_height, 
			m_currentRow, 
			m_currentFrame, 
			TheGame::instance()->getRenderer()
		);
	}
}
void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}
void SDLGameObject::clean()
{
}

