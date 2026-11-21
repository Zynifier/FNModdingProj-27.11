// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ZiplineSmashBase.generated.h"

class AActor;
class UObject;

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayAbility_ZiplineSmashBase : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void BeginAsyncBreakNearbyStructuresOverlap(const FVector BoxPos, const FVector BoxExtent, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore);

	UFUNCTION(BlueprintImplementableEvent)
	void EndAsyncBreakNearbyStructuresOverlap(const TArray<AActor*>& OverlapActors);

};

