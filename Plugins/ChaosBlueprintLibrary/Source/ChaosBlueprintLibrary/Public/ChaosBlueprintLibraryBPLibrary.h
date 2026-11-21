// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "ChaosBlueprintLibraryBPLibrary.generated.h"

class UCustomCharacterPartAnimInstance;

UCLASS()
class UChaosBlueprintLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Animation|Cloth")
	static void ClothControllerWriteToSimulation(const UCustomCharacterPartAnimInstance* CharacterPartAnimInstance, UPARAM(ref, DisplayName="Clothing Asset Name") FString& ClothingAssetName, UPARAM(ref) FClothCoreSettings& ClothCoreSettings, UPARAM(ref) FClothParameters& ClothSettings, UPARAM(ref) FVector& WindVelocity, UPARAM(DisplayName="Cloth Settings (World Space)") FClothParameters& OutWorldSpaceClothSettings, UPARAM(DisplayName="Wind Velocity (World Space)") FVector& OutWorldSpaceWindVelocity);

};

