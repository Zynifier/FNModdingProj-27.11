// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Plugin/Squeegee/FortSqueegeeTypes.h"
#include "FortContentGateDetailsWidget.generated.h"

class UFortContentGateRatingWidget;

UCLASS()
class UFortContentGateDetailsWidget : public UFortSqueegeeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowGamemodeDescription(const FString& ActivityTitle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowWeaponDescription();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortContentGateRatingWidget> ContentGateRatingWidget;

};

