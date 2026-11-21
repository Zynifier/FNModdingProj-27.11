// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionListEntry.h"
#include "AthenaCollectionListEntryCharacter.generated.h"

class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionListEntryCharacter : public UAthenaCollectionListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Locations Found Set"))
	void BP_OnLocationsFoundSet(int32 NumFound, int32 NumAvailable, bool bAllFound);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionListEntryCharacter", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Item Icon"))
	FName ParamName_ItemIcon;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Is Discovered"))
	FName ParamName_IsDiscovered;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Is Complete"))
	FName ParamName_IsComplete;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Secondary Icon"))
	FName ParamName_SecondaryIcon;

};

