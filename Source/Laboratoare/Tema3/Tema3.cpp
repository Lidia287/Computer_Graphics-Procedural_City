#include "Tema3.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

Tema3::Tema3()
{
}

Tema3::~Tema3()
{
}

void Tema3::Init()
{



	isBuilding = 0;

	const string textureLoc = "Source/Laboratoare/Tema3/Textures/";

	// Load textures
	
	

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "sidewalk.jpg").c_str(), GL_REPEAT);
		mapTextures["sidewalk"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "tower2.jpg").c_str(), GL_REPEAT);
		mapTextures["tower2"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "black.jpg").c_str(), GL_REPEAT);
		mapTextures["black"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grey1.jpg").c_str(), GL_REPEAT);
		mapTextures["grey1"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grey2.jpg").c_str(), GL_REPEAT);
		mapTextures["grey2"] = texture;
	}

	

	


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "darkgrass.jpg").c_str(), GL_REPEAT);
		mapTextures["darkgrass"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "grass.png").c_str(), GL_REPEAT);
		mapTextures["grass"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "street.jpg").c_str(), GL_REPEAT);
		mapTextures["street"] = texture;
	}


	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "rotateStreet.jpg").c_str(), GL_REPEAT);
		mapTextures["rotateStreet"] = texture;
	}

	

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "intersect.jpg").c_str(), GL_REPEAT);
		mapTextures["intersect"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "buildingBlue.jpg").c_str(), GL_REPEAT);
		mapTextures["buildingBlue"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "buildingBlue512.jpg").c_str(), GL_REPEAT);
		mapTextures["buildingBlue512"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "brown512.jpg").c_str(), GL_REPEAT);
		mapTextures["brown512"] = texture;
	}

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "brown.jpg").c_str(), GL_REPEAT);
		mapTextures["brown"] = texture;
	}


	{
		mapTextures["random"] = CreateRandomTexture(32, 32);
	}

	// Load meshes
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("StreetLamp");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "StreetLamp.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("Streetlight_LowRes");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "Streetlight_LowRes.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("Bench_LowRes");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "Bench_LowRes.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	


	{
		Mesh* mesh = new Mesh("cylinder");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "cylinder.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	{
		Mesh* mesh = new Mesh("bench");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "bench.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	

	// Create a simple quad
	{
		vector<glm::vec3> vertices
		{
			glm::vec3(0.5f,   0.5f, 0.0f),	// Top Right
			glm::vec3(0.5f,  -0.5f, 0.0f),	// Bottom Right
			glm::vec3(-0.5f, -0.5f, 0.0f),	// Bottom Left
			glm::vec3(-0.5f,  0.5f, 0.0f),	// Top Left
		};

		vector<glm::vec3> normals
		{
			glm::vec3(0, 1, 1),
			glm::vec3(1, 0, 1),
			glm::vec3(1, 0, 0),
			glm::vec3(0, 1, 0)
		};

		// TODO : Complete texture coordinates for the square
		vector<glm::vec2> textureCoords
		{
			glm::vec2(1.0f, 0.0f),
			glm::vec2(1.0f, 1.0f),
			glm::vec2(0.0f, 1.0f),
			glm::vec2(0.0f, 0.0f)
		};

		vector<unsigned short> indices =
		{
			1, 0, 3,
			1, 2, 3

		};

		Mesh* mesh = new Mesh("square");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}



	{
		vector<glm::vec3> vertices
		{
			glm::vec3(0.5f,   0.0f, 0.5f),	// Top Right
			glm::vec3(0.5f,  0.0f, -0.5f),	// Bottom Right
			glm::vec3(-0.5f, 0.0f, -0.5f),	// Bottom Left
			glm::vec3(-0.5f,  0.0f, 0.5f),	// Top Left
		};

		vector<glm::vec3> normals
		{
			glm::vec3(0, 1, 1),
			glm::vec3(1, 0, 1),
			glm::vec3(1, 0, 0),
			glm::vec3(0, 1, 0)
		};

		// TODO : Complete texture coordinates for the square
		vector<glm::vec2> textureCoords
		{
			glm::vec2(0.0f, 1.0f),
			glm::vec2(1.0f, 1.0f),
			glm::vec2(1.0f, 0.0f),
			glm::vec2(0.0f, 0.0f)
		};



		vector<unsigned short> indices =
		{
			0, 1, 3,
			1, 2, 3
		};

		Mesh* mesh = new Mesh("squareRotate");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}

	//parallelepiped

	{
	

	float dimension = 0.5f;

	vector<glm::vec3> vertices;
	vector<unsigned short> indices;
	vector<glm::vec2> textureCoords;
	vector<glm::vec3> normals;


	for (int i = 0; i < 6; i++) {
		

		if (i == 0) {
			vertices.push_back(glm::vec3(-dimension, dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(dimension, dimension, -dimension));
		}

		if (i == 1) {
			vertices.push_back(glm::vec3(dimension, dimension, -dimension));
			vertices.push_back(glm::vec3(dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(dimension, -dimension, dimension));
			vertices.push_back(glm::vec3(dimension, dimension, dimension));
		}

		if (i == 2) {
			vertices.push_back(glm::vec3(dimension, dimension, dimension));
			vertices.push_back(glm::vec3(dimension, -dimension, dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, dimension));
			vertices.push_back(glm::vec3(-dimension, dimension, dimension));
		}

		if (i == 3) {
			vertices.push_back(glm::vec3(-dimension, dimension, dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, dimension, -dimension));
		}

		if (i == 4) {
			vertices.push_back(glm::vec3(dimension, -dimension, dimension));
			vertices.push_back(glm::vec3(dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, -dimension, dimension));
			
		}

		if (i == 5) {
			vertices.push_back(glm::vec3(dimension, dimension, dimension));
			vertices.push_back(glm::vec3(dimension, dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, dimension, -dimension));
			vertices.push_back(glm::vec3(-dimension, dimension, dimension));

		}

		normals.push_back(glm::vec3(1, 1, 0));
		normals.push_back(glm::vec3(1, 1, 0));
		normals.push_back(glm::vec3(1, 1, 0));
		normals.push_back(glm::vec3(1, 1, 0));


		textureCoords.push_back(glm::vec2(0.0f, 0.0f));
		textureCoords.push_back(glm::vec2(0.0f, 1.0f));
		textureCoords.push_back(glm::vec2(1.0f, 1.0f));
		textureCoords.push_back(glm::vec2(1.0f, 0.0f));

	


		indices.push_back(0 + 4 * i);
		indices.push_back(1 + 4 * i);
		indices.push_back(3 + 4 * i);
		indices.push_back(1 + 4 * i);
		indices.push_back(2 + 4 * i);
		indices.push_back(3 + 4 * i);
	}

		Mesh* mesh = new Mesh("parallelepiped");
		mesh->InitFromData(vertices, normals, textureCoords, indices);
		meshes[mesh->GetMeshID()] = mesh;
	}



	// Create a shader program for drawing face polygon with the color of the normal
	{
		Shader *shader = new Shader("ShaderLab9");
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/VertexShader.glsl", GL_VERTEX_SHADER); 
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	//Light & material properties
	{
		lightPosition = glm::vec3(0, 8, 0);
		lightDirection = glm::vec3(0, -1, 0);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;

		spotLight = 0;
		cutOff = glm::radians(150.);

		directionalLight = glm::vec3(0,0,0);

	}


	


	generatedBuildings = false;

	spaces = new Space*[50];

	xstart = -24.5f;
	zstart = -24.5f;

	for (int i = 0; i < 50; i ++) {

		spaces[i] = new Space[50];

		for (int j = 0; j < 50; j ++) {
			
			spaces[i][j].setValues(xstart, 0, zstart, true);

			zstart++;
			emptySpaces++;
			
		}

		xstart++;
		zstart = -24.5f;
	}




	//the edges of the given coordinate system
	xstart = -24.5f;
	xend = 24.5f; 
	zstart = -24.5f;
	zend = 24.5f;


	//generating random list of x values
	int countX = 0;
	int currentX = xstart;
	xList[countX] = xstart;

	while (currentX + 5 < xend) {
		currentX = currentX + rand() % 10 + 5;

		if (currentX + 5 < xend) {
			countX++;
			xList[countX] = currentX + 0.5f;
		}
	}


	countX++;
	xList[countX] = xend;


	//generating random list of z values
	int countZ = 0;
	int currentZ = zstart;
	zList[countZ] = zstart;

	while (currentZ + 5 < zend) {
		currentZ = currentZ + rand() % 10 + 5;

		if (currentZ + 5 < zend) {
			countZ++;
			zList[countZ] = currentZ + 0.5f;
		}
	}

	countZ++;
	zList[countZ] = zend;


	//creating matrix of intersections with the random coordinates computed
	//they will be in ascending order
	numberOfX = countX + 1;
	numberOfZ = countZ + 1;

	intersections = new Intersection*[numberOfX];

	for (int i = 0; i < numberOfX; i ++) {
		intersections[i] = new Intersection[numberOfZ];

		for (int j = 0; j < numberOfZ; j ++) {
			intersections[i][j].setValues(xList[i], 0, zList[j]);
		}

	}

	buildingCounter = totalSpaces;
	

 }

void Tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema3::Update(float deltaTimeSeconds)
{

	

	

	//put grass in the scene
	for (int i = -24; i < 25; i++) {

		for (int j = -24; j < 25; j++) {


			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(i+0.5f, -0.01f, j+0.5f));
			modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["darkgrass"]); 


		}

	}


	//draw the intersections 
	for (int i = 0; i < numberOfX; i++) {

		for (int j = 0; j < numberOfZ; j++) {

			

			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(intersections[i][j].x, intersections[i][j].y, intersections[i][j].z));
			modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
			RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["intersect"]);

		

			float spX = intersections[i][j].x + 24.5f;
			float spZ = intersections[i][j].z + 24.5f;

			int sX = spX;
			int sZ = spZ;

			spaces[sX][sZ].free = false;

			emptySpaces--;

		}

	}


	//draw the streets between the intersections
	//the matrix elements are in ascending order so I only need to draw a street between the current and the next intersections
	//the streets betwen the current and previous intersections were already drawn
	for (int i = 0; i < numberOfX; i++) {

		for (int j = 0; j < numberOfZ; j++) {

	
			if (i + 1 <= numberOfX - 1) {
				drawStreetBetween(intersections[i][j], intersections[i + 1][j]);
			}

			if (j + 1 <= numberOfZ - 1) {
				drawStreetBetween(intersections[i][j], intersections[i][j + 1]);
			}
		}


	}

	//compute buildings characteristics
	if (generatedBuildings == false) {
		buildings = new Building[totalSpaces];
		generatedBuildings = true;

		buildingCounter = 0;

		for (int i = 1; i < 49; i++) {

			for (int j = 1; j < 49; j++) {

				if (spaces[i][j].free == true) {

				
					int numberOfSpaces = 1;

					
					int numberOfComponents = rand() % 3 + 1;
					buildings[buildingCounter].setValues(spaces[i][j].x, spaces[i][j].y, spaces[i][j].z, numberOfSpaces, numberOfComponents);

					int type = rand() % 3 + 2;

					buildings[buildingCounter].type = type;

					spaces[i][j].free = false;

					computeBuildingScale(&buildings[buildingCounter]);

					buildingCounter++;
				}

			}

			
		}
		
	}

	//draw the buildings
	for (int i = 0; i < buildingCounter; i++) {
		generateBuilding(buildings[i]);
	}
	


}

