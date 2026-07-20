#pragma once
class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);
	void Timer(int prefereredRefresh);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
}
