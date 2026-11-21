// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortDeathCauseData.generated.h"

UENUM(BlueprintType)
enum class EDeathCauseReason : uint8
{
	SelfInflicted = 0,
	SelfInflictedDBNO = 1,
	Eliminated = 2,
	EliminatedDBNO = 3,
};

USTRUCT()
struct FFortDeathCauseInfoVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant")
	FString DisplayText;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant")
	FGameplayTag DeathCauseTag;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant")
	TArray<FText> SelfInflictedMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant", meta=(DisplayName="Self Inflicted DBNO Messages"))
	TArray<FText> SelfInflictedDBNOMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant")
	TArray<FText> EliminatedMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info Variant", meta=(DisplayName="Eliminated DBNO Messages"))
	TArray<FText> EliminatedDBNOMessages;

};

USTRUCT()
struct FFortDeathCauseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info")
	FString DisplayText;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info")
	FGameplayTag DeathCauseTag;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info", meta=(DisplayName="Eliminated By Name"))
	FText EliminatedByName;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info")
	TArray<FText> SelfInflictedMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info", meta=(DisplayName="Self Inflicted DBNO Messages"))
	TArray<FText> SelfInflictedDBNOMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info")
	TArray<FText> EliminatedMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info", meta=(DisplayName="Eliminated DBNO Messages"))
	TArray<FText> EliminatedDBNOMessages;

	UPROPERTY(EditDefaultsOnly, Category="Death Cause Info", meta=(TitleProperty="DisplayText"))
	TArray<FFortDeathCauseInfoVariant> DeathCauseInfoVariants;

};

UCLASS()
class UFortDeathCauseData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Death Cause", meta=(TitleProperty="DisplayText"))
	TArray<FFortDeathCauseInfo> DeathCauseInfos;

};

