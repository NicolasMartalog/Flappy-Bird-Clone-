#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#pragma once

namespace Sonar
{
    // handles some featurees of each state in the app
	class State
	{
	public:
		virtual void Init() = 0;

		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() { }
		virtual void Resume() { }
	};
}


#endif // STATE_HPP_INCLUDED
