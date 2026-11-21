// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Online/Collections/FortMcpCollectionBase.h"
#include "FortMcpCollectableCharacter.generated.h"

class AFortPlayerController;
enum class ECharacterEncounterType : uint8;
enum class EFortCollectedState : uint8;
enum class ESavePlayerQuestUpdate : uint8;

UENUM(BlueprintType)
enum class ECharacterEncounterType : uint8
{
	Converstation = 0,
	Attack = 1,
	Count = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class ESavePlayerQuestUpdate : uint8
{
	QuestGiven = 0,
	QuestCompleted = 1,
};

USTRUCT(BlueprintType)
struct FFortMcpCollectedCharacterProperties
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 QuestsGiven;

	UPROPERTY()
	int32 QuestsCompleted;

	UPROPERTY()
	uint8 EncounterTypeFlags;

};

UCLASS()
class UFortMcpCollectableCharacter : public UFortMcpCollectionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static EFortCollectedState AddToPlayerCollection(const AFortPlayerController* FPC, const FGameplayTag& Variant, const FFortMcpCollectedCharacterProperties& Props, const FGameplayTagContainer& ContextTags, ECharacterEncounterType EncounterType = ECharacterEncounterType::Converstation);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported, please remove calls to it"))
	static void SavePlayerQuestUpdate(const AFortPlayerController* FPC, const FGameplayTag& Variant, ESavePlayerQuestUpdate Update);

};

