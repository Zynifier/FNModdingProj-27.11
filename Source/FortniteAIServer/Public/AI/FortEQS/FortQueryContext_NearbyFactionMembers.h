// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "ScalableFloat.h"
#include "FortQueryContext_NearbyFactionMembers.generated.h"

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortQueryContext_NearbyFactionMembers : public UEnvQueryContext
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_NearbyFactionMembers")
	FScalableFloat NearbyFactionMemberDistance;

};

