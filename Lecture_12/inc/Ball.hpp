#pragma once
#include <Utils.hpp>

namespace mt
{
	class Ball
	{
	private:
		mt::utils::Point m_p0;
		mt::utils::Vec m_velocity;
		float m_r;
		sf::CircleShape* m_shape;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;

		bool m_collised = false;
		
	public:
		Ball(mt::utils::Point p0, mt::utils::Vec v)
		{
			m_p0 = p0;
			m_velocity = v;
		}

		bool Setup(const std::string& name, float scale_x, float scale_y)
		{
			m_texture = new sf::Texture;
			if (!m_texture->loadFromFile(name))
			{
				std::cout << "Can`t load " << name << std::endl;
				return false;
			}

			m_sprite = new sf::Sprite;
			m_sprite->setTexture(*m_texture);
			//m_texture->setSmooth(true);
			float x = m_texture->getSize().x;
			float y = m_texture->getSize().y;
			m_sprite->setScale(scale_x, scale_y);
			m_sprite->setOrigin(x / 2, y / 2);
			m_r = x / 2 * scale_x;
			m_sprite->setRotation(90);

			return true;
		}

		~Ball()
		{
			//delete m_shape;
			if(m_texture!=nullptr)
				delete m_texture;
			if (m_sprite != nullptr)
				delete m_sprite;
		}

		void Move(double dt)
		{
			m_p0.x += m_velocity.x * dt;
			m_p0.y += m_velocity.y * dt;
			//std::cout << m_p0.x << " " << m_p0.y << std::endl;
			//std::cout << std::setprecision(7) << x << " " << y << std::endl;
			//m_shape->setPosition(m_p0.x, m_p0.y);
			m_sprite->setPosition(m_p0.x, m_p0.y);
		}

		sf::Sprite* Get() { return m_sprite; }

		void SetVelocity(mt::utils::Vec v)
		{
			m_velocity = v;
		}

		mt::utils::Point GetPosition() { return m_p0; }
		mt::utils::Vec GetVelocity() { return m_velocity; }

		float Radius() { return m_r; }

		void CheckCollision(Ball* blue)
		{
			float brad = blue->Radius();
			float rrad = m_r;
			mt::utils::Point bp = blue->GetPosition();
			mt::utils::Point rp = m_p0;

			if (!m_collised && Distance(bp, rp) >= brad - rrad)
			{
				mt::utils::Vec v = m_velocity;
				mt::utils::Vec x = { rp.x - bp.x, rp.y - bp.y };

				float v_len = sqrt(pow(v.x, 2) + pow(v.y, 2));
				float x_len = sqrt(pow(x.x, 2) + pow(x.y, 2));

				float v_proj_x = (x.x * v.x + x.y * v.y) / x_len;

				// нормирование (http://site.ru)
				mt::utils::Vec e = { x.x / x_len, x.y / x_len };
				mt::utils::Vec X = { e.x * v_proj_x, e.y * v_proj_x };

				// получаем нормальный вектор
				mt::utils::Vec n = { v.x - X.x, v.y - X.y };

				m_velocity = { -(X.x - n.x), -(X.y - n.y) };
				m_collised = true;
			}
			else if (Distance(bp, rp) + 10 < brad - rrad)
			{
				m_collised = false;
			}
		}
	};

}