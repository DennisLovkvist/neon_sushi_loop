/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2021-10-18)
 */

#pragma once
#include <SFML/Graphics.hpp>

const static int SCREEN_WIDTH = 1920;
const static int SCREEN_HEIGHT = 1080;
const static int COUNT_RIPPLES = 100;
const static int COUNT_DROPLETS = 60;	
const static int COUNT_SKYSCRAPER_WINDOWS = 332;
const static int COUNT_RAIN = 100;
const static int COUNT_FLYING_CARS = 20;

struct Canvas
{

	sf::RenderTexture render_target_pass_0;
	sf::RenderTexture render_target_pass_1;
	sf::RenderTexture render_target_pass_2;

	sf::RenderTexture render_target_window_refraction;
	sf::RenderTexture render_target_water_surface_distortion;
	sf::RenderTexture render_target_glas_refraction;

	sf::Sprite sprite_pass_0;
	sf::Sprite sprite_pass_1;
	sf::Sprite sprite_pass_2;
	
	sf::Sprite sprite_window_refraction;
	sf::Sprite sprite_water_surface_distortion;	
	sf::Sprite sprite_glas_refraction;	

	sf::Sprite sprite_distortion_pattern;
	sf::Texture texture_distortion_pattern;
	sf::Texture tex_sprite_sheet;
	
	float time = 0.0f;

	sf::IntRect rectangle_window_droplets[2];
	sf::IntRect rectangle_flying_cars[4];
	sf::IntRect rectangle_sushi_plates[5];

	sf::Vertex shape_ground[4];	
	sf::Vertex shape_skybox[4];
	
	sf::Sprite sprite_moon;

	float speed_clouds[3];	
	sf::Sprite sprite_clouds[3];

	sf::Sprite sprite_skyline_0;
	sf::Sprite sprite_skyline_1;
	sf::Sprite sprite_skyline_2;
	sf::Sprite sprite_skyline_reflection;
	sf::Sprite sprite_water_mask;

	sf::Sprite sprite_flying_cars[COUNT_FLYING_CARS];	
	sf::Vertex shape_light_trail_outer[3*COUNT_FLYING_CARS];
	sf::Vertex shape_light_trail_inner[3*COUNT_FLYING_CARS];
	float height_flying_cars[COUNT_FLYING_CARS];
	float speed_flying_cars[COUNT_FLYING_CARS];

	sf::Sprite sprite_window_small;
	sf::Color skyscraper_windows_color[332];
	sf::Vector2f skyscraper_windows_position[332];

	sf::Sprite sprite_neon_glow[7];
	sf::Sprite sprite_neon_signs[7];

	sf::Sprite sprite_ripples[COUNT_RIPPLES];
	float time_ripples[COUNT_RIPPLES];

	sf::Vertex droplet_trail[COUNT_DROPLETS*8];
	sf::Sprite sprite_droplets[COUNT_DROPLETS];
	float speed_droplets[COUNT_DROPLETS];
	float alpha_droplets[COUNT_DROPLETS];
	float scale_droplets[COUNT_DROPLETS];

	float speed_rain[COUNT_RAIN];
	float scale_rain[COUNT_RAIN];
	sf::Sprite sprite_rain[COUNT_RAIN];	
	sf::Sprite sprite_rain_highlight[COUNT_RAIN];

	sf::Sprite sprite_wall_pattern[6];
	sf::Vertex shape_window_frame[16];

	sf::Sprite sprite_arcade_layer_0;
	sf::Sprite sprite_arcade_layer_1;

	sf::Sprite sprite_neon_sign;

	sf::Sprite sprite_table;

	sf::Sprite sprite_tom_torso;
	sf::Sprite sprite_eddi_torso;
	sf::Sprite sprite_tom_head;
	sf::Sprite sprite_eddi_head;
	
	sf::Vertex shape_conveyor_belt[4];
	
	sf::Sprite sprite_sushi[5];
	sf::Sprite sprite_glas[2];
	sf::Sprite sprite_bottles[3];

	sf::Vertex shape_ambient_light[4];
};

void UpdateCanvas(Canvas&, float,float);
void UpdateFallingRain(Canvas&,float);
void UpdateRainWaterRipples(Canvas&,float);
void UpdateWindowRainDroplets(Canvas&,float);
void UpdateFlyingCars(Canvas&,float);
void UpdateMisc(Canvas&,float,float);
void UpdateWindows(Canvas&, float);

void InitCanvas(Canvas&);
void InitRendering(Canvas&,sf::Color&);
void InitWall(Canvas&,sf::IntRect&,sf::Color&);
void InitCity(Canvas&,sf::IntRect&, sf::Color&);
void InitArcadeMachine(Canvas&, sf::IntRect&);
void InitFlyingCars(Canvas&,sf::Color&);
void InitSushiTable(Canvas&);
void InitCharacters(Canvas&);
void InitWhiskeyTable(Canvas&);
void InitFallingRain(Canvas&);
void InitRainWaterRipples(Canvas&);
void InitWindowRainDroplets(Canvas&);
void InitClouds(Canvas&);
void InitCityNeonSigns(Canvas&);	
void InitSkyscraperWindows(Canvas&);

void RandomizeCloud(sf::Sprite&, float&);
void LoadTextures(Canvas&);
void RenderPass0(Canvas&,sf::Shader&,sf::Shader&);
void RenderPass1(Canvas&);
void DrawWorld(sf::RenderWindow&, sf::Shader&,sf::Shader&,Canvas&);
