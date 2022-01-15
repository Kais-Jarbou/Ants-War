class Box
{
public:
	float X, Z, W, L;
	SkyBox sky;
	Ant ants [5];
	bool living [5];
	bool col;
	Camera out;

public: 
	Box () {};
	Box(float x, float z, float w, float l) {

		X = x;
		Z = z;
		W = w;
		L = l;
		out = Camera(X+W/2+10, 13, Z, 0);
		sky = SkyBox();
	}
};

