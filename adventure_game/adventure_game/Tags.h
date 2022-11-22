#pragma once
#include <string>

/*----- Warp Tags -----*/
namespace WarpID {
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
}