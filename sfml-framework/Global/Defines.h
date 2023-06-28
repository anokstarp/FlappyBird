#pragma once

enum class SceneId
{
	None = -1,
	Title,
	Game,
	Count,
};

enum class ResourceTypes
{
	Texture,
	Font,
	SoundBuffer,
	Count,
};

enum class Sides
{
	Left,
	Right,
	None,
};

enum class Origins
{
	TL,
	TC,
	TR,
	ML,
	MC,
	MR,
	BL,
	BC,
	BR,
	CUSTOM,
};

#define SCREEN_WIDTH = 1920;
#define SCREEN_HEIGHT = 1080;