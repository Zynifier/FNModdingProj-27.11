// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortGameDataSubsystem.generated.h"

class UFortGameDataSubsystem;
class UObject;

USTRUCT(BlueprintType)
struct FFortUnableToPerformData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortUnableToPerformData")
	FGameplayTagContainer FailureTags;

	UPROPERTY(EditAnywhere, Category="FortUnableToPerformData")
	FText Message;

	UPROPERTY(EditDefaultsOnly, Category="FortUnableToPerformData")
	EGameplayContainerMatchType MatchType;

};

UCLASS(BlueprintType)
class UFortGameDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static UFortGameDataSubsystem* Get(const UObject* WorldContextObject);

private:
	UPROPERTY(Transient)
	TArray<FFortUnableToPerformData> TagsToMessageTableCache;

};

