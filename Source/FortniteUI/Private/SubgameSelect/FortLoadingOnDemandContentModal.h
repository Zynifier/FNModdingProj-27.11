// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortLoadingOnDemandContentModal.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLoadingOnDemandContentModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetCancelButtonText(const FText& InText);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedProgress(float Percent);

	UFUNCTION(BlueprintCallable)
	void StartProgressUpdateTimer();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLoadingOnDemandContentModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

};

