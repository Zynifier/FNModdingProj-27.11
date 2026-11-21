// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaCDNWarmer.generated.h"

class UEpicMediaCDNHostnames;

UCLASS(Config=Game, BlueprintType)
class UFortMediaCDNWarmer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

	UPROPERTY(BlueprintReadWrite, Category="FortMediaCDNWarmer")
	bool bWarmLive;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaCDNWarmer")
	TObjectPtr<UEpicMediaCDNHostnames> CDNHostNames;

};

