#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;
	float alpha;

public:
	Color(float red = 1.0  , float green = 1.0 , float blue = 1.0 , float alpha = 1.0) : red(red), green(green), blue(blue),
		alpha(alpha)
	{}

	

	inline float GetRed() const { return this->red; }
	inline float GetGreen()  const { return this->green; }
	inline float GetBlue()  const { return this->blue; }
	inline float GetAlpha()  const { return this->alpha; }

	inline void SetRed(float redToSet)
	{
		// Solo asigna redComponent si redToSet está en el rango [0.0, 1.0]
		this->red = (redToSet >= 0.0 && redToSet <= 1.0) ? redToSet : this->red;
	}


	inline void SetGreen(const float& greenToSet)
	{
		if (greenToSet >= 0.0 && greenToSet <= 1.0)
		{
			this->green = greenToSet;
		}
	}

	inline void SetBlue(const float& blueToSet)
	{
		if (blueToSet >= 0.0 && blueToSet <= 1.0)
		{
			this->blue = blueToSet;
		}
	}

	inline void SetAlpha(const float& alphaToSet)
	{
		if (alphaToSet >= 0.0 && alphaToSet <= 1.0)
		{
			this->alpha = alphaToSet;
		}
	}

	bool operator==(const Color& other) const {
		return red == other.red && green == other.green && blue == other.blue;
	}

	bool operator!=(const Color& other) const {
		return !(*this == other);
	}

};

