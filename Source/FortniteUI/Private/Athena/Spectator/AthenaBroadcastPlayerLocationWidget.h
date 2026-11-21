// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastPlayerLocationWidget.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaBroadcastPlayerLocationWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PlayerLocationText;

private:
	UFUNCTION()
	void OnRemoteClientPoiTagIDChanged(int16 RemoteClientPoiTagID);

};

