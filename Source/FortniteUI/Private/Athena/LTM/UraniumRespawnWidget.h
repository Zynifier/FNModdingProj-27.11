// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "UraniumRespawnWidget.generated.h"

class AFortPlayerStateAthena;
class UFortLazyImage;

UCLASS()
class UUraniumRespawnWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetUpPlayerPortrait(UFortLazyImage* Image, const AFortPlayerStateAthena* PlayerState);

};

