// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CosmeticBackendLoadout.h"
#include "FortCosmeticLoadoutSubsystem.generated.h"

class AActor;
class AFortPlayerController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortPlayerCosmeticLoadoutChangedDelegate, const AFortPlayerController*, PlayerController);

UCLASS(MinimalAPI)
class UFortCosmeticLoadoutSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Equip Cosmetic Loadout Preset"))
	void BP_EquipCosmeticLoadoutPreset(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(DisplayName="Get Cosmetic Loadout", ExpandBoolAsExecs="ReturnValue"))
	bool BP_GetCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId, FCosmeticBackendLoadout& OutLoadout) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(DisplayName="Get Equipped Cosmetic Loadout", ExpandBoolAsExecs="ReturnValue"))
	bool BP_GetEquippedCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, FCosmeticBackendLoadout& OutLoadout) const;

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Put Cosmetic Loadout"))
	void BP_PutCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId, const FCosmeticBackendLoadout& Loadout);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Remove Cosmetic Loadout"))
	void BP_RemoveCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId);

	UPROPERTY(BlueprintAssignable)
	FFortPlayerCosmeticLoadoutChangedDelegate OnPlayerCosmeticLoadoutChanged;

	UPROPERTY(BlueprintAssignable)
	FFortPlayerCosmeticLoadoutChangedDelegate OnPlayerCosmeticLoadoutPresetChanged;

private:
	UFUNCTION()
	void HandlePlayerDestroyed(AActor* DestroyedActor);

};

