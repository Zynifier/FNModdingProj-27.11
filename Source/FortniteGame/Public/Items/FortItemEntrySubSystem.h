// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortItemEntrySubSystem.generated.h"

class UGameplayAbility;

USTRUCT()
struct FFortItemEntryAbilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TMap<TWeakObjectPtr<UGameplayAbility>, float> AbilityCooldownMap;

};

USTRUCT()
struct FFortItemEntryTaggedFloatData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TMap<FGameplayTag, float> TaggedFloatMap;

};

USTRUCT()
struct FFortItemEntryTaggedIntegerData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TMap<FGameplayTag, int32> TaggedIntegerMap;

};

UCLASS(MinimalAPI)
class UFortItemEntrySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FGuid, FFortItemEntryAbilityData> ItemAbilityCooldownMap;

	UPROPERTY(Transient)
	TMap<FGuid, FFortItemEntryTaggedIntegerData> ItemTaggedIntegerMap;

	UPROPERTY(Transient)
	TMap<FGuid, FFortItemEntryTaggedFloatData> ItemTaggedFloatMap;

};

