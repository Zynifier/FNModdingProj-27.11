// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastSessionId.generated.h"

class UTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaBroadcastSessionId : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_SessionId;

};

