// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "AthenaTrapAIPerceptionStimuliSourceComponent.generated.h"

class AActor;

USTRUCT()
struct FTrapDetectionState
{
	GENERATED_BODY()

};

USTRUCT()
struct FTrapPerceptionSettings
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Activation", "Collision"))
class UAthenaTrapAIPerceptionStimuliSourceComponent : public UAIPerceptionStimuliSourceComponent
{
	GENERATED_BODY()

public:
	UAthenaTrapAIPerceptionStimuliSourceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<AActor>, FTrapDetectionState> TrapDiscoverabilityMap;

	UPROPERTY(EditAnywhere, Category="Trap", meta=(AllowPrivateAccess="true"))
	uint8 bEnablePerceptionSystemOnTrap : 1;

};

