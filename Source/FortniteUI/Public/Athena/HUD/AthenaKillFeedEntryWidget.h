// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaKillFeedEntryWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaKillFeedEntryWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnKillFeedEntrySet(const FText& KillfeedEntryText);

};

