// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortQueryTest_WithinTaggedArea.generated.h"

UCLASS()
class UFortQueryTest_WithinTaggedArea : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinTaggedArea")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinTaggedArea")
	FVector AreaExtentBuffer;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinTaggedArea")
	bool bAssumeInfiniteHeightForArea;

};

