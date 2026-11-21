// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "WaterVolume_Deep.generated.h"

class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AWaterVolume_Deep : public APhysicsVolume
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterVolume_Deep")
	TObjectPtr<USoundBase> EntrySound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterVolume_Deep")
	TObjectPtr<USoundBase> ExitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterVolume_Deep")
	int32 DamagePerSec;

};

