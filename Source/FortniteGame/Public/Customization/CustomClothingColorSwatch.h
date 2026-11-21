// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Customization/CustomColorSwatch.h"
#include "CustomClothingColorSwatch.generated.h"

UENUM()
enum EClothingColorName
{
	EClothingColorName_AccessoryColor1 = 0 UMETA(DisplayName="AccessoryColor1"),
	EClothingColorName_AccessoryColor2 = 1 UMETA(DisplayName="AccessoryColor2"),
	EClothingColorName_NumTypes = 2,
};

UCLASS(EditInlineNew)
class UCustomClothingColorSwatch : public UCustomColorSwatch
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="ColorSwatch", meta=(ArraySizeEnum="/Script/FortniteGame.EClothingColorName"))
	FLinearColor AccessoryColors[2];

};