//for each type of building , compute scale factors for components
void Tema3::computeBuildingScale(Building *b) {

	if (b->numberOfSpaces == 1) {



		if (b->numberOfComponents == 1) {
			

			float sx1 = generateRandomScale(0.7f,1.0f);
			float sy1 = generateRandomScale(0.9f,1.7f);
			float sz1 = generateRandomScale(0.7f,1.0f);

			b->setValues(sx1, sy1, sz1);

		}
		else if (b->numberOfComponents == 2) {


			float sx1 = generateRandomScale(0.6f, 0.7f);
			float sy1 = generateRandomScale(1.75f, 2.0f);
			float sz1 = generateRandomScale(0.6f, 0.7f);


			float sx2 = generateRandomScale(0.4f, 0.5f);
			float sy2 = generateRandomScale(0.4f, 0.5f);
			float sz2 = generateRandomScale(0.4f, 0.5f);

			b->setValues(sx1,sy1,sz1,sx2,sy2,sz2);

		}
		else if (b->numberOfComponents == 3) {
		

			float sx1 = generateRandomScale(0.25f, 0.3f);
			float sy1 = generateRandomScale(0.4f, 0.5f);
			float sz1 = generateRandomScale(0.25f, 0.3f);


			float sx2 = generateRandomScale(0.2f, 0.22f);
			float sy2 = generateRandomScale(0.2f, 0.3f);
			float sz2 = generateRandomScale(0.2f, 0.22f);


			float sx3 = generateRandomScale(0.11f, 0.17f);
			float sy3 = generateRandomScale(0.1f, 0.25f);
			float sz3 = generateRandomScale(0.12f, 0.17f);


			b->setValues(sx1, sy1, sz1, sx2, sy2, sz2, sx3, sy3, sz3);
		}


	}
	
	
	
}

