// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortSkydivingShadowProxy.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortSkydivingShadowProxy : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSkydivingShadowProxy")
	float SkydivingHeightThreshold;

	UPROPERTY(EditAnywhere, Category="FortSkydivingShadowProxy")
	float SkydivingHeightCheckInterval;

	UPROPERTY(Config)
	bool bDestroyOnHide;

protected:
	UFUNCTION()
	void CheckHeight();

	UFUNCTION(BlueprintImplementableEvent)
	void HideShadowProxy();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowShadowProxy();

};

