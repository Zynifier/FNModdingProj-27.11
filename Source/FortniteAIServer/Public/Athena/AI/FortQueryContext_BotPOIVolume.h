// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "Math/MathFwd.h"
#include "FortQueryContext_BotPOIVolume.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortQueryContext_BotPOIVolume : public UEnvQueryContext
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_BotPOIVolume")
	bool bSetProjectedToNavmeshLocationAsContext;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_BotPOIVolume", meta=(EditCondition="bSetProjectedToNavmeshLocationAsContext"))
	FVector ProjectionExtent;

};

