// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortProgressiveSetDetailsWidget.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveSetDetailsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortProgressiveSetDetailsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Set Details"))
	void BP_OnUpdateSetDetails(const FText& SetName, const FText& ExpiringText, const bool bCompleted);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

};

