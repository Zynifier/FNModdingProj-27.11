// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortAthenaExitCraftInfo.generated.h"

class AFortAthenaExitCraft;
class AFortAthenaExitCraftSpawner;

USTRUCT(BlueprintType)
struct FExitCraftInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	FGameplayTag RequiredExitCraftTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawner")
	FScalableFloat ExitCraftSpawnerZOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawner")
	FScalableFloat ExitCraftSpawnDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawner")
	FScalableFloat SpawnDestructionInitialDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Spawner")
	FScalableFloat SpawnDestructionDelayBetweenPieces;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitCraftZOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitCraftTargetZOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitCraftTimeToHoverLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitCraftTimeToHoverRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat MinLandingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitZOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat ExitTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft")
	FScalableFloat InteractionTime;

};

UCLASS()
class UFortAthenaExitCraftInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaExitCraftInfo")
	TSubclassOf<AFortAthenaExitCraft> ExitCaftClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaExitCraftInfo")
	TSubclassOf<AFortAthenaExitCraftSpawner> ExitCraftSpawnerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaExitCraftInfo")
	FExitCraftInfo ExitCraftInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorSpawnerTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush SpawnerMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D SpawnerMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush SpawnerCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D SpawnerCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorCraftTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush CraftMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D CraftMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush CraftCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D CraftCompassIconScale;

};

