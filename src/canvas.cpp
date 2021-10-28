/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2021-10-18)
 */

#include <SFML/Graphics.hpp>
#include "canvas.h"
#include <cmath>
#include <iostream>
#include <chrono>

void LoadTextures(Canvas& world)
{
	world.tex_sprite_sheet.loadFromFile("content/textures/sprite_sheet.png");
}

void InitCanvas(Canvas& world)
{
	//auto begin = std::chrono::high_resolution_clock::now();  

	sf::Color color;
	sf::IntRect rect;

	InitRendering(world,color);

	InitWall(world,rect,color);

	InitCity(world,rect,color);

	InitArcadeMachine(world,rect);

	InitFlyingCars(world,color);

	InitSushiTable(world);

	InitCharacters(world);
	
	InitWhiskeyTable(world);

	InitClouds(world);

	InitCityNeonSigns(world);
	
	InitSkyscraperWindows(world);

	InitFallingRain(world);

	InitRainWaterRipples(world);

	InitWindowRainDroplets(world);

	/*
	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    printf("Time measured: %.8f seconds.\n", elapsed.count() * 1e-9);*/

	
}
void InitRendering(Canvas& world,sf::Color& color)
{
	world.render_target_pass_0.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.render_target_pass_1.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.render_target_pass_2.create(SCREEN_WIDTH, SCREEN_HEIGHT);

	world.render_target_water_surface_distortion.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.render_target_glas_refraction.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.render_target_window_refraction.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.texture_distortion_pattern.create(660,200);	
	world.sprite_water_surface_distortion.setTexture(world.render_target_water_surface_distortion.getTexture());	
	world.sprite_glas_refraction.setTexture(world.render_target_glas_refraction.getTexture());	
	world.sprite_distortion_pattern.setTexture(world.texture_distortion_pattern);

	world.shape_ambient_light[0].position.x = 0;
	world.shape_ambient_light[0].position.y = 0;
	world.shape_ambient_light[1].position.x = SCREEN_WIDTH;
	world.shape_ambient_light[1].position.y = 0;
	world.shape_ambient_light[2].position.x = SCREEN_WIDTH;
	world.shape_ambient_light[2].position.y = SCREEN_HEIGHT;
	world.shape_ambient_light[3].position.x = 0;
	world.shape_ambient_light[3].position.y = SCREEN_HEIGHT;

	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	*r = 255;*g = 65;*b = 0;*a = 30;
	world.shape_ambient_light[0].color = color;
	world.shape_ambient_light[3].color = color;
	
	*r = 255;*g = 51;*b = 255;*a = 30;
	world.shape_ambient_light[1].color = color;
	world.shape_ambient_light[2].color = color;

	*r = 200;*g = 200;*b = 255;*a = 200;
	world.sprite_pass_0.setColor(color);
}
void InitWall(Canvas& world, sf::IntRect& rect, sf::Color& color)
{	
	world.shape_window_frame[0].position.x = 190;
	world.shape_window_frame[0].position.y = 130;
	world.shape_window_frame[1].position.x = 1460;
	world.shape_window_frame[1].position.y = 130;
	world.shape_window_frame[2].position.x = 1460;
	world.shape_window_frame[2].position.y = 146;
	world.shape_window_frame[3].position.x = 190;
	world.shape_window_frame[3].position.y = 146;

	world.shape_window_frame[4].position.x = 190;
	world.shape_window_frame[4].position.y = 590;
	world.shape_window_frame[5].position.x = 1460;
	world.shape_window_frame[5].position.y = 590;
	world.shape_window_frame[6].position.x = 1460;
	world.shape_window_frame[6].position.y = 606;
	world.shape_window_frame[7].position.x = 190;
	world.shape_window_frame[7].position.y = 606;

	world.shape_window_frame[8].position.x = 190;
	world.shape_window_frame[8].position.y = 130;
	world.shape_window_frame[9].position.x = 206;
	world.shape_window_frame[9].position.y = 130;
	world.shape_window_frame[10].position.x = 206;
	world.shape_window_frame[10].position.y = 600;
	world.shape_window_frame[11].position.x = 190;
	world.shape_window_frame[11].position.y = 600;

	world.shape_window_frame[12].position.x = 1450;
	world.shape_window_frame[12].position.y = 130;
	world.shape_window_frame[13].position.x = 1466;
	world.shape_window_frame[13].position.y = 130;
	world.shape_window_frame[14].position.x = 1466;
	world.shape_window_frame[14].position.y = 600;
	world.shape_window_frame[15].position.x = 1450;
	world.shape_window_frame[15].position.y = 600;

	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	*r = 30;*g = 30;*b = 30;*a = 255;
	for (size_t i = 0; i < 16; i++)
	{
		world.shape_window_frame[i].color = color;
	}
	int* x = &rect.left;
	int* y = &rect.top;
	int* w = &rect.width;
	int* h = &rect.height;

	*x = 196;*y = 790;*w = 414;*h = 290;
	world.sprite_neon_sign.setTextureRect(rect);

	world.sprite_neon_sign.setTexture(world.tex_sprite_sheet);
	world.sprite_neon_sign.setPosition(1470,150);


	*x = 0;*y = 783;*w = 196;*h = 298;

	for (size_t i = 0; i < 6; i++)
	{	
		world.sprite_wall_pattern[i].setTexture(world.tex_sprite_sheet);
		world.sprite_wall_pattern[i].setTextureRect(rect);
	}

	world.sprite_wall_pattern[0].setPosition(0,0);
	world.sprite_wall_pattern[1].setPosition(1450,0);
	world.sprite_wall_pattern[2].setPosition(1450+196,0);
	world.sprite_wall_pattern[3].setPosition(1450+196+196,0);
	world.sprite_wall_pattern[4].setPosition(1944,-60);
	world.sprite_wall_pattern[5].setPosition(1944,600);

	world.sprite_wall_pattern[0].setScale(1,2.2);
	world.sprite_wall_pattern[1].setScale(1,2.2);
	world.sprite_wall_pattern[2].setScale(1,2.2);
	world.sprite_wall_pattern[3].setScale(1,2.2);	
	world.sprite_wall_pattern[4].setScale(1,6.6);
	world.sprite_wall_pattern[5].setScale(1,6.6);

	world.sprite_wall_pattern[4].rotate(90);
	world.sprite_wall_pattern[5].rotate(90);
}
void InitCity(Canvas& world, sf::IntRect& rect, sf::Color& color)
{
	world.sprite_water_mask.setTexture(world.tex_sprite_sheet);
	world.sprite_window_refraction.setTexture(world.tex_sprite_sheet);
	world.sprite_window_small.setTexture(world.tex_sprite_sheet);
	world.sprite_skyline_reflection.setTexture(world.tex_sprite_sheet);
	world.sprite_skyline_0.setTexture(world.tex_sprite_sheet);
	world.sprite_skyline_1.setTexture(world.tex_sprite_sheet);
	world.sprite_skyline_2.setTexture(world.tex_sprite_sheet);
	world.sprite_moon.setTexture(world.tex_sprite_sheet);

	int* x = &rect.left;
	int* y = &rect.top;
	int* w = &rect.width;
	int* h = &rect.height;

	*x = 0;*y = 1080;*w = 760;*h = 250;
	world.sprite_water_mask.setTextureRect(rect);
	
	*x = 950;*y = 790;*w = 16;*h = 16;
	world.sprite_window_refraction.setTextureRect(rect);

	*x = 950;*y = 806;*w = 8;*h = 8;
	world.sprite_window_small.setTextureRect(rect);
	
	*x = 760;*y = 1080;*w = 742;*h = 332;
	world.sprite_skyline_reflection.setTextureRect(rect);
	
	*x = 0;*y = 310;*w = 1370;*h = 472;
	world.sprite_skyline_0.setTextureRect(rect);
	
	*x = 812;*y = 930;*w = 408;*h = 150;
	world.sprite_skyline_1.setTextureRect(rect);

	*x = 950;*y = 818;*w = 420;*h = 112;
	world.sprite_skyline_2.setTextureRect(rect);

	*x = 1500;*y = 0;*w = 422;*h = 422;
	world.sprite_moon.setTextureRect(rect);

	world.sprite_moon.setPosition(512,0);
	world.sprite_skyline_0.setPosition(128,128);
	world.sprite_skyline_1.setPosition(128,240);
	world.sprite_skyline_2.setPosition(660,240);

	
	world.shape_ground[0].position.x = 130;
	world.shape_ground[0].position.y = 325;

	world.shape_ground[1].position.x = 750;
	world.shape_ground[1].position.y = 325;

	world.shape_ground[2].position.x = 750;
	world.shape_ground[2].position.y = 600;

	world.shape_ground[3].position.x = 130;
	world.shape_ground[3].position.y = 600;

	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	*r = 44;*g = 12;*b = 61;*a = 255;
	world.shape_ground[0].color = color;
	world.shape_ground[1].color = color;
	world.shape_ground[2].color = color;
	world.shape_ground[3].color = color;

	world.shape_skybox[0].position.x = 130;
	world.shape_skybox[0].position.y = 0;

	world.shape_skybox[1].position.x = 1450;
	world.shape_skybox[1].position.y = 0;

	world.shape_skybox[2].position.x = 1450;
	world.shape_skybox[2].position.y = 600;

	world.shape_skybox[3].position.x = 130;
	world.shape_skybox[3].position.y = 600;

	*r = 24;*g = 8;*b = 32;*a = 255;
	world.shape_skybox[0].color = color;
	world.shape_skybox[1].color = color;
	*r = 44;*g = 12;*b = 61;*a = 255;
	world.shape_skybox[2].color = color;
	world.shape_skybox[3].color = color;
}
void InitArcadeMachine(Canvas& world, sf::IntRect& source_rectangle)
{	
	world.sprite_arcade_layer_0.setTexture(world.tex_sprite_sheet);
	world.sprite_arcade_layer_1.setTexture(world.tex_sprite_sheet);

	source_rectangle.left = 958;source_rectangle.top = 1532;source_rectangle.width = 254;source_rectangle.height = 516;
	world.sprite_arcade_layer_0.setTextureRect(source_rectangle);

	source_rectangle.left = 646;source_rectangle.top = 1686;source_rectangle.width = 312;source_rectangle.height = 288;
	world.sprite_arcade_layer_1.setTextureRect(source_rectangle);

	world.sprite_arcade_layer_0.setPosition(20,250);
	world.sprite_arcade_layer_1.setPosition(-10,300);
}
void InitSushiTable(Canvas& world)
{		
	sf::IntRect rect = sf::IntRect(0,130,1500,180);
	world.sprite_table.setTextureRect(rect);
	world.sprite_table.setTexture(world.tex_sprite_sheet);	
	world.sprite_table.setPosition(0,750);
	world.sprite_table.setScale(2.1,1);
		
	world.rectangle_sushi_plates[0] = sf::IntRect(0,0,300,130);	
	world.rectangle_sushi_plates[1] = sf::IntRect(300,0,300,130);	
	world.rectangle_sushi_plates[2] = sf::IntRect(600,0,300,130);	
	world.rectangle_sushi_plates[3] = sf::IntRect(900,0,300,130);	
	world.rectangle_sushi_plates[4] = sf::IntRect(1200,0,300,130);	

	for (size_t i = 0; i < 5; i++)
	{
		world.sprite_sushi[i].setTexture(world.tex_sprite_sheet);
		world.sprite_sushi[i].setTextureRect(world.rectangle_sushi_plates[((rand() % 4) + 1)]);
		world.sprite_sushi[i].setPosition(30 + 550*i,780);
	}

	world.shape_conveyor_belt[0].position.x = 0;
	world.shape_conveyor_belt[0].position.y = 850;
	world.shape_conveyor_belt[1].position.x = SCREEN_WIDTH;
	world.shape_conveyor_belt[1].position.y = 850;
	world.shape_conveyor_belt[2].position.x = SCREEN_WIDTH;
	world.shape_conveyor_belt[2].position.y = 930;
	world.shape_conveyor_belt[3].position.x = 0;
	world.shape_conveyor_belt[3].position.y = 930;

	sf::Color color_0 = sf::Color(50, 50, 50);
	sf::Color color_1 = sf::Color(40, 40, 40);

	world.shape_conveyor_belt[0].color = color_0;
	world.shape_conveyor_belt[1].color = color_0;
	world.shape_conveyor_belt[2].color = color_1;
	world.shape_conveyor_belt[3].color = color_1;
}
void InitFlyingCars(Canvas& world,sf::Color& color)
{
	world.rectangle_flying_cars[0] = sf::IntRect(966,790,48,22);	
	world.rectangle_flying_cars[1] = sf::IntRect(1016,790,32,12);	
	world.rectangle_flying_cars[2] = sf::IntRect(1016,802,32,10);	
	world.rectangle_flying_cars[3] = sf::IntRect(1048,790,28,12);

	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	float* height;
	sf::Sprite* flying_car;

	for (size_t i = 0; i < COUNT_FLYING_CARS; i++)
	{
		height = &world.height_flying_cars[i];
		flying_car = &world.sprite_flying_cars[i];

		flying_car->setTexture(world.tex_sprite_sheet);

		int n = (rand() % 4) + 0;	
		int x = ((rand() % 1200) + 0) - 1200;
		int y = 250 + ((rand() % 100) + 1)-50;
		*height = 14.0f;

		if(n == 1)
		{
			*height = 8;
		}
		else if(n == 2)
		{
			*height = 6;
		}
		else if(n == 3)
		{
			*height = 8;
		}
		*r = 255;*g = ((rand() % 255) + 1);*b = 255;*a = 255;
		world.speed_flying_cars[i] = (rand() % 4) + 2;
		flying_car->setPosition(x,y);	
		flying_car->setTextureRect(world.rectangle_flying_cars[n]);
		flying_car->setColor(color);
	}
}
void InitCharacters(Canvas& world)
{
	sf::IntRect rect = sf::IntRect(1370,494,346,346);
	world.sprite_tom_torso.setTexture(world.tex_sprite_sheet);	
	world.sprite_tom_torso.setTextureRect(rect);
	world.sprite_tom_torso.rotate(-90);
	world.sprite_tom_torso.setPosition(450,800);

	world.sprite_tom_head.setTexture(world.tex_sprite_sheet);		
	rect.left = 1716;rect.top = 494;rect.width = 268;rect.height = 210;
	world.sprite_tom_head.setTextureRect(rect);
	world.sprite_tom_head.rotate(-90);
	world.sprite_tom_head.setPosition(535,580);

	world.sprite_eddi_torso.setTexture(world.tex_sprite_sheet);	
	rect.left = 1370;rect.top = 840;rect.width = 240;rect.height = 240;
	world.sprite_eddi_torso.setTextureRect(rect);
	world.sprite_eddi_torso.rotate(-90);
	world.sprite_eddi_torso.setPosition(220,814);

	world.sprite_eddi_head.setTexture(world.tex_sprite_sheet);	
	rect.left = 1716;rect.top = 704;rect.width = 170;rect.height = 156;
	world.sprite_eddi_head.setTextureRect(rect);
	world.sprite_eddi_head.rotate(-90);
	world.sprite_eddi_head.setPosition(280,700);
}
void InitWhiskeyTable(Canvas& world)
{	
	world.sprite_bottles[0].setTexture(world.tex_sprite_sheet);
	world.sprite_bottles[1].setTexture(world.tex_sprite_sheet);
	world.sprite_bottles[2].setTexture(world.tex_sprite_sheet);
	world.sprite_glas[0].setTexture(world.tex_sprite_sheet);
	world.sprite_glas[1].setTexture(world.tex_sprite_sheet);

	sf::IntRect rect = sf::IntRect(646,1490,188,196);
	world.sprite_glas[0].setTextureRect(rect);
	world.sprite_glas[1].setTextureRect(rect);

	rect.left = 0;rect.top = 1490;rect.width = 276;rect.height = 558;
	world.sprite_bottles[0].setTextureRect(rect);

	rect.left = 276;rect.top = 1490;rect.width = 178;rect.height = 558;
	world.sprite_bottles[1].setTextureRect(rect);

	rect.left = 456;rect.top = 1490;rect.width = 190;rect.height = 558;
	world.sprite_bottles[2].setTextureRect(rect);

	world.sprite_glas[0].setPosition(200,790);
	world.sprite_glas[1].setPosition(450,790);
	world.sprite_bottles[0].setPosition(1100,420);
	world.sprite_bottles[1].setPosition(1430,420);
	world.sprite_bottles[2].setPosition(1700,420);
}
void InitFallingRain(Canvas& world)
{
	sf::IntRect rect = sf::IntRect(1220,960,14,42);
	sf::Color color = sf::Color(255,255,255,40);

	for (size_t i = 0; i < COUNT_RAIN; i++)
	{
		world.sprite_rain[i].setTexture(world.tex_sprite_sheet);
		world.sprite_rain[i].setTextureRect(rect);
		world.sprite_rain[i].setColor(color);
		
		int x = rand()%(1400-240 + 1) + 240;
		int y = rand()%(600-100 + 1) + 100;
		world.sprite_rain[i].setPosition(x,y);		
		world.sprite_rain[i].setScale(world.scale_rain[i],world.scale_rain[i]);

		world.scale_rain[i] = (float)(rand()%(100-10 + 1) + 10)/100.0f;			
		world.speed_rain[i] = (rand()%(50-45 + 1) + 45)*world.scale_rain[i];		
	}	
}
void InitRainWaterRipples(Canvas& world)
{
	sf::IntRect rect = sf::IntRect(0,1450,76,20);
	for (size_t i = 0; i < COUNT_RIPPLES; i++)
	{
		world.sprite_ripples[i].setTexture(world.tex_sprite_sheet);
		world.sprite_ripples[i].setTextureRect(rect);
		world.sprite_ripples[i].setScale(0.2,0.2);
		world.time_ripples[i] = (float)(rand()%(85-0 + 1) + 0)/100.0f;
	}
}
void InitWindowRainDroplets(Canvas& world)
{

	world.rectangle_window_droplets[0] = sf::IntRect(1220,930,26,30);
	world.rectangle_window_droplets[1] = sf::IntRect(1246,930,26,30);

	sf::IntRect rect = sf::IntRect(1220,930,26,30);
	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{
		world.sprite_rain_highlight[i].setTexture(world.tex_sprite_sheet);
		world.sprite_rain_highlight[i].setTextureRect(rect);
		world.sprite_rain_highlight[i].setScale(0.5f,1);
	}

	rect.left = 1220;rect.top = 960;rect.width = 14;rect.height = 42;
	sf::Color color = sf::Color(50,50,50);
	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{
		world.sprite_droplets[i].setTexture(world.tex_sprite_sheet);
		world.sprite_droplets[i].setColor(color);
	}
	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{
		int x = rand()%(1400-240 + 1) + 240;
		int y = rand()%(800-100 + 1) + 100;
		world.sprite_droplets[i].setPosition(x,y);		
		world.sprite_droplets[i].setTextureRect(world.rectangle_window_droplets[(rand() % (1 - 0 + 1))]);

		world.scale_droplets[i] = (float)(rand()%(100-50 + 1) + 50)/100.0f;
		world.speed_droplets[i] = (float)(rand()%(50-25 + 1) + 25)/100.0f;
		world.alpha_droplets[i] = 255;
	}

	sf::Color color_transparent = sf::Color(255,255,255,0);
	sf::Color color_opaque = sf::Color(255,255,255,0);

	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{		
		sf::Vector2f position = world.sprite_droplets[i].getPosition();

		int index = (8*i);
		float mx = position.x + 13.0f*world.scale_droplets[i];
		float my = position.y + 16.0f*world.scale_droplets[i];

		float width = 6*world.scale_droplets[i];
		
		world.droplet_trail[index].color = color_transparent;
		world.droplet_trail[index+1].color = color_opaque;	
		world.droplet_trail[index+2].color = color_transparent;	
		world.droplet_trail[index+3].color = color_transparent;
		world.droplet_trail[index+4].color = color_transparent;
		world.droplet_trail[index+5].color = color_opaque;
		world.droplet_trail[index+6].color = color_transparent;
		world.droplet_trail[index+7].color = color_transparent;

		world.droplet_trail[index].position.x = mx - width;
		world.droplet_trail[index].position.y = my;
		world.droplet_trail[index+1].position.x = mx;
		world.droplet_trail[index+1].position.y = my;
		world.droplet_trail[index+2].position.x = mx;
		world.droplet_trail[index+2].position.y = my - 8;
		world.droplet_trail[index+3].position.x = mx - width;
		world.droplet_trail[index+3].position.y = my - 8;
		world.droplet_trail[index+4].position.x = mx + width;
		world.droplet_trail[index+4].position.y = my;		
		world.droplet_trail[index+5].position.x = mx;
		world.droplet_trail[index+5].position.y = my;	
		world.droplet_trail[index+6].position.x = mx;
		world.droplet_trail[index+6].position.y = my - 8;	
		world.droplet_trail[index+7].position.x = mx + width;
		world.droplet_trail[index+7].position.y = my - 8;	
	}
}
void RandomizeCloud(sf::Sprite& sprite, float& speed)
{
		float r = rand()%(255-240 + 1) + 240;
		float g = rand()%(255-100 + 1) + 100;
		float b = rand()%(255-240 + 1) + 240;
		sprite.setColor(sf::Color(r,g,b));	
		sprite.setPosition(-64, 200);
		speed = (float)(((50-25 + 1) + 25)/100.0f);		
}
void InitClouds(Canvas& world)
{
	world.sprite_clouds[0].setTexture(world.tex_sprite_sheet);
	world.sprite_clouds[1].setTexture(world.tex_sprite_sheet);
	world.sprite_clouds[2].setTexture(world.tex_sprite_sheet);

	sf::IntRect rect;	
	int* x = &rect.left;
	int* y = &rect.top;
	int* w = &rect.width;
	int* h = &rect.height;

	*x = 1370;*y = 452;*w = 254;*h = 44;
	world.sprite_clouds[0].setTextureRect(rect);
	*x = 1624;*y = 422;*w = 154;*h = 72;
	world.sprite_clouds[1].setTextureRect(rect);
	*x = 1779;*y = 422;*w = 102;*h = 56;
	world.sprite_clouds[2].setTextureRect(rect);

	RandomizeCloud(world.sprite_clouds[0],world.speed_clouds[0]);
	RandomizeCloud(world.sprite_clouds[1],world.speed_clouds[1]);
	RandomizeCloud(world.sprite_clouds[2],world.speed_clouds[2]);

	world.sprite_clouds[0].setPosition(0, 200);
	world.sprite_clouds[1].setPosition(400, 200);
	world.sprite_clouds[2].setPosition(800, 200);


}
void InitCityNeonSigns(Canvas& world)
{
	for (size_t i = 0; i < 7; i++)
	{
		world.sprite_neon_signs[i].setTexture(world.tex_sprite_sheet);
	}	
	for (size_t i = 0; i < 7; i++)
	{		
		world.sprite_neon_glow[i].setTexture(world.tex_sprite_sheet);
	}	

	sf::IntRect rect;	
	int* x = &rect.left;
	int* y = &rect.top;
	int* w = &rect.width;
	int* h = &rect.height;

	*x = 812;*y = 790;*w = 140;*h = 140;

	for (size_t i = 0; i < 7; i++)
	{
		world.sprite_neon_glow[i].setTextureRect(rect);
	}	

	*x = 1370;*y = 310;*w = 98;*h = 30;
	world.sprite_neon_signs[0].setTextureRect(rect);

	*x = 1370;*y = 340;*w = 48;*h = 22;
	world.sprite_neon_signs[1].setTextureRect(rect);

	*x = 1418;*y = 340;*w = 74;*h = 22;
	world.sprite_neon_signs[2].setTextureRect(rect);

	*x = 1370;*y = 364;*w = 54;*h = 52;
	world.sprite_neon_signs[3].setTextureRect(rect);

	*x = 1424;*y = 364;*w = 76;*h = 58;
	world.sprite_neon_signs[4].setTextureRect(rect);

	*x = 1370;*y = 416;*w = 54;*h = 36;
	world.sprite_neon_signs[5].setTextureRect(rect);

	*x = 1424;*y = 422;*w = 54;*h = 30;	
	world.sprite_neon_signs[6].setTextureRect(rect);	

	sf::Color color;
	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	*r = 255;*g = 51;*b = 255;*a = 100;
	world.sprite_neon_glow[0].setColor(color);	

	*r = 0;*g = 255;*b = 0;*a = 50;
	world.sprite_neon_glow[1].setColor(color);

	*r = 255;*g = 255;*b = 0;*a = 100;
	world.sprite_neon_glow[2].setColor(color);

	*r = 255;*g = 0;*b = 0;*a = 100;
	world.sprite_neon_glow[3].setColor(color);

	*r = 255;*g = 51;*b = 255;*a = 100;
	world.sprite_neon_glow[4].setColor(color);

	*r = 100;*g = 100;*b = 255;*a = 100;
	world.sprite_neon_glow[5].setColor(color);

	*r = 255;*g = 0;*b = 0;*a = 50;
	world.sprite_neon_glow[6].setColor(color);

	world.sprite_neon_glow[0].scale(1.5f,0.5f);
	world.sprite_neon_glow[1].scale(1.5,0.4f);
	world.sprite_neon_glow[2].scale(1,0.5f);
	world.sprite_neon_glow[6].scale(1,0.5f);

	world.sprite_neon_signs[0].setPosition(463,310);
	world.sprite_neon_signs[1].setPosition(255,360);
	world.sprite_neon_signs[2].setPosition(642,475);
	world.sprite_neon_signs[3].setPosition(282,257);
	world.sprite_neon_signs[4].setPosition(715,320);
	world.sprite_neon_signs[5].setPosition(780,320);
	world.sprite_neon_signs[6].setPosition(282,310);
	
	world.sprite_neon_glow[0].setPosition(420,290);
	world.sprite_neon_glow[1].setPosition(180,348);
	world.sprite_neon_glow[2].setPosition(612,455);
	world.sprite_neon_glow[3].setPosition(245,220);
	world.sprite_neon_glow[4].setPosition(680,280);
	world.sprite_neon_glow[5].setPosition(730,280);
	world.sprite_neon_glow[6].setPosition(240,290);
}
void InitSkyscraperWindows(Canvas& world)
{
	const int window_position_data_x[332] = {242,259,276,293,242,259,276,293,242,259,276,293,242,259,276,293,242,259,276,293,242,259,276,293,242,259,276,293,242,259,276,293,398,407,416,425,398,407,416,425,398,407,416,425,398,407,416,425,398,407,416,425,398,407,416,425,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,440,449,458,467,488,497,506,515,488,497,506,515,488,497,506,515,488,497,506,515,488,497,506,515,488,497,506,515,488,497,506,515,488,497,506,515,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,538,547,556,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,578,587,596,708,717,726,708,717,726,708,717,726,708,717,726,708,717,726,708,717,726,708,708,770,779,788,770,779,788,770,779,788,770,779,788,770,779,788,770,779,788,728,736,744,752,728,736,744,752,728,736,744,752,728,736,744,752,728,728,728,728,398,407,416,398,407,416,398,407,416,398,407,416,398,407,416,398,407,416,398,407,416,496,505,514,496,505,514,496,505,514,496,505,514,496,505,514,496,505,514,496,505,543,543,543,543,530,537,544,551,590,599,608,590,599,608,590,599,608,590,599,608,590,599,608,590,599,608,590,599};
	const int window_position_data_y[332] = {400,400,400,400,418,418,418,418,436,436,436,436,454,454,454,454,472,472,472,472,490,490,490,490,508,508,508,508,526,526,526,526,344,344,344,344,354,354,354,354,364,364,364,364,374,374,374,374,404,404,404,404,414,414,414,414,368,368,368,368,378,378,378,378,388,388,388,388,398,398,398,398,408,408,408,408,418,418,418,418,428,428,428,428,438,438,438,438,448,448,448,448,458,458,458,458,468,468,468,468,478,478,478,478,420,420,420,420,430,430,430,430,440,440,440,440,450,450,450,450,460,460,460,460,470,470,470,470,480,480,480,480,490,490,490,490,400,400,400,410,410,410,420,420,420,430,430,430,440,440,440,450,450,450,460,460,460,470,470,470,480,480,480,490,490,490,370,370,370,380,380,380,390,390,390,400,400,400,410,410,410,420,420,420,430,430,430,440,440,440,450,450,450,460,460,460,470,470,470,480,480,480,490,490,490,384,384,384,394,394,394,404,404,404,414,414,414,424,424,424,434,434,434,444,454,404,404,404,414,414,414,424,424,424,434,434,434,444,444,444,454,454,454,460,460,460,460,470,470,470,470,480,480,480,480,490,490,490,490,500,510,520,530,430,430,430,440,440,440,450,450,450,460,460,460,470,470,470,480,480,480,490,490,490,210,210,210,220,220,220,230,230,230,240,240,240,250,250,250,260,260,260,270,270,186,196,206,216,240,250,260,270,220,220,220,230,230,230,240,240,240,250,250,250,260,260,260,270,270,270,280,280};

	sf::Color* color;
	sf::Vector2f* position;
	for (size_t i = 0; i < COUNT_SKYSCRAPER_WINDOWS; i++)
	{
		position = &world.skyscraper_windows_position[i];
		position->x = window_position_data_x[i];
		position->y = window_position_data_y[i];
		color = &world.skyscraper_windows_color[i];
		color->r = color->g = color->b = 255;		
		color->a = ((rand() % 255) + 160);
	}
}


