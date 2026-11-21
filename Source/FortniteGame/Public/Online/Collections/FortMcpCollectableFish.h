// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Online/Collections/FortMcpCollectionBase.h"
#include "FortMcpCollectableFish.generated.h"

class AFortPlayerController;
class UFortItemDefinition;
enum class EFortCollectedState : uint8;

USTRUCT(BlueprintType)
struct FFortMcpCollectedFishProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortMcpCollectedFishProperties")
	float Weight;

	UPROPERTY(BlueprintReadWrite, Category="FortMcpCollectedFishProperties")
	float Length;

};

UCLASS()
class UFortMcpCollectableFish : public UFortMcpCollectionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static EFortCollectedState AddToPlayerCollection(const AFortPlayerController* FPC, const FGameplayTag& Variant, const FFortMcpCollectedFishProperties& Props, const FGameplayTagContainer& ContextTags);

private:
	UPROPERTY()
	TMap<FString, TObjectPtr<UFortItemDefinition>> SpeciesToItemDefMap;

};

