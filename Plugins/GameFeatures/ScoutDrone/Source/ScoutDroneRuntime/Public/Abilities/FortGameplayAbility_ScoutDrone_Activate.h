// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ScoutDrone_Activate.generated.h"

class AFortScoutDrone;

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayAbility_ScoutDrone_Activate : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Remote Controlled Actor Spawn Properties")
	TSubclassOf<AFortScoutDrone> RCActorClass;

	UPROPERTY(EditDefaultsOnly, Category="Remote Controlled Actor Spawn Properties")
	FVector SpawnOffset;

};

