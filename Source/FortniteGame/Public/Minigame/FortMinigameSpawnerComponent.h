// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Items/FortItemEntry.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "Minigame/FortMinigameItemContainerComponent.h"
#include "FortMinigameSpawnerComponent.generated.h"

class AFortPickup;
class AFortPlayerController;
class UFortWorldItemDefinition;
enum class EFortPickupSourceTypeFlag : uint8;
enum class EFortPickupSpawnSource : uint8;

USTRUCT(BlueprintType)
struct FMinigameSpawnerSpawnParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Minigame")
	TSoftObjectPtr<UFortWorldItemDefinition> PickupToSpawn;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Minigame")
	int32 PickupQuantity;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Transient, Category="Minigame")
	int32 PickupInstigatorHandle;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Minigame")
	FGuid ItemVariantGuid;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="Minigame")
	FTransform SpawnTransform;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Minigame")
	int32 WeaponAmmoOverride;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameSpawnerComponent : public UFortMinigameItemContainerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool MakeSpawnParamsFromItemEntry(FMinigameSpawnerSpawnParams& SpawnParams, const FFortItemEntry& ItemEntry, const FTransform& SpawnTransform) const;

	UFUNCTION(BlueprintCallable)
	AFortPickup* SpawnPickupFromSpawnParams(const FMinigameSpawnerSpawnParams& SpawnParams, TSubclassOf<AFortPickup> PickupClass, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

protected:
	UFUNCTION()
	void OnRep_ToSpawnList();

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, ReplicatedUsing=OnRep_ToSpawnList, Category="Minigame", meta=(AllowPrivateAccess="TRUE"))
	TArray<FMinigameSpawnerSpawnParams> ToSpawnList;

};

