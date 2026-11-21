// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortProgressiveStageList.generated.h"

class UAthenaScrollBox;
class UCommonButtonGroupBase;
class UFortProgressiveStageWidget;
class UFortSwipePanel;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortProgressiveStageList : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SelectStageInDirection(const int32 Direction);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UFortProgressiveStageWidget* AddStageWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void ClearStageWidgets();

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_StageItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_StageList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_Navigation;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortProgressiveStageWidget>> Stages;

};

