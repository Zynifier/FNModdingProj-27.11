// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/Collections/AthenaCollectionItemToast.h"
#include "AthenaCollectionItemToastCharacter.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionItemToastCharacter : public UAthenaCollectionItemToast
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Location Set"))
	void BP_OnLocationsSet(int32 NumFound, int32 NumLocations);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="3", ClampMin="0", DisplayName="Found Locations"))
	int32 DesignTime_FoundLocations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="3", ClampMin="1", DisplayName="Num Locations"))
	int32 DesignTime_NumLocations;
#endif

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToastCharacter")
	FText NumLocationsFormat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_NumLocations;

};

