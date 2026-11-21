// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortActiveComponentWidget.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActiveComponentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortActiveComponentWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActiveComponentWidget", meta=(BindWidget, EditInline="true"))
	UCommonTextBlock* Text_ActiveComponentName;

};

