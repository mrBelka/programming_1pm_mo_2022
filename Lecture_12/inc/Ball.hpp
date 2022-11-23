#pragma once

namespace mt
{
	struct Point
	{
		float x;
		float y;
	};

	struct Vec
	{
		float x;
		float y;
	};

	class Ball
	{
	private:
		Point m_p0;
		Vec m_velocity;
		float m_r;
		sf::CircleShape* m_shape;
		
	public:
		Ball(Point p0, Vec v, float r, sf::Color color)
		{
			m_p0 = p0;
			m_velocity = v;
			m_r = r;
			m_shape = new sf::CircleShape(m_r);
			m_shape->setFillColor(color);
			m_shape->setOrigin(m_r, m_r);
		}

		~Ball()
		{
			delete m_shape;
		}

		void Move(double dt)
		{
			m_p0.x += m_velocity.x * dt;
			m_p0.y += m_velocity.y * dt;
			std::cout << m_p0.x << " " << m_p0.y << std::endl;
			//std::cout << std::setprecision(7) << x << " " << y << std::endl;
			m_shape->setPosition(m_p0.x, m_p0.y);
		}

		sf::CircleShape* Get() { return m_shape; }

		void SetVelocity(Vec v)
		{
			m_velocity = v;
		}

		Point GetPosition() { return m_p0; }
		Vec GetVelocity() { return m_velocity; }

		float Radius() { return m_r; }
	};

}