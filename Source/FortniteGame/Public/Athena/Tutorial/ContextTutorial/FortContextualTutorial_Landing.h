// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_Landing.generated.h"

UCLASS()
class UFortContextualTutorial_Landing : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

	UFUNCTION()
	void HandleStartSkydivingForCompletion();

};

