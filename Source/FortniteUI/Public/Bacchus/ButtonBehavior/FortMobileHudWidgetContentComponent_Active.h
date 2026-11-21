// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileHudWidgetContentComponent.h"
#include "FortMobileHudWidgetContentComponent_Active.generated.h"

class UFortMobileHudWidgetContentComponent_Active_Visibility;
class UUserWidget;

UCLASS()
class UFortMobileHudWidgetContentComponent_Active : public UFortMobileHudWidgetContentComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Active")
	TSoftClassPtr<UUserWidget> ToggleSoftClass;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Active")
	TArray<TObjectPtr<UFortMobileHudWidgetContentComponent_Active_Visibility>> VisibilityModifiers;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> CurrentToggleWidget;

};

