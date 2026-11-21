// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "FortTeamIdentification.generated.h"

class UCustomAccessoryColorSwatch;
class UTexture2D;

UCLASS(Abstract, Const, CollapseCategories, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"), meta=(ShowWorldContextPin))
class UFortMinigameTeamIdentification : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Name")
	TSoftObjectPtr<UTexture2D> Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Icons")
	TSoftObjectPtr<UTexture2D> Logo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Icons")
	TSoftObjectPtr<UTexture2D> Avatar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FColor FirstColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FColor SecondColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FColor StartGradient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Colors")
	FColor EndGradient;

};

UCLASS(Abstract, Const, CollapseCategories, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object"), meta=(ShowWorldContextPin))
class UFortTeamIdentification : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	FColor HUDColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Color")
	TObjectPtr<UCustomAccessoryColorSwatch> CharacterAccessoryColorSwatch;

};

