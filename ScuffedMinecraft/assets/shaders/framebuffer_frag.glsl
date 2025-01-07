#version 330 core

out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D screenTexture;
uniform sampler2D depthTexture;

uniform bool underwater;
uniform bool underlava;

const vec3 waterFogColor = vec3(0, 0, 0.25);
const vec3 lavaFogColor = vec3(0.45, 0.1, 0);
const float fogNear = 0.9;
const float fogFar = 1.0;

void main()
{
	vec3 color = texture(screenTexture, TexCoords).rgb;
	float depth = texture(depthTexture, TexCoords).r;

	vec3 finalColor = color;

	// Calculate fog
	if (underwater)
	{
		float fogFactor = (fogFar - depth) / (fogFar - fogNear);
		fogFactor = clamp(fogFactor, .354, 1.0);

		finalColor = mix(waterFogColor, color, fogFactor);
	}
	if (underlava)
	{
		float fogFactor = (fogFar - depth) / (fogFar - fogNear);
		fogFactor = clamp(fogFactor, .0154, .5);

		finalColor = mix(lavaFogColor, color, fogFactor);
	}

	FragColor = vec4(vec3(finalColor), 1.0);
}