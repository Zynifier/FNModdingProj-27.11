// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Customization/CustomDynamicColorSwatch.h"
#include "CustomAccessoryColorSwatch.generated.h"

UENUM()
enum EAccessoryColorName
{
	EAccessoryColorName_AccessoryColor1 = 0 UMETA(DisplayName="AccessoryColor1"),
	EAccessoryColorName_AccessoryColor2 = 1 UMETA(DisplayName="AccessoryColor2"),
	EAccessoryColorName_AccessoryColor3 = 2 UMETA(DisplayName="AccessoryColor3"),
	EAccessoryColorName_NumTypes = 3,
};

UCLASS(BlueprintType)
class UCustomAccessoryColorSwatch : public UCustomDynamicColorSwatch
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="ColorSwatch", meta=(ArraySizeEnum="/Script/FortniteGame.EAccessoryColorName"))
	FLinearColor AccessoryColors[3];

};

