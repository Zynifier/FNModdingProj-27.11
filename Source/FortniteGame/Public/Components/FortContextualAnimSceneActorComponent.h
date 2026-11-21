// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ContextualAnimSceneActorComponent.h"
#include "FortContextualAnimSceneActorComponent.generated.h"

class AFortPlayerPawn;

UCLASS(HideCategories=("Mobility", "VirtualTexture", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortContextualAnimSceneActorComponent : public UContextualAnimSceneActorComponent
{
	GENERATED_BODY()

public:
	UFortContextualAnimSceneActorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	void OnFinishedCharacterCustomization(AFortPlayerPawn* Pawn);

};

