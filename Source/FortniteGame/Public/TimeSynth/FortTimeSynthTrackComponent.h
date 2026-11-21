// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "FortTimeSynthTrackComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortTimeSynthTrackComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortTimeSynthTrackComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

