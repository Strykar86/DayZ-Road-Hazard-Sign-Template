# DayZ Custom Hazard Sign Template

A simple and clean template for creating custom static road hazard signs for your DayZ server or mod. This template uses a `hiddenSelections` config, allowing you to create infinite sign variations by just changing the texture, without needing to duplicate the 3D model.

## Features

-   **Efficient:** Uses a single 3D model. New sign variants are just new textures, keeping mod size small.
-   **Flexible:** Includes two different configuration methods to suit any project.
-   **Beginner-Friendly:** The template is well-commented and includes a PSD for easy editing.

## Step 1: Create Your Custom Texture

1.  **Unzip the Template:** First, find and unzip the `YellowSignTemplate.zip`.
2.  **Edit in Photopea:** Open the `.psd` file in [Photopea.com](https://www.photopea.com).
3.  **Export as PNG:** Go to `File > Export as > PNG`. Make sure **"Don't use palettes"** is selected.
4.  **Filename:** Save the file with a `_co` suffix (e.g., `my_custom_sign_co.png`).
5.  **Convert to PAA:** Use the "Image to PAA" utility in DayZ Tools.
6.  **Place Your Texture:** Move your new `.paa` texture file into the `data/textures` folder.

---

## Step 2: Choose Your Configuration Method

Now that you have your texture, choose one of the two methods below to configure your sign. Click on an option to expand it.

<details>
<summary><strong>Method 1: The Modular 'Server Pack' Approach (Recommended for flexibility)</strong></summary>

This method is ideal if you want to keep the core sign assets separate from your custom variants. It allows you or others to create new sign packs that just require this template to be loaded.

**Part A: The Core Mod (`RoadHazardSign.pbo`)**

Your template will serve as the "Core Mod." Its `config.cpp` should define the hidden `scope = 1` base class.

```cpp
// config.cpp for the Core Mod
class CfgPatches
{
	class RoadHazardSign
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;

	class RoadHazardSign_Base : HouseNoDestruct
	{
		scope = 1; // Hidden template class
		model = "RoadHazardSign\data\YourSignModel.p3d";
		hiddenSelections[] = { "sign_base" };
		hiddenSelectionsTextures[] = { "RoadHazardSign\data\textures\signbase_co.paa" };
	};
};
```

**Part B: The Variant Mod (`MyCustomSigns.pbo`)**

A user would create a second, lightweight mod. This mod's config requires your core mod and only defines the new variants.

```cpp
// config.cpp for the Variant Mod
class CfgPatches
{
	class MyCustomSigns
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		// This line makes your mod a required dependency
		requiredAddons[]={"RoadHazardSign"}; 
	};
};

class CfgVehicles
{
	// Reference the base class from the core mod
	class RoadHazardSign_Base; 

	// Create your new, spawnable sign
	class MyAwesomeSign : RoadHazardSign_Base
	{
		scope = 2; // Makes it visible in-game
		displayName = "My Awesome Custom Sign";
		hiddenSelectionsTextures[] = { "MyCustomSigns\data\my_cool_texture.paa" };
	};
};
```

</details>

<details>
<summary><strong>Method 2: The 'All-in-One' Approach (Simpler for self-contained mods)</strong></summary>

This method is simpler if you just want to create a single mod that contains everything. All sign definitions are in the one `config.cpp`.

In your `config.cpp`, you will create multiple classes that all inherit from your `scope = 1` base class.

```cpp
// config.cpp for the All-in-One Mod
class CfgPatches
{
	class MySignMod
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;

	// Base class - hidden from game lists
	class MySign_Base : HouseNoDestruct
	{
		scope = 1;
		author = "Your Name";
		model = "MySignMod\data\MySignModel.p3d";
		hiddenSelections[] = { "sign_base" };
	};

	// First spawnable sign
	class MySign_Variant1 : MySign_Base
	{
		scope = 2;
		displayName = "Custom Sign - Variant 1";
		hiddenSelectionsTextures[] = { "MySignMod\data\textures\variant1_co.paa" };
	};

	// Second spawnable sign
	class MySign_Variant2 : MySign_Base
	{
		scope = 2;
		displayName = "Custom Sign - Variant 2";
		hiddenSelectionsTextures[] = { "MySignMod\data\textures\variant2_co.paa" };
	};
};
```
</details>

---

## Step 3: Pack and Deploy

1.  After setting up your config using your chosen method, use DayZ Tools (like PBOProject) to pack your mod folder(s) into a PBO file.
2.  Add the packed mod(s) to your server, load them, and enjoy your custom signs!
