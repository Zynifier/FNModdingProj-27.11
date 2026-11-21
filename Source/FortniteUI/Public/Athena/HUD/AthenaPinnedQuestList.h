// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPinnedQuestList.generated.h"

class UAthenaPinnedQuestInfo;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaPinnedQuestList : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaPinnedQuestInfo> PinnedQuestInfo_LocalPlayer;

};

