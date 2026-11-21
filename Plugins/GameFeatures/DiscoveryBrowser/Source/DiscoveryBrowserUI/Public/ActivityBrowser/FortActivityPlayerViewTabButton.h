// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/FortTabButton.h"
#include "FortActivityPlayerViewTabButton.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivityPlayerViewTabButton : public UFortTabButton
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Count;

};

