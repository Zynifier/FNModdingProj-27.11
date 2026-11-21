// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "UObject/NoExportTypes.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortMinigameStats.generated.h"

class AController;
class AFortPlayerState;
class APlayerController;
class UFortItemDefinition;
class UFortMinigameStatFilter;
class UFortMinigameStatsComponent;
class UObject;
class UTexture2D;
enum class EFortQuestObjectiveStatEvent : uint8;

UENUM(BlueprintType)
enum class EFortMinigameStatOperation : uint8
{
	Equal = 0,
	Less = 1,
	Greater = 2,
	LessOrEqual = 3,
	GreaterOrEqual = 4,
};

UENUM(BlueprintType)
enum class EFortMinigameStatScope : uint8
{
	Group = 0,
	Team = 1,
	Player = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddToPlayerDefinedStatDelegate, int32, Amount, const APlayerController*, InstigatingController);

USTRUCT(BlueprintType)
struct FFortMinigameStat
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMinigameStat")
	TObjectPtr<UFortMinigameStatFilter> Filter;

	UPROPERTY(VisibleAnywhere, Category="FortMinigameStat")
	int32 Count;

};

USTRUCT(BlueprintType)
struct FFortMinigameGroupStats
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMinigameGroupStats")
	TArray<FFortMinigameStat> Stats;

};

USTRUCT(BlueprintType)
struct FFortMinigamePlayerBucketStats : public FFortMinigameGroupStats
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMinigamePlayerBucketStats")
	int32 BucketIndex;

};

USTRUCT(BlueprintType)
struct FFortMinigamePlayerStats : public FFortMinigameGroupStats
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMinigamePlayerStats")
	FUniqueNetIdRepl Player;

};

USTRUCT()
struct FFortMinigameStatCollection
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleInstanceOnly, Category="FortMinigameStatCollection")
	FFortMinigameGroupStats GroupStats;

	UPROPERTY(VisibleInstanceOnly, Category="FortMinigameStatCollection")
	TArray<FFortMinigamePlayerStats> PlayerStats;

	UPROPERTY(VisibleInstanceOnly, Category="FortMinigameStatCollection")
	TArray<FFortMinigamePlayerBucketStats> PlayerBucketStats;

};

USTRUCT(BlueprintType)
struct FFortMinigameStatQuery
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery")
	TObjectPtr<UFortMinigameStatFilter> Stat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery")
	EFortMinigameStatScope Scope;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery")
	uint8 bAnyMatch : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery")
	EFortMinigameStatOperation Operation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery", meta=(EditCondition="bStaticCount"))
	int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMinigameStatQuery")
	uint8 bStaticCount : 1;

};

USTRUCT(BlueprintType)
struct FFortMinigameTeamStats : public FFortMinigameGroupStats
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortMinigameTeamStats")
	uint8 Team;

};

USTRUCT(BlueprintType)
struct FMinigameScoreboardValue
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardValue")
	TObjectPtr<UFortMinigameStatFilter> StatFilter;

	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardValue")
	int32 Value;

	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardValue")
	bool bHighlight;

};

USTRUCT(BlueprintType)
struct FMingiameScoreboardRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MingiameScoreboardRow")
	FText Name;

	UPROPERTY(BlueprintReadOnly, Category="MingiameScoreboardRow")
	int32 TeamColorIndex;

	UPROPERTY(BlueprintReadOnly, Category="MingiameScoreboardRow")
	TArray<FMinigameScoreboardValue> Values;

	UPROPERTY(BlueprintReadOnly, Category="MingiameScoreboardRow")
	int32 WinCount;

	UPROPERTY(BlueprintReadOnly, Category="MingiameScoreboardRow")
	bool bHighlight;

};

USTRUCT(BlueprintType)
struct FMinigameScoreboardPlayerRow : public FMingiameScoreboardRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardPlayerRow")
	TObjectPtr<AFortPlayerState> PlayerState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinigameScoreboardPlayerRow")
	bool bHasLeftGame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MinigameScoreboardPlayerRow")
	bool bHideFromDisplay;

};

USTRUCT(BlueprintType)
struct FMinigameScoreboardBucketRow : public FMingiameScoreboardRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardBucketRow")
	int32 Standing;

	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardBucketRow")
	int32 BucketIndex;

	UPROPERTY(BlueprintReadOnly, Category="MinigameScoreboardBucketRow")
	TArray<FMinigameScoreboardPlayerRow> PlayerRows;

};

USTRUCT()
struct FPlayerDefinedStatFilterEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FStatEventFilter StatEventFilter;

	UPROPERTY()
	FText StatName;

	UPROPERTY()
	TSoftObjectPtr<UTexture2D> StatIcon;

};

USTRUCT(BlueprintType)
struct FPlayerDefinedStatFilterArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPlayerDefinedStatFilterEntry> ReplicatedEntries;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMinigameStatsComponent> Owner;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortMinigameStatFilter : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	int32 Accumulate(int32 A, int32 B) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	int32 Compare(int32 FirstScore, int32 SecondScore) const;

	UFUNCTION(BlueprintNativeEvent)
	FText FormatStat(int32 InCount) const;

	UFUNCTION(BlueprintNativeEvent)
	bool Matches(EFortQuestObjectiveStatEvent InStatEvent, UObject* InTargetObject, AController* InPlayerController, const FGameplayTagContainer& InTargetTags, const FGameplayTagContainer& InSourceTags, const FGameplayTagContainer& InContextTags) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	EFortQuestObjectiveStatEvent StatEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	EFortQuestObjectiveItemEvent ItemEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FGameplayTagQuery TargetTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FGameplayTagQuery SourceTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FGameplayTagQuery ContextTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	bool bAccumulates;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FText HudShortDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	FString AnalyticsString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMinigameStatFilter")
	TSoftObjectPtr<UTexture2D> HudIcon;

};

UCLASS(BlueprintType)
class UFortMinigamePlayerDefinedStatFilter : public UFortMinigameStatFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnAddToPlayerDefinedStatDelegate OnAddToPlayerDefinedStatDelegate;

};

