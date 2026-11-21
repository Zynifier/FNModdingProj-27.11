// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "RespawnAndSpectateSelectContainerWidget.generated.h"

class URespawnAndSpectateSelectWidgetBase;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URespawnAndSpectateSelectContainerWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPanelOptionSelected(int32 SelectedOption);

	UFUNCTION()
	void OnRespawnAndSpectateSelectAvailableOptionsChanged();

	UFUNCTION()
	void OnRespawnAndSpectateSelectPlayerRespawned();

	UFUNCTION()
	void UpdateRespawnAndSpectateSelectWidgetVisibility(bool bNewVisibility);

	UPROPERTY(EditAnywhere, Category="RespawnAndSpectateSelectContainerWidget")
	TSubclassOf<URespawnAndSpectateSelectWidgetBase> RespawnAndSpectateSelectWidgetClass;

};