void Tema3::generateBuilding(Building b) {

	isBuilding = 1;

	if (b.numberOfSpaces == 1) {
		
	

		if (b.numberOfComponents == 1) {

			materialShininess = 30;
			cutOff = glm::radians(150.);

			lightPosition = glm::vec3(b.x, b.y + b.sy1 * 2, b.z);
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + b.sy1/2, b.z));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx1, b.sy1, b.sz1));
			RenderSimpleMesh(meshes["parallelepiped"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);
		}
		else if (b.numberOfComponents == 2) {

			materialShininess = 30;
			cutOff = glm::radians(150.);
		
			lightPosition = glm::vec3(b.x, b.y + b.sy1 * 2 , b.z);
			glm::mat4 modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + b.sy1 / 2, b.z));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx1, b.sy1, b.sz1));
			RenderSimpleMesh(meshes["parallelepiped"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);

			lightPosition = glm::vec3(b.x, b.y + b.sy1 * 2 + b.sy2 * 2, b.z);
			modelMatrix = glm::mat4(1);
			modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + b.sy1 + b.sy2 / 2, b.z));
			modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx2, b.sy2, b.sz2));
			RenderSimpleMesh(meshes["parallelepiped"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]); 
		}
		else if (b.numberOfComponents == 3) {


			if (b.type == 3) {

				materialShininess = 30;
				cutOff = glm::radians(170.);

				lightPosition = glm::vec3(b.x, b.y + 8 * b.sy1, b.z);
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + 4 * b.sy1, b.z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx1, b.sy1, b.sz1));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["cylinder"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);


				lightPosition = glm::vec3(b.x, b.y + 4 * b.sy1 + 8 * b.sy2 , b.z);
				modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + 4 * b.sy1 + 4 * b.sy2, b.z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx2, b.sy2, b.sz2));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["cylinder"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);


				lightPosition = glm::vec3(b.x, b.y + 4 * b.sy1 + 4 * b.sy2 + 8 * b.sy3, b.z);
				modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + 4 * b.sy1 + 4 * b.sy2 + 4 * b.sy3, b.z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx3, b.sy3, b.sz3));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["cylinder"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);

			}


			if (b.type == 2) {

				materialShininess = 30;
				cutOff = glm::radians(170.);

				
				lightPosition = glm::vec3(b.x, b.y + 8 * b.sy1 , b.z);
				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + 4 * b.sy1, b.z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx1, b.sy1, b.sz1));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["cylinder"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);


				lightPosition = glm::vec3(b.x, b.y + 4 * b.sy1 + 8 * b.sy2, b.z);
				modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(b.x, b.y + 4 * b.sy1 + 4 * b.sy2, b.z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(b.sx2, b.sy2, b.sz2));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["cylinder"], shaders["ShaderLab9"], modelMatrix, mapTextures["buildingBlue512"]);
			}
		}


	}

	isBuilding = 0;
	
	
}

