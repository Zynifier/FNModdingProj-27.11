// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortQuestMapEventSequence.generated.h"

class UFortQuestMapEventDot;
class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapEventSequence : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_DotBox;

	UPROPERTY(EditAnywhere, Category="FortQuestMapEventSequence")
	TSubclassOf<UFortQuestMapEventDot> DotWidgetClass;

};

