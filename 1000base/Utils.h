#pragma once

/* macros */
#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

class C_BaseEntity;

class Utils {
public:
	template <typename t>
	t get_vfunc(void* class_pointer, size_t index) {
		return (*(t**)class_pointer)[index];
	}

	void SetClantag(const char* tag);
	void InitHooks();
	DWORD FindPatternIDA(std::string moduleName, std::string pattern);
	bool WorldToScreen(const Vector &origin, Vector &screen);
	float GetDistance(Vector EntityOrigin, C_BaseEntity* LocalPlayer);
private:
}; extern Utils* g_Utils;