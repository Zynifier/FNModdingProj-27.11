// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "CreativeModalDialogWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativeModalDialogWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="CreativeModalDialogWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle MainMenuInputRowHandle;

};

