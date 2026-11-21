// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "FortMobileHudWidgetContentComponent_Active_Visibility.generated.h"

class UFortMobileHudWidgetContentComponent_Active;

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UFortMobileHudWidgetContentComponent_Active_Visibility : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMobileHudWidgetContentComponent_Active> WidgetComponent;

	UPROPERTY(EditDefaultsOnly, Category="HUD Visibility")
	TArray<FTagVisibility> TagVisibilities;

};

