// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FrontEnd/Habanero/FortHabaneroDisplayData.h"
#include "FortHabaneroTierWidget.generated.h"

class UFortHabaneroDisplayData;

UCLASS(meta=(DisableNativeTick))
class UFortHabaneroTierWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void FailedToFindRank();

	UFUNCTION(BlueprintImplementableEvent)
	void StartQueryForRank();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidgetDisplay(const FFortHabaneroTier& DisplayData);

	UPROPERTY(EditAnywhere, Category="FortHabaneroTierWidget", meta=(AllowPrivateAccess))
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

	UPROPERTY(EditAnywhere, Category="FortHabaneroTierWidget", meta=(AllowPrivateAccess))
	bool bInitializeToRepresentLocalUser;

};

