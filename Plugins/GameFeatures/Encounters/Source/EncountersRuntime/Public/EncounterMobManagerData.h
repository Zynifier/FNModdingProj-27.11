// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "EncounterMobManagerData.generated.h"

class AEncounterMobAnchor;
class AFortAthenaLivingWorldStaticPointProvider;
class AFortAthenaLivingWorldVolume;
class IFortAthenaLivingWorldPointProviderInterface;
class UEnvQuery;
class UFortAthenaLivingWorldEncounter;

UENUM()
enum class EEncounterMobSpawnType : int32
{
	/** Represents volume-based LWM point providers */
	VolumeBased = 0,
	/** Represents static point-based LWM point providers */
	StaticPointBased = 1,
};

USTRUCT()
struct FEncounterMobInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	AFortAthenaLivingWorldVolume* VolumePointProvider;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> CurrentPointProviders;

};

USTRUCT()
struct FEncounterMobSpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo")
	FScalableFloat LeashRadiusInner;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo")
	FScalableFloat LeashRadiusOuter;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo")
	TWeakObjectPtr<AEncounterMobAnchor> EncounterAnchorPoint;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo")
	EEncounterMobSpawnType MobSpawnType;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo")
	FGameplayTagContainer PointProviderFilterTags;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo", meta=(EditCondition="MobSpawnType==EEncounterMobSpawnType::StaticPointBased"))
	TArray<TWeakObjectPtr<AFortAthenaLivingWorldStaticPointProvider>> StaticPointProviders;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo", meta=(EditCondition="MobSpawnType==EEncounterMobSpawnType::VolumeBased"))
	TObjectPtr<UEnvQuery> PointProviderEQS;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnInfo", meta=(EditCondition="MobSpawnType==EEncounterMobSpawnType::VolumeBased"))
	TSubclassOf<AFortAthenaLivingWorldVolume> PointProviderVolumeClass;

};

USTRUCT()
struct FEncounterMobSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData")
	FString DevNotes;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData", meta=(Categories="Encounter.Mobs"))
	FGameplayTag MobIdentifier;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData")
	bool bActiveOnStart;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> MobEncounterData;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData")
	bool bOverrideDefaultSpawnInfo;

	UPROPERTY(EditAnywhere, Category="EncounterMobSpawnData", meta=(EditCondition="bOverrideDefaultSpawnInfo"))
	FEncounterMobSpawnInfo MobSpawnInfo;

};

