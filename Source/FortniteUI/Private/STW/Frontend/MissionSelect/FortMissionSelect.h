// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "CommonActivatablePanelLegacy.h"
#include "STW/Frontend/MissionSelect/FortMissionSelect_STW.h"
#include "FortMissionSelect.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMissionSelect : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MissionSelect")
	bool NavigateMissionTiles(EUINavigation Direction);

	UPROPERTY(BlueprintAssignable)
	FMissionSelectNavigationDelegate OnNavigation;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool CanCaptureAcceptInput();

};

