// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "StartUpUIStateWidget_SubgameSelect.generated.h"

class UCommonUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UStartUpUIStateWidget_SubgameSelect : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> BottomBar;

};

