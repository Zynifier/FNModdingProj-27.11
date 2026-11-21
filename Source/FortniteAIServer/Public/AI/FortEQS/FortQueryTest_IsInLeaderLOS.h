// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_IsInLeaderLOS.generated.h"

UCLASS()
class UFortQueryTest_IsInLeaderLOS : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsInLeaderLOS", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery OwnerTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsInLeaderLOS", meta=(AllowPrivateAccess="true"))
	bool bRequireLOSRayCast;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsInLeaderLOS", meta=(AllowPrivateAccess="true", EditCondition="bRequireLOSRayCast", EditConditionHides))
	float RayCastLeaderVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsInLeaderLOS", meta=(AllowPrivateAccess="true", EditCondition="bRequireLOSRayCast", EditConditionHides))
	float RayCastItemVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_IsInLeaderLOS", meta=(AllowPrivateAccess="true", EditCondition="bRequireLOSRayCast", EditConditionHides))
	float MinDotProduct;

};

