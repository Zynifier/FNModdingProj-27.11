// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Subscriptions/FortProgressiveItemTypes.h"
#include "FortProgressiveSetTile.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveSetTile : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Initialize Set Info"))
	void BP_OnInitializeSetInfo(const FProgressiveSetInfo& InSetInfo, const FText& BottomText, const FText& BottomSubtext, const bool bSubscribed);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Tile Material Loaded"))
	void BP_OnTileMaterialLoaded(const bool bSubscribed);

};

