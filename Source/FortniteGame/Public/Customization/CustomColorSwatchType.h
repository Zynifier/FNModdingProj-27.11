// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomColorSwatchType.generated.h"

UENUM()
enum ECharacterColorSwatchType
{
	ECharacterColorSwatchType_Skin = 0 UMETA(DisplayName="Skin"),
	ECharacterColorSwatchType_Hair = 1 UMETA(DisplayName="Hair"),
	// For various reasons, we may not use "Accessory"... primarily related to the fact that accessory colors are NOT
// stored globally, they are per-character part.
// ECharacterColorSwatchType_Accessory UMETA(DisplayName="Accessory"),

	ECharacterColorSwatchType_NumTypes = 2,
};

UENUM()
enum EColorSwatchType
{
	EColorSwatchType_Skin = 0 UMETA(DisplayName="Skin"),
	EColorSwatchType_Hair = 1 UMETA(DisplayName="Hair"),
	EColorSwatchType_BodyAccessory = 2 UMETA(DisplayName="Body Accessory"),
	EColorSwatchType_Accessory = 3 UMETA(DisplayName="Accessory"),
	EColorSwatchType_NumTypes = 4,
};

