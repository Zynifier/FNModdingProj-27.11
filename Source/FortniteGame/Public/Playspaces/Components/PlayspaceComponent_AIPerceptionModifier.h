// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_AIPerceptionModifier.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_AIPerceptionModifier : public UFortPlayspaceComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 AIBotSightClampPriority;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	FScalableFloat AIBotSightRadiusClamp;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	FScalableFloat AIBotLoseSightRadiusClamp;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_AIPerceptionModifier", meta=(Categories="AI"))
	float ConcealmentDistance;

};

