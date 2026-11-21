// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionScreenInfoOverlay.h"
#include "AthenaCollectionScreenInfoOverlayCharacter.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionScreenInfoOverlayCharacter : public UAthenaCollectionScreenInfoOverlay
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Locations Found Set"))
	void BP_OnLocationsFoundSet(int32 NumFound, int32 NumAvailable, bool bAllFound);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="99", ClampMin="0", DisplayName="Locations Found"))
	int32 DesignTime_LocationsFound;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="99", ClampMin="1", DisplayName="Locations Available"))
	int32 DesignTime_LocationsAvailable;
#endif

private:
	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Progress"))
	FName ParamName_Progress;

};

