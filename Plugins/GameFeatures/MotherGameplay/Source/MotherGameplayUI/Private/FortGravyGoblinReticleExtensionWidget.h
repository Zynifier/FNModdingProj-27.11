// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"
#include "FortGravyGoblinReticleExtensionWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortGravyGoblinReticleExtensionWidget : public UFortWeaponReticleExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemActivatable();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemInactivatable();

};

