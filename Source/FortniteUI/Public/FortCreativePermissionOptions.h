// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/MyIsland/FortCreativeMyIslandContentPanelInterface.h"
#include "FortMatchmakingKnobsModal.h"
#include "FortCreativePermissionOptions.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePermissionOptions : public UFortMatchmakingKnobsModal, public IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(BlueprintProtected))
	bool ArePermisionChecksEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnApplyChanges(const bool bSuccessful);

	UPROPERTY(BlueprintReadWrite, Category="FortCreativePermissionOptions")
	bool bCanEdit;

};

