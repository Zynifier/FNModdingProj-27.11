// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioParameterComponent.h"
#include "FortAudioParameterComponent_Pawn.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerController;

UCLASS(BlueprintType, HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD"))
class UFortAudioParameterComponent_Pawn : public UAudioParameterComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnViewTargetSet(AActor* Actor);

private:
	UFUNCTION()
	void OnFootstepEvent();

	UFUNCTION()
	void OnHealthChanged();

	UFUNCTION()
	void OnViewTargetChanged(AFortPlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget);

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedPawnOwner;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> CachedLocalPC;

};