float Tema3::generateRandomScale(float low, float high) {

	float result = low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));

	return result;
}


void Tema3::drawStreetBetween(Intersection p1, Intersection p2) {

	//there are two cases , when the x values are the same and when the x values are the same
	//these cases influence the orientation of the street
	if (p1.x == p2.x) {

		
		float z = p1.z;



		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(p1.x, 0.0f, (p1.z + p2.z) / 2));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, abs(p1.z - p2.z) - 1 ));
		modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
		RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["street"]);

		while (z + 1 < p2.z) {
			z = z + 1;

			//sidewalk left
			if (p1.x != -24.5) {


			

				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(p1.x - 0.75f, 0.0f, z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 1.0f, 1.0f));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["sidewalk"]);

				//place street lighters randomly
				if ((int)(z - 0.5f) % 3 == 0) {
					modelMatrix = glm::mat4(1);
					modelMatrix = glm::translate(modelMatrix, glm::vec3(p1.x - 0.9f, 0.0f, z));
					modelMatrix = glm::scale(modelMatrix, glm::vec3(0.002f, 0.002f, 0.002f));
					RenderSimpleMesh(meshes["Streetlight_LowRes"], shaders["ShaderLab9"], modelMatrix, mapTextures["grey2"]);
				}

				float spX = p1.x - 1 + 24.5f;
				float spZ = z + 24.5f;

				int sX = spX;
				int sZ = spZ;

				spaces[sX][sZ].free = false;

				emptySpaces--;
			
			}


			

			float spX = p1.x + 24.5f;
			float spZ = z + 24.5f;

			int sX = spX;
			int sZ = spZ;

			spaces[sX][sZ].free = false;

			emptySpaces--;

			//sidewalk right
			if (p1.x != 24.5) {


				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(p1.x + 0.75f, 0.0f, z));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 1.0f, 1.0f));
				modelMatrix = glm::rotate(modelMatrix, RADIANS(90.0f), glm::vec3(1, 0, 0));
				RenderSimpleMesh(meshes["square"], shaders["ShaderLab9"], modelMatrix, mapTextures["sidewalk"]);

			

			

				float spX = p1.x + 1 + 24.5f;
				float spZ = z + 24.5f;

				int sX = spX;
				int sZ = spZ;

				spaces[sX][sZ].free = false;

				emptySpaces--;

			}
		}
	}

	if (p1.z == p2.z) {
	


		float x = p1.x;

		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, glm::vec3((p1.x + p2.x) / 2, 0.0f, p1.z));
		modelMatrix = glm::scale(modelMatrix, glm::vec3(abs(p1.x - p2.x) - 1, 1.0f, 1.0f));
		RenderSimpleMesh(meshes["squareRotate"], shaders["ShaderLab9"], modelMatrix, mapTextures["rotateStreet"]);

	

		while (x + 1 < p2.x) {
			x = x + 1;

			

			//sidewalk up
			if (p1.z != -24.5) {

			

				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(x, 0.0f, p1.z - 0.75f));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, 0.5f));
				RenderSimpleMesh(meshes["squareRotate"], shaders["ShaderLab9"], modelMatrix, mapTextures["sidewalk"]);

				
				//place benches randomly
				if (((int)(x - 0.5f) % 3 == 0) && (x - 0.5f < p2.x - 2) && (x - 0.5f > p1.x + 0.5f)) {
					modelMatrix = glm::mat4(1);
					modelMatrix = glm::translate(modelMatrix, glm::vec3(x - 0.5f, 0.0f, p1.z - 0.9f));
					modelMatrix = glm::scale(modelMatrix, glm::vec3(0.002f, 0.002f, 0.002f));
					RenderSimpleMesh(meshes["Bench_LowRes"], shaders["Simple"], modelMatrix, mapTextures["brown512"]);
				}

				float spX = x + 24.5f;
				float spZ = p1.z - 1 + 24.5f;

				int sX = spX;
				int sZ = spZ;

				spaces[sX][sZ].free = false;

				emptySpaces--;
			}




			float spX = x + 24.5f;
			float spZ = p1.z + 24.5f;

			int sX = spX;
			int sZ = spZ;

			spaces[sX][sZ].free = false;

			emptySpaces--;


			//sidewalk down
			if (p1.z != 24.5) {

				

				glm::mat4 modelMatrix = glm::mat4(1);
				modelMatrix = glm::translate(modelMatrix, glm::vec3(x, 0.0f, p1.z + 0.75f));
				modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, 0.5f));
				RenderSimpleMesh(meshes["squareRotate"], shaders["ShaderLab9"], modelMatrix, mapTextures["sidewalk"]);

				

				float spX = x + 24.5f;
				float spZ = p1.z + 1 + 24.5f;

				int sX = spX;
				int sZ = spZ;

				spaces[sX][sZ].free = false;

				emptySpaces--;
			}
		}
	}
}


