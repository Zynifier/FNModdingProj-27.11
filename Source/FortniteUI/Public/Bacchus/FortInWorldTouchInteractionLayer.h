// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortInWorldTouchInteractionLayer.generated.h"

class UWidgetInteractionComponent;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortInWorldTouchInteractionLayer : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractor;

};

