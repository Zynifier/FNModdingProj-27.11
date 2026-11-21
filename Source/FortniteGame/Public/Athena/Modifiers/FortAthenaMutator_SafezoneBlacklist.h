// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SafezoneBlacklist.generated.h"

class AFortPoiVolume;
class UBlacklistEntryBase;

USTRUCT()
struct FHotfixableBlacklistLiteralLocations
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector2D Position;

	UPROPERTY()
	float Radius;

};

UCLASS(Config=Game, HideCategories=("Actor", "Replication", "Tick", "ActorTick", "HLOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SafezoneBlacklist : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Blacklist")
	FScalableFloat MasterDisableSwitch;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Blacklist")
	TArray<TObjectPtr<UBlacklistEntryBase>> BlacklistEntries;

	UPROPERTY(Config, Transient)
	TArray<FGameplayTag> HotfixBlacklistPoiTags;

	UPROPERTY(Config, Transient)
	TArray<FHotfixableBlacklistLiteralLocations> HotfixBlacklistLocations;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UBlacklistEntryBase>> HotfixedEntries;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UBlacklistEntryBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Blacklist")
	FScalableFloat IsEntryDisabled;

	UPROPERTY(EditDefaultsOnly, Category="BlacklistRadius")
	FScalableFloat ConsiderSafeZoneRadius;

};

UCLASS(meta=(DisplayName="Around Location"))
class UBlacklistEntry_Location : public UBlacklistEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Blacklist")
	FVector CheckLocation;

	UPROPERTY(EditDefaultsOnly, Category="Blacklist")
	FScalableFloat CheckRadius;

};

UCLASS(meta=(DisplayName="Around POI"))
class UBlacklistEntry_PoiVolume : public UBlacklistEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Blacklist", meta=(Categories="Athena.Location"))
	FGameplayTag PoiTag;

	UPROPERTY(EditDefaultsOnly, Category="Blacklist")
	FScalableFloat CheckRadius;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortPoiVolume> RelevantVolume;

};

