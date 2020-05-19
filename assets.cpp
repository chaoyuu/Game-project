#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
	// Cache Dino Texture.
	{
		Texture* texture = new Texture("Texture.Dino", "Assets/dino.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Cache Dino Walking Texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* texture = new Animated_Texture(
			"Texture.Dino.Walking",
			"Assets/dino.walking.png",
			renderer,
			frame_count,
			frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}

	// Create player walking texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking", "Assets/player.walking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player running texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Running", "Assets/player.running.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Idle", "Assets/player.idle.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player attacking texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Attacking", "Assets/player.attacking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player dieing texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Dieing", "Assets/player.dieing.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create collider texture
	{
		Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/music.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	// Create walking sound
	{
		Sound* sound = new Sound("Sound.Walking", "Assets/walking.wav");
		_assets[sound->id()] = sound;
	}

	// Create running sound
	{
		Sound* sound = new Sound("Sound.Running", "Assets/running.wav");
		_assets[sound->id()] = sound;
	}

	// Create attacking sound
	{
		Sound* sound = new Sound("Sound.Attacking", "Assets/attacking.wav");
		_assets[sound->id()] = sound;
	}

	// Create dieing sound
	{
		Sound* sound = new Sound("Sound.Dieing", "Assets/dieing.wav");
		_assets[sound->id()] = sound;
	}

	// Create portal entry texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Entry", "Assets/portal.green.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Create portal exit texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Portal.Exit", "Assets/portal.purple.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}

	// Create dieing texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.DIEING.Area", "Assets/DIEING.Area.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
		
	}

}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if (_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}