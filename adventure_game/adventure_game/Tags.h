#pragma once
#include <string>

/*----- SDL Errors -----*/
namespace SDL_ERROR
{
	const std::string SDL_ERROR_INITIALISE = "Failed to initialise SDL...";
	const std::string SDL_ERROR_TEXT = "Failed to initialise Text...";
	const std::string SDL_ERROR_IMAGE = "Failed to initialise Image...";
	const std::string SDL_ERROR_FONT = "Failed to open font file...";
}

/*----- Warp Tags -----*/
namespace WarpID 
{
	const std::string LITTLEROOT_EXTERIOR_HOSPITAL_WARP = "LITTLEROOT_EXTERIOR_HOSPITAL";
	const std::string LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT = "LITTLEROOT_INTERIOR_HOSPITAL_WARP_EXIT";
}

/*----- Object Tags -----*/
namespace ObjectTag
{
	const std::string ANIMATOR = "Animator";
	const std::string BACKGROUND = "Background";
	const std::string FOREGROUND = "Foreground";
	const std::string MIDDLEGROUND = "Middleground";
	const std::string USERINTERFACE = "UI";
}

/*----- Error Tags -----*/
namespace Error
{
	const std::string ERROR_DYANAMICOBJECT_COMPONENT_ADD = "The component you tried to add does not exist";
	const std::string ERROR_DYANAMICOBJECT_COMPONENT_ADD_EXISTS = "The component you tried to add already exists";
	const std::string ERROR_DYANAMICOBJECT_COMPONENT_GET_DNEXISTS = "The component you tried to get does not exist";

	const std::string ERROR_CASTING_FAILEDTOCAST = "Could not cast object";

	const std::string ERROR_SAVING_FAILED = "Failed to save data";
	const std::string ERROR_LOADING_FAILED = "Failed to load data";

	const std::string ERROR_MENU_FAILEDTOADD = "Failed to add menu to UI Controller";
	const std::string ERROR_MENU_FAILEDTORESET = "Failed to reset UI Controller";
}