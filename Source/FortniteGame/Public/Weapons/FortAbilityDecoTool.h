// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "Math/MathFwd.h"
#include "Weapons/FortDecoTool.h"
#include "FortAbilityDecoTool.generated.h"

class ABuildingActor;
class ABuildingSMActor;
class UFortGameplayAbility;

USTRUCT(BlueprintType)
struct FAbilityToolSpawnParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Ability")
	TSubclassOf<ABuildingActor> SpawnClass;

	UPROPERTY(BlueprintReadWrite, Category="Ability")
	FVector Location;

	UPROPERTY(BlueprintReadWrite, Category="Ability")
	FRotator Rotation;

	UPROPERTY(BlueprintReadWrite, Category="Ability")
	TObjectPtr<ABuildingSMActor> AttachedToActor;

};

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortAbilityDecoTool : public AFortDecoTool
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ability")
	ABuildingActor* AbilitySpawnDeco(const FAbilityToolSpawnParameters& SpawnParameters);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ability")
	FGameplayAbilitySpecHandle GetPlacementAbilityHandle();

	UFUNCTION(BlueprintCallable, Category="Ability")
	UFortGameplayAbility* GetPlacementAbilityInstance();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Ability")
	void GetSpawnParameters(FAbilityToolSpawnParameters& OutSpawnParamters) const;

private:
	UPROPERTY(Transient)
	FAbilityToolSpawnParameters CachedSpawnParameters;

};

