// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Components/FortGameStateComponent.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "FortWeaponModOverrideData.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;
class UFortWeaponModAudioData;

USTRUCT()
struct FFortWeaponModOverrideDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortWeaponModOverrideDataRow")
	FGameplayTag WeaponTag;

	UPROPERTY(EditAnywhere, Category="FortWeaponModOverrideDataRow")
	FGameplayTag ModTag;

	UPROPERTY(EditAnywhere, Category="FortWeaponModOverrideDataRow")
	FWeaponModStaticMeshData ModMeshData;

	UPROPERTY(EditAnywhere, Category="FortWeaponModOverrideDataRow")
	TObjectPtr<UFortWeaponModAudioData> AudioData;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_WeaponModOverrideManager : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Transient)
	TMap<FName, FWeaponModCosmeticData> CachedModOverrides;

};