void UpdateFallingRain(Canvas& world, float dt)
{
	sf::Sprite* rain;
	float scale;
	for (size_t i = 0; i < COUNT_RAIN; i++)
	{
		rain = &world.sprite_rain[i];
		rain->move(0,world.speed_rain[i]);

		if(rain->getPosition().y > 600)
		{
			int x = rand()%(1400-240 + 1) + 240;
			int y = 100;
			rain->setPosition(x,y);
			world.scale_rain[i] = scale = (float)(rand()%(100-10 + 1) + 10)/100.0f;		
			world.speed_rain[i] = (rand()%(50-45 + 1) + 45)*scale;	
			rain->setScale(scale,scale);
		}
	}
}
void UpdateRainWaterRipples(Canvas& world, float dt)
{
	for (size_t i = 0; i < COUNT_RIPPLES; i++)
	{
		world.time_ripples[i] += dt;
		int frame = 16 * (world.time_ripples[i]/0.85f);

		sf::IntRect rect = world.sprite_ripples[i].getTextureRect();
		rect.left = 76*frame;
		world.sprite_ripples[i].setTextureRect(rect);

		if(frame >= 16)
		{
			world.time_ripples[i] = 0;
			world.sprite_ripples[i].setPosition(rand()%(1400-800 + 1) + 800,rand()%(600-400 + 1) + 400);
		}

	}
}
void UpdateWindowRainDroplets(Canvas& world, float dt)
{
	float speed_0;
	float speed_1;

	float scale;

	sf::Sprite* droplet;
	sf::Vector2f position;

	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{
		world.speed_droplets[i]*=1.01f;
		speed_0 = world.speed_droplets[i];
		speed_1 = world.speed_droplets[i] * 0.6f;

		int index = (8*i);
		world.droplet_trail[index].position.y += speed_0;
		world.droplet_trail[index+1].position.y += speed_0;	
		world.droplet_trail[index+4].position.y += speed_0;
		world.droplet_trail[index+5].position.y += speed_0;

		world.droplet_trail[index+2].position.y += speed_1;
		world.droplet_trail[index+3].position.y += speed_1;
		world.droplet_trail[index+6].position.y += speed_1;
		world.droplet_trail[index+7].position.y += speed_1;

		droplet = &world.sprite_droplets[i];
		scale = world.scale_droplets[i];
		droplet->setScale(scale,scale);
		droplet->move(0,speed_0);
		position = droplet->getPosition();	

		world.sprite_rain_highlight[i].setPosition(position.x+(10*scale),position.y - 24);			
		
		if(position.y > 800)
		{
			int x = rand()%(1400-240 + 1) + 240;
			int y = rand()%(400-100 + 1) + 100;
			droplet->setPosition(x,y);
			droplet->setColor(sf::Color(50,50,50));
			int n = 0 + (rand() % (1 - 0 + 1));
			droplet->setTextureRect(world.rectangle_window_droplets[n]);
			world.speed_droplets[i] = (float)(rand()%(50-25 + 1) + 25)/100.0f;
			world.alpha_droplets[i] = 255;

			world.scale_droplets[i] = (float)(rand()%(100-50 + 1) + 50)/100.0f;
			scale = world.scale_droplets[i];
			float mx = x + (13.0f*scale);
			float my = y + (16.0f*scale);

			float trail_length = 6*scale;

			world.droplet_trail[index].position.x = mx - trail_length;
			world.droplet_trail[index].position.y = my;

			world.droplet_trail[index+1].position.x = mx;
			world.droplet_trail[index+1].position.y = my;

			world.droplet_trail[index+2].position.x = mx;
			world.droplet_trail[index+2].position.y = my - 8;				

			world.droplet_trail[index+3].position.x = mx - trail_length;
			world.droplet_trail[index+3].position.y = my - 8;		

			world.droplet_trail[index+4].position.x = mx + trail_length;
			world.droplet_trail[index+4].position.y = my;				

			world.droplet_trail[index+5].position.x = mx;
			world.droplet_trail[index+5].position.y = my;				

			world.droplet_trail[index+6].position.x = mx;
			world.droplet_trail[index+6].position.y = my - 8;			

			world.droplet_trail[index+7].position.x = mx + trail_length;
			world.droplet_trail[index+7].position.y = my - 8;	

		}


	}

	
	
}
void UpdateFlyingCars(Canvas& world, float dt)
{
	int index = 0;
	int x;int y;
	float* height;
	float* speed;
	sf::Vector2f pos;
	sf::Sprite* flying_car;
	sf::Vertex* vertex;
	sf::Color color;
	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	for (size_t i = 0; i < COUNT_FLYING_CARS; i++)
	{
		height = &world.height_flying_cars[i];
		speed = &world.speed_flying_cars[i];
		flying_car = &world.sprite_flying_cars[i];
		flying_car->move(world.speed_flying_cars[i],0);
		pos = flying_car->getPosition();		
		x = 10;y = *height;

		*r = 255;*g = 51;*b = 255;*a = 20;
		vertex = &world.shape_light_trail_outer[index];
		vertex->position.x = x + pos.x;
		vertex->position.y = y + pos.y;		
		vertex->color = color;

		*r = 255;*g = 51;*b = 255;*a = 0;
		vertex = &world.shape_light_trail_outer[index + 1];
		vertex->position.x = x + pos.x;
		vertex->position.y = y + pos.y - *height;
		vertex->color = color;

		vertex = &world.shape_light_trail_outer[index + 2];
		vertex->position.x = x + pos.x - 75 + ((rand() % 20) + 1)-10;
		vertex->position.y = y + pos.y;		
		vertex->color = color;

		*r = 126;*g = 26;*b = 126;*a = 20;
		vertex = &world.shape_light_trail_inner[index];
		vertex->position.x = x + pos.x;
		vertex->position.y = y + pos.y - (*height)/3;	
		vertex->color = color;

		*r = 126;*g = 26;*b = 126;*a = 0;
		vertex = &world.shape_light_trail_inner[index + 1];
		vertex->position.x = x + pos.x;
		vertex->position.y = y + pos.y - (*height)/2;	
		vertex->color = color;

		vertex = &world.shape_light_trail_inner[index + 2];
		vertex->position.x = x + pos.x - 40 + ((rand() % 20) + 1)-10;
		vertex->position.y = y + pos.y;	
		vertex->color = color;

		index += 3;

		if(pos.x > 1200)
		{			
			int n = (rand() % 4) + 0;	
			x = ((rand() % 1200) + 0) - 1200;
			y = 250 + ((rand() % 100) + 1)-50;
			*height = 14.0f;

			if(n == 1)
			{
				*height = 8;
			}
			else if(n == 2)
			{
				*height = 6;
			}
			else if(n == 3)
			{
				*height = 8;
			}
			*r = 255;*g = ((rand() % 255) + 1);*b = 255;*a = 255;
			*speed = (rand() % 4) + 2;
			flying_car->setPosition(x,y);	
			flying_car->setTextureRect(world.rectangle_flying_cars[n]);
			flying_car->setColor(color);
		}
	}
}
void UpdateMisc(Canvas& world, float dt, float t)
{


float scale = std::abs(std::sin(t))/100;

	world.sprite_tom_torso.setScale(1+scale,1+scale);
	world.sprite_tom_head.setPosition(535,580 + std::sin(t)*2);
	
	scale = std::abs(std::sin(t*2))/100;
	world.sprite_eddi_torso.setScale(1+scale,1+scale);
	world.sprite_eddi_head.setPosition(280,700 + std::sin(t*2)*2);


	float alpha = rand()%(255-230 + 1) + 230;
	world.sprite_arcade_layer_1.setColor(sf::Color(255,255,255,alpha));



	alpha = rand()%(255-230 + 1) + 230;
	world.sprite_neon_sign.setColor(sf::Color(255,255,255,alpha));


	for (size_t i = 0; i < 5; i++)
	{
		world.sprite_sushi[i].move(-2,0);

		if(world.sprite_sushi[i].getPosition().x < -300)
		{		
			world.sprite_sushi[i].setTextureRect(world.rectangle_sushi_plates[((rand() % 4) + 1)]);
			world.sprite_sushi[i].setPosition((30 + 550*5) + ((rand() % 32) + 1)-16, 780);
		}

	}
	for (size_t i = 0; i < 3; i++)
	{
		world.sprite_clouds[i].move(world.speed_clouds[i],0);

		if(world.sprite_clouds[i].getPosition().x > 1200)
		{		
			RandomizeCloud(world.sprite_clouds[i],world.speed_clouds[i]);
		}

	}

	for (size_t i = 0; i < 7; i++)
	{
		sf::Color c = world.sprite_neon_glow[i].getColor();

		c.a += ((rand() % 6) + 1)-3;
		if(c.a < 50)
		{
			c.a = 50;
		}
		else if(c.a > 100)
		{			
			c.a = 100;
		}
		int rnd = (rand() % 1000) + 1;

		if(rnd > 95)
		{
			c.a = 100;
		}
		else if(rnd < 5)
		{
			c.a = 50;
		}
		world.sprite_neon_glow[i].setColor(c);
	}
}
void UpdateWindows(Canvas& world, float dt)
{
	
	sf::Color color;
	
	sf::Uint8* r = &color.r;
	sf::Uint8* g = &color.g;
	sf::Uint8* b = &color.b;
	sf::Uint8* a = &color.a;

	*r = 255;*g = 255;*b = 255;

	for (size_t i = 0; i < COUNT_SKYSCRAPER_WINDOWS; i++)
	{
		if((rand() % 500) == 1)
		{
			*a = ((rand() % 255) + 160);
			world.skyscraper_windows_color[i] = color;
		}
	}
}
void UpdateCanvas(Canvas& world, float dt, float t)
{
	
	//auto begin = std::chrono::high_resolution_clock::now();
	UpdateFallingRain(world,dt);
	UpdateRainWaterRipples(world,dt);
	UpdateWindowRainDroplets(world,dt);
	UpdateFlyingCars(world,dt);	
	UpdateMisc(world,dt,t);	
	UpdateWindows(world,dt);
/*
	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);    
    printf("Time measured: %.8f seconds.\n", elapsed.count() * 1e-9);*/

}

