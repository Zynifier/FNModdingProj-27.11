// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortConditionalCalendarEvent.generated.h"

UCLASS(MinimalAPI)
class AFortConditionalCalendarEvent : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly)
	void SetCalendarActionEnabled(bool NewEnabled);

};

