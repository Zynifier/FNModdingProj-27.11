// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_StormForming.generated.h"

UCLASS()
class UFortContextualTutorial_StormForming : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

	UPROPERTY(Transient)
	bool bPreviousMapOpen;

	UPROPERTY(Transient)
	FTimerHandle UpdateMapHandle;

};