void Tema3::FrameEnd()
{
	DrawCoordinatSystem();
}

void Tema3::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
	if (!mesh || !shader || !shader->program)
		return;

	// render an object using the specified shader and the specified position
	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(GetSceneCamera()->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(GetSceneCamera()->GetProjectionMatrix()));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	mesh->Render();
}

void Tema3::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);


	// Set shader uniforms for light & material properties
	// TODO: Set light position uniform
	int light_position = glGetUniformLocation(shader->program, "light_position");
	glUniform3f(light_position, lightPosition.x, lightPosition.y, lightPosition.z);

	int directional_light = glGetUniformLocation(shader->program, "directional_light");
	glUniform3f(directional_light, directionalLight.x, directionalLight.y, directionalLight.z);

	int light_direction = glGetUniformLocation(shader->program, "light_direction");
	glUniform3f(light_direction, lightDirection.x, lightDirection.y, lightDirection.z);

	// TODO: Set eye position (camera position) uniform
	glm::vec3 eyePosition = GetSceneCamera()->transform->GetWorldPosition();
	int eye_position = glGetUniformLocation(shader->program, "eye_position");
	glUniform3f(eye_position, eyePosition.x, eyePosition.y, eyePosition.z);

	// TODO: Set material property uniforms (shininess, kd, ks, object color) 
	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);

	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);



	int isBuildingLoc = glGetUniformLocation(shader->program, "isBuilding");
	glUniform1i(isBuildingLoc, isBuilding);

	int cutOffLoc = glGetUniformLocation(shader->program, "cut_off");
	glUniform1f(cutOffLoc, cutOff);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	//glUniform1i(glGetUniformLocation(shader->program, "isgrass"), 0);

	if (texture1)
	{
		//TODO : activate texture location 0
		glActiveTexture(GL_TEXTURE0);
		//TODO : Bind the texture1 ID
		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
		//TODO : Send texture uniform value
		glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);

	}

	

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

