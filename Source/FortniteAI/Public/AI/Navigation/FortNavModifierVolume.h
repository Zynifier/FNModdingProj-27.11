// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavModifierVolume.h"
#include "FortNavModifierVolume.generated.h"

class ANavigationData;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Variable", "Tags", "Cooking", "Collision", "Navigation", "Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(BlueprintSpawnableComponent))
class AFortNavModifierVolume : public ANavModifierVolume
{
	GENERATED_BODY()

public:
	AFortNavModifierVolume(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Navigation Data")
	TArray<TSubclassOf<ANavigationData>> EnableOnlyForNavmeshClasses;

};

