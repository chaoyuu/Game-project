#pragma once
#include"input.h"
#include "area.h"
#include"scene.h"
#include "player.h"
#include"game_object.h"
#include"assets.h"
Area::Area()
	: Game_Object("DIEING.Area","DIEING.Area")
{
	_width = 200;
	_height = 200;
	_translation = Vector_2D(500, 400);
}

Area::~Area()
{
}

void Area::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{
	Game_Object* Player_Area = scene->get_game_object("Player_Area");

	Vector_2D Area_center = _translation + Vector_2D((float)_width / 2, (float)_height / 2);
	Vector_2D player_center = Player_Area->translation()
		+ Vector_2D((float)Player_Area->width() / 2, (float)Player_Area->height() / 2);

	float distance_to_player = (Area_center - player_center).magnitude();

	if (distance_to_player < 50.0f)
	{
		Player* player = (Player*)scene->get_game_object("DIEING_Area");
		player->set_speed(true);
		player->set_translation(player_center);
	}

	
}
void Area::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}


