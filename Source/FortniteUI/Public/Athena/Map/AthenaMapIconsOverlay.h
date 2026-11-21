// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/Overlay.h"
#include "AthenaMapIconsOverlay.generated.h"

class UAthenaChallengeIndicatorCache;
class UAthenaFrontEndMapPoiIcon;
class UAthenaMapNavigableIconSingleChallenge;
class UAthenaMapNavigableIconStackOfChallenges;
class UAthenaMapNavigableIconStackOfNoLocationChallenges;
class UFortGameStateComponent_EventLevel;

USTRUCT()
struct FDisabledQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

};

USTRUCT(BlueprintType)
struct FSelectedChallengesData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	bool bIsCompleted;

	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	bool bIsLocked;

	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	bool bHasIconOverride;

	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	float Progress;

	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	int32 NumObjectivesCompleted;

	UPROPERTY(BlueprintReadOnly, Category="SelectedChallengesData")
	int32 NumObjectives;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMapIconsOverlay : public UOverlay
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaMapIconsOverlay")
	TSubclassOf<UAthenaMapNavigableIconSingleChallenge> AthenaMapNavigableIconSingleChallengeClass;

	UPROPERTY(EditAnywhere, Category="AthenaMapIconsOverlay")
	TSubclassOf<UAthenaMapNavigableIconStackOfChallenges> AthenaMapNavigableIconStackOfChallengesClass;

	UPROPERTY(EditAnywhere, Category="AthenaMapIconsOverlay")
	TSubclassOf<UAthenaMapNavigableIconStackOfNoLocationChallenges> AthenaMapNavigableIconStackOfNoLocationChallengesClass;

	UPROPERTY(EditAnywhere, Category="AthenaMapIconsOverlay")
	bool bShowNoLocationIcon;

	UPROPERTY(EditAnywhere, Category="AthenaMapIconsOverlay")
	bool bAllowFocusControl;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaChallengeIndicatorCache> ChallengeIndicatorCache;

	UPROPERTY(Transient)
	FUserWidgetPool WidgetsPool;

	UPROPERTY(Config)
	TArray<FDisabledQuestData> DisabledQuests;

};

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFrontEndMapIconsOverlay : public UAthenaMapIconsOverlay
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaFrontEndMapIconsOverlay")
	TSubclassOf<UAthenaFrontEndMapPoiIcon> AthenaMapPoiIconClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventLevelInstance;

};

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaInGameMapIconsOverlay : public UAthenaMapIconsOverlay
{
	GENERATED_BODY()

};

