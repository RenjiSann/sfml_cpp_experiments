#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;


class PendulumDisplay
{
	public:
		PendulumDisplay(
				const Vector2f& size,
				bool trace); 

		void clearTrace();
		void drawTo(RenderWindow& rw);
		void addDot(const Vector2f& pos, const Color& c, bool trace);
		void setSize(const Vector2f& newSize);
	private:
		// Constants
		static const unsigned int traceOpacity{64};
		static constexpr float traceRadius{5};
		static constexpr float dotRadius{10};


		bool keepTrace;
		RenderTexture fixLayer;
		RenderTexture periodlayer;
};
