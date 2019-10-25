class Building
{
public:
	float x;
	float y;
	float z;
	int numberOfSpaces;
	float x2;
	float y2;
	float z2;
	int numberOfComponents; // 1 = house , 2 = building of flats , 3 = office tower
	int type; // cylinder with 2 or 3 

	float sx1;
	float sx2;
	float sx3;

	float sy1;
	float sy2;
	float sy3;

	float sz1;
	float sz2;
	float sz3;

public:
	void setValues(float x, float y, float z, int numberOfSpaces, int numberOfComponents);
	void setValues(float x, float y, float z, int numberOfSpaces, float x2, float y2, float z2, int type);
	void setValues(float sx1, float sy1, float sz1);
	void setValues(float sx1, float sy1, float sz1, float sx2, float sy2, float sz2);
	void setValues(float sx1, float sy1, float sz1, float sx2, float sy2, float sz2, float sx3, float sy3, float sz3);
};