void RenderPass0(Canvas& world,sf::Shader& shader,sf::Shader& shader_perlin)
{
	
	world.render_target_water_surface_distortion.clear(sf::Color::Black);
	world.time += 0.016f;
	shader_perlin.setUniform("u_time", world.time);
	world.sprite_distortion_pattern.setPosition(800,300);
	world.render_target_water_surface_distortion.draw(world.sprite_distortion_pattern,&shader_perlin);


	for (size_t i = 0; i < COUNT_RIPPLES; i++)
	{
		world.render_target_water_surface_distortion.draw(world.sprite_ripples[i]);
	}

	world.render_target_pass_0.clear(sf::Color::Black);

	shader.setUniform("hmap",world.render_target_water_surface_distortion.getTexture());
	
	world.render_target_pass_0.clear(sf::Color::Transparent);
	world.sprite_skyline_reflection.setPosition(745,320);
	world.render_target_pass_0.draw(world.sprite_skyline_reflection,&shader);




}
void RenderPass1(Canvas& world,sf::Shader& shader)
{

	
	
	world.render_target_pass_1.clear(sf::Color::Black);

	world.render_target_pass_1.draw(world.shape_skybox, 4, sf::Quads);

	world.sprite_pass_0.setTexture(world.render_target_pass_0.getTexture());
	world.sprite_pass_0.setScale(1, -1);
	world.sprite_pass_0.setPosition(0, SCREEN_HEIGHT);
	
	world.render_target_pass_1.draw(world.sprite_pass_0);





	world.render_target_pass_1.draw(world.shape_ground, 4, sf::Quads);
	world.render_target_pass_1.draw(world.sprite_moon);
	world.render_target_pass_1.draw(world.sprite_skyline_1);
	world.render_target_pass_1.draw(world.sprite_skyline_2);

	world.render_target_pass_1.draw(world.sprite_clouds[0]);
	world.render_target_pass_1.draw(world.sprite_clouds[1]);
	world.render_target_pass_1.draw(world.sprite_clouds[2]);

	for (size_t i = 0; i < COUNT_FLYING_CARS; i++)
	{	
		world.render_target_pass_1.draw(world.shape_light_trail_inner, COUNT_FLYING_CARS*3, sf::Triangles);	
		world.render_target_pass_1.draw(world.shape_light_trail_outer, COUNT_FLYING_CARS*3, sf::Triangles);
		
	}

	for (size_t i = 0; i < COUNT_FLYING_CARS; i++)
	{			
		world.render_target_pass_1.draw(world.sprite_flying_cars[i]);		
	}





	world.render_target_pass_1.draw(world.sprite_skyline_0);

	

	world.render_target_pass_1.draw(world.sprite_neon_glow[0]);
	world.render_target_pass_1.draw(world.sprite_neon_glow[3]);
	
	world.render_target_pass_1.draw(world.sprite_neon_glow[2]);
	world.render_target_pass_1.draw(world.sprite_neon_glow[1]);
	world.render_target_pass_1.draw(world.sprite_neon_glow[4]);
	world.render_target_pass_1.draw(world.sprite_neon_glow[5]);

	world.render_target_pass_1.draw(world.sprite_neon_glow[6]);



	world.render_target_pass_1.draw(world.sprite_neon_signs[0]);
	world.render_target_pass_1.draw(world.sprite_neon_signs[1]);
	world.render_target_pass_1.draw(world.sprite_neon_signs[2]);
	world.render_target_pass_1.draw(world.sprite_neon_signs[3]);

	world.render_target_pass_1.draw(world.sprite_neon_signs[4]);
	world.render_target_pass_1.draw(world.sprite_neon_signs[5]);
	world.render_target_pass_1.draw(world.sprite_neon_signs[6]);



		for (size_t i = 0; i < COUNT_SKYSCRAPER_WINDOWS; i++)
		{
			
			if(i > 31)
			{	
				world.sprite_window_small.setPosition(world.skyscraper_windows_position[i]);
				world.sprite_window_small.setColor(world.skyscraper_windows_color[i]);			
				world.render_target_pass_1.draw(world.sprite_window_small);
			}
			else
			{	world.sprite_window_refraction.setPosition(world.skyscraper_windows_position[i]);
				world.sprite_window_refraction.setColor(world.skyscraper_windows_color[i]);			
				world.render_target_pass_1.draw(world.sprite_window_refraction);
			}
		}




	
for (size_t i = 0; i < COUNT_RAIN; i++)
	{
		world.render_target_pass_1.draw(world.sprite_rain[i]);
	}
	world.sprite_pass_1.setTexture(world.render_target_pass_1.getTexture());
	world.sprite_pass_1.setScale(1, -1);
	world.sprite_pass_1.setPosition(0, SCREEN_HEIGHT);


	world.render_target_window_refraction.clear(sf::Color::Black);
	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{
		int lol = (8*i);
		world.droplet_trail[lol+0].color = sf::Color(255,255,255,0);
		world.droplet_trail[lol+1].color = sf::Color(100,100,100,255);	
		world.droplet_trail[lol+2].color =  sf::Color(255,255,255,0);	
		world.droplet_trail[lol+3].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+4].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+5].color = sf::Color(100,100,100,255);
		world.droplet_trail[lol+6].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+7].color =  sf::Color(255,255,255,0);
		sf::Vertex* ptr = &world.droplet_trail[8*i];
		world.render_target_window_refraction.draw(ptr,8,sf::Quads);
	}

	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{

		world.sprite_droplets[i].setColor(sf::Color::White);
		world.render_target_window_refraction.draw(world.sprite_droplets[i]);
	}
	
	for (size_t i = 0; i < COUNT_DROPLETS; i++)
	{

		int lol = (8*i);
		world.droplet_trail[lol+0].color = sf::Color(255,255,255,0);
		world.droplet_trail[lol+1].color = sf::Color(100,100,100,100);	
		world.droplet_trail[lol+2].color =  sf::Color(255,255,255,0);	
		world.droplet_trail[lol+3].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+4].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+5].color = sf::Color(100,100,100,100);
		world.droplet_trail[lol+6].color =  sf::Color(255,255,255,0);
		world.droplet_trail[lol+7].color =  sf::Color(255,255,255,0);


		sf::Vertex* ptr = &world.droplet_trail[8*i];
		world.render_target_pass_1.draw(ptr,8,sf::Quads);
		world.sprite_droplets[i].setColor(sf::Color(255,255,255,40));
		world.render_target_pass_1.draw(world.sprite_droplets[i]);



	}
	
	
	
}
void RenderPass2(Canvas& world, sf::Shader& shader)
{
	
	
	shader.setUniform("hmap",world.render_target_window_refraction.getTexture());
	world.render_target_pass_2.draw(world.sprite_pass_1,&shader);


	for (size_t i = 0; i < 6; i++)
	{
		world.render_target_pass_2.draw(world.sprite_wall_pattern[i]);

	}


	world.render_target_pass_2.draw(world.shape_window_frame,16,sf::Quads);

	world.render_target_pass_2.draw(world.sprite_arcade_layer_0);
	world.render_target_pass_2.draw(world.sprite_arcade_layer_1);

	world.render_target_pass_2.draw(world.sprite_table);
	
	world.render_target_pass_2.draw(world.sprite_eddi_torso);
	world.render_target_pass_2.draw(world.sprite_eddi_head);
	
	world.render_target_pass_2.draw(world.sprite_tom_torso);
	world.render_target_pass_2.draw(world.sprite_tom_head);

	world.render_target_pass_2.draw(world.shape_conveyor_belt,4,sf::Quads);

	for (size_t i = 0; i < 5; i++)
	{
		world.render_target_pass_2.draw(world.sprite_sushi[i]);

	}


	
}
void DrawWorld(sf::RenderWindow& window, sf::Shader& shader,sf::Shader& shader_perlin, Canvas& world)
{

	
	RenderPass0(world,shader,shader_perlin);

	RenderPass1(world,shader_perlin);

	RenderPass2(world,shader);

	

	world.sprite_pass_2.setTexture(world.render_target_pass_2.getTexture());
	world.sprite_pass_2.setScale(1, -1);
	world.sprite_pass_2.setPosition(0, SCREEN_HEIGHT);

	world.render_target_glas_refraction.clear(sf::Color::Black);
	world.render_target_glas_refraction.draw(world.sprite_bottles[0]);
	world.render_target_glas_refraction.draw(world.sprite_bottles[1]);
	world.render_target_glas_refraction.draw(world.sprite_bottles[2]);

	world.render_target_glas_refraction.draw(world.sprite_glas[0]);
	world.render_target_glas_refraction.draw(world.sprite_glas[1]);

/*
	world.render_target_pass_3.clear(sf::Color::Black);

	shader.setUniform("hmap",world.render_target_glas_refraction.getTexture());
	world.render_target_pass_3.draw(world.sprite_pass_2,&shader);


	world.render_target_pass_3.draw(world.sprite_neon_sign);

	world.render_target_pass_3.draw(world.sprite_bottles[0]);
	world.render_target_pass_3.draw(world.sprite_bottles[1]);
	world.render_target_pass_3.draw(world.sprite_bottles[2]);

	
	world.render_target_pass_3.draw(world.sprite_glas[0]);
	world.render_target_pass_3.draw(world.sprite_glas[1]);

	world.render_target_pass_3.draw(world.shape_ambient_light,4,sf::Quads);
	

	world.sprite_pass_3.setTexture(world.render_target_pass_3.getTexture());
	world.sprite_pass_3.setScale(0.72, -0.72);
	world.sprite_pass_3.setPosition(0, SCREEN_HEIGHT*0.78);
	window.draw(world.sprite_pass_3);*/

	window.clear(sf::Color::Black);

	shader.setUniform("hmap",world.render_target_glas_refraction.getTexture());
	window.draw(world.sprite_pass_2,&shader);


	window.draw(world.sprite_neon_sign);

	window.draw(world.sprite_bottles[0]);
	window.draw(world.sprite_bottles[1]);
	window.draw(world.sprite_bottles[2]);

	
	window.draw(world.sprite_glas[0]);
	window.draw(world.sprite_glas[1]);

	window.draw(world.shape_ambient_light,4,sf::Quads);


}
