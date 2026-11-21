// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalGameplayTags.generated.h"

UCLASS()
class UFortQueryTest_GoalGameplayTags : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="GameplayTagCheck")
	bool bShouldLookupQueryByTag;

	UPROPERTY(EditAnywhere, Category="GameplayTagCheck", meta=(EditCondition="!bShouldLookupQueryByTag"))
	FGameplayTagQuery TagQueryToMatch;

	UPROPERTY(EditAnywhere, Category="GameplayTagCheck", meta=(EditCondition="bShouldLookupQueryByTag"))
	FGameplayTag QueryLookupTag;

	UPROPERTY(EditAnywhere, Category="GameplayTagCheck", meta=(EditCondition="bShouldLookupQueryByTag"))
	bool bShouldPassWhenQueryNotFound;

	UPROPERTY(EditAnywhere, Category="GameplayTagCheck")
	bool bRequireAllProvidedTagQueriesPass;

};

