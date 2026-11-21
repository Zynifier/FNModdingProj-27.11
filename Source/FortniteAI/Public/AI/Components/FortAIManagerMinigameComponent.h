// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortAIManagerMinigameComponent.generated.h"

class AActor;
class AController;
class APawn;
class UObject;
class UPrimitiveComponent;

USTRUCT()
struct FAISpawnCountInfo
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAIManagerMinigameComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleMinigameStarted();

	UFUNCTION()
	void OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnPawnSpawned(APawn* Pawn, const int32 RequestID);

protected:
	UFUNCTION(BlueprintPure)
	FGameplayTag GetSpawnTagFromPawnObject(const UObject* PawnObject) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIManagerMinigameComponent")
	TArray<FGameplayTag> SpawnableAITypeTags;

};

