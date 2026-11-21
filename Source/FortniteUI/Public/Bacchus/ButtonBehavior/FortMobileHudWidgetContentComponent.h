// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMobileHudWidgetContentComponent.generated.h"

class UHUDWidgetBehavior;

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UFortMobileHudWidgetContentComponent : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UHUDWidgetBehavior> WidgetBehavior;

};

