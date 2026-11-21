// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortTeamEnum.h"
#include "FortUserOptionDefinitions.h"
#include "FortCreativeTeamOption.generated.h"

enum class ECreativeTeamType : uint8;

UENUM(BlueprintType)
enum class ECreativeTeamType : uint8
{
	/** Use the specified team index value */
	TeamIndex = 0,
	None = 1,
	All = 2,
	Any = 3,
	Allies = 4,
	Hostiles = 5,
	Friendlies = 6,
	Enemies = 7,
	Neutral = 8,
	Random = 9,
	DoNotSwitch = 10,
	ActivatingTeam = 11,
	WinningTeam = 12,
	UseGameWinConditions = 13,
	CompletingTeamWins = 14,
	TriggeringPlayer = 15,
	TriggeringTeam = 16,
	Spectating = 17,
	Cooperative = 18,
	FreeForAll = 19,
	Custom = 20,
	SpawnOnNextRound = 21,
	Spawn = 22,
	Spectate = 23,
};

USTRUCT(BlueprintType, Atomic)
struct FCreativeTeamOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Creative|TeamOption")
	ECreativeTeamType TeamType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Creative|TeamOption")
	int32 TeamIndex;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionTeamTypeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	ECreativeTeamType Value;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionTeamIndexMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FCreativeTeamOption DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MinTeamIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	int32 MaxTeamIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText TeamIndexDisplayPattern;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<ECreativeTeamType> TeamTypesToShow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<ECreativeTeamType> TeamTypesToHide;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	TArray<FUserOptionDefinitionTeamTypeEntry> TeamTypeEntries;

};

UCLASS(meta=(ScriptName="CreativeTeamOptionLibrary"))
class UCreativeTeamOptionBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|TeamOption", meta=(ScriptMethod))
	static EFortTeam::Type ConvertToTeam(const FCreativeTeamOption& TeamOption);

	UFUNCTION(BlueprintPure, Category="Creative|TeamOption", meta=(ScriptMethod))
	static int32 GetLegacyTeamIndex(const FCreativeTeamOption& TeamOption, const bool bShiftIndex = true);

	UFUNCTION(BlueprintPure, Category="Creative|TeamOption", meta=(ScriptMethod))
	static bool IsTeamType(const FCreativeTeamOption& TeamOption, const ECreativeTeamType TeamType);

	UFUNCTION(BlueprintPure, Category="Creative|TeamOption")
	static FCreativeTeamOption MakeFromLegacyTeamIndex(const int32 LegacyTeamIndex);

	UFUNCTION(BlueprintCallable, Category="Creative|TeamOption", meta=(ScriptMethod))
	static void SetLegacyTeamIndex(UPARAM(ref) FCreativeTeamOption& TeamOption, const int32 LegacyTeamIndex);

};

