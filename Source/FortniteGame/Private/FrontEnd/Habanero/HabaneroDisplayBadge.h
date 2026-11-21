// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FrontEnd/Habanero/FortHabaneroDisplayData.h"
#include "HabaneroDisplayBadge.generated.h"

class UFortHabaneroDisplayData;

UCLASS(meta=(DisableNativeTick))
class UHabaneroDisplayBadge : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBadgeInternal(const FFortHabaneroTier& TierData);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HabaneroDisplayBadge", meta=(AllowPrivateAccess))
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

};

