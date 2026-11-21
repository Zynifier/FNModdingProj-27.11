// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GG.generated.h"

class AActor;
class AFortPlayerStateAthena;
class UFortWeaponItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLocalPlayerWeaponProgressed, UFortWeaponItemDefinition*, NextWeapon);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOtherPlayerWeaponProgressed, AFortPlayerStateAthena*, OtherPlayer, UFortWeaponItemDefinition*, NextWeapon);

USTRUCT()
struct FGunGameGunEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GunGameGunEntry")
	FScalableFloat Enabled;

	UPROPERTY(EditDefaultsOnly, Category="GunGameGunEntry")
	FScalableFloat AwardAtElim;

	UPROPERTY(EditDefaultsOnly, Category="GunGameGunEntry")
	bool bShowHarvestingToolOnLadder;

protected:
	UPROPERTY(EditDefaultsOnly, Category="GunGameGunEntry")
	TObjectPtr<UFortWeaponItemDefinition> Weapon;

	UPROPERTY(EditDefaultsOnly, Category="GunGameGunEntry")
	FPrimaryAssetId WeaponAssetId;

};

USTRUCT()
struct FGunGameGunEntries
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGunGameGunEntry> Entries;

};

USTRUCT()
struct FGunGamePlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortWeaponItemDefinition>> CurrentlyAssignedWeapons;

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Replication", "FortAthenaMutator", "HLOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GG : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_GG")
	FLocalPlayerWeaponProgressed OnLocalPlayerAwardedWeapon;

	UPROPERTY(VisibleDefaultsOnly, BlueprintAssignable, Category="FortAthenaMutator_GG")
	FOtherPlayerWeaponProgressed OnOtherPlayerAwardedWeapon;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat UseInfiniteAmmo;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat GameIsReverse;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat bShareSquadKills;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat FinalTierSize;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat ElimsWithFinalTierToWin;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	TArray<FGunGameGunEntry> WeaponEntries;

	UPROPERTY(VisibleAnywhere, Category="Mechanics")
	int32 ScoreToWin;

	UPROPERTY(EditDefaultsOnly, Category="Messaging")
	TArray<FAthenaGameMessageData> IntroMessages;

	UPROPERTY()
	TObjectPtr<AActor> CachedContext;

	UPROPERTY(Transient)
	TMap<int32, FGunGameGunEntries> AwardEntriesAtElimMap;

	UPROPERTY()
	TMap<TObjectPtr<AFortPlayerStateAthena>, FGunGamePlayerData> PlayerData;

};

