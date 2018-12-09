#ifndef SCREEN	
#define SCREEN
#include<iostream>
#include<string>
#include<vector>

class Screen
{
	friend class Window_mgr;
public:
	typedef std::string::size_type pos;
	//构造函数
	Screen() = default;
	Screen(pos ht, pos wd):height(ht), width(wd), contens(ht*wd, ' '){}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contens(ht*wd, c) {}
	// 内联函数
	char get() const //隐式内联
	{
		return contens[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move( pos ht, pos wd);

	//继续添加函数
	Screen &set(char);
	Screen &set(pos, pos, char);

	Screen &display(std::ostream &os) 
	{
		do_display(os); 
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contens;

	void do_display(std::ostream &os) const { os << contens; }
};
inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contens[row + c];
}


inline
Screen &Screen::set(char c)
{
	contens[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos r, pos w, char c)
{
	contens[r*width + w] = c;
	return *this;
}

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contens = std::string(s.height*s.width, ' ');
}


#endif
