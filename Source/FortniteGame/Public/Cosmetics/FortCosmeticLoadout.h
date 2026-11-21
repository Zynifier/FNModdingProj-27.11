// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortCosmeticLoadout.generated.h"

class UAthenaBackpackItemDefinition;
class UAthenaBattleBusItemDefinition;
class UAthenaCallingCardItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaCharmItemDefinition;
class UAthenaCosmeticItemDefinition;
class UAthenaDanceItemDefinition;
class UAthenaGliderItemDefinition;
class UAthenaHatItemDefinition;
class UAthenaItemWrapDefinition;
class UAthenaLoadingScreenItemDefinition;
class UAthenaMapMarkerItemDefinition;
class UAthenaMusicPackItemDefinition;
class UAthenaPetItemDefinition;
class UAthenaPickaxeItemDefinition;
class UAthenaSkyDiveContrailItemDefinition;
class UAthenaVehicleCosmeticItemDefinition;
class UAthenaVictoryPoseItemDefinition;
class UFortApparelItemDefinition;
class UFortMcpProfileAthena;

UENUM(BlueprintType)
enum class EAthenaCustomizationCategory : uint8
{
	None = 0,
	Glider = 1,
	// First real slot

	Pickaxe = 2,
	Hat = 3,
	Backpack = 4,
	Character = 5,
	LoadingScreen = 6,
	BattleBus = 7,
	VehicleDecoration = 8,
	CallingCard = 9,
	MapMarker = 10,
	Dance = 11,
	ConsumableEmote = 12,
	VictoryPose = 13,
	SkyDiveContrail = 14,
	MusicPack = 15,
	ItemWrap = 16,
	PetSkin = 17,
	Charm = 18,
	RegCosmeticDef = 19,
	Apparel = 20,
	SparksCosmeticDef = 21,
	// Last real slot

	Loadout = 22,
	SaveLoadout = 23,
	MAX = 24 UMETA(Hidden),
};

UENUM()
enum class EFortLockerAnalyticAction : uint8
{
	// locker tab level actions

	Locker_SaveChanges = 0,
	Locker_CreateNew = 1,
	// Locker Actions

	Locker_Clear = 2,
	Locker_Revert = 3,
	Locker_Randomize = 4,
	// preset selector screen

	Preset_Delete = 5,
	Preset_ChangeActive = 6,
	Preset_ChangeName = 7,
	InGame_Warmup = 8,
};

USTRUCT(BlueprintType)
struct FFortAthenaLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	FString BannerIconId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	FString BannerColorId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TObjectPtr<UAthenaSkyDiveContrailItemDefinition> SkyDiveContrail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaGliderItemDefinition> Glider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TObjectPtr<UAthenaPickaxeItemDefinition> Pickaxe;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TObjectPtr<UAthenaCharacterItemDefinition> Character;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TArray<FMcpVariantChannelInfo> CharacterVariantChannels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaHatItemDefinition> Hat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TObjectPtr<UAthenaBackpackItemDefinition> Backpack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaLoadingScreenItemDefinition> LoadingScreen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaBattleBusItemDefinition> BattleBus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaVehicleCosmeticItemDefinition> VehicleDecoration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaCallingCardItemDefinition> CallingCard;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaMapMarkerItemDefinition> MapMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> Dances;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaVictoryPoseItemDefinition> VictoryPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaMusicPackItemDefinition> MusicPack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TObjectPtr<UAthenaItemWrapDefinition> ItemWrapOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TArray<TObjectPtr<UAthenaItemWrapDefinition>> ItemWraps;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaCharmItemDefinition> CharmOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout", meta=(SkipInCombinedLoad))
	TArray<TObjectPtr<UAthenaCharmItemDefinition>> Charms;

	UPROPERTY(EditAnywhere, Category="PrototypeCosmetics", meta=(SkipInCombinedLoad))
	TObjectPtr<UAthenaPetItemDefinition> PetSkin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaLoadout")
	TArray<TObjectPtr<UFortApparelItemDefinition>> ApparelArray;

	UPROPERTY(Transient)
	bool bIsDefaultCharacter;

	UPROPERTY(Transient)
	bool bForceUpdateVariants;

protected:
	UPROPERTY(NotReplicated)
	TObjectPtr<UFortMcpProfileAthena> CachedProfileSource;

};

USTRUCT()
struct FFortReconstructibleAthenaLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> EquippedItemDefs;

	UPROPERTY()
	TArray<FMcpVariantChannelInfo> VariantDataBucket;

};

