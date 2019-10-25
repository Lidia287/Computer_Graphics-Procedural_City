#version 330
 
uniform sampler2D texture_1;
uniform sampler2D texture_2;
 
in vec2 texcoord;

in vec3 world_position;
in vec3 world_normal;

in vec3 v_position;

uniform int isgrass;


uniform int isglobe;
uniform float time;

// Uniforms for light properties
uniform vec3 light_direction;
uniform vec3 light_position;
uniform vec3 eye_position;

uniform vec3 directional_light;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

//uniform vec3 object_color;
uniform float cut_off;

uniform int isBuilding;


layout(location = 0) out vec4 out_color;

void main()
{

	vec3 L = normalize(light_position - world_position);
	vec3 V = normalize(eye_position - world_position);
	vec3 H = normalize(L + V);
	
	// TODO: define ambient light component
	float ambient_light = 0.25 * material_kd;

	// TODO: compute diffuse light component
	float diffuse_light = material_kd * max(dot(normalize(world_normal),L),0);

	// TODO: compute specular light component
	float specular_light = 0;

	if (diffuse_light > 0)
	{
		specular_light =  pow(max(0, dot(normalize(world_normal),H)), material_shininess);
	}

	// TODO: compute light
	float d = length(world_position - light_position);
	float fa = 1/pow(d,2);

	float spot_light = dot(-L, light_direction);
	float spot_light_limit = cos(cut_off);

	float linear_att = (spot_light - spot_light_limit) / (1 - spot_light_limit);
	float light_att_factor = pow(linear_att, 2);



	// TODO : calculate the out_color using the texture2D() function
	vec4 color = texture2D(texture_1, texcoord);

	color = texture2D(texture_1, texcoord);
	

	if (color.a < 0.5) 
		discard;
	//out_color = color; 


	vec3 objectColor = vec3(color.r,color.g,color.b);
	
	
	if(isBuilding == 1){
		objectColor = (ambient_light + (diffuse_light  + specular_light ) * light_att_factor) * objectColor;
	}	


	vec3 v_pos = vec3(v_position.x, 0 ,v_position.z);

	 L = normalize(v_pos - world_position); //directional_light
	 V = normalize(eye_position - world_position);
	 H = normalize(L + V);
	
	// TODO: define ambient light component
	 ambient_light = 0.25 * material_kd;

	// TODO: compute diffuse light component
	 diffuse_light = material_kd * max(dot(normalize(world_normal),L),0);

	// TODO: compute specular light component
	 specular_light = 0;

	if (diffuse_light > 0)
	{
		specular_light =  pow(max(0, dot(normalize(world_normal),H)), material_shininess);
	}




	if(isBuilding == 0){
		objectColor = (ambient_light + (diffuse_light  + specular_light )) * objectColor;
	}
	
	
	
	// TODO: write pixel out color
	out_color = vec4(objectColor, 1);
	

}