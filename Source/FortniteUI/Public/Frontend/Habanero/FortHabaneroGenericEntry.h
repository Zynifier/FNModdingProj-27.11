// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Misc/DateTime.h"
#include "FortHabaneroGenericEntry.generated.h"

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortHabaneroGenericEntry : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText DateTimeAsTimeZoneTimeShort(const FDateTime& InDateTime, const FString& InTimeZone = TEXT(""));

};

