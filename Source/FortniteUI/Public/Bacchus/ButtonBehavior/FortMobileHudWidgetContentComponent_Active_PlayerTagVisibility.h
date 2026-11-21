// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileHudWidgetContentComponent_Active_Visibility.h"
#include "FortMobileHudWidgetContentComponent_Active_PlayerTagVisibility.generated.h"

class UAbilitySystemComponent;

UCLASS()
class FORTNITEUI_API UFortMobileHudWidgetContentComponent_Active_PlayerTagVisibility : public UFortMobileHudWidgetContentComponent_Active_Visibility
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};

