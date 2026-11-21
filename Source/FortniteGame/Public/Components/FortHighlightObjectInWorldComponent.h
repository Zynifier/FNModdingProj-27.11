// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "FortHighlightObjectInWorldComponent.generated.h"

class AActor;
class UParticleSystem;

USTRUCT()
struct FHighlightObjectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	FGameplayTagContainer HighlightTags;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	FName FriendlyStencilName;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	FName EnemyStencilName;

	UPROPERTY()
	uint8 FriendlyStencilIndex;

	UPROPERTY()
	uint8 EnemyStencilIndex;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	TObjectPtr<UParticleSystem> Effect;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	float OverlapRadius;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditDefaultsOnly, Category="HighlightObjectData")
	TSubclassOf<AActor> ActorClassFilter;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> PreviouslyOverlappingActors;

	UPROPERTY(Transient)
	bool bIgnoreDistanceCheck;

	UPROPERTY(Transient)
	bool bOnlyHighlightOwningActor;

};

UCLASS(BlueprintType, HideCategories=("Trigger", "Sockets", "Tags", "Activation", "Component", "AssetUserData", "Collision"), meta=(BlueprintSpawnableComponent))
class UFortHighlightObjectInWorldComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Highlight Object Data")
	TArray<FHighlightObjectData> HighlightData;

};