Texture2D* Tema3::CreateRandomTexture(unsigned int width, unsigned int height)
{
	GLuint textureID = 0;
	unsigned int channels = 3;
	unsigned int size = width * height * channels;
	unsigned char* data = new unsigned char[size];

	// TODO: generate random texture data

	for (int i = 0; i < size; i++)
		data[i] = rand() >> 5;

	// Generate and bind the new texture ID
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// TODO: Set the texture parameters (MIN_FILTER, MAG_FILTER and WRAPPING MODE) using glTexParameteri

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4);

	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	CheckOpenGLError();

	// TODO: Use glTextImage2D to set the texture data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// TODO: Generate texture mip-maps
	glGenerateMipmap(GL_TEXTURE_2D);

	CheckOpenGLError();

	// Save the texture into a wrapper Texture2D class for using easier later during rendering phase
	Texture2D* texture = new Texture2D();
	texture->Init(textureID, width, height, channels);

	SAFE_FREE_ARRAY(data);
	return texture;
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Tema3::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));

		extraRotation = glm::mat4(forward.z, 0, -forward.x, 0, 0, 1, 0, 0, forward.x, 0, forward.z, 0, 0, 0, 0, 1);

	}



}

void Tema3::OnKeyPress(int key, int mods)
{
	// add key press event


}

void Tema3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema3::OnWindowResize(int width, int height)
{
}
