// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InfiltrationCarryObject.generated.h"

class AFortAthenaMutator_Infiltration;
class AInfiltrationCarryObjectSpawnPoint;

UCLASS(HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision"), ClassGroup=("Fortnite"), meta=(BlueprintSpawnableComponent))
class UInfiltrationCarryObjectComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UPROPERTY(Replicated)
	TWeakObjectPtr<AInfiltrationCarryObjectSpawnPoint> ParentSpawnPoint;

	UPROPERTY(Replicated)
	TWeakObjectPtr<AFortAthenaMutator_Infiltration> CachedMutator;

protected:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="InfiltrationCarryObjectComponent", meta=(AllowPrivateAccess="true"))
	bool bIsInteractable;

};

