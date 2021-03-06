#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include "common/Point.h"
#include "Component.h"

class VideoBuffer;
class Window_
{
private:
	Point position;
	Point size;
	VideoBuffer* videoBuffer;
	std::vector<Component*> Components;
	Component* focused;
	Component* clicked;

public:
	Window_(Point position, Point size);
	~Window_();

	void AddComponent(Component *other);
	void RemoveComponent(Component *other);
	void FocusComponent(Component *toFocus) { focused = toFocus; }
	bool IsFocused(const Component *other) const { return other == focused; }
	bool IsClicked(const Component *other) const { return other == clicked; }

	void DoTick(float dt);
	void DoDraw();

	void DoMouseMove(int x, int y, int dx, int dy);
	void DoMouseDown(int x, int y, unsigned char button);
	void DoMouseUp(int x, int y, unsigned char button);
	void DoMouseWheel(int x, int y, int d);
	void DoKeyPress(int key, unsigned short character, unsigned char modifiers);
	void DoKeyRelease(int key, unsigned short character, unsigned char modifiers);

	VideoBuffer* GetVid() { return videoBuffer; }
};

#endif
