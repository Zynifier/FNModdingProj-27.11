// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortRarityEnum.h"
#include "Items/FortPickupManagementInterface.h"
#include "FortGameStateComponent_PickupManagement.generated.h"

USTRUCT()
struct FManagedActorInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FPickupManagedActorBucket
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FPickupManagementSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings", meta=(ClampMax="1000", ClampMin="1"))
	int32 PickupsAllowedMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings", meta=(ClampMin="1"))
	int32 PickupsDesiredSlack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings", meta=(ClampMin="0.01"))
	float PickupDespawnDelaySeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings")
	bool bDebugPickupManagement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings")
	bool bEnablePickupManagement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings")
	EFortRarity NotJunkPickupThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings")
	EFortRarity ImportantPickupThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupManagementSettings")
	bool bFlagPlayerDropsAsImportant;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortGameStateComponent_PickupManagement : public UGameStateComponent, public IFortPickupManagementInterface
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_PickupManagement(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditDefaultsOnly, Category="Pickup Management")
	FPickupManagementSettings DefaultPickupManagementSettings;

};

