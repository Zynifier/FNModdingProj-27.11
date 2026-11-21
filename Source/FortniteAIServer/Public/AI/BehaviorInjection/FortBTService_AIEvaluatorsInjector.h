// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GameplayTagContainer.h"
#include "FortBTService_AIEvaluatorsInjector.generated.h"

class UObject;

USTRUCT()
struct FFortBTService_InjectionTagKey
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortBTService_InjectionTagKey")
	FGameplayTag InjectionTag;

	UPROPERTY(VisibleAnywhere, Category="FortBTService_InjectionTagKey")
	FName InjectionKeyName;

};

UCLASS()
class UFortBTService_AIEvaluatorsInjector : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> ReferenceHolder;

	UPROPERTY(VisibleAnywhere, Category="FortBTService_AIEvaluatorsInjector")
	TArray<FFortBTService_InjectionTagKey> InjectionTagsKeys;

};

