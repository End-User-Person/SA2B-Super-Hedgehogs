/**
 * SADX Mod Loader.
 * Mod metadata structures.
 */

#ifndef SADXMODLOADER_SADXMODINFO_H
#define SADXMODLOADER_SADXMODINFO_H

#include <SA2ModLoader.h>
#include <SA2Structs.h>

 // SADX Mod Loader API version.
static const int ModLoaderVer = 9;

#undef ReplaceFile // Windows function macro
struct HelperFunctions
{
	// The version of the structure.
	int Version;
	/**
	* @brief Gets the real path to a replaceable file.
	*
	* If your mod contains files in its SYSTEM folder that it loads manually,
	* you can use this function to retrieve the full path to the file. This
	* allows other mods to replace this file without any extra work from you.
	* Requires version >= 5.
	*
	* @param path The file path (e.g "SYSTEM\\my_cool_file.bin")
	* @return The replaced path to the file.
	*/
	const char *(__cdecl* GetReplaceablePath)(const char* path);
	// Replaces the source file with the destination file.
	// Requires version >= 6.
	void(__cdecl *ReplaceFile)(const char *src, const char *dst);
	// Sets the window title.
	// Requires version >= 7.
	void(__cdecl *SetWindowTitle)(const char *title);
};

typedef void(__cdecl *ModInitFunc)(const char *path, const HelperFunctions &helperFunctions);

typedef void(__cdecl *ModEvent)();


#endif // SADXMODLOADER_SADXMODINFO_H
