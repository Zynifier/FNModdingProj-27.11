// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativeGeneralThrottleManager.generated.h"

class UObject;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnThrottleComplete, bool, Succeeded);

UCLASS()
class UFortCreativeGeneralThrottleManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
	void RequestThrottleObject(UObject* InWorldContextObject, UObject* InThrottleObject, int32 InThrottleBucketID, FOnThrottleComplete InThrottleCompleteFunction);

};

