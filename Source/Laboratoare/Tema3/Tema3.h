#pragma once
#include <Component/SimpleScene.h>
#include <Component/Transform/Transform.h>
#include <Core/GPU/Mesh.h>
#include "Intersection.h"
#include "Building.h"
#include "Space.h"

class Tema3 : public SimpleScene
{
public:
	Tema3();
	~Tema3();

	void Init() override;


	float xList[30];
	float zList[30];

	float xstart, xend, zstart, zend;
	int numberOfX, numberOfZ;

	Intersection **intersections;

	Space **spaces;

	Building *buildings;

	int emptySpaces;
	bool generatedBuildings;
	int buildingCounter;

	int totalSpaces = 2500;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void drawStreetBetween(Intersection p1, Intersection p2);

	void generateBuilding(Building b);

	float generateRandomScale(float low, float high);

	void computeBuildingScale(Building *b);

	void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture1 = NULL);
	Texture2D* CreateRandomTexture(unsigned int width, unsigned int height);


	void RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix);

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	std::unordered_map<std::string, Texture2D*> mapTextures;
	GLuint randomTextureID;

	glm::mat4 extraRotation;

	glm::vec3 lightPosition;
	glm::vec3 lightDirection;

	glm::vec3 directionalLight;

	unsigned int materialShininess;
	float materialKd;
	float materialKs;

	int spotLight;
	float cutOff;

	int isBuilding;
};
