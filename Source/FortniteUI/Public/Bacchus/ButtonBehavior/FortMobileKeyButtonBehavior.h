// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Bacchus/HUDWidgetBehavior.h"
#include "FortMobileKeyButtonBehavior.generated.h"

class UFortMobileKeyButton;

UCLASS(Abstract, BlueprintType, Blueprintable)
class FORTNITEUI_API UFortMobileKeyButtonBehavior : public UHUDWidgetBehavior
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Action")
	FKey Key;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortMobileKeyButton> Button;

};

