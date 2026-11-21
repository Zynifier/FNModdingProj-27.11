// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortServerMessageWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortServerMessageWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleServerAlert(int32 TimeRemainingStart, int32 TimeRemainingEnd);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAlertBegin(int32 SecondsRemainingStart, int32 SecondsRemainingEnd, const FText& AlertText);

	UFUNCTION()
	void SetServerMigrationDelegate();

};

