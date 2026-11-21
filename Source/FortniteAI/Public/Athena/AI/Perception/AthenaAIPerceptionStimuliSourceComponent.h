// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "AthenaAIPerceptionStimuliSourceComponent.generated.h"

UCLASS(HideCategories=("Activation", "Collision"), meta=(BlueprintSpawnableComponent))
class UAthenaAIPerceptionStimuliSourceComponent : public UAIPerceptionStimuliSourceComponent
{
	GENERATED_BODY()

public:
	UAthenaAIPerceptionStimuliSourceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void OnOwnerTeamIndexChanged();

	UPROPERTY(EditAnywhere, Category="AI Perception")
	bool bIsConsideredAsThreateningObjectForBots;

};

